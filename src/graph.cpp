#include "graph.hpp"
#include <algorithm>

Grafo::Grafo(int tamanho) {
    this->tamanho = tamanho;
    this->nos = new No[tamanho];
}


No* Grafo::getNos() {
    return this->nos;
}

void Grafo::setTamanho(int novoTamanho) {
    this->tamanho = novoTamanho;
}

int Grafo::getTamanho() {
    return this->tamanho;
}


void Grafo::bubbleSort() {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            int cor1 = nos[j].getCor();
            int cor2 = nos[j + 1].getCor();

            if (cor1 > cor2)
                std::swap(nos[j], nos[j + 1]);
            else if (cor1 == cor2) {
                if (nos[j].getRotulo() > nos[j + 1].getRotulo())
                    std::swap(nos[j], nos[j + 1]);
            }
        }
    }
}


void Grafo::selectionSort() {
    for (int i = 0; i < tamanho - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < tamanho; j++) {
            int cor1 = nos[j].getCor();
            int cor2 = nos[minIndex].getCor();

            if (cor1 < cor2) {
                minIndex = j;
            } else if (cor1 == cor2) {
                if (nos[j].getRotulo() < nos[minIndex].getRotulo()) {
                    minIndex = j;
                }
            }
        }

        if (minIndex != i) {
            std::swap(nos[i], nos[minIndex]);
        }
    }
}


void Grafo::insertionSort() {
    for (int i = 1; i < tamanho; i++) {
        No current = nos[i];
        int j = i - 1;

        while (j >= 0 && (nos[j].getCor() > current.getCor() ||
                          (nos[j].getCor() == current.getCor() && nos[j].getRotulo() > current.getRotulo()))) {
            nos[j + 1] = nos[j];
            j--;
        }

        nos[j + 1] = current;
    }
}


int Grafo::partition(int down, int up) {
    No pivot = nos[up];
    int i = down - 1;

    for (int j = down; j <= up - 1; j++) {
        int cor1 = nos[j].getCor();
        int cor2 = pivot.getCor();

        if (cor1 < cor2 || (cor1 == cor2 && nos[j].getRotulo() < pivot.getRotulo())) {
            i++;
            std::swap(nos[i], nos[j]);
        }
    }

    std::swap(nos[i + 1], nos[up]);
    return i + 1;
}

void Grafo::quickSort(int down, int up) {
    if (down < up) {
        int pi = partition(down, up);

        quickSort(down, pi - 1);
        quickSort(pi + 1, up);
    }
}


void Grafo::merge(int left, int mid, int right) {
    int nodeLSize = mid - left + 1;
    int nodeRSize = right - mid;

    No* L = new No[nodeLSize];
    No* R = new No[nodeRSize];

    for (int i = 0; i < nodeLSize; i++) {
        L[i] = nos[left + i];
    }
    for (int j = 0; j < nodeRSize; j++) {
        R[j] = nos[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < nodeLSize && j < nodeRSize) {
        int cor1 = L[i].getCor();
        int cor2 = R[j].getCor();

        if (cor1 < cor2 || (cor1 == cor2 && L[i].getRotulo() < R[j].getRotulo())) {
            nos[k] = L[i];
            i++;
        } else {
            nos[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < nodeLSize) {
        nos[k] = L[i];
        i++;
        k++;
    }

    while (j < nodeRSize) {
        nos[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}


void Grafo::mergeSort(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(left, mid);
        mergeSort(mid + 1, right);

        merge(left, mid, right);
    }
}

void Grafo::heapify(int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n &&
        (nos[left].getCor() < nos[smallest].getCor() ||
         (nos[left].getCor() == nos[smallest].getCor() && nos[left].getRotulo() < nos[smallest].getRotulo()))) {
        smallest = left;
    }

    if (right < n &&
        (nos[right].getCor() < nos[smallest].getCor() ||
         (nos[right].getCor() == nos[smallest].getCor() && nos[right].getRotulo() < nos[smallest].getRotulo()))) {
        smallest = right;
    }

    if (smallest != i) {
        std::swap(nos[i], nos[smallest]);
        heapify(n, smallest);
    }
}

void Grafo::heapSort() {
    int n = getTamanho();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    for (int i = n - 1; i > 0; i--) {
        std::swap(nos[0], nos[i]);
        heapify(i, 0);
    }

    int start = 0, end = this->getTamanho() - 1;
    while (start < end) {
        std::swap(nos[start], nos[end]);
        start++;
        end--;
    }
}
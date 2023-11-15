#include "graph.hpp"

Grafo::Grafo(int tamanho) {
    this->tamanho = tamanho;
    this->nos = new No[tamanho];
}

No* Grafo::getNos() {
    if (this->nos == nullptr) {
        // Lida com a situação de ponteiro nulo, lança uma exceção ou realiza alguma ação apropriada.
    }
    return this->nos;
}

void Grafo::setTamanho(int novoTamanho) {
    if (novoTamanho <= 0) {
        throw std::invalid_argument("O tamanho do grafo deve ser positivo.");
    }
    this->tamanho = novoTamanho;
}

int Grafo::getTamanho() {
    return this->tamanho;
}

void Grafo::insertionSort(int right, int left) {
    for (int i = left + 1; i <= right; i++) {
        No current = this->nos[i];
        int j = i - 1;

        while (j >= left &&
               (this->nos[j].getCor() > current.getCor() ||
                (this->nos[j].getCor() == current.getCor() &&
                 this->nos[j].getRotulo() > current.getRotulo()))) {

          this->nos[j + 1] = this->nos[j];
          j--;
        }

        this->nos[j + 1] = current;
    }
}

void Grafo::insertionSort() {
  for (int i = 1; i < tamanho; i++) {
    No current = this->nos[i];
    int j = i - 1;

    while (j >= 0 && (this->nos[j].getCor() > current.getCor() || 
                     (this->nos[j].getCor() == current.getCor() && this->nos[j].getRotulo() > current.getRotulo()))) {
      this->nos[j + 1] = this->nos[j];
      j--;
    }

    this->nos[j + 1] = current;
  }
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

No Grafo::getNoPorRotulo(int label) {
    for (int i = 0; i < tamanho; i++) {
        if (this->getNos()[i].getRotulo() == label) {
            return this->getNos()[i];
        }
    }
    throw std::out_of_range("Rotulo nao encontrado");
}

void Grafo::combSort() {
    int n = this->getTamanho();
    int gap = n; // Inicializa o fator de lacuna
    bool swapped = true;

    while (gap != 1 || swapped) {
        // Atualiza o fator de lacuna de acordo com o método recomendado (1.3)
        gap = (gap * 10) / 13;
        if (gap < 1) gap = 1;

        swapped = false;

        // Realiza uma passagem pelos nós com o fator de lacuna atual
        for (int i = 0; i < n - gap; i++) {
            No& current = this->nos[i];
            No& next = this->nos[i + gap];

            if (current.getCor() > next.getCor() ||
                (current.getCor() == next.getCor() && current.getRotulo() > next.getRotulo())) {
                std::swap(current, next);
                swapped = true;
            }
        }
    }
}

bool Grafo::guloso() {
  for (int i = 0; i < this->getTamanho(); i++) {
    No* noAtual = &(this->getNos()[i]);
    int corAtual = noAtual->getCor();
    int aux = 1;

    while (aux < corAtual) {
      bool corEncontrada = false;

    for (int j = 0; j < noAtual->getNumVizinhos(); j++) {
        int rotuloVizinho = noAtual->getVizinhos()[j].getRotulo();;
        No vizinho = this->getNoPorRotulo(rotuloVizinho);

        if (vizinho.getCor() == aux) {
          corEncontrada = true;
          break;
        }
      }

      if (!corEncontrada) return false;

      aux++;
    }
  }
  return true;
}
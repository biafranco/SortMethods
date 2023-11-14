#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "node.hpp"

class Grafo {
public:
    Grafo(int tamanho);
    No* getNos();
    void setTamanho(int novoTamanho);
    int getTamanho();
    void bubbleSort();
    void selectionSort();
    void insertionSort();
    void quickSort(int down, int up);
    void mergeSort(int left, int right);
    void heapSort();
    void timSort();
    bool greedy();

private:
    int tamanho;
    No* nos;
    int partition(int down, int up);
    void merge(int left, int mid, int right);
    void heapify(int n, int i);
    void insertionSort(int left, int right);
};

#endif


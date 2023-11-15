#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "node.hpp"

/**
 * @class Grafo
 * @brief Classe que representa um grafo e fornece operações de ordenação e busca.
 */
class Grafo {
public:
    /**
     * @brief Construtor da classe Grafo.
     * @param tamanho O tamanho inicial do grafo.
     */
    Grafo(int tamanho);

    /**
     * @brief Obtém os nós do grafo.
     * @return Um ponteiro para a lista de nós do grafo.
     */
    No* getNos();

    /**
     * @brief Define o tamanho do grafo.
     * @param novoTamanho O novo tamanho a ser atribuído ao grafo.
     */
    void setTamanho(int novoTamanho);

    /**
     * @brief Obtém o tamanho do grafo.
     * @return O tamanho atual do grafo.
     */
    int getTamanho();

    /**
     * @brief Ordena os nós do grafo usando o algoritmo Bubble Sort.
     */
    void bubbleSort();

    /**
     * @brief Ordena os nós do grafo usando o algoritmo Selection Sort.
     */
    void selectionSort();

    /**
     * @brief Ordena os nós do grafo usando o algoritmo Insertion Sort.
     * @param right Índice do lado direito da sublista a ser ordenada.
     * @param left Índice do lado esquerdo da sublista a ser ordenada.
     */
    void insertionSort(int right, int left);

    /**
     * @brief Ordena os nós do grafo usando o algoritmo Insertion Sort.
     */
    void insertionSort();

    /**
     * @brief Ordena os nós do grafo usando o algoritmo Quick Sort.
     * @param down Índice mais baixo da sublista a ser ordenada.
     * @param up Índice mais alto da sublista a ser ordenada.
     */
    void quickSort(int down, int up);

    /**
     * @brief Ordena os nós do grafo usando o algoritmo Merge Sort.
     * @param left Índice do lado esquerdo da sublista a ser ordenada.
     * @param right Índice do lado direito da sublista a ser ordenada.
     */
    void mergeSort(int left, int right);

    /**
     * @brief Ordena os nós do grafo usando o algoritmo Heap Sort.
     */
    void heapSort();

    /**
     * @brief Ordena os nós do grafo usando o algoritmo Comb Sort.
     */
    void combSort();

    /**
     * @brief Obtém um nó do grafo pelo rótulo.
     * @param label O rótulo do nó desejado.
     * @return Um objeto No correspondente ao rótulo fornecido.
     */
    No getNoPorRotulo(int label);

    /**
     * @brief Executa um algoritmo guloso para coloração de vértices do grafo.
     * @return Verdadeiro se a coloração for bem-sucedida, falso caso contrário.
     */
    bool guloso();

private:
    int tamanho; ///< O tamanho do grafo.
    No* nos;     ///< Lista de nós do grafo.

    /**
     * @brief Particiona a lista de nós para o algoritmo Quick Sort.
     * @param down Índice mais baixo da sublista a ser particionada.
     * @param up Índice mais alto da sublista a ser particionada.
     * @return O índice do pivô após a partição.
     */
    int partition(int down, int up);

    /**
     * @brief Funde duas sublistas para o algoritmo Merge Sort.
     * @param left Índice do lado esquerdo da sublista a ser fundida.
     * @param mid Índice médio entre as duas sublistas a serem fundidas.
     * @param right Índice do lado direito da sublista a ser fundida.
     */
    void merge(int left, int mid, int right);

    /**
     * @brief Converte uma subárvore em um heap para o algoritmo Heap Sort.
     * @param n O tamanho da subárvore.
     * @param i O índice da raiz da subárvore.
     */
    void heapify(int n, int i);
};

#endif

#include "graph.hpp"
#include <iostream>
#include <sstream>

int main() {
    char identificador;
    int tamanho;
    std::cin >> identificador >> tamanho;

    // Aloca espaço para os nós
    Grafo* grafo = new Grafo(tamanho);
    
    for(int i = 0; i < tamanho; i++){
    grafo->getNos()[i].setRotulo(i);
  }
    for (int i = 0; i < tamanho; i++) {
    int numVizinhos;
    std::cin >> numVizinhos;

    for (int j = 0; j < numVizinhos; j++) {
      int rotuloVizinho;
      std::cin >> rotuloVizinho;
      grafo->getNos()[i].adicionarVizinho(rotuloVizinho);
        }
    }
        
        
  for (int i = 0; i < tamanho; i++) {
    int colour;
    std::cin >> colour;
    grafo->getNos()[i].setCor(colour);
  }

  switch (identificador) {
    case 'b':
      grafo->bubbleSort();
      break;

    case 's':
      grafo->selectionSort();
      break;

    case 'i':
      grafo->insertionSort();
      break;

    case 'q':
      grafo->quickSort( 0, (tamanho - 1) );
      break;

    case 'm':
      grafo->mergeSort( 0, (tamanho - 1) );
      break;

    case 'p':
        grafo->heapSort();
        break;
        
    case 'y':
      grafo->combSort();
      break;

    default:
      std::cerr << "Modo invalido" << std::endl;
      return 1; 
  }
  
    if(grafo->guloso()){
      std::cout << 1 << " ";
      for(int i = 0; i < tamanho; i++) 
      std::cout << grafo->getNos()[i].getRotulo() << " ";
    }
    else std::cout << 0;



  delete grafo;

  return 0;
}
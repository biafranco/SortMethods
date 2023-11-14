#include "graph.hpp"
#include <iostream>
#include <sstream>

int main() {
    char identificador;
    int tamanho;
    std::cin >> tamanho >> identificador;

    std::cout << "identificador: " << identificador << std::endl;
    std::cout << "tamanho: " << tamanho << std::endl;

    // Aloca espaço para os nós
    Grafo* grafo = new Grafo(tamanho);

    for (int i = 0; i < tamanho; i++) {
        grafo->getNos()[i].setRotulo(i);
    }

    for (int i = 0; i < tamanho; i++) {
        int numVizinhos;
        std::cin >> numVizinhos;

        for (int j = 0; j < numVizinhos; j++) {
            int vizinho;
            std::cin >> vizinho;
            // Add neighbor by index
            grafo->getNos()[i].adicionarVizinho(vizinho);
        }
    }

    for (int i = 0; i < tamanho; i++) {
        int cor;
        std::cin >> cor;
        grafo->getNos()[i].setCor(cor);
    }

 for (int i = 0; i < tamanho; i++) {
    for (int j = 0; j < grafo->getNos()[i].getNumVizinhos(); j++) {
        int vRotulo = grafo->getNos()[i].getVizinhos()[j].getRotulo();
        grafo->getNos()[i].adicionarVizinho(vRotulo);
    }
}


    for (int i = 0; i < tamanho; i++)
    {
        std::cout << "Node " << grafo->getNos()[i].getRotulo() << "foi alocado"<< std::endl;
    }

    std::cout << "Grafo criado de tamanho: " << grafo->getTamanho() << std::endl;

    delete grafo;
    return 0;
}       


/*
6 b
3 1 2 3
3 0 2 4
3 0 1 5
1 0
1 1
1 2
1 2 3 3 1 1
*/
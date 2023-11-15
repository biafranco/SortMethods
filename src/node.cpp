#include "node.hpp"

// Implementação para a classe No

/**
 * @brief Construtor padrão da classe No.
 */
No::No() : rotulo(0), cor(0), vizinhos(nullptr), numVizinhos(0) {}

/**
 * @brief Define o rótulo do nó.
 * @param novoRotulo O novo rótulo a ser atribuído ao nó.
 */
void No::setRotulo(int novoRotulo) {
    rotulo = novoRotulo;
}

/**
 * @brief Define a cor do nó.
 * @param novaCor A nova cor a ser atribuída ao nó.
 */
void No::setCor(int novaCor) {
    cor = novaCor;
}

/**
 * @brief Obtém o rótulo do nó.
 * @return O rótulo do nó.
 */
int No::getRotulo() {
    return rotulo;
}

/**
 * @brief Obtém a cor do nó.
 * @return A cor do nó.
 */
int No::getCor() {
    return cor;
}

/**
 * @brief Obtém o número de vizinhos do nó.
 * @return O número de vizinhos do nó.
 */
int No::getNumVizinhos() {
    return numVizinhos;
}

/**
 * @brief Adiciona um vizinho ao nó.
 * @param rotuloV O rótulo do novo vizinho a ser adicionado.
 */
void No::adicionarVizinho(int rotuloV) {
  if (vizinhos == nullptr)
    vizinhos = new No[1];
  else {
    No * aux = new No[this->getNumVizinhos()+1];
    for(int i = 0; i < this->getNumVizinhos(); i++) {
      aux[i] = vizinhos[i];
    }

    delete[] vizinhos;
    vizinhos = aux;
  }
    vizinhos[numVizinhos++].setRotulo(rotuloV);
}

/**
 * @brief Obtém a lista de vizinhos do nó.
 * @return Um ponteiro para a lista de vizinhos.
 */
No* No::getVizinhos() {
    return vizinhos;
}

#include "node.hpp"

// Implementação para a classe No

No::No(){
    this->rotulo = 0;
    this->cor = 0;
    this -> vizinhos = nullptr;
    this -> numVizinhos = 0;

}
void No::setRotulo(int novoRotulo) {
    rotulo = novoRotulo;
}

void No::setCor(int novaCor) {
    cor = novaCor;
}

int No::getRotulo() {
    return rotulo;
}

int No::getCor() {
    return cor;
}

int No::getNumVizinhos() {
    return numVizinhos;
}

void No::adicionarVizinho(int idVizinho) {
}

No* No::getVizinhos() {
    return vizinhos;
}

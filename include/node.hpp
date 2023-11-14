#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

class No {
  friend class Grafo;
public:

  No();
  int getRotulo();

  void setRotulo(int novoRotulo);
  void adicionarVizinho(int idVizinho);
  int getCor();
  void setCor(int novaCor);
  No *getVizinhos();
  int getNumVizinhos();

private:
  int rotulo;           ///< O rótulo do nó.
  int cor;              ///< A cor do nó.
  No *vizinhos;         ///< Lista encadeada de rótulos de vizinhos.
  int numVizinhos;      ///< Número de vizinhos.
};

#endif

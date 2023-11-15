#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

/**
 * @brief Classe que representa um nó em um grafo.
 * 
 * Esta classe é utilizada para criar e manipular nós em um grafo.
 */
class No {
  friend class Grafo;
public:

  /**
   * @brief Construtor padrão da classe No.
   */
  No();

  /**
   * @brief Obtém o rótulo do nó.
   * @return O rótulo do nó.
   */
  int getRotulo();

  /**
   * @brief Define o rótulo do nó.
   * @param novoRotulo O novo rótulo a ser atribuído ao nó.
   */
  void setRotulo(int novoRotulo);

  /**
   * @brief Adiciona um vizinho ao nó.
   * @param idVizinho O rótulo do novo vizinho a ser adicionado.
   */
  void adicionarVizinho(int idVizinho);

  /**
   * @brief Obtém a cor do nó.
   * @return A cor do nó.
   */
  int getCor();

  /**
   * @brief Define a cor do nó.
   * @param novaCor A nova cor a ser atribuída ao nó.
   */
  void setCor(int novaCor);

  /**
   * @brief Obtém a lista de vizinhos do nó.
   * @return Um ponteiro para a lista de vizinhos.
   */
  No *getVizinhos();

  /**
   * @brief Obtém o número de vizinhos do nó.
   * @return O número de vizinhos do nó.
   */
  int getNumVizinhos();

private:
  int rotulo;           ///< O rótulo do nó.
  int cor;              ///< A cor do nó.
  No *vizinhos;         ///< Lista encadeada de rótulos de vizinhos.
  int numVizinhos;      ///< Número de vizinhos.
};

#endif

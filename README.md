# 📊 SortMethods

Projeto acadêmico que implementa múltiplos algoritmos de ordenação aplicados a um grafo com nós coloridos. O grafo é construído a partir de entrada padrão, e os algoritmos de ordenação organizam os nós com base em suas cores. Após a ordenação, é aplicada uma heurística gulosa sobre o grafo.

---

## ✨ Funcionalidades

- Leitura de grafos com rótulos, vizinhos e cores.
- Ordenação dos nós com diferentes algoritmos:
  - Bubble Sort
  - Selection Sort
  - Insertion Sort
  - Quick Sort
  - Merge Sort
  - Heap Sort
  - Comb Sort
- Aplicação de uma heurística gulosa ao grafo ordenado.
- Impressão do resultado da heurística e ordem dos nós, se aplicável.

---

## 🗂️ Estrutura do Projeto

.
├── src/
│   ├── main.cpp          # Função principal
│   └── graph.hpp         # Definição e implementação das operações do grafo
├── input.txt             # Exemplo de entrada
├── output.txt            # Resultado esperado
├── Makefile              # Compilação automatizada
└── README.md             # Este arquivo

---

## 🧪 Exemplo de Uso

### 📦 Compilação

make

### ▶️ Execução

./bin/main < input.txt > output.txt

---

## 📥 Formato de entrada (input.txt)

q 4
2 1 2
2 0 3
2 0 3
2 1 2
3 1 2 3

- Primeira linha: <modo> <tamanho>
  - modo: caractere que define o algoritmo de ordenação a ser usado (b, s, i, q, m, p, y)
  - tamanho: número de nós no grafo
- Linhas seguintes:
  - Lista de vizinhos de cada nó
  - Lista de cores dos nós

---

## 📤 Saída esperada (output.txt)

1 0 1 2 3

- 1: indica que a heurística foi bem-sucedida
- A sequência representa a ordem dos nós após ordenação e aplicação da heurística

---

## 🔤 Modos de Ordenação

| Letra | Algoritmo        |
|-------|------------------|
| b     | Bubble Sort      |
| s     | Selection Sort   |
| i     | Insertion Sort   |
| q     | Quick Sort       |
| m     | Merge Sort       |
| p     | Heap Sort        |
| y     | Comb Sort        |

---

## 👩‍💻 Autora

Bianca Franco  
Aluna de Sistemas de Informação — UFMG  
📧 contato.biancafranco@gmail.com  
🔗 https://github.com/biafranco

---

## 📝 Licença

Projeto acadêmico desenvolvido como parte da disciplina de Estruturas de Dados. Uso não-comercial e educacional.

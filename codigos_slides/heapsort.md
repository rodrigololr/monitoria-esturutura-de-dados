---
marp: true
theme: gaia
backgroundColor: #1a1a1a
color: #f0f0f0
---

# **Algoritmos de Ordenação: Heap Sort**
## Estrutura de Dados em C

---

## **6. Heap Sort**

E agora, vamos ver uma demonstração de como o algoritmo funciona...

---

### **Heap Sort: Como Pensa?**

Usa uma estrutura de dados auxiliar chamada **Heap**, que é uma árvore binária com propriedades especiais.

- **Lógica:**
  1.  **Construir Max-Heap:** Transforma o vetor em um "Max-Heap", onde o maior elemento está sempre na raiz (topo).
  2.  **Extrair e Ordenar:** Troca o maior elemento (a raiz) com o último elemento, "remove" o último da consideração e reconstitui o Heap com os elementos restantes. Repete até o vetor estar ordenado.

---

### **Heap Sort: Código em C**

```c
#include <stdio.h>

void trocar(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int arr[], int n, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && arr[esq] > arr[maior]) maior = esq;
    if (dir < n && arr[dir] > arr[maior]) maior = dir;
    if (maior != i) {
        trocar(&arr[i], &arr[maior]);
        heapify(arr, n, maior);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        trocar(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
```

---
### **Heap Sort: Complexidade**
- **Tempo:** O(n log n) em todos os casos (pior, médio e melhor).
- **Espaço:** O(1), pois é um algoritmo in-place (não usa espaço extra significativo).
- **Estável:** Não, pois a ordem relativa dos elementos iguais pode ser alterada.
- **Uso:** Útil para ordenar grandes conjuntos de dados, especialmente quando a memória é limitada, pois não requer espaço extra significativo.
- **Importante:** Heap Sort é um algoritmo eficiente e é frequentemente usado em sistemas que requerem ordenação em tempo real, como sistemas operacionais e bancos de dados.
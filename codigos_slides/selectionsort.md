---
marp: true
theme: gaia
backgroundColor: #1a1a1a
color: #f0f0f0
---

# **Algoritmos de Ordenação: Selection Sort**
## Estrutura de Dados em C

---

## **2. Selection Sort**

E agora, vamos ver uma demonstração de como o algoritmo funciona...

---

### **Selection Sort: Como Pensa?**

Ele divide o vetor em duas partes: uma ordenada (que começa vazia) e uma não ordenada.

- **Lógica:** A cada passo, ele encontra o **menor elemento** da parte não ordenada.
- Depois, ele **troca** esse menor elemento com o primeiro elemento da parte não ordenada.
- Isso aumenta a parte ordenada em um elemento, até que todo o vetor esteja ordenado.

**Analogia:** Como você organiza cartas de um baralho na mão, procurando sempre a menor carta para colocar no começo.

---

### **Selection Sort: Código em C**

```c
#include <stdio.h>

void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        trocar(&arr[min_idx], &arr[i]);
    }
}
```

---
### **Selection Sort: Complexidade**
- **Tempo:** O(n²) no pior caso, O(n²) no melhor caso (sempre que o vetor já está ordenado).
- **Espaço:** O(1), pois é um algoritmo in-place (não usa espaço extra significativo).
- **Estável:** Não, pois a ordem relativa dos elementos iguais pode ser alterada.
- **Uso:** Útil para listas pequenas ou quando a memória é limitada, pois não requer espaço extra significativo.
- **Importante:** Selection Sort é um algoritmo simples e fácil de entender, mas não é eficiente para grandes conjuntos de dados.
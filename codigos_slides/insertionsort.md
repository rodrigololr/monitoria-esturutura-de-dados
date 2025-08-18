---
marp: true
theme: gaia
backgroundColor: #1a1a1a
color: #f0f0f0
---

# **Algoritmos de Ordenação: Insertion Sort**
## Estrutura de Dados em C

---

## **3. Insertion Sort**

E agora, vamos ver uma demonstração de como o algoritmo funciona...

---

### **Insertion Sort: Como Pensa?**

Também divide o vetor em uma parte ordenada e uma não ordenada. Ele é muito eficiente para vetores pequenos ou "quase ordenados".

- **Lógica:** Pega o primeiro elemento da parte não ordenada.
- Compara ele com os elementos da parte ordenada (da direita para a esquerda), **deslocando** os maiores para a direita.
- **Insere** o elemento na posição correta que foi aberta.

**Analogia:** Exatamente como a maioria das pessoas organiza um baralho.

---

### **Insertion Sort: Código em C**

```c
#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}
```

---
### **Insertion Sort: Complexidade**
- **Tempo:** O(n²) no pior caso, O(n) no melhor caso (quando o vetor já está ordenado).
- **Espaço:** O(1), pois é um algoritmo in-place (não usa espaço extra significativo).
- **Estável:** Sim, mantém a ordem relativa dos elementos iguais.
- **Uso:** Muito eficiente para listas pequenas ou quase ordenadas. É o algoritmo de ordenação mais usado em sistemas de ordenação de baixo nível, como o algoritmo `sort()` da linguagem C++.
- **Importante:** Insertion Sort é um algoritmo adaptativo, o que significa que ele se torna mais eficiente quando o vetor já está parcialmente ordenado.
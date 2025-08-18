---
marp: true
theme: gaia
backgroundColor: #1a1a1a
color: #f0f0f0
---

# **Algoritmos de Ordenação: Merge Sort**
## Estrutura de Dados em C

---

## **4. Merge Sort**

E agora, vamos ver uma demonstração de como o algoritmo funciona...

---

### **Merge Sort: Como Pensa?**

Um algoritmo de **"Dividir para Conquistar"**. É extremamente eficiente e estável.

- **Dividir:** Quebra o vetor recursivamente ao meio, até que restem apenas sub-vetores de tamanho 1.
- **Conquistar:** Começa a **juntar (merge)** esses sub-vetores dois a dois, de forma ordenada, criando sub-vetores maiores e ordenados.
- O processo continua até que todos os sub-vetores sejam juntados em um único vetor final.

---

### **Merge Sort: Código em C**

```c
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int esq, int meio, int dir) {
    int n1 = meio - esq + 1;
    int n2 = dir - meio;
    int E[n1], D[n2];

    for (int i = 0; i < n1; i++) E[i] = arr[esq + i];
    for (int j = 0; j < n2; j++) D[j] = arr[meio + 1 + j];

    int i = 0, j = 0, k = esq;
    while (i < n1 && j < n2) {
        if (E[i] <= D[j]) arr[k++] = E[i++];
        else arr[k++] = D[j++];
    }
    while (i < n1) arr[k++] = E[i++];
    while (j < n2) arr[k++] = D[j++];
}

void mergeSort(int arr[], int esq, int dir) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;
        mergeSort(arr, esq, meio);
        mergeSort(arr, meio + 1, dir);
        merge(arr, esq, meio, dir);
    }
}
```

---
### **Merge Sort: Complexidade**
- **Tempo:** O(n log n) em todos os casos (pior, médio e melhor).
- **Espaço:** O(n), pois usa espaço extra para os sub-vetores temporários.
- **Estável:** Sim, mantém a ordem relativa dos elementos iguais.
- **Uso:** Muito eficiente para grandes conjuntos de dados, especialmente quando a memória não é uma limitação.
- **Importante:** Merge Sort é um algoritmo de ordenação estável, o que significa que ele preserva a ordem relativa dos elementos iguais. Isso é especialmente útil em aplicações onde a estabilidade é necessária, como em ordenações múltiplas.
- **Nota:** Merge Sort é particularmente útil para ordenar listas ligadas, pois pode ser implementado de forma eficiente sem usar espaço extra significativo, apenas alterando os ponteiros dos nós.
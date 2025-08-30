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

Um algoritmo de **"dividir para conquistar"**. É extremamente eficiente e estável.

- **Dividir:** Quebra o vetor recursivamente ao meio, até que restem apenas sub-vetores de tamanho 1.
- **Conquistar:** Começa a **juntar (merge)** esses sub-vetores dois a dois, de forma ordenada, criando sub-vetores maiores e ordenados.
- O processo continua até que todos os sub-vetores sejam juntados em um único vetor final.

---

### **Merge Sort: Código em C**

```c
#include <stdio.h>

void merge(int arr[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;          // A metade esquerda já ordenada é [2, 10, 15].
    int n2 = fim - meio;                // A metade direita já ordenada é [4, 9, 12].
    int E[n1], D[n2];                   

    for (int i = 0; i < n1; i++){
        E[i] = arr[inicio + i];
    }

    for (int j = 0; j < n2; j++) {
        D[j] = arr[meio + 1 + j];
    }

    int ponteiro_esquerda = 0;
    int ponteiro_direita = 0;
    int k = inicio;

    while (ponteiro_esquerda < n1 && ponteiro_direita < n2) { // E = [2, 10, 15] e D = [4, 9, 12]
        if (E[ponteiro_esquerda] <= D[ponteiro_direita]) {
            arr[k++] = E[ponteiro_esquerda++];
        } else {
            arr[k++] = D[ponteiro_direita++];
        }
    }
    // whiles para pegar os elementos que sobraram no vetor que não acabou
    while (ponteiro_esquerda < n1) {
        arr[k++] = E[ponteiro_esquerda++];
    }
    while (ponteiro_direita < n2) {
        arr[k++] = D[ponteiro_direita++];
    }
}

void mergeSort(int arr[], int inicio, int fim){
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, fim);
        merge(arr, inicio, meio, fim);
    }
}
```

---
### **Merge Sort: Complexidade**
- **Tempo:** O(n log n) em todos os casos (pior, médio e melhor).
- **Estável:** Sim, mantém a ordem relativa dos elementos iguais.
- **Uso:** Muito eficiente para grandes conjuntos de dados, especialmente quando a memória não é uma limitação.
- **Importante:** Merge Sort é um algoritmo de ordenação estável, o que significa que ele preserva a ordem relativa dos elementos iguais. Isso é especialmente útil em aplicações onde a estabilidade é necessária, como em ordenações múltiplas.
- **Nota:** Merge Sort é particularmente útil para ordenar listas ligadas, pois pode ser implementado de forma eficiente sem usar espaço extra significativo, apenas alterando os ponteiros dos nós.
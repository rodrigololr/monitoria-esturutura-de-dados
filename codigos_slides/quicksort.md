---
marp: true
theme: gaia
backgroundColor: #1a1a1a
color: #f0f0f0
---


# **Algoritmos de Ordenação: Quick Sort**
## Estrutura de Dados em C

---

## **5. Quick Sort**

E agora, vamos ver uma demonstração de como o algoritmo funciona...

---

### **Quick Sort: Como Pensa?**

O outro grande algoritmo de **"Dividir para Conquistar"**. Geralmente o mais rápido na prática.

- **Lógica:** Escolhe um elemento do vetor para ser o **pivô**.
- **Particiona:** Reorganiza o vetor de forma que todos os elementos menores que o pivô fiquem à sua esquerda, e os maiores, à sua direita.
- **Recursão:** Chama o `quickSort` recursivamente para a metade da esquerda e para a metade da direita.

---

### **Quick Sort: Código em C**

```c
#include <stdio.h>

void trocar(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int particionar(int arr[], int menor, int maior) {
    int pivo = arr[maior];
    int i = (menor - 1);
    for (int j = menor; j <= maior - 1; j++) {
        if (arr[j] < pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[maior]);
    return (i + 1);
}

void quickSort(int arr[], int menor, int maior) {
    if (menor < maior) {
        int pi = particionar(arr, menor, maior);
        quickSort(arr, menor, pi - 1);
        quickSort(arr, pi + 1, maior);
    }
}
```

---
### **Quick Sort: Complexidade**
- **Tempo:** O(n log n) no melhor e médio caso, O(n²) no pior caso (quando o pivô é sempre o maior ou menor elemento).
- **Espaço:** O(log n) na média, devido à pilha de chamadas recursivas.
- **Estável:** Não, pois a ordem relativa dos elementos iguais pode ser alterada.
- **Uso:** Muito eficiente para grandes conjuntos de dados, especialmente quando a memória é limitada. É o algoritmo de ordenação mais usado em sistemas de ordenação de alto desempenho, como o algoritmo `sort()` da linguagem C++.
- **Importante:** algoritmo adaptativo, o que significa que ele se torna mais eficiente quando o vetor já está parcialmente ordenado. É simples e fácil de implementar, tornando-o uma boa escolha para muitos casos práticos. No entanto, é importante escolher um bom pivô para evitar o pior caso de complexidade O(n²).
- **Nota:** Quick Sort é frequentemente implementado com uma estratégia de escolha de pivô aleatória ou usando o "pivô mediano" para melhorar a eficiência em casos de dados já ordenados ou quase ordenados.
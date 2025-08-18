---
marp: true
theme: gaia
backgroundColor: #1a1a1a
color: #f0f0f0
---

# **Algoritmos de Ordenação: Radix Sort**
## Estrutura de Dados em C

---

## **8. Radix Sort**

E agora, vamos ver uma demonstração de como o algoritmo funciona...

---

### **Radix Sort: Como Pensa?**

Também é **não-comparativo** e ordena números inteiros processando seus dígitos.

- **Lógica:**
  1.  Ordena os números com base no dígito **menos significativo** (unidade).
  2.  Depois, ordena com base no próximo dígito (dezena).
  3.  Continua o processo para cada dígito, até o mais significativo.
- **Importante:** A ordenação de cada passo precisa ser **estável** (geralmente usa-se Counting Sort).

---

### **Radix Sort: Código em C**

```c
#include <stdio.h>

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > max) max = arr[i];
    return max;
}

void countSort(int arr[], int n, int exp) {
    int saida[n];
    int i, contagem[10] = {0};
    for (i = 0; i < n; i++) contagem[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++) contagem[i] += contagem[i - 1];
    for (i = n - 1; i >= 0; i--) {
        saida[contagem[(arr[i] / exp) % 10] - 1] = arr[i];
        contagem[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++) arr[i] = saida[i];
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}
```

---
### **Radix Sort: Complexidade**
- **Tempo:** O(nk), onde n é o número de elementos e k é o número de dígitos do maior número.
- **Espaço:** O(n + k), onde n é o número de elementos e k é o número de dígitos do maior número.
- **Estável:** Sim, mantém a ordem relativa dos elementos iguais.
- **Uso:** Útil para ordenar números inteiros ou strings de tamanho fixo, especialmente quando o intervalo de valores é pequeno em comparação com o número de elementos a serem ordenados.
- **Importante:** um algoritmo eficiente para ordenar números inteiros ou strings de tamanho fixo, especialmente quando o intervalo de valores é pequeno em comparação com o número de elementos.
---
marp: true
theme: gaia
backgroundColor: #1a1a1a
color: #f0f0f0
---

# **Algoritmos de Ordenação: Counting Sort**
## Estrutura de Dados em C

---

## **7. Counting Sort**

E agora, vamos ver uma demonstração de como o algoritmo funciona...

---

### **Counting Sort: Como Pensa?**

Um algoritmo **não-comparativo**, para inteiros dentro de um intervalo conhecido.

- **Lógica:**
  1.  Cria um vetor auxiliar para **contar a frequência** de cada elemento.
  2.  Usa essa contagem para determinar a **posição final** de cada elemento em um vetor de saída.
  3.  Copia os elementos ordenados de volta para o vetor original.

---

### **Counting Sort: Código em C**

```c
void countingSort(char arr[], int n){
    char saida[n];
    int contagem[RANGE + 1];
    //memset: inicializa o vetor de contagem com zeros
    memset(contagem, 0, sizeof(contagem));

    for(int i = 0; i < n; ++i){
        ++contagem[arr[i]];
    }

    for (int i = 1; i <= RANGE; ++i) {
        contagem[i] += contagem[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        saida[contagem[arr[i]] - 1] = arr[i];
        --contagem[arr[i]];
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = saida[i];
    }
}



```

---
### **Counting Sort: Complexidade**
- **Tempo:** O(n + k), onde n é o número de elementos e k é o intervalo dos valores (máximo - mínimo).
- **Estável:** Sim, mantém a ordem relativa dos elementos iguais.
- **Uso:** Útil quando o intervalo de valores é pequeno em comparação com o número de elementos a serem ordenados.
- **Importante:** Counting Sort não é um algoritmo de comparação, então não se aplica a todos os tipos de dados. É mais eficiente para inteiros ou caracteres com um intervalo limitado.
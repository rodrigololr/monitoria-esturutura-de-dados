---
marp: true
theme: gaia
backgroundColor: #1a1a1a
color: #f0f0f0
---

# **Algoritmos de Ordenação: Bubble Sort**
## Estrutura de Dados em C

---

## **1. Bubble Sort**

E agora, vamos ver uma demonstração de como o algoritmo funciona...

---

### **Bubble Sort: Como Pensa?**

É o mais simples de todos. Ele percorre o vetor várias vezes, e a cada passagem, "flutua" o maior elemento para o final.

- **Lógica:** Compara elementos **vizinhos** (`v[i]` e `v[i+1]`).
- Se estiverem na ordem errada, ele os **troca**.
- Repete esse processo até que, em uma passagem completa, nenhuma troca seja necessária.

**Analogia:** Pense em bolhas de ar subindo em um copo d'água, as maiores chegam no topo primeiro.

---

### **Bubble Sort: Código em C**

```c
void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int trocou = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                trocar(&arr[j], &arr[j + 1]);
                trocou = 1;
            }
        }
        if (trocou == 0) {
            break;
        }
    }
}
```

---
### **Bubble Sort: Complexidade**
- **Tempo:** O(n²) no pior caso, O(n) no melhor caso (quando o vetor já está ordenado).
- **Espaço:** O(1), pois é um algoritmo in-place (não usa espaço extra significativo).
- **Estável:** Sim, mantém a ordem relativa dos elementos iguais.
- **Uso:** Raramente usado em aplicações reais devido à sua ineficiência em grandes conjuntos de dados, mas é bom para entender os conceitos básicos de ordenação.
- **Importante:** Bubble Sort é um algoritmo de comparação, então não é adequado para tipos de dados complexos ou grandes volumes de dados.


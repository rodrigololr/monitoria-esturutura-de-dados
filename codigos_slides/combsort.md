---
marp: true
theme: gaia
backgroundColor: #1a1a1a
color: #f0f0f0
---

# **Algoritmos de Ordenação: Comb Sort**
## O "Turbo" do Bubble Sort

---

## **Comb Sort**

E agora, vamos ver uma demonstração de como o algoritmo funciona...

---

### **Comb Sort: Como Pensa?**

O Comb Sort ("Pente Sort") é uma otimização inteligente do Bubble Sort. Ele foi criado para resolver o principal problema do Bubble Sort: os **"turtles"** (elementos pequenos que estão no final do vetor e demoram muitas passagens para chegar ao início).

- **Lógica:** Em vez de comparar apenas elementos vizinhos, o Comb Sort começa comparando elementos com um **`gap` (espaçamento) grande**.
- A cada passagem pelo vetor, esse `gap` diminui por um "fator de encolhimento" (geralmente 1.3).

---
- Ao fazer isso, ele move os "turtles" para perto de suas posições corretas muito mais rápido.
- Quando o `gap` finalmente chega a `1`, o algoritmo se comporta como um Bubble Sort simples para finalizar os ajustes finos.

---

### **Comb Sort: Código em C**

```c

void combSort(int arr[], int length) {
    int sm;
    float shrink = 1.3;
    int gap = length;
    int sorted = 0;

    while (!sorted) {
        gap /= shrink;
        if (gap <= 1) {
            sorted = 1;
            gap = 1;
        }

        for (int i = 0; i < length-gap; i++) {
            sm = gap + i;
            if (arr[i] > arr[sm]) {
                int temp = arr[i];
                arr[i] = arr[sm];
                arr[sm] = temp;
                sorted = 0;
            }
        }
    }
}
```
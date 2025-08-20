---
marp: true
theme: gaia
backgroundColor: #1a1a1a
color: #f0f0f0
---

# **Estruturas de Dados: Fila de Prioridade**
## Quem é mais importante passa na frente

---

## **O que é uma Fila de Prioridade?**

É um tipo abstrato de dado similar a uma fila normal, mas com uma regra diferente para remoção.

- Cada elemento da fila tem uma **prioridade** associada a ele.
- Em vez da regra FIFO, a regra aqui é: o elemento com a **maior prioridade** é sempre o primeiro a ser removido.

**Analogia do Mundo Real:** A sala de emergência de um hospital. Pacientes com casos mais graves (maior prioridade) são atendidos primeiro.

---

## **Como Funciona (Visualmente)**

Agora, vou mostrar uma demonstração visual do *comportamento* de uma fila de prioridade...

*(Slide de transição para sua demonstração)*

**Conceitos Visuais a Demonstrar:**
1.  **Enqueue:** Adicione itens com dados e prioridades diferentes em ordem aleatória. (Ex: {dado: 'C', prio: 3}, {dado: 'A', prio: 1}, {dado: 'B', prio: 2}).
2.  **Dequeue:** Mostre que, ao remover, o item de maior prioridade ('A', com prio 1) sai primeiro. O foco é no **comportamento**.

---

## **As Funções da Fila de Prioridade (Código em C)**

**Nota:** Implementações eficientes usam uma estrutura chamada **Heap**. Para fins didáticos, vamos mostrar uma implementação **simples** com um vetor que se mantém ordenado.

---
**As Estruturas:**
```c
#define MAX_TAMANHO 50

typedef struct {
    int dado;
    int prioridade;
} Item;

typedef struct {
    Item itens[MAX_TAMANHO];
    int qtd;
} FilaPrioridade;
```

---

### **Funções: `enqueue` (Inserção Ordenada)**

A função `enqueue` insere o novo item na posição correta para manter o vetor ordenado por prioridade (menor número = maior prioridade).

---

```c
void enqueuePrio(FilaPrioridade* fp, int dado, int prioridade) {
    if (fp->qtd >= MAX_TAMANHO) return; // Fila cheia
    
    Item novo_item;
    novo_item.dado = dado;
    novo_item.prioridade = prioridade;
    
    int i = fp->qtd - 1;
    while (i >= 0 && fp->itens[i].prioridade > novo_item.prioridade) {
        fp->itens[i + 1] = fp->itens[i];
        i--;
    }
    fp->itens[i + 1] = novo_item;
    fp->qtd++;
}
```
---
### **Função: `dequeue` (Remoção Simples)**

Como a fila está sempre ordenada, a maior prioridade está sempre no início.


```c
Item dequeuePrio(FilaPrioridade* fp) {
    Item erro = {-1, -1};
    if (fp->qtd == 0) return erro; // Fila vazia
    
    Item item_removido = fp->itens[0];
    
    // Desloca todos os outros para a esquerda
    for (int i = 0; i < fp->qtd - 1; i++) {
        fp->itens[i] = fp->itens[i + 1];
    }
    fp->qtd--;
    return item_removido;
}




```
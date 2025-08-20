---
marp: true
theme: gaia
backgroundColor: #1a1a1a
color: #f0f0f0
---

<style>
p {
    font-size: 30px;
}
h1,h2,h3,h4,h5,h6 {
    font-size: 50px;
}
    code {
        font-size: 30px;

    }
    pre {
        font-size: 30px;
    }


</style>

# **Estruturas de Dados: Listas Encadeadas**
## A base das estruturas dinâmicas

---

## **O que é uma Lista Encadeada?**

Diferente de vetores que guardam tudo em um bloco contínuo de memória, a Lista Encadeada é uma estrutura **dinâmica**. Cada elemento, chamado de **Nó** (`Node`), é um objeto separado.

Cada **Nó** contém duas coisas:
1.  O **Dado** que queremos armazenar (um `int`, uma `struct`, etc.).
2.  Um **Ponteiro** para o próximo nó da sequência.

**Analogia do Mundo Real:** Uma **caça ao tesouro**. Cada pista (`Nó`) te dá uma informação (`Dado`) e te diz onde encontrar a próxima pista (`Ponteiro`). O último nó aponta para `NULL`.

---

## **Como Funciona (Visualmente)**

Agora, vou mostrar uma demonstração visual de como a lista encadeada funciona...

**Conceitos Visuais a Demonstrar:**
1.  Comece com uma lista vazia (`cabeça = NULL`).
2.  **Inserção no Início:** Desenhe um novo nó. Faça o `proximo` dele apontar para a antiga `cabeça`. Atualize a `cabeça` para ser o novo nó. Repita algumas vezes.
---
3.  **Percorrer a Lista:** Mostre como você "pula" de nó em nó seguindo os ponteiros `proximo`.
4.  **Remoção:** Mostre como "bypassar" um nó. Faça o `proximo` do nó anterior apontar para o `proximo` do nó a ser removido e use `free()` na memória!

---

## **As Funções da Lista (Código em C)**

A base da lista é a `struct No`. A lista em si é apenas um ponteiro para o primeiro nó (`cabeça` ou `head`).

**A Estrutura do Nó:**
```c
typedef struct No {
    int dado;
    struct No* proximo;
} No;

// Para criar uma lista, basta criar um ponteiro para No
// No* minha_lista = NULL; // Declara uma lista vazia
```
---

### **Função: Inserir no Início**

Esta é a operação de inserção mais comum e eficiente, em tempo O(1).

```c
// A função recebe um ponteiro para a cabeça da lista (No**)
// para que possamos modificar a cabeça original.
void insereNoInicio(No** cabeca_ref, int novo_dado) {
    // 1. Aloca memória para o novo nó
    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) return; // Falha na alocação

    // 2. Coloca os dados no novo nó
    novo_no->dado = novo_dado;

    // 3. Faz o 'proximo' do novo nó ser a cabeça atual
    novo_no->proximo = (*cabeca_ref);

    // 4. Move a cabeça para apontar para o novo nó
    (*cabeca_ref) = novo_no;




}
```
---

### **Função: Percorrer e Imprimir**

Para acessar os elementos, percorremos a lista do início ao fim, até encontrar `NULL`.

```c
void imprimeLista(No* no) {
    while (no != NULL) {
        printf("%d -> ", no->dado);
        no = no->proximo;
    }
    printf("NULL\n");
}
```
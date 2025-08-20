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

# **Estruturas de Dados: Lista Circular**
## Uma lista sem fim

---

## **O que é uma Lista Circular?**
É uma variação da lista encadeada (simples ou dupla) onde não existe um "fim" com `NULL`.
- O ponteiro `proximo` do **último nó** aponta de volta para o **primeiro nó** (`cabeça`), formando um ciclo fechado.

**Analogia do Mundo Real:** Uma **roda-gigante** ou os assentos de um carrossel. Depois do último, você volta para o primeiro.

---

**Onde é Usada?**
- Escalonamento de processos em sistemas operacionais (Round-Robin).
- Controle de turnos em jogos.
- Playlists que tocam em loop.

---

## **Como Funciona (Visualmente)**

Agora, vou mostrar uma demonstração visual de como a lista circular funciona...

**Conceitos Visuais a Demonstrar:**
1.  **Inserção do Primeiro Nó:** Mostre que um nó sozinho aponta para si mesmo.
2.  **Inserção de Outros Nós:** Adicione mais nós e mostre como o ponteiro do último sempre aponta para o primeiro.
3.  **Percorrer a Lista:** Demonstre como o percurso pode continuar indefinidamente. Explique que o critério de parada não é `!= NULL`, mas sim "chegar de volta na cabeça".

---

## **As Funções da Lista Circular (Código em C)**

A `struct No` é a mesma da lista simples. A mudança está na lógica das funções.

**A Estrutura do Nó:**
```c
typedef struct No {
    int dado;
    struct No* proximo; // Aponta para o próximo nó
} No;
```

---

### **Função: Inserir no Início (Lógica diferente!)**

Para inserir no início, precisamos encontrar o último nó para que ele aponte para o novo início.

```c
void insereNoInicio(No** cabeca_ref, int dado) {
    No* novo_no = (No*) malloc(sizeof(No));
    novo_no->dado = dado;
    
    if (*cabeca_ref == NULL) { // Se a lista está vazia
        *cabeca_ref = novo_no;
        novo_no->proximo = *cabeca_ref; // Aponta para si mesmo
    } else {
        // Encontra o último nó
        No* ultimo = *cabeca_ref;
        while (ultimo->proximo != *cabeca_ref) {
            ultimo = ultimo->proximo;
        }
        // O último nó agora aponta para o novo
        ultimo->proximo = novo_no;
        // O novo aponta para a antiga cabeça
        novo_no->proximo = *cabeca_ref;
        // A cabeça agora é o novo nó
        *cabeca_ref = novo_no;
    }
}





```
---
### **Função: Percorrer e Imprimir**

O loop `while` tradicional não funciona. Usamos um `do-while`.

```c
void imprimeLista(No* cabeca) {
    if (cabeca == NULL) return;

    No* temp = cabeca;
    do {
        printf("%d -> ", temp->dado);
        temp = temp->proximo;
    } while (temp != cabeca); // Para quando voltar ao início
    printf("(volta para %d)\n", cabeca->dado);
}
```
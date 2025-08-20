---
marp: true
theme: gaia
backgroundColor: #1a1a1a
color: #f0f0f0
---

# **Lista Duplamente Encadeada**
## O Guia Completo em C

---

## **Revisão: O que é uma Lista Dupla?**

É uma lista onde cada nó possui **dois ponteiros**:
- `proximo`: Aponta para o nó seguinte.
- `anterior`: Aponta para o nó anterior.

**Implicações:**
1.  Podemos percorrer a lista nos **dois sentidos**.
2.  Toda operação de inserção ou remoção exige mais cuidado para **atualizar os dois ponteiros**.
---
```c
/* Estrutura nó para a lista duplamente encadeada */
typedef struct no {
    int valor;
    struct no *proximo;
    struct no *anterior;
} No;
```

---

## **Operação 1: Inserir no Início**

Esta é a inserção mais simples. O novo nó se tornará a nova "cabeça" da lista.

**Lógica:**
1.  O `proximo` do novo nó aponta para a cabeça antiga.
2.  O `anterior` do novo nó é `NULL`, pois ele é o primeiro.
3.  O `anterior` da cabeça antiga (se ela existir) passa a apontar para o novo nó.
4.  A cabeça da lista (`*lista`) é atualizada para ser o novo nó.

---
### **Código: `inserir_no_inicio`**

```c
/* Procedimento para inserir um novo nó no início da lista */
void inserir_no_inicio(No **lista, int num) {
    No *novo = malloc(sizeof(No));
    if(novo) {
        novo->valor = num;
        novo->proximo = *lista; // Próximo do novo aponta para o início antigo
        novo->anterior = NULL;
        
        // Se a lista não estiver vazia, o anterior do início antigo aponta para o novo
        if(*lista)
            (*lista)->anterior = novo;
        
        // O novo nó passa a ser o início da lista
        *lista = novo;
    }
    else
        printf("Erro ao alocar memoria!\n");
}
```
---

## **Operação 2: Inserir no Fim**

Para inserir no fim, precisamos primeiro encontrar qual é o último nó.

**Lógica:**
1.  Se a lista estiver vazia, a inserção no fim é igual à inserção no início.
2.  Se não, usamos um ponteiro `aux` para percorrer a lista até que `aux->proximo` seja `NULL`.
3.  Quando `aux` for o último nó, fazemos seu `proximo` apontar para o novo nó.
4.  O `anterior` do novo nó aponta para `aux`.

---
### **Código: `inserir_no_fim`**

```c
void inserir_no_fim(No **lista, int num) {
    No *aux, *novo = malloc(sizeof(No));
    if(novo) {
        novo->valor = num;
        novo->proximo = NULL;

        // Se a lista está vazia, o novo é o primeiro
        if(*lista == NULL) {
            *lista = novo;
            novo->anterior = NULL;
        }
        else {
            aux = *lista;
            while(aux->proximo) // Encontra o último nó
                aux = aux->proximo;
            aux->proximo = novo;
            novo->anterior = aux;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}
```

---

## **A Grande Vantagem: Imprimir ao Contrário**

Com o ponteiro `anterior`, podemos facilmente percorrer a lista do fim para o começo.

**Lógica:**
1.  Primeiro, precisamos de uma função auxiliar (`ultimo`) para encontrar o último nó da lista.
2.  A função `imprimirContrario` recebe este último nó.
3.  Ela simplesmente imprime o valor e "anda para trás" usando o ponteiro `anterior`, até que ele seja `NULL`.

---
### **Código: `ultimo` e `imprimirContrario`**

```c
// Retorna ponteiro para o último nó da lista
No* ultimo(No **lista) {
    No *aux = *lista;
    while(aux->proximo)
        aux = aux->proximo;
    return aux;
}

// Imprime a lista do fim para o início
void imprimirContrario(No *no) {
    printf("\n\tLista (Inversa): ");
    while(no) {
        printf("%d ", no->valor);
        no = no->anterior;
    }
    printf("\n\n");
}
```

---

## **O Desafio: Remover um Nó**

Remover um nó exige religar os ponteiros do nó anterior e do posterior, "pulando" o nó que foi removido.

**Lógica:**
1.  **Caso 1: Remover a cabeça.** A cabeça da lista avança para o próximo, e o `anterior` do novo primeiro nó vira `NULL`.
2.  **Caso 2: Remover do meio/fim.** Encontramos o nó a ser removido (`remover`). O `proximo` do `remover->anterior` deve apontar para o `remover->proximo`. E o `anterior` do `remover->proximo` deve apontar para o `remover->anterior`.

---
### **Código: `remover`**

```c
No* remover(No **lista, int num) {
    No *aux, *remover = NULL;

    if(*lista) {
        if((*lista)->valor == num) { // Remove o primeiro nó
            remover = *lista;
            *lista = remover->proximo;
            if(*lista)
                (*lista)->anterior = NULL;
        }
        else {
            aux = *lista;
            while(aux->proximo && aux->proximo->valor != num)
                aux = aux->proximo;
            if(aux->proximo) { // Encontrou o nó para remover
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                if(aux->proximo)
                    aux->proximo->anterior = aux;
            }
        }
    }
    return remover; // Retorna o nó removido para liberar a memória (free)
}
```

---

## **Visão Geral do Programa (main)**

Agora que entendemos as funções, vemos como a `main` as utiliza para criar um menu interativo e manipular a lista.

```c
int main() {
    int opcao, valor, anterior;
    No *removido, *lista = NULL;

    do {
        // ... (código do printf com as opções do menu) ...
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: // Inserir no Início
                // ...
                break;
            case 2: // Inserir no Fim
                // ...
                break;
            // ... (``` casos) ...
            case 8: // Imprimir ao Contrário
                imprimirContrario(ultimo(&lista));
                break;
        }
    } while(opcao != 0);

    return 0;
}







```

---

## **Dica de Mestre: Desenhe no Papel!**

A melhor forma de entender de verdade a manipulação de ponteiros em listas duplas é **desenhando**.

1.  Desenhe uma lista com 3 caixinhas (nós).
2.  Desenhe as setas `proximo` e `anterior`.
3.  Escolha uma operação (ex: "inserir no meio").
4.  Siga o código linha por linha, **riscando as setas antigas e desenhando as novas** no seu papel.

Você vai ver a lógica acontecer na sua frente!
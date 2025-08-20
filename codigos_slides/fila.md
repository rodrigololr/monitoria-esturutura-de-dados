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

# **Estruturas de Dados: Filas (Queue)**
## Estática vs. Dinâmica

---

## **O que é uma Fila?**

A Fila é uma estrutura que segue a regra **FIFO** (*First-In, First-Out*): o **primeiro** a entrar é o **primeiro** a sair.

**Analogia:** Uma fila de supermercado. Quem chega primeiro, é atendido primeiro.

**Onde é Usada?**
- Filas de impressão de documentos.
- Playlists de músicas.
- Gerenciamento de tarefas em sistemas operacionais.

---

## **Como Funciona (Visualmente)**

Agora, vou mostrar uma demonstração visual do comportamento FIFO da fila...


**Conceitos a Demonstrar:**
1.  **Enqueue (Enfileirar):** Adicionar itens no **fim** da fila.
2.  **Dequeue (Desenfileirar):** Remover itens do **início** da fila.
3.  **Front (Espiar):** Olhar o início sem remover.

---

## **Explicação 1: Estática (com Vetor Circular)**

É a implementação mais comum com vetores.

- **Como funciona?** Usamos um vetor de tamanho **fixo** e dois índices, `inicio` e `fim`, que "dão a volta" no vetor (usando o operador `%`) para reaproveitar o espaço.
- **Vantagens:** Rápida e eficiente no uso de memória estática.
- **Desvantagem:** Tamanho **limitado**.
---
**implementação 1: Estática (com Vetor Circular)**
```c
#define MAX_TAMANHO 50

typedef struct {
    int itens[MAX_TAMANHO];
    int inicio;
    int fim;
    int qtd;
} FilaEstatica;
```

---

## **Explicação 2: Dinâmica (com Lista Encadeada)**

A versão mais flexível, sem limite de tamanho.

- **Como funciona?** Usamos uma lista encadeada, mas com uma otimização: guardamos um ponteiro para o **início** e também para o **fim** da lista.
- **Por quê?** Ter um ponteiro para o `fim` permite adicionar novos elementos (enqueue) de forma super rápida, em tempo **O(1)**, sem precisar percorrer a lista inteira.
--- 
## **Implementação 2: Dinâmica (com Lista Encadeada)**
```c
typedef struct No {
    int dado;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
    No* fim;
} FilaDinamica;
```

---

### **Funções da Fila Dinâmica: `enqueue` (Enfileirar)**

A operação `enqueue` cria um novo nó e o adiciona no final da lista.

```c
void enqueue(FilaDinamica* f, int valor){
    // 1. Aloca e preenche o novo nó
    No* novo_no = (No*) malloc(sizeof(No));
    novo_no->dado = valor;
    novo_no->proximo = NULL;

    // 2. Se a fila não está vazia, o fim antigo aponta para o novo
    if (f->fim != NULL) {
        f->fim->proximo = novo_no;
    }
    // 3. O novo nó agora é o novo fim
    f->fim = novo_no;
    // 4. Se a fila estava vazia, o início também é o novo nó
    if (f->inicio == NULL) {
        f->inicio = novo_no;
    }
}
{}
{}
```
---

### **Funções da Fila Dinâmica: `dequeue` (Desenfileirar)**

A operação `dequeue` remove o nó do início, libera sua memória e retorna o valor.

```c
int dequeue(FilaDinamica* f) {
    if (f->inicio == NULL) { // Verifica se a fila está vazia
        printf("Erro: Fila vazia!\n");
        return -1;
    }
    
    No* temp = f->inicio; // Guarda o nó do início
    int valor_removido = temp->dado;
    
    // O início da fila agora é o próximo elemento
    f->inicio = f->inicio->proximo;
    
    // Se a fila ficou vazia, o fim também deve ser NULL
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    
    free(temp); // Libera a memória do início antigo
    
    return valor_removido;
}





```
---
### **Função: `Front` (Espiar)**
Para olhar o valor do início sem remover, usamos a função `front`.

```c
int front(FilaDinamica* f) {
    if (f->inicio == NULL) {
        printf("Erro: Fila vazia!\n");
        return -1;
    }
    return f->inicio->dado; // Retorna o valor do início
}
```
---
## **Estática vs. Dinâmica: Qual Usar?**

| Característica | Fila Estática (Vetor) | Fila Dinâmica (Lista) |
| :--- | :--- | :--- |
| **Alocação** | Memória Contígua | Memória Encadeada |
| **Tamanho** | Fixo e limitado | Flexível, cresce e diminui |
| **Performance**| Geralmente mais rápida | Pequeno overhead de `malloc/free`|
| **Complexidade** | Lógica do vetor circular | Requer domínio de ponteiros |
---
**Conclusão:** A escolha segue a mesma lógica da Pilha. A versão dinâmica é a mais utilizada em cenários reais pela sua flexibilidade.
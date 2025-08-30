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

# **Estruturas de Dados: Pilhas (Stack)**
## Estática vs. Dinâmica

---

## **O que é uma Pilha?**

A Pilha é uma estrutura de dados que segue a regra **LIFO** (*Last-In, First-Out*): o **último** a entrar é o **primeiro** a sair.

**Analogia:** Uma pilha de pratos. Você só pode colocar ou tirar pratos do **topo**.

**Onde é Usada?**
- Botão "Voltar" do navegador.
- Mecanismo de "Desfazer" (CTRL+Z).
- Controle de chamadas de funções em um programa.

---

## **Como Funciona (Visualmente)**

Agora, vou mostrar uma demonstração visual do comportamento LIFO da pilha...


**Conceitos a Demonstrar:**
1.  **Push (Empilhar):** Adicionar itens no topo.
2.  **Pop (Desempilhar):** Remover itens do topo.
3.  **Peek (Espiar):** Olhar o topo sem remover.

---

## **Implementação 1: Estática (com Vetor)**

Essa é a forma mais simples de criar uma pilha.

- **Como funciona?** Usamos um vetor de tamanho **fixo** e uma variável `topo` que guarda o índice do último elemento inserido.
- **Vantagens:** Rápida e muito fácil de implementar.
- **Desvantagem:** Tamanho **limitado**. Se o vetor encher, ocorre um *stack overflow*.

```c
typedef struct {
    int itens[50]; // Tamanho fixo
    int topo; // Começa em -1 (vazia)
} PilhaEstatica;
```

---

## **Explicação 2: Dinâmica (com Lista Encadeada)**

Essa é a forma mais flexível e robusta.

- **Como funciona?** A pilha não tem limite de tamanho! Cada elemento é um "Nó" (`struct No`) alocado dinamicamente na memória com `malloc`.
- A pilha em si é apenas um **ponteiro que aponta para o nó do topo**.
- A lógica é exatamente a mesma de **inserir e remover no início de uma lista encadeada**.
---
## **Implementação: Dinâmica (com Lista Encadeada)**
```c
typedef struct No {
    int dado;
    struct No* proximo;
} No;

typedef struct {
    No* topo;
} PilhaDinamica;
```

---

### **Funções da Pilha Dinâmica: `push` (Empilhar)**

A operação `push` cria um novo nó e o torna o novo topo da pilha.

```c
void push(PilhaDinamica* p, int valor) {
    // 1. Aloca memória para o novo nó
    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro de alocação (Stack Overflow)!\n");
        return;
    }
    // 2. Preenche o novo nó
    novo_no->dado = valor;
    
    // 3. O 'proximo' do novo nó aponta para o topo antigo
    novo_no->proximo = p->topo;
    
    // 4. A pilha agora aponta para o novo nó como seu topo
    p->topo = novo_no;
}
```

---

### **Funções da Pilha Dinâmica: `pop` (Desempilhar)**

A operação `pop` remove o nó do topo, libera sua memória e retorna o valor.

```c
int pop(PilhaDinamica* p) {
    if (p->topo == NULL) { // Verifica se a pilha está vazia
        printf("Erro: Pilha vazia (Stack Underflow)!\n");
        return -1;
    }
    
    No* temp = p->topo; // Guarda o nó do topo para não perdê-lo
    int valor_removido = temp->dado;
    
    // O topo da pilha agora é o próximo elemento
    p->topo = p->topo->proximo;
    
    free(temp); // Libera a memória do topo antigo
    
    return valor_removido;
}
```
---
## **Estática vs. Dinâmica: Qual Usar?**

| Característica | Pilha Estática (Vetor) | Pilha Dinâmica (Lista) |
| :--- | :--- | :--- |
| **Alocação** | Memória Contígua | Memória Encadeada |
| **Tamanho** | Fixo e limitado | Flexível, cresce e diminui |
| **Performance**| Geralmente mais rápida | Pequeno overhead de `malloc/free`|
| **Complexidade** | Mais simples de codificar | Requer domínio de ponteiros |
---
**Conclusão:** Use a estática para problemas simples com limite conhecido. Use a dinâmica para a maioria dos casos reais, onde a flexibilidade é crucial.
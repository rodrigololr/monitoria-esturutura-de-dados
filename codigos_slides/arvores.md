---
marp: true
theme: gaia
backgroundColor: #1a1a1a
color: #f0f0f0

---

# **Introdução às Árvores Binárias de Busca (ABB)**
## Organizando Dados de um Jeito Não-Linear

---

## **O que são Árvores?**

As Árvores são Estruturas de Dados **não-lineares** que organizam dados de forma hierárquica.

- Pense numa árvore genealógica ou numa estrutura de pastas de um computador.
- Elas são formadas por **nós** (os elementos) e **arestas** (as ligações entre eles).
- O primeiro nó é chamado de **raiz**.
- Cada nó pode ter **filhos** e um único **pai**.
- Nós sem filhos são chamados de **folhas**.

---

## **Estrutura de um Nó (em C)**
Assim como nas listas encadeadas, cada nó da árvore é uma `struct`. A diferença é que, em vez de um `proximo` e `anterior`, temos ponteiros para os filhos.

- `valor`: O dado armazenado no nó.
- `esquerda`: Ponteiro para o filho à esquerda.
- `direita`: Ponteiro para o filho à direita.

```c
typedef struct NoArvore {
    int valor;
    struct NoArvore *esquerda; // Filho à esquerda
    struct NoArvore *direita;  // Filho à direita
} NoArvore;









rodrigo lima



```

---

## **Árvores Binárias de Busca (ABB)**

Uma **Árvore Binária de Busca (ABB)** é um tipo especial de árvore binária (onde cada nó tem no máximo dois filhos):

- Para **QUALQUER nó**:
    - Todos os valores na sua **subárvore esquerda** são **menores** que o valor do nó.
    - Todos os valores na sua **subárvore direita** são **maiores** que o valor do nó.

Essa regra torna a busca, inserção e remoção de elementos muito eficientes!

---

## **Operação 1: Busca em uma ABB**

A busca em uma ABB é muito eficiente. Em vez de percorrer todos os nós, eliminamos metade da árvore a cada comparação.
Lógica:
1.  Começa na raiz.
2.  Se o valor procurado for igual ao nó atual, encontrou.
3.  Se for menor, vai para o filho da esquerda.
4.  Se for maior, vai para o filho da direita.
5.  Se chegar a um nó `NULL` (final de um galho) e não encontrar, o valor não está na árvore.

---
### **Código: `buscar` (em C)**

```c
NoArvore* buscar(NoArvore* raiz, int valor) {
    // Caso 1: A árvore está vazia ou o valor não foi encontrado
    if (raiz == NULL || raiz->valor == valor) {
        return raiz; // Retorna NULL se não achou, ou o nó se achou
    }

    // Caso 2: O valor procurado é menor, vai para a subárvore esquerda
    if (valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);
    }
    // Caso 3: O valor procurado é maior, vai para a subárvore direita
    else {
        return buscar(raiz->direita, valor);
    }
}
```

---

## **Operação 2: Inserção em uma ABB**

Para inserir, sempre seguimos a regra da ABB até encontrar o local vazio adequado.

**Lógica:**
1.  Começa na raiz.
2.  Se o valor a inserir for menor que o nó atual, tenta inserir na esquerda.
3.  Se for maior, tenta inserir na direita.
4.  Se chegar a um nó `NULL`, cria um novo nó ali.
5.  (Não permite valores duplicados nesta implementação)

---
### **Código: `inserir` (em C)**

```c
NoArvore* inserir(NoArvore* raiz, int valor) {
    // Caso 1: A árvore está vazia, cria o primeiro nó
    if (raiz == NULL) {
        NoArvore* novo_no = (NoArvore*) malloc(sizeof(NoArvore));
        novo_no->valor = valor;
        novo_no->esquerda = NULL;
        novo_no->direita = NULL;
        return novo_no;
    }

    // Caso 2: O valor já existe, não insere (ou trata como erro/ignora)
    if (valor == raiz->valor) {
        printf("Valor %d ja existe na arvore.\n", valor);
        return raiz;
    }

    // Caso 3: O valor é menor, tenta inserir na esquerda
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }
    // Caso 4: O valor é maior, tenta inserir na direita
    else {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}
```

---

## **Operação 3: Remoção em uma ABB**

A remoção é a operação mais complexa em uma ABB, pois precisa manter a estrutura e a regra da ABB.

Existem **dois cenários principais** para remover um nó `X`:

1.  **Nó X é uma FOLHA:** É o caso mais simples. Basta remover o nó `X` e ajustar o ponteiro do seu pai para `NULL`.
2.  **Nó X tem UM FILHO:** Basta remover o nó `X` e ligar o seu pai diretamente ao seu único filho.

---
### **Remoção: Detalhe do Caso (Nó Folha ou Com Um Filho)**

Para a nossa primeira abordagem de código, vamos focar nos cenários mais simples de remoção: quando o nó a ser removido é uma folha ou tem apenas um filho.
Lógica Simplificada:
- Encontre o nó a ser removido.
- Se não tiver filhos: Libera o nó e o ponteiro do pai para ele vira `NULL`.
- Se tiver um filho: Libera o nó e o ponteiro do pai aponta para o filho único.


---
### **Código: `remover` (em C)**

```c
NoArvore* remover(NoArvore* raiz, int valor) {
    // Caso base: Árvore vazia ou valor não encontrado
    if (raiz == NULL) {
        return NULL;
    }

   
    if (valor < raiz->valor) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = remover(raiz->direita, valor);
    } else { 
        if (raiz->esquerda == NULL) {
            NoArvore* temp = raiz->direita;
            free(raiz); 
            return temp;
        }
    
        else if (raiz->direita == NULL) {
            NoArvore* temp = raiz->esquerda;
            free(raiz); 
            return temp;
        }

        printf("Nao e possivel remover %d nesta versao simplificada (tem 2 filhos).\n", valor);
        return raiz; // Retorna o nó sem remover para simplificar a didática agora.
    }

    return raiz; // Retorna a raiz da subárvore modificada
}
```

---

## **Percorrendo a Árvore (In-Order)**

Para verificar se a ABB está correta, podemos percorrer seus nós. A travessia **In-Order** imprime os nós em ordem crescente.

**Lógica (In-Order):**
1.  Percorre a subárvore esquerda.
2.  Visita/Imprime o nó atual.
3.  Percorre a subárvore direita.

---
### **Código: `imprimirEmOrdem` (em C)**

```c
void imprimirEmOrdem(NoArvore* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimirEmOrdem(raiz->direita);
    }
}
```

---

## **Exemplo de Uso (Função `main`)**

```c
int main() {
    NoArvore* raiz = NULL; // A árvore começa vazia

    // Inserindo alguns valores
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);
```
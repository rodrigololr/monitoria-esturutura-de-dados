---
marp: true
theme: gaia
backgroundColor: #1a1a1a
color: #f0f0f0
---

# **Ponteiros em C: O Superpoder da Memória**
## Manipulando dados pela raiz

---

## **O Problema da Cópia Lenta (A Ancoragem)**

Lembram da nossa `struct` Personagem?
```c
typedef struct {
    float vida;
    float escudo;
    char nome[20];
    // imagine mais 50 campos aqui...
} Personagem;
```
Quando fazemos `imprimeStatus(jett)`, o C **copia** a struct inteira para a função. Se ela for gigante, seu programa fica lento!

**Não seria mais fácil enviar só o ENDEREÇO da `jett` em vez da casa inteira?**

---

## **A Revelação: Ponteiros!**

Um **ponteiro** é uma variável especial.

- Ela não guarda um valor comum (como 100 ou 9.5).
- Ela guarda um **ENDEREÇO DE MEMÓRIA**.

É a diferença entre ter uma foto da casa (`struct`) e ter o endereço do GPS para chegar até ela (`ponteiro`).

---

## **Operador `&`: Pegando o Endereço**

O operador `&` (E-Comercial) serve para uma única coisa: nos dar o **endereço de memória** de uma variável.

```c
Personagem jett;

// A variável 'ptr_jett' vai guardar o ENDEREÇO da 'jett'.
Personagem* ptr_jett = &jett; 
```

É como pedir o CEP de uma casa.

---

## **Operador `*`: Acessando o Valor**

O operador `*` (Asterisco) faz o caminho inverso. Ele "visita" o endereço guardado no ponteiro e nos diz qual **valor** está lá. Chamamos isso de **derreferenciar**.

```c
int numero = 100;
int* ptr = &numero;

// ptr  -> contém o endereço de 'numero'
// *ptr -> contém o valor 100
printf("O valor é: %d", *ptr); // Imprime 100
```

---

## **Anatomia de um Ponteiro**

Declaramos um ponteiro com um `*` e o inicializamos com o endereço (`&`) de uma variável do mesmo tipo.

```c
// Variável normal
int numero = 10;

// Ponteiro para um inteiro
int* ptr_numero;

// ptr_numero agora guarda o ENDEREÇO de 'numero'
ptr_numero = &numero; 
```
---
**Visualmente:**

| Variável | Endereço | Conteúdo |
| :--- | :--- | :--- |
| `numero` | `0x1234` | `10` |
| `ptr_numero` | `0x5678` | `0x1234` |

---

## **A Seta Mágica: `->`**

Quando usamos um ponteiro para uma `struct`, acessar um campo seria feio: `(*ptr_jett).vida`.

Para nossa sorte, o C nos dá um atalho muito mais limpo: o **operador seta (`->`)**.

```c
Personagem jett = {100.0, 50.0, "Jett"};
Personagem* ptr_jett = &jett;

// As duas linhas abaixo fazem A MESMA COISA:
printf("Vida: %.1f\n", (*ptr_jett).vida); // O jeito difícil
printf("Vida: %.1f\n", ptr_jett->vida);  // O jeito fácil e correto!
```

---

## **Mão na Massa (Parte 1: A Função)**

Primeiro, vamos criar a função que recebe o **ponteiro**. Note que o parâmetro é `Personagem* p`, não `Personagem p`.

```c
// A função agora recebe um ENDEREÇO (ponteiro)
void receberDano(Personagem* p, float dano) {
    // Usamos a seta '->' pois 'p' é um ponteiro
    printf("'%s' vai receber %.1f de dano!\n", p->nome, dano);
    p->vida -= dano; // Modifica o valor original na memória!
}
```

---

## **Mão na Massa (Parte 2: A Chamada)**

Agora, na `main`, vamos chamar a função. O ponto principal é que não passamos a variável `jett`, mas sim o **endereço dela**, usando `&jett`.

```c
int main() {
    Personagem jett = {100.0, "Jett"};
    printf("Vida inicial da Jett: %.1f\n", jett.vida);

    // Passamos o ENDEREÇO da jett para a função
    receberDano(&jett, 30.0);

    printf("Vida final da Jett: %.1f\n", jett.vida);
    return 0;
}
```

---

## **Mão na Massa (Parte 3: O Resultado)**

Ao rodar o código, a saída confirma que a variável `jett` original foi alterada pela função, pois passamos seu endereço.

**Saída do Terminal:**

Vida inicial da Jett: 100.0
'Jett' vai receber 30.0 de dano!
Vida final da Jett: 70.0

Isso prova o poder dos ponteiros: modificar dados em qualquer lugar do programa de forma eficiente.

---

## **Resumo da Ópera**

- Ponteiros guardam **endereços de memória**.
- **`&`** pega o endereço de uma variável.
- **`*`** acessa o valor no endereço para o qual um ponteiro aponta.
- Passar `structs` para funções usando ponteiros é **muito mais eficiente**.
- Use **`->`** para acessar membros de uma `struct` através de um ponteiro.

---

## **Próximos Passos!**

Você aprendeu a apontar para "caixas" de dados. Mas e se a gente apontar para uma única letra? E se a gente "andar" com esse ponteiro?
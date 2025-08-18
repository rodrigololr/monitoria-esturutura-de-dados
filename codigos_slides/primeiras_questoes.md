---
marp: true
theme: gaia
backgroundColor: #1a1a1a
color: #f0f0f0
size: 16:9
style: |
  p, li {
    font-size: 24px;
  }
---

# **Exercícios de Fixação**
## Structs, Ponteiros e Strings

---

## **Questão 1: Cadastro Simplificado de Livros**

Crie um programa em C que permita cadastrar informações sobre livros. Para cada livro, devem ser armazenadas as seguintes informações:

- Título (string de até 50 caracteres).
- Autor (string de até 50 caracteres).
- Ano de publicação (inteiro).
- Preço (float).

**Requisitos:**
1. Utilize uma `struct` para representar cada livro.
2. O programa deve permitir cadastrar 5 livros (utilize um array de structs).
3. Ao final, o programa deve listar todos os livros cadastrados, mostrando todas as suas informações.

---

## **Questão 2: Busca por Autor**

Modifique o programa da questão anterior. Adicione uma funcionalidade que permita ao usuário buscar por livros de um determinado autor.

**Requisitos:**
1. O programa deve pedir ao usuário para digitar o nome de um autor.
2. Crie uma função que receba o array de livros e o nome do autor como parâmetros.
3. Dentro da função, use `strcmp` para encontrar os livros do autor correspondente.
4. Imprima as informações de todos os livros encontrados.

---

## **Questão 3: Agenda de Tarefas com Status**

Crie um programa para gerenciar uma agenda de até 10 tarefas. Para cada tarefa, armazene:

- Descrição (string de até 100 caracteres).
- Prioridade (inteiro de 1 a 5, sendo 1 a mais alta).
- Concluída (um `int` que servirá como flag: `1` para concluída, `0` para pendente).

**Requisitos:**
1. Utilize uma `struct` para a tarefa.
2. Permita adicionar novas tarefas.
3. Permita listar todas as tarefas, mostrando o status ("Concluída" ou "Pendente") com base no valor da flag.

---

## **Questão 4: Ordenação por Prioridade**

Modifique a agenda de tarefas da questão anterior. Crie uma função que ordene as tarefas por prioridade, da mais alta (1) para a mais baixa (5), antes de exibi-las.

**Requisitos:**
1. Implemente uma função que receba o array de tarefas.
2. Use um algoritmo de ordenação simples (ex: Bubble Sort).
3. A comparação para a ordenação deve ser feita usando o campo `prioridade` da `struct`.

---

## **Questão 5: Inserção com Deslocamento**

Crie um programa com um array de livros **já ordenado** pelo título. O seu objetivo é inserir um novo livro nesse array, mantendo a ordem alfabética.

**Requisitos:**
1. Crie um array de `struct Livro` já preenchido e ordenado.
2. Encontre a posição correta onde o novo livro deve ser inserido.
3. Desloque os elementos necessários para a direita para abrir espaço.
4. Insira o novo livro na posição correta e exiba o array final.

---

## **Como a `strcmp` "Pensa"?**

A função `strcmp` não diz apenas se duas strings são iguais. Ela nos informa sobre a *ordem alfabética* entre elas.

Pense nela como a subtração `a - b` para letras:

- `strcmp(str1, str2)` retorna **< 0** (negativo)
  - Se `str1` vem **ANTES** de `str2` no alfabeto. (Ex: "Alex" vs "Bia")

- `strcmp(str1, str2)` retorna **> 0** (positivo)
  - Se `str1` vem **DEPOIS** de `str2` no alfabeto. (Ex: "Carlos" vs "Bia")

- `strcmp(str1, str2)` retorna **0**
  - Se `str1` é **IGUAL** a `str2`. (Ex: "Larissa" vs "Larissa")
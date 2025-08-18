---
marp: true
theme: gaia
backgroundColor: #1a1a1a
color: #f0f0f0
---


## **Como a `strcmp` "Pensa"?**

A função `strcmp` não diz apenas se duas strings são iguais. Ela nos informa sobre a *ordem alfabética* entre elas.
Pense nela como a subtração `a - b` para letras:

- `strcmp(str1, str2)` retorna **< 0** (negativo)
  - Se `str1` vem **ANTES** de `str2` no alfabeto. (Ex: "Alex" vs "Bia")

- `strcmp(str1, str2)` retorna **> 0** (positivo)
  - Se `str1` vem **DEPOIS** de `str2` no alfabeto. (Ex: "Carlos" vs "Bia")

- `strcmp(str1, str2)` retorna **0**
  - Se `str1` é **IGUAL** a `str2`. (Ex: "Ana" vs "Ana")



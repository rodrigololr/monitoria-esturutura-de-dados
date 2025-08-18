#include <stdio.h>
#include <string.h>

#define CAPACIDADE_MAX 10

typedef struct{
    char titulo[51];
    char autor[51];
} Livro;

void insere_ordenado(Livro biblioteca[], int *numero_atual_livros_ptr, Livro novo_livro){

    if(*numero_atual_livros_ptr >= CAPACIDADE_MAX){
        printf("erro cheio");
    }

    int posicacao_insercao = 0;
    while(posicacao_insercao < *numero_atual_livros_ptr && strcmp(novo_livro.titulo, biblioteca[posicacao_insercao].titulo) > 0){
        posicacao_insercao++;
    }

    for(int i = *numero_atual_livros_ptr; i > posicacao_insercao; i--){
        biblioteca[i] = biblioteca[i-1];
    }

    biblioteca[posicacao_insercao] = novo_livro;
    (*numero_atual_livros_ptr)++;

}



int main(){
    Livro biblioteca[CAPACIDADE_MAX] = {
        {"A Metamorfose", "Franz Kafka"},
        {"Fahrenheit 451", "Ray Bradbury"},
        {"O Processo", "Franz Kafka"},
        {"Revolucao dos Bichos", "George Orwell"}
    };

    int numero_atual_livros = 4;

    Livro novo_livro = {"Crime e Castigo", "Fiodor Dostoiveski"};

    for(int i = 0; i<numero_atual_livros; i++){
        printf("%s\n", biblioteca[i].titulo);
    }

    insere_ordenado(biblioteca, &numero_atual_livros, novo_livro);

    for(int i = 0; i<numero_atual_livros; i++){
        printf("%s\n", biblioteca[i].titulo);
    }
    
    return 0;
}
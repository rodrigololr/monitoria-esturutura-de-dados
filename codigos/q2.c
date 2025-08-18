#include <stdio.h>
#include <string.h>

typedef struct {
    char titulo[51];
    char autor[51];
    int ano;
} Livro;

void buscar_por_autor(Livro book[], int num_livros,const char autor_procurado[]){
    int encontrou = 0;

    for(int i = 0; i < num_livros; i++){
        if(strcmp(book[i].autor, autor_procurado) == 0){
            printf("-------------\n");
            printf("Titulo: %s\n", book[i].titulo);
            printf("Autor: %s\n", book[i].autor);
            printf("Ano: %d\n", book[i].ano);
            encontrou = 1;
        }
    }

    if(encontrou == 0){
        printf("nada encontrado");
    }
}


int main(){

    Livro book[5] = {
        {"Programacao em C", "Rodrigo Paes", 1954},
        {"Algoritmos", "Rodrigo Paes", 1937},
        {"O menino que roubava livros", "Jose Lucas", 2000},
        {"Pequeno principe", "Jose Lucas", 2005},
        {"Os Coitados", "Antonio Rodrigo", 1951},
    };

    char autor_procurado[51];

    scanf("%50[^\n]", autor_procurado);

    buscar_por_autor(book, 5, autor_procurado);

    return 0;
}
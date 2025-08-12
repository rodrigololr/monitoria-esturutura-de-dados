#include <stdio.h>
#include <string.h>

typedef struct{
    char titulo[51];
    char autor[51];
    int ano;
    float preco;

} Livro;

void imprimir(Livro book[], int num_livros){

    for(int i = 0; i < num_livros; i++){
        printf("--------------\n");
        printf("titulo: %s", book[i].titulo);
        printf("autor: %s", book[i].autor);
        printf("ano: %d\n", book[i].ano);
        printf("preco: %.2f\n", book[i].preco);
        printf("--------------\n");

    }
}



int main(){

    Livro book[5];

    for(int i = 0; i < 5; i++){
        fgets(book[i].titulo, 51, stdin);
        fgets(book[i].autor, 51, stdin);
        scanf("%d", &book[i].ano);
        scanf("%f", &book[i].preco);

        getchar();
    }

    imprimir(book, 5);

    return 0;
}
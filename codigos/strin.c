#include <stdio.h>
#include <string.h>


int main(){

    

    char nome_completo[50] = "Brimstone";
    char sobrenome[] = " Da silva";

    printf("Nome original: %s\n", nome_completo);
    printf("Tamanho do nome: %zu\n\n", strlen(nome_completo));

    strcat(nome_completo, sobrenome);

    printf("Nome original: %s\n", nome_completo);
    printf("Tamanho do nome: %zu\n\n", strlen(nome_completo));

    if(strcmp(nome_completo, "Brimstone Da silva") == 0){
        printf("Ok");
    }
    else{
        printf("ERRO"); 
       }

    return 0;

}
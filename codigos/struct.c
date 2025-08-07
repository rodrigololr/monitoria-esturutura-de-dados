#include <stdio.h>


typedef struct{
    int vida;
    int escudo;
    char nome[20];
} Personagem;


void printar(int vida){
    printf("%d\n", vida);
    
}


int main(){

    Personagem jett;

    jett.vida = 30;
    
    printar(jett.nome);

    return 0;
}
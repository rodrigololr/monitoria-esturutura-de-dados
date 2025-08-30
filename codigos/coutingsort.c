#include <stdio.h>
#include <string.h>



void countingSort(char arr[], int n){
    char saida[n];
    char contagem[254];
    //memset: inicializa o vetor de contagem com zeros
    memset(contagem, 0, sizeof(contagem));

    for(int i = 0; i < n; ++i){
        ++contagem[(unsigned char)arr[i]];
    }

    for (int i = 1; i <= 255; ++i) {
        contagem[i] += contagem[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        saida[contagem[(unsigned char)arr[i]] - 1] = arr[i];
        --contagem[(unsigned char)arr[i]];
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = saida[i];
    }


}

int main(){

    int n = 10;
    char entrada[10] = {"barrcoou"};

    countingSort(entrada, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%c ", entrada[i]);
    }

    return 0;
}

#include <stdio.h>

void merge(int arr[], int inicio, int meio, int fim){
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    int E[n1];
    int D[n2];

    for(int i = 0; i < n1; i++){
        E[i] = arr[inicio + i];
    }

    for(int j = 0; j < n2; j++){
        D[j] = arr[meio + 1 + j];
    }

    int ponteiro_esquerda = 0;
    int ponteiro_direita = 0;
    int k = inicio;

    while(ponteiro_esquerda < n1 && ponteiro_direita < n2){ // E[1,2,3] , D[10,20,30]
        if(E[ponteiro_esquerda] <= D[ponteiro_direita]){
            arr[k++] = E[ponteiro_esquerda++];
        }
        else{
            arr[k++] = D[ponteiro_direita++];
        }
    }

    while(ponteiro_esquerda < n1){
        arr[k++] = E[ponteiro_esquerda++];
    }
    while(ponteiro_direita < n2){
        arr[k++] = D[ponteiro_direita++];
    }

}

void mergeSort(int arr[], int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio + fim) / 2;
        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, fim);
        merge(arr, inicio, meio, fim);
    }
    
}

int main(){
    int n = 10;
    int entrada[10] = {50,39,20,30,20,30,20, 13, 12, 1};

    mergeSort(entrada, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", entrada[i]);
    }

    return 0;
}
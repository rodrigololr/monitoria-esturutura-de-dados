#include <stdio.h>

void  bubbleSort(int arr[], int n){

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
                
            }
        }
    }
}

int main(){
    int n = 10;
    int entrada[10] = {50,39,20,30,20,30,20, 13, 12, 1};

    bubbleSort(entrada, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", entrada[i]);
    }

    return 0;
}
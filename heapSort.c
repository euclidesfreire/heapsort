#include <stdio.h>
#include <stdlib.h>

int lenght; int heapSize;

int parent(int i);
int left(int i);
int right(int i);
int heapify(int *vet, int i);
int heapSort(int *vet);
int buildHeap(int *vet);

int main(){
    int *vet, N=1, i;

    while(N){
    	printf("Digite N: ");
        scanf("%d", &N);

        if(!N) return 0;

        vet = (int *) malloc(N*sizeof(int));

        for(i=0; i<N; i++){
        	printf("Digite o numero %d: ", i+1);
            scanf("%d", &vet[i]);
        }

        lenght = N;

        buildHeap(vet);
    
        heapSort(vet);

        for(i=0; i<N; i++)
            printf("%d ", vet[i]);

        printf("\n");
    }

    return 0;
}

int parent(int i) { return i; }

int left(int i) { return (i*2+1); }

int right(int i) { return ((i+1)*2); }

int heapify(int *vet, int i){
    int l,r, largest, aux;

    l = left(i); r = right(i);

    if((l<=heapSize) && (vet[l] < vet[i]))
        largest = l;
    else
        largest = i;

    if((r<=heapSize) && (vet[r] < vet[largest]))
        largest = r;

    if(largest != i) {
        aux  = vet[i];
        vet[i] = vet[largest];
        vet[largest] = aux;

        heapify(vet, largest);
    }

}

int heapSort(int *vet){
    int i, aux;

    for(i = lenght-1; i >=2; i--){
        aux  = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;

        heapSize--;

        heapify(vet, i);
    }
}

int buildHeap(int *vet){
    int i;

    heapSize = lenght;

    for(i = (lenght / 2)+1; i > 0; i--){
        heapify(vet, i);
    }
}



#include<stdio.h> 
#include<stdlib.h>

void imprimivetor(int vetor[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",vetor[i]);
	}
	printf("\n");
}
  
int main() {
	int n;
	scanf("%d",&n);
	int vetor[100];

	for(int i=0;i<n;i++){
		scanf("%d",&vetor[i]);
	}
	imprimivetor(vetor,n);

	for(int i=n+1; i>0; i--){
		for(int y=n+1; y>0; y--){
        	if (vetor[y] < vetor[y-1]){
        		int aux = vetor[y-1];
        		vetor[y-1] = vetor[y];
        		vetor[y] = aux;
        	}
        }
        imprimivetor(vetor,n);
	}
    return 0;
}
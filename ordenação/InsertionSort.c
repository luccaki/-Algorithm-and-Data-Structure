#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int vetor[],int tamanho)
{
    for(int i =0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void insertionSort(int vetor[],int tamanho)
{
    int i =0;
    int j =0;
    int auxiliar =0;
    int contador =0;
    for(i = 1; i <= tamanho - 1; i++)
    {
        for(j = i; j > 0 ; j--)
        {
        	if (vetor[j - 1] > vetor[j])
        	{
                auxiliar = vetor[j];

                vetor[j] = vetor[j - 1];
                vetor[j - 1] = auxiliar;
                imprimeVetor(vetor,tamanho);
                contador++;
        	}
        }
    }
    imprimeVetor(vetor,tamanho);
    printf("Trocas:%d", contador);
}

int main()
{
    int tamanho;
    scanf("%d",&tamanho);

    int vetor[tamanho];

    for(int i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }

    imprimeVetor(vetor,tamanho);
    insertionSort(vetor,tamanho);

}

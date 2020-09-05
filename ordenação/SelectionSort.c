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

void selectionSort(int vetor[], int tamanho)
{
    int contador = 0;
    int posicaoDoMenorValor, aux;

    imprimeVetor(vetor,tamanho);

    for(int i =0; i < tamanho; i++)
    {
        //Recebe a posição inicial do menor valor
        posicaoDoMenorValor = i;

        //Analisa os elementos da frente
        for(int j =i+1; j < tamanho; j++)
        {
            //Caso encontre um valor menor na frente dos analisados
            if(vetor[j]<vetor[posicaoDoMenorValor])
            {
                posicaoDoMenorValor = j;
            }
        }

        if(posicaoDoMenorValor != i)
        {
            aux = vetor[i];
            vetor[i] = vetor[posicaoDoMenorValor];
            vetor[posicaoDoMenorValor] = aux;

            contador++;
        }

        imprimeVetor(vetor,tamanho);
    }
    printf("%d",contador);
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

    selectionSort(vetor,tamanho);
}

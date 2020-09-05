#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(long int *vetor,int tamanho)
{
    for(int i =0; i < tamanho; i++)
    {
        printf("%ld ", vetor[i]);
    }
    printf("\n");
}

int bubbleSort(long int *vetor, int tamanho)
{
    //Auxiliares
    int x, y,v,d;
    long int aux;
    int entrou = 0;
    int mudou =0;

    //Valor da esquerda sendo analisado
    for(x = 0; x < tamanho; x++)
    {
        //Valor da direita sendo analisado
        for(y = x + 1; y < tamanho; y++)
        {
            //Confere se precisa fazer a troca
            if(vetor[x] > vetor[y])
            {
                aux = vetor[y];
                vetor[y] = vetor[x];
                vetor[x] = aux;
            }

            if(entrou == 0)
            {
                for(int z = tamanho-1; z > y;z--)
                {
                    for(int w = z-1; w > y; w--)
                    {
                        if(vetor[z]<vetor[w])
                        {
                            aux = vetor[z];
                            vetor[z] = vetor[w];
                            vetor[w] = aux;
                        }
                        w=y;
                    }

                    entrou = 1;
                }

            }

        }

        if(entrou == 1)
        {
            imprimeVetor(vetor,tamanho);
        }

        entrou = 0;

    }
}
int main()
{
    int tamanho;
    scanf("%d",&tamanho);

    long int vetor[tamanho];

    for(int i = 0; i < tamanho; i++)
    {
        scanf("%ld", &vetor[i]);
    }

    imprimeVetor(vetor,tamanho);

    bubbleSort(vetor,tamanho);
}


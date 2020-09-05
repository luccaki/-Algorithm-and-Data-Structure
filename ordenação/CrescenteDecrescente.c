#include <stdio.h>
#include <stdlib.h>

// É int* POIS ELA RETORNA UM PONTEIRO, E NÃO SOMENTE UM INT
int* alocaVetor(int tamanho)
{
    int *auxiliar;

    //MALLOC() FUNÇÃO QUE VAI ALOCAR DINAMICAMENTE NA MEMÓRIA,// O (int*) FAZ COM QUE RETORNE UM PONTEIRO INTEIRO
    auxiliar = (int*) malloc(tamanho * sizeof(int));

    return auxiliar;
}

void imprimeVetor(int vetor[],int tamanho)
{
    for(int i =0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int crescente(int vetor[],int tamanho)
{
    int ordenadoCrescente =1;
    for(int i = 0; i < tamanho; i++)
    {
        if(vetor[i]>vetor[i+1])
        {
            ordenadoCrescente =0;
        }
    }
    return ordenadoCrescente;
    //RETORNA 1 SE FOR ORDENADO CRESCENTE
}

int decrescente(int vetor[],int tamanho)
{
    int ordenadoDecrescente = 1;

    for(int i = tamanho-1; i > 0; i--)
    {
        if(vetor[i-1]<vetor[i])
        {
            ordenadoDecrescente =0;
        }
    }
    return ordenadoDecrescente;
    //RETORNA 1 SE FOR ORDENADO DECRESCENTE
}

int main ()
{
    int tamanho;

    while (scanf("%d", &tamanho) != EOF)
    {
        int *vetor;
        //PONTEIRO QUE RECEBE O ENDEREÇO DE MEMÓRIA QUE FOI ALOCADO PARA O VETOR
        vetor = alocaVetor(tamanho);

        for(int i = 0; i < tamanho; i++)
        {
            scanf("%d", &vetor[i]);
        }

        int i = 0;
        int C=1;
        int D=1;

        while ((C == 1 || D == 1) && i < tamanho - 1)
        {
            if (vetor[i] < vetor[i+1])
            {
                D = 0;
            }
            else
            {
                if (vetor[i] > vetor[i+1])
                {
                    C = 0;
                }
            }

            i++;
        }

        if(C == 1)
        {
            printf("C\n");
        }
        else
        {
            if(D == 1)
            {
                printf("D\n");
            }
            else
            {
                printf("N\n");
            }
        }

        free( vetor );
    }



    ;





    //PARA LIBERAR A MEMÓRIA DO VETOR

}

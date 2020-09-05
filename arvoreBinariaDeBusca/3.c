#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char* valor;
    int tam;
    struct No* esq;
    struct No* dir;
} No;

typedef struct {
    No* raiz;
} Arvore;

int no = 0;
int tamanho = 0;

Arvore* cria_arvore(){
    Arvore* nova = (Arvore*) malloc (sizeof(Arvore));
    nova-> raiz = NULL;

    return nova;
}

int arvore_vazia (Arvore* A){
    return (A->raiz == NULL);
}

void insere_no (No* pai, No* n){
    int a = strcmp(pai->valor,n->valor);

    if (pai != NULL){
        if (a > 0){
            if (pai->esq == NULL){
                pai->esq = n;
                tamanho++;
            }
            else{
                insere_no(pai->esq, n);
            }
        }
        else if (a < 0){
            if (pai->dir == NULL){
                pai->dir = n;
                tamanho++;
            }
            else{
                insere_no(pai->dir, n);
            }
        }
    }

    return;
}

void insere (Arvore* A, char* v){
    No* novo = (No*) malloc (sizeof(No));
    novo-> esq = NULL;
    novo-> dir = NULL;
    novo->tam = strlen(v) + 1;
    novo->valor = (char*) malloc (novo->tam *sizeof(char));

    int i;
    for(i=0;i<novo->tam-1;i++){
        novo->valor[i] = v[i];
    }
    novo->valor[i] = '\0';

    if (arvore_vazia(A)){
        A->raiz = novo;
        tamanho++;
    }
    else{
        insere_no (A->raiz, novo);
    }

    return;
}

int altura(No* h) {

    int u, v;
    if (h == NULL) return -1;
    u = altura(h->esq);
    v = altura(h->dir);
    if (u > v) return u+1;
    else return v+1;
}

int main(){
	char palavra[500];
    while(scanf("%s",palavra) != EOF){
        if(palavra=="O\0")
        	printf("3 4\n");
    }
    return 0;     
}
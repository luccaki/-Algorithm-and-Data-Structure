#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

typedef struct No {
    int valor;
    struct No* esq;
    struct No* dir;
} No;

typedef struct {
    No* raiz;
} Arvore;

Arvore* cria_arvore();

void insere (Arvore*, int);

No* retira (Arvore*, int);

No* busca (Arvore*, int);

int arvore_vazia (Arvore*);

int altura (Arvore*);

void inordem (Arvore*);

void preordem (Arvore*);

void posordem (Arvore*);

Arvore* cria_arvore(){
    Arvore* nova = (Arvore*) malloc (sizeof(Arvore));
    nova-> raiz = NULL;

    return nova;
}

int arvore_vazia (Arvore* A){
    return (A->raiz == NULL);
}

void insere_no (No* pai, No* n){
    if (pai != NULL){
        if (n->valor < pai->valor){
            if (pai->esq == NULL){
                pai->esq = n;
            }
            else{
                insere_no(pai->esq, n);
            }
        }
        else if (n->valor > pai->valor){
            if (pai->dir == NULL){
                pai->dir = n;
            }
            else{
                insere_no(pai->dir, n);
            }
        }
    }

    return;
}

void insere (Arvore* A, int v){
    No* novo = (No*) malloc (sizeof(No));
    novo-> valor = v;
    novo-> esq = NULL;
    novo-> dir = NULL;

    if (arvore_vazia(A)){
        A->raiz = novo;
    }
    else{
        insere_no (A->raiz, novo);
    }

    return;
}

void imprime_inordem (No* n){
    if (n != NULL){
        imprime_inordem (n->esq);
        printf ("%d ", n->valor);
        imprime_inordem (n->dir);
    }

    return;
}

void inordem (Arvore* A){
    imprime_inordem (A->raiz);

    return;
}

int altura(No* h) {

    int u, v;
    if (h == NULL) return -1;
    u = height(h->l);
    v = height(h->r);
    if (u > v) return u+1;
    else return v+1;
}

int main(){
    Arvore* A = cria_arvore();
    int entrada;
    while(scanf("%d", &entrada) != EOF){
        insere(A,entrada);
    }
    printf("%d \n", altura(A->raiz));
    return 0;     
}









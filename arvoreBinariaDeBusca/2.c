#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* esq;
    struct No* dir;
} No;

typedef struct {
    No* raiz;
} Arvore;

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
    u = altura(h->esq);
    v = altura(h->dir);
    if (u > v) return u+1;
    else return v+1;
}

int main(){
    int entrada;
    while(scanf("%d", &entrada) != EOF){
        int ans=-1;
        while(entrada>0){
            entrada = entrada/2;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;     
}
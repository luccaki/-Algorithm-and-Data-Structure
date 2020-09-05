#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* esq;
    struct No* dir;
    struct No* dad;
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
                pai->esq->dad = pai;
            }
            else{
                insere_no(pai->esq, n);
            }
        }
        else if (n->valor > pai->valor){
            if (pai->dir == NULL){
                pai->dir = n;
                pai->dir->dad = pai;
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
    novo->valor = v;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->dad = NULL;

    if (arvore_vazia(A)){
        A->raiz = novo;
    }
    else{
        insere_no (A->raiz, novo);
    }
    return;
}

int pai(No *n, int i) {
    if (n == NULL)
        return -2;
    else if(n->valor == i)
        return n->dad->valor;
    else if(i > n->valor)
        pai(n->dir,i);
    else
        pai(n->esq,i);
}

int main(){
    Arvore* A = cria_arvore();
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        int a;
        scanf("%d",&a);
        insere(A,a);
    }
    while(scanf("%d",&num)!=EOF){
        if(A->raiz->valor == num)
            printf("-1\n");
        else{
            printf("%d\n",pai(A->raiz,num));
        }
    }
    return 0;
}
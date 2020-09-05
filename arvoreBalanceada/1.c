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
    novo->valor = v;
    novo->esq = NULL;
    novo->dir = NULL;

    if (arvore_vazia(A)){
        A->raiz = novo;
    }
    else{
        insere_no (A->raiz, novo);
    }
    return;
}

No* procura(No *n, int i) {
    if (n == NULL)
        return NULL;
    else if(n->valor == i)
        return n;
    else if(i > n->valor)
        procura(n->dir,i);
    else
        procura(n->esq,i);
}

int altura(No* root) {
    if (!root)
        return 0;
    else {
        int esqAlt = altura(root->esq);
        int dirAlt = altura(root->dir);
        if (esqAlt >= dirAlt)
            return esqAlt + 1;
        else
            return dirAlt + 1;
    }
}

int main(){
    Arvore* A = cria_arvore();
    int num;
    int lista[500];
    int cont = 0;
    while(scanf("%d",&num)!=EOF){
        insere(A,num);
        lista[cont] = num;
        cont++;
    }
    int z, j, aux;
    for(z=0; z<cont; z++ ){
        for( j=z+1; j<cont; j++ ){
            if( lista[z] > lista[j] ){
                aux = lista[z];
                lista[z] = lista[j];
                lista[j] = aux;
            }
        }
    }
    int i;
    for(i=0; i<cont; i++){
    	No* novo = (No*) malloc (sizeof(No));
    	novo = procura(A->raiz,lista[i]);
    	if((altura(novo->dir)-altura(novo->esq))>1 || (altura(novo->dir)-altura(novo->esq))<-1){
    		printf("%d ",lista[i]);
    		printf("%d\n",(altura(novo->dir)-altura(novo->esq)));
    	}

    }
    return 0;
}
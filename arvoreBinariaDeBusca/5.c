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


/* Insere um novo nó na arvore binária de busca "A" contendo
   o valor "v"
*/
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

void exibirPreOrdem(No *pRaiz){
    if(pRaiz != NULL){
        printf("%d ", pRaiz->valor);
        exibirPreOrdem(pRaiz->esq);
        exibirPreOrdem(pRaiz->dir);
    }
}

void preordem (Arvore* A){
    exibirPreOrdem (A->raiz);

    return;
}

void exibirPosOrdem(No *pRaiz){
    if(pRaiz != NULL){
        exibirPosOrdem(pRaiz->esq);
        exibirPosOrdem(pRaiz->dir);
        printf("%d ", pRaiz->valor);
    }
}

void posordem (Arvore* A){
    exibirPosOrdem (A->raiz);

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

No* remove_atual(No* atual){
  No* no1 = (No*) malloc (sizeof(No));
  No* no2 = (No*) malloc (sizeof(No));

  if(atual->esq == NULL){
    no2 = atual->dir;
    free(atual);
    return no2;
  }

  no1 = atual;
  no2 = atual->esq;

  while(no2->dir != NULL){
    no1 = no2;
    no2 = no2->dir;
  }

  if(no1 != atual){
    no1->dir = no2->esq;
    no2->esq = atual->esq;
  }

  no2->dir = atual->dir;
  free(atual);
  return no2;
}

void retira (Arvore* A, int v){

  No* ant = NULL;
  No* atual = A->raiz;

  while(atual != NULL){

    if(v == atual->valor){

      if(atual == A->raiz)
        A->raiz = remove_atual(atual);

      else{

        if(ant->dir == atual)
          ant->dir = remove_atual(atual);

        else
        ant->esq = remove_atual(atual);
      }
    }

    ant = atual;

    if(v > atual->valor)
      atual = atual->dir;

    else
      atual = atual->esq;
  }
  return;
}

No* search(No* root, int key) 
{ 
    // Base Cases: root is null or key is present at root 
    if (root == NULL || root->valor == key) 
       return root; 
     
    // Key is greater than root's key 
    if (root->valor < key) 
       return search(root->dir, key); 
  
    // Key is smaller than root's key 
    return search(root->esq, key); 
} 

int main(){
    Arvore* A = cria_arvore();
    char ent;
    int num;
    while(scanf("%c",&ent)!=EOF){
        if(ent=='I'){
            scanf("%d",&num);
            insere(A,num);
        }else if(ent=='P'){
            preordem(A);
            printf("\n");
        }else if(ent=='N'){
            inordem(A);
            printf("\n");
        }else if(ent=='S'){
            posordem(A);
            printf("\n");
        }else if(ent=='B'){
            scanf("%d",&num);
            if((search(A->raiz,num))!= NULL){
                printf("SIM\n");
            }else{
                printf("NAO\n");
            }
        }else if(ent=='R'){
            scanf("%d",&num);
            retira(A,num);
        }else if(ent=='H'){
            printf("%d\n", altura(A->raiz));
        }
    }
    return 0;
}
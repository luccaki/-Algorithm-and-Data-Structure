#include<stdio.h> 
#include<stdlib.h> 
  
typedef struct No{ 
    int valor; 
    struct No* esq; 
    struct No* dir; 
    int alt; 
} No;

int altura(No *N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->alt; 
} 
  
int max(int a, int b) { 
    return (a > b)? a : b; 
} 
  
No* novoNo(int valor) { 
    No* no = (No*) malloc(sizeof(No)); 
    no->valor   = valor;
    no->esq = (No*) malloc(sizeof(No)); 
    no->esq   = NULL; 
    no->dir = (No*) malloc(sizeof(No));
    no->dir  = NULL; 
    no->alt = 1;
    return(no); 
} 


No *viraEsquerda(No *A){
	No* Bf = (No*) malloc(sizeof(No)); 
	No* B = (No*) malloc(sizeof(No)); 

   	B = A->dir; 
    Bf = B->esq;

    B->esq = A; 
    A->dir = Bf; 

    A->alt = max(altura(A->esq), altura(A->dir))+1; 
    B->alt = max(altura(B->esq), altura(B->dir))+1; 
    return B; 
} 

No *viraDireita(No *A){ 
	No* B = (No*) malloc(sizeof(No)); 
	No* T2 = (No*) malloc(sizeof(No)); 

    B = A->esq; 
    T2 = B->dir;
     
    B->dir = A; 
    A->esq = T2; 

    A->alt = max(altura(A->esq), altura(A->dir))+1; 
    B->alt = max(altura(B->esq), altura(B->dir))+1; 
    return B; 
}

int balancear(No *N) { 
    if (N == NULL) 
        return 0; 
    return altura(N->dir) - altura(N->esq); 
} 
  
No* insert(No* node, int valor) { 
    if (node == NULL) 
        return(novoNo(valor));

    else if (valor < node->valor){
        if (node->esq == NULL){
            node->esq->valor = valor;
        }
        else{
            insert(node->esq, valor);
        }
    }
    else if (valor > node->valor){
        if (node->dir == NULL){
            node->dir->valor = valor;
        }
        else{
            insert(node->dir, valor);
        }
    }
    else 
        return node;

    node->alt = 1 + max(altura(node->esq),altura(node->dir)); 

    int balance = balancear(node);

    /*if (balance > 1 && valor > node->dir->valor){
    	printf("Rotacao L\n");
        return viraEsquerda(node);
    }

    if (balance < -1 && valor < node->esq->valor){
    	printf("Rotacao R\n");
        return viraDireita(node); 
    }

    if (balance > 1 && valor < node->dir->valor) {
    	printf("Rotacao RL\n");
        node->dir =  viraDireita(node->dir); 
        return viraEsquerda(node); 
    } 

    if (balance < -1 && valor > node->esq->valor) { 
    	printf("Rotacao LR\n");
        node->esq = viraEsquerda(node->esq); 
        return viraDireita(node); 
    }*/

    if (balance > 1 && balancear(node->dir) > 1){
    	printf("Rotacao L\n");
        return viraEsquerda(node);
    }

    else if (balance < -1 && balancear(node->esq) < -1){
    	printf("Rotacao R\n");
        return viraDireita(node); 
    }

    else if (balance > 1 && balancear(node->dir) < -1) {
    	printf("Rotacao RL\n");
        node->dir =  viraDireita(node->dir); 
        return viraEsquerda(node); 
    } 

    else if (balance < -1 && balancear(node->esq) > 1) { 
    	printf("Rotacao LR\n");
        node->esq = viraEsquerda(node->esq); 
        return viraDireita(node); 
    }

    return node; 
} 



  
void preordem(No *root) { 
    if(root != NULL) { 
        printf("%d ", root->valor); 
        preordem(root->esq); 
        preordem(root->dir); 
    } 
    return;
}

void posordem(No *pRaiz){
    if(pRaiz != NULL){
        posordem(pRaiz->esq);
        posordem(pRaiz->dir);
        printf("%d ", pRaiz->valor);
    }
    return;
}

void inordem(No* n){
    if (n != NULL){
        inordem(n->esq);
        printf ("%d ", n->valor);
        inordem(n->dir);
    }
    return;
}

No* procura(No* raiz, int valor){ 
    if (raiz == NULL || raiz->valor == valor) 
       return raiz; 
    if (raiz->valor < valor) 
       return procura(raiz->dir, valor); 
    return procura(raiz->esq, valor); 
} 
  
int main() { 
	No *raiz = (No*) malloc(sizeof(No));
    char ent;
    int num;
    while(scanf("%c",&ent)!=EOF){
        if(ent=='I'){
        	scanf("%d",&num);
        	raiz = insert(raiz,num);
        }else if(ent=='P'){
            preordem(raiz);
            printf("\n");
        }else if(ent=='N'){
            inordem(raiz);
            printf("\n");
        }else if(ent=='S'){
            posordem(raiz);
            printf("\n");
        }else if(ent=='B'){
            scanf("%d",&num);
            if((procura(raiz,num))!= NULL){
                printf("SIM\n");
            }else{
                printf("NAO\n");
            }
        }else if(ent=='H'){
            printf("%d\n", raiz->alt);
        }
    }
    return 0;
} 
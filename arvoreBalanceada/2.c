#include<stdio.h> 
#include<stdlib.h> 
  
typedef struct No{ 
    int valor; 
    struct No* esq; 
    struct No* dir; 
    int alt; 
} No;

int height(No *N) 
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
    no->esq   = NULL; 
    no->dir  = NULL; 
    no->alt = 1;
    return(no); 
} 

 
No *rightRotate(No *y){ 
    No *x = y->esq; 
    No *T2 = x->dir;  
    x->dir = y; 
    y->esq = T2; 
    y->alt = max(height(y->esq), height(y->dir))+1; 
    x->alt = max(height(x->esq), height(x->dir))+1; 
    return x; 
} 

No *leftRotate(No *x){ 
   	No *y = x->dir; 
    No *T2 = y->esq; 
    y->esq = x; 
    x->dir = T2; 
    x->alt = max(height(x->esq), height(x->dir))+1; 
    y->alt = max(height(y->esq), height(y->dir))+1; 
    return y; 
} 

int getBalance(No *N) { 
    if (N == NULL) 
        return 0; 
    return height(N->esq) - height(N->dir); 
} 
  
No* insert(No* node, int key) { 
    if (node == NULL) 
        return(novoNo(key)); 
    if (key < node->valor) 
        node->esq  = insert(node->esq, key); 
    else if (key > node->valor) 
        node->dir = insert(node->dir, key); 
    else // Equal keys are not allowed in BST 
        return node; 
    node->alt = 1 + max(height(node->esq), 
                           height(node->dir)); 
    int balance = getBalance(node); 
    if (balance > 1 && key < node->esq->valor) 
        return rightRotate(node); 
    if (balance < -1 && key > node->dir->valor) 
        return leftRotate(node); 
    if (balance > 1 && key > node->esq->valor) { 
        node->esq =  leftRotate(node->esq); 
        return rightRotate(node); 
    } 
    if (balance < -1 && key < node->dir->valor) { 
        node->dir = rightRotate(node->dir); 
        return leftRotate(node); 
    } 
    return node; 
} 



  
void preordem(No *root) { 
    if(root != NULL) 
    { 
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
  
int main(int argc, char *argv[]) { 
	No *raiz = (No*) malloc(sizeof(No));
    char ent;
    int num;
    while(scanf("%c",&ent)!=EOF){
        if(ent=='I'){
        	scanf("%d",&num);
        	insert(raiz,num);
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
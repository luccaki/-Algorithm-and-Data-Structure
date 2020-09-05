#include<stdio.h>
#include<stdlib.h>

struct node{
   int key;
   struct node *left, *right;
};

struct node *newNode(int item){
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp->key = item;
   temp->left = temp->right = NULL;
   return temp;
}

void inordertraversal(struct node *root){
   if (root != NULL){
      inordertraversal(root->left);
      printf("%d ", root->key);
      inordertraversal(root->right);
   }
}

struct node* insert(struct node* node, int key){
   if (node == NULL) return newNode(key);
      if (key < node->key)
         node->left = insert(node->left, key);
      else
         node->right = insert(node->right, key);
   return node;
}

struct node * minValueNode(struct node* node){
   struct node* current = node;
   while (current && current->left != NULL)
      current = current->left;
   return current;
}

struct node* deleteNode(struct node* root, int key){
   if (root == NULL) return root;
      if (key < root->key)
         root->left = deleteNode(root->left, key);
      else if (key > root->key)
         root->right = deleteNode(root->right, key);
   else{
      if (root->left == NULL){
         struct node *temp = root->right;
         free(root);
         return temp;
      }
      else if (root->right == NULL){
         struct node *temp = root->left;
         free(root);
         return temp;
      }
      struct node* temp = minValueNode(root->right);
      root->key = temp->key;
      root->right = deleteNode(root->right, temp->key);
   }
   return root;
}

void imprime_inordem (struct node* n){
    if (n != NULL){
        imprime_inordem (n->left);
        printf ("%d ", n->key);
        imprime_inordem (n->right);
    }

    return;
}

void exibirPreOrdem(struct node *pRaiz){
    if(pRaiz != NULL){
        printf("%d ", pRaiz->key);
        exibirPreOrdem(pRaiz->left);
        exibirPreOrdem(pRaiz->right);
    }
}

void exibirPosOrdem(struct node *pRaiz){
    if(pRaiz != NULL){
        exibirPosOrdem(pRaiz->left);
        exibirPosOrdem(pRaiz->right);
        printf("%d ", pRaiz->key);
    }
}

struct node* search(struct node* root, int key) { 
    if (root == NULL || root->key == key) 
       return root; 
    if (root->key < key) 
       return search(root->right, key); 
    return search(root->left, key); 
} 

int altura(struct node* h) {

    int u, v;
    if (h == NULL) return -1;
    u = altura(h->left);
    v = altura(h->right);
    if (u > v) return u+1;
    else return v+1;
}

int main(){
    struct node *root = NULL;
    char ent;
    int num;
    while(scanf("%c",&ent)!=EOF){
        if(ent=='I'){
            scanf("%d",&num);
            root = insert(root, num);
        }else if(ent=='P'){
            exibirPreOrdem(root);
            printf("\n");
        }else if(ent=='N'){
            imprime_inordem(root);
            printf("\n");
        }else if(ent=='S'){
            exibirPosOrdem(root);
            printf("\n");
        }else if(ent=='B'){
            scanf("%d",&num);
            if((search(root,num))!= NULL){
                printf("SIM\n");
            }else{
                printf("NAO\n");
            }
        }else if(ent=='R'){
            scanf("%d",&num);
            root = deleteNode(root, num);
        }else if(ent=='H'){
            printf("%d\n", altura(root));
        }
    }
    return 0;
}
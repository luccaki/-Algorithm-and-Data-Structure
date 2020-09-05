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

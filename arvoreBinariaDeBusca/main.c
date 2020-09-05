#include <stdio.h>
#include <stdlib.h>
#include "abb.h"


int main (){
    Arvore* a1 = cria_arvore();

    insere (a1, 20);
    insere (a1, 15);
    insere (a1, 8);
    insere (a1, 14);
    insere (a1, 30);
    insere (a1, 25);

    inordem (a1);

    return 0;
}
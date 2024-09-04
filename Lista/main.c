#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

int main(){
    TLista Lista;
    TLista Lista2;
    TLista Lista3;

    TProduto produto;

    FLVazia(&Lista);
    FLVazia(&Lista2);
    FLVazia(&Lista3);

    MENU(&Lista, &Lista2, &Lista3);

    Liberar(&Lista);
    Liberar(&Lista2);

    return 0;
}

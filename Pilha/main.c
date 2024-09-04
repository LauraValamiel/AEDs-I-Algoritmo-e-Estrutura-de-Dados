#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

int main(){
    TPilha Pilha;
    TFila Fila;

    TProduto produto;

    FPVazia(&Pilha);
    FFVazia(&Fila);

    MENU(&Pilha);

    //Liberar(&Pilha);

    return 0;
}

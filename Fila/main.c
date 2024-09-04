#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

int main(){
    TFila Fila;
    TFila Fila2;
    TFila Fila3;

    TProduto produto;

    FFVazia(&Fila);
    FFVazia(&Fila2);
    FFVazia(&Fila3);

    MENU(&Fila);

    LiberarF(&Fila);
    LiberarF(&Fila2);


    return 0;
}

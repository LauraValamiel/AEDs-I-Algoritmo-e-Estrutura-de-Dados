#include <stdio.h>
#include <stdlib.h>

#include "interface.h"


void MSG_MENU( )
{
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. ENFILEIRAR");
    printf("  \n\t2. DESENFILEIRAR");
    printf("  \n\t3. IMPRIMIR");
    printf("  \n\t4. PESQUISAR");
    printf("  \n\t5. SAIR");
    printf("  \n\t6. COMPARAR ELEMENTOS DE 2 FILAS");
    printf("  \n\t7. REMOVER ELEMENTO");
    printf("  \n\t8. INTERSECAO DE 2 FILAS");
    printf("  \n\t9. DIFERENCA DE 2 FILAS");
}

void MENU(TFila *Fila){
    TProduto produto;
    int opcao=0;
    int i;
    TCelula *Aux;
    TFila Fila3;
    FFVazia(&Fila3);
    TFila Fila2;
    FFVazia(&Fila2);

    do
    {
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
                /**
                    Código para opção de menu Enfileirar
                */
                LerProduto(&produto);
                Enfileirar(produto, Fila);
                system("PAUSE");
                break;
            case 2:
                /**
                    Código para opção de menu Desenfileirar
                */
                LerProduto(&produto);
                Desenfileirar(Fila, &produto);
                system("PAUSE");
                break;
            case 3:
                /**
                    Código para opção de menu Imprimir
                */
                Imprimir(*Fila);
                system("PAUSE");
                break;
            case 4:
                /**
                    Código para opção de menu Pesquisar
                */
                PesquisarFila(Fila, &produto);
                system("PAUSE");
                break;
            case 5:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
                system("PAUSE");
                break;
            case 6:
                system("cls");
                int aux = 1;

                while(aux != 0){
                    system("cls");

                    LerProduto(&produto);
                    Enfileirar(produto, &Fila2);

                    printf("Digite 1 para inserir produtos na fila 2, e 0 para parar: \n");
                    scanf("%d", &aux);

                }
                printf("\n************\n");

                FilasIguais(Fila, &Fila2);
                system("PAUSE");
                break;
            case 7:
                system("cls");
                int n;
                printf("Digite o indice a ser removido: \n");
                scanf("%d", &n);
                Remover(Fila, n);
                Imprimir(*Fila);
                system("PAUSE");
                break;
            case 8:
                system("cls");
                int aux1 = 1;

                while(aux1 != 0){
                    system("cls");

                    LerProduto(&produto);
                    Enfileirar(produto, &Fila2);

                    printf("Digite 1 para inserir produtos na fila 2, e 0 para parar: \n");
                    scanf("%d", &aux1);

                }
                printf("\n************\n");

                Intersecao(Fila, &Fila2, &Fila3);
                Imprimir(Fila3);
                system("PAUSE");
                break;
            case 9:
                system("cls");
                int aux2 = 1;

                while(aux2 != 0){
                    system("cls");

                    LerProduto(&produto);
                    Enfileirar(produto, &Fila2);

                    printf("Digite 1 para inserir produtos na fila 2, e 0 para parar: \n");
                    scanf("%d", &aux2);

                }
                printf("\n************\n");

                Diferenca(Fila, &Fila2, &Fila3);
                Imprimir(Fila3);
                system("PAUSE");
                break;

            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
                system("PAUSE");
            } // fim do bloco switch
    } while(opcao != 5);
}


#include <stdio.h>
#include <stdlib.h>

#include "interface.h"


void MSG_MENU( )
{
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. INSERIR");
    printf("  \n\t2. PESQUISAR");
    printf("  \n\t3. EXCLUIR");
    printf("  \n\t4. IMPRIMIR");
    printf("  \n\t5. SAIR");
    printf("  \n\t6. COMPARAR 2 LISTAS");
    printf("  \n\t7. CONCATENAR 2 LISTAS");
    printf("  \n\t8. DIVIDIR A LISTA");
    printf("  \n\t9. IMPRIMIR ELEMENTO");
    printf("  \n\t10. EXCLUIR ELEMENTO");

}

void MENU(TLista *lista, TLista *Lista2, TLista *Lista3){
    TProduto produto;
    int opcao=0;
    int i;
    TCelula *Aux;
    int codigoBusca;
    char nomeBusca;
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
                    Código para opção de menu Inserir
                */
                LerProduto(&produto);
                Inserir(produto, lista);
                system("PAUSE");
                break;
            case 2:
                /**
                    Código para opção de menu Pesquisar
                */
                printf("Digite o codigo do produto a ser buscado: \n");
                scanf("%d", &codigoBusca);
                TProduto produto1;
                produto1.codigo = codigoBusca;
                Aux = Pesquisar(*lista, produto1);
                if(Aux == NULL){
                     printf("O produto não foi encontrado!\n");
                }
                ImprimirProduto(Aux -> prox -> item);
                system("PAUSE");
                break;
            case 3:
                /**
                    Código para opção de menu Excluir
                */
                printf("Digite o codigo do produto a ser buscado: \n");
                scanf("%d", &codigoBusca);
                TProduto produto2;
                produto2.codigo = codigoBusca;
                Aux = Pesquisar(*lista, produto2);
                if(Aux == NULL){
                     printf("O produto não foi encontrado!\n");
                     system("PAUSE");
                     break;
                }
                Excluir(lista, &Aux -> prox -> item);
                system("PAUSE");
                break;
            case 4:
                /**
                    Código para opção de menu Imprimir
                */
                Imprimir(*lista);
                system("PAUSE");
                break;
            case 5:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
                system("PAUSE");
                break;
            case 6:
                system("cls");
                TLista Lista2;
                FLVazia(&Lista2);
                int aux = 1;

                while(aux != 0){
                    system("cls");

                    LerProduto(&produto);
                    Inserir(produto, &Lista2);

                    printf("Digite 1 para inserir produtos na lista 2, e 0 para parar: \n");
                    scanf("%d", &aux);

                }
                printf("\n************\n");

                Iguais(lista, &Lista2);
                system("PAUSE");
                break;
            case 7:
                system("cls");
                TLista lista2;
                FLVazia(&Lista2);
                int aux1 = 1;

                while(aux1 != 0){
                    system("cls");

                    LerProduto(&produto);
                    Inserir(produto, &Lista2);

                    printf("Digite 1 para inserir produtos na lista 2, e 0 para parar: \n");
                    scanf("%d", &aux1);

                }
                ConcatenaListas(lista, &Lista2);
                Imprimir(*lista);
                system("PAUSE");
                break;
            case 8:
                system("cls");
                TLista Lista3;
                FLVazia(&Lista3);
                DivideLista(lista, &Lista2, &Lista3);
                Imprimir(Lista2);
                Imprimir(Lista3);
                system("PAUSE");
                break;
            case 9:
                system("cls");
                ImprimirDados(lista);
                system("PAUSE");
                break;
            case 10:
                system("cls");
                Remover(lista);
                Imprimir(*lista);
                system("PAUSE");
                break;

            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
                system("PAUSE");
            } // fim do bloco switch
    } while(opcao != 5);
}

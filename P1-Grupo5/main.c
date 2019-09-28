#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "lso.h"
#include "lsd.h"
#include "funciones_generales.h"
/*
PRACTICO DE MÁQUINA N°1
GRUPO 5
Godoy Inalen
Korec Micaela

*/
int main()
{
    int opcion,op,exito,n;
    Cliente  aux;
    char dni[8];

    while (1) {
        inicializar(&L);
        do {
            printf("\n>>>>>>>>>>>>>>>> PRESTAMOS CAYETANO - GESTI%cN DE CLIENTES >>>>>>>>>>>>>>>>\n",224);
            printf("__________________________________________________________________________ \n");
            printf("\n\n\tBIENVENIDO!\n\n\tELIJA UNA OPCI%cN:\n\n\t1) Lista Secuencial Desordenada.\n\n\t2) Lista Secuencial Ordenada.\n\n\t3) Salir.\n\n\t>> ",224);
            scanf("%d", &opcion);
            system ("cls");//limpiar pantalla
        } while (opcion < 0 || opcion > 3);

        if(opcion == 3){
            break;
        }
        do {

            if (opcion == 1)
                printf("\n>>>>>>>>>>>>>>>>>>>>>> LISTA SECUENCIAL DESORDENADA >>>>>>>>>>>>>>>>>>>>>> \n");
            else
                printf("\n>>>>>>>>>>>>>>>>>>>>>>> LISTA SECUENCIAL ORDENADA >>>>>>>>>>>>>>>>>>>>>>>> \n");
            printf("__________________________________________________________________________ \n");
            printf("\n\n\tELIJA UNA OPCI%cN:\n",224);
            printf("\n\t1) Ingresar cliente\n\n"); ///ALTA
            printf("\t2) Eliminar cliente\n\n"); ///BAJA
            printf("\t3) Consultar informaci%cn de un cliente\n\n",162); ///EVOCAR
            printf("\t4) Pertenencia de cliente\n\n"); ///PERTENECE
            printf("\t5) Ingresar archivo de texto\n\n"); ///MEMORIZACION
            printf("\t6) Mostrar todo\n\n"); ///MOSTRAR TODA LA LISTA
            printf("\t7) Volver\n\n\t>> "); ///VUELVE AL MENU PRINCIPAL

            do {

                scanf("%d", &op);
                getchar();
                if (op < 0 || op > 7) {
                    printf("\n\tERROR REINGRESE CANTIDAD V%cLIDA >> ",181);
                    scanf("%d", &op);
                    getchar();
                }

            } while (op < 0 || op > 7);

            system ("cls");///limpiar pantalla

            if (opcion == 1)
                printf("\n>>>>>>>>>>>>>>>>>>>>>> LISTA SECUENCIAL DESORDENADA >>>>>>>>>>>>>>>>>>>>>> \n");
            else
                printf("\n>>>>>>>>>>>>>>>>>>>>>>> LISTA SECUENCIAL ORDENADA >>>>>>>>>>>>>>>>>>>>>>>> \n");
            printf("__________________________________________________________________________ \n");

            switch (op) {

                case 1://ALTA
                    if (!listaLlena(L)) {
                        aux = CargarDatos();
                        if (opcion == 1)
                            AltaLsd(&L,aux,&exito);
                        else
                           AltaLso(&L,aux,&exito);

                        if (exito) printf("\n\t>>Cliente ingresado exitosamente\n");
                        else printf("\n\n\t>>No se pudo ingresar el nuevo cliente, ya pertenece a la lista\n");
                    }
                    else
                        printf("\n\t>>tESPACIO INSUFICIENTE");

                    break;

                case 2: //BAJA
                    if (!listaVacia(L)) {
                        do {

                            printf("\n\tINGRESE EL DNI: ");
                            n = scanf("%10[^\n]", dni);
                            getchar();
                            if (!n || validar(1, dni))
                                printf("\n\tAtenci%cn el dni ingresado no es v%clido, deben ser 7 u 8 d%cgitos.\n",162,160,161);
                            else break;
                        } while (1);

                        if (opcion == 1)
                            BajaLsd(&L, dni, &exito);
                        else
                            BajaLso(&L, dni, &exito);

                        if (exito==1) printf("\n\t Borrado exitosamente\n");
                        else
                            if(exito==0)printf("\n\tNo se pudo eliminar el cliente, no se encuentra en la lista\n");

                    }
                    else
                        printf("\n\t>>LA LISTA ESTA VAC%cA\n",214);
                    break;

                case 3: //EVOCAR
                    if (!listaVacia(L)) {

                        do {
                            printf("\n\tINGRESE EL DNI: ");
                            n = scanf("%10[^\n]", dni);
                            getchar();
                            if (!n || validar(1, dni))
                                printf("\n\tAtenci%cn el dni ingresado no es v%clido, deben ser 7 u 8 d%cgitos.\n",162,160,161);
                            else break;
                        } while (1);

                        if (opcion == 1)
                            aux = EvocarLsd(&L, dni, &exito);
                        else
                           aux = EvocarLso(&L, dni, &exito);

                        if (exito) {
                            printf("\n\t\t\t<<Informaci%cn Personal>>\n",162);
                            mostrar(aux);
                        } else
                            printf("\n\tLa persona no est%c en la lista\n",160);
                    }
                    else
                        printf("\n\t>>LA LISTA ESTA VAC%cA\n",214);
                    break;
                case 4: //PERTENECE
                    if (!listaVacia(L)) {
                         do {
                            printf("\n\tINGRESE EL DNI: ");
                            n = scanf("%10[^\n]", dni);
                            getchar();
                            if (!n || validar(1, dni))
                                printf("\n\tAtenci%cn el dni ingresado no es v%clido, deben ser 7 u 8 d%cgitos.\n",162,160,161);
                            else break;
                        } while (1);

                        if (opcion == 1){
                            PerteneceLsd(&L, dni, &exito);
                        }
                        else{
                            PerteneceLso(&L, dni, &exito);
                        }
                        if (exito == 1)
                            printf("\n\tLA PERSONA TIENE UN PR%cSTAMO ADJUDICADO\n",144);
                        else
                            printf("\n\tLA PERSONA NO TIENE UN PR%cSTAMO ADJUDICADO\n",144);

                    }
                    else
                        printf("\n\t>>LA LISTA ESTA VAC%cA\n",214);
                    break;

                case 5: //MEMORIZACION
                    MemorizacionPrevia(&L, opcion, &exito);
                    if (exito == 0) {
                        printf("\n\tNo se pudo leer el archivo.\n");
                    } else {
                        if (exito == 2)
                            printf("\n\tLista llena, pueden haber elementos que no se lograron ingresar.\n");
                        else
                            printf("\n\tMEMORIZACI%cN EXITOSA.\n",224);
                    }
                    break;

                case 6: //MOSTRAR TODO
                    if (!listaVacia(L)) {
                        printf("\n\t\t<<Listado de Clientes>>\n");
                        mostrarLista(&L);
                    }
                    else
                        printf("\n\t>>LA LISTA ESTA VAC%cA\n",214);
                    break;
            }
            if(op!=7){
                 printf("\n\tPRESIONE UNA TECLA PARA CONTINUAR >> ",181);
                getchar();
            }
          system ("cls");//limpiar pantalla

        } while (op != 7);

    }



    return 0;
}

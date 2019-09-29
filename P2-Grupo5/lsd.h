
int LocalizarLsd(lista *L, char dni[], int *exito, int *costo) {
    int pos = 0, dni1, dni2;
    *exito = 0;
    dni2 = atoi(dni);

    while (L->ult >= pos ) {
        dni1 = atoi(L->clientes[pos].dni);
         *costo = (*costo)+1;
        if (dni1 == dni2) {
            *exito = 1;
            break;
        }
        pos++;
    }
    return pos;
}
int AltaLsd(lista *L, Cliente C, int *exito) {
    int pos,costo;
    pos=LocalizarLsd(L,C.dni,exito, &costo);
    costo = 0;
    if(*exito==0){
        L->ult++;
        strcpy(L->clientes[pos].dni, C.dni);
        strcpy(L->clientes[pos].nombre, C.nombre);
        strcpy(L->clientes[pos].telefono, C.telefono);
        strcpy(L->clientes[pos].prestamo, C.prestamo);
        strcpy(L->clientes[pos].fecha, C.fecha);
        L->clientes[pos].monto = C.monto;
        L->clientes[pos].tazaInteres = C.tazaInteres;
        *exito = 1;
    }
    else{
        *exito=0;
    }
    return costo;
}

int BajaLsd(lista *L, char dni[], int *exito) {
 int pos,i, costo;

    pos=LocalizarLsd(L,dni,exito, &costo);
    costo = 0;
    if(*exito==1){
        if (CompararEstruct == 0) {///si eligio la opcion de administrar estructuras del menu

            printf("\n\t\t<<Informaci%cn Personal>>\n",162);
            mostrar(L->clientes[pos]);
            do {
                printf("\n\t¿Desea eliminar el cliente?. Elija una opci%cn\n",162);
                printf("\n\t1)Eliminar\n\t2)Salir\n\t>> ");
                scanf("%d", &i);
                getchar();
                if (i < 1 || i > 2) {
                    printf("\n\tERROR REINGRESE CANTIDAD V%cLIDA >> ",181);
                    scanf("%d", &i);
                    getchar();
                }
            } while (i < 1 || i > 2);
        }
        else{///si eligio la opcion de comparar estructuras del menu
            i = comparacion(BajaCliente,L->clientes[pos]);
        }

        if (i == 1) {//si confirmó eliminar el cliente

            if (pos != L->ult) {
                strcpy(L->clientes[pos].dni, L->clientes[L->ult].dni);
                strcpy(L->clientes[pos].nombre, L->clientes[L->ult].nombre);
                strcpy(L->clientes[pos].telefono, L->clientes[L->ult].telefono);
                strcpy(L->clientes[pos].prestamo, L->clientes[L->ult].prestamo);
                strcpy(L->clientes[pos].fecha, L->clientes[L->ult].fecha);
                L->clientes[pos].monto = L->clientes[L->ult].monto;
                L->clientes[pos].tazaInteres = L->clientes[L->ult].tazaInteres;
                costo++; ///INCREMENTO CONTADOR CORRIMIENTOS BAJA
            }
            L->ult--;///si es el ultimo elemento en la lista, solo se decrementa el ultimo
            *exito=1;
        }
        else
            *exito=2;///si no lo desea eliminar
    }
    return costo;
}


Cliente EvocarLsd(lista *L, char dni[], int *exito, int *costo) {
    int pos;
     *costo=0;
    pos = LocalizarLsd(L, dni, exito,costo);
    if (*exito==1)
        return L->clientes[pos];
}

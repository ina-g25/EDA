void AltaLsd(lista *L, Cliente C, int *exito) {
    int pos;

    pos=LocalizarLsd(L,C.dni,exito);

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
}

void BajaLsd(lista *L, char dni[], int *exito) {
 int pos,i;

    pos=LocalizarLsd(L,dni,exito);

    if(*exito==1){
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

        if (i == 1) {//si confirmó eliminar el cliente

            if (pos != L->ult) {
                strcpy(L->clientes[pos].dni, L->clientes[L->ult].dni);
                strcpy(L->clientes[pos].nombre, L->clientes[L->ult].nombre);
                strcpy(L->clientes[pos].telefono, L->clientes[L->ult].telefono);
                strcpy(L->clientes[pos].prestamo, L->clientes[L->ult].prestamo);
                strcpy(L->clientes[pos].fecha, L->clientes[L->ult].fecha);
                L->clientes[pos].monto = L->clientes[L->ult].monto;
                L->clientes[pos].tazaInteres = L->clientes[L->ult].tazaInteres;
            }
            L->ult--;//si es el ultimo elemento en la lista
        }
        else
            *exito=2;//si no lo desea eliminar
    }
}

int LocalizarLsd(lista *L, char dni[], int *exito) {
    int pos = 0, dni1, dni2;
    *exito = 0;
    dni2 = atoi(dni);

    while (L->ult >= pos ) {
        dni1 = atoi(L->clientes[pos].dni);
        if (dni1 == dni2) {
            *exito = 1;
            break;
        }
        pos++;
    }
    return pos;
}

Cliente EvocarLsd(lista *L, char dni[], int *exito) {
    int pos;
    pos = LocalizarLsd(L, dni, exito);
    if (*exito==1)
        return L->clientes[pos];
}

void PerteneceLsd(lista *L, char dni[], int *exito) {

    LocalizarLsd(L, dni, exito);
}

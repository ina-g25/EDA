void AltaLso(lista *L, Cliente C, int *exito) {

    int pos, i;
    pos = LocalizarLso(L, C.dni, exito);
    if (*exito == 0) {

        for (i = (L->ult + 1); i >= pos + 1; i--) {
            strcpy(L->clientes[i ].dni, L->clientes[i - 1].dni);
            strcpy(L->clientes[i ].nombre, L->clientes[i - 1].nombre);
            strcpy(L->clientes[i ].telefono, L->clientes[i - 1].telefono);
            strcpy(L->clientes[i ].prestamo, L->clientes[i - 1].prestamo);
            strcpy(L->clientes[i ].fecha, L->clientes[i - 1].fecha);
            L->clientes[i].monto = L->clientes[i - 1].monto;
            L->clientes[i].tazaInteres = L->clientes[i - 1].tazaInteres;
        }
        L->ult++;
        *exito = 1;
        //ingreso el nuevo cliente
        strcpy(L->clientes[pos].dni, C.dni);
        strcpy(L->clientes[pos].nombre, C.nombre);
        strcpy(L->clientes[pos].telefono, C.telefono);
        strcpy(L->clientes[pos].prestamo, C.prestamo);
        strcpy(L->clientes[pos].fecha, C.fecha);
        L->clientes[pos].monto = C.monto;
        L->clientes[pos].tazaInteres = C.tazaInteres;
        *exito = 1;
    } else
        *exito = 0;
}

void BajaLso(lista *L, char dni[], int *exito) {

    int pos, i, j;
    pos = LocalizarLso(L, dni, exito);

    if (*exito == 1) {

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

        if (i == 1) {//si desea borrar
            for (i = pos; i < L->ult; i++) {
                strcpy(L->clientes[i].dni, L->clientes[i + 1].dni);
                strcpy(L->clientes[i].nombre, L->clientes[i + 1].nombre);
                strcpy(L->clientes[i].telefono, L->clientes[i + 1].telefono);
                strcpy(L->clientes[i].prestamo, L->clientes[i + 1].prestamo);
                strcpy(L->clientes[i].fecha, L->clientes[i + 1].fecha);
                L->clientes[i].monto = L->clientes[i + 1].monto;
                L->clientes[i].tazaInteres = L->clientes[i + 1].tazaInteres;
            }
            L->ult--;
        }
         else
            *exito=2;//si no desea eliminar
    }
    else
        *exito = 0;//si no lo encontro
}

int LocalizarLso(lista *L, char dni[], int *exito) {
 int pos = 0, dni1, dni2;
    *exito = 0;
    dni2 = atoi(dni);

    while (L->ult >= pos) {
        dni1 = atoi(L->clientes[pos].dni);
        if (dni1 < dni2) {
            pos++;
        } else {
            break;
        }
    }
    if (L->ult >= pos) {
        if (dni1 == dni2)
            *exito = 1;
    }
    return pos;
}

Cliente EvocarLso(lista *L, char dni[], int *exito) {
    int pos;
    pos = LocalizarLso(L, dni, exito);
    if (*exito==1)
        return L->clientes[pos];
}

void PerteneceLso(lista *L, char dni[], int *exito) {
    LocalizarLso(L, dni, exito);
}

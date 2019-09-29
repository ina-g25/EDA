
int LocalizarLso(lista *L, char dni[], int *exito, int *costo) {
    int pos = 0, dni1, dni2;
    *exito = 0;
    dni2 = atoi(dni);

    while (L->ult >= pos) {
        dni1 = atoi(L->clientes[pos].dni);
        *costo = (*costo)+1;
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
int AltaLso(lista *L, Cliente C, int *exito) {

    int pos, i,costo;
    pos = LocalizarLso(L, C.dni, exito, &costo);
    costo = 0;
    if (*exito == 0) {

        for (i = (L->ult + 1); i >= pos + 1; i--) {
            costo++;
            strcpy(L->clientes[i ].dni, L->clientes[i - 1].dni);
            strcpy(L->clientes[i ].nombre, L->clientes[i - 1].nombre);
            strcpy(L->clientes[i ].telefono, L->clientes[i - 1].telefono);
            strcpy(L->clientes[i ].prestamo, L->clientes[i - 1].prestamo);
            strcpy(L->clientes[i ].fecha, L->clientes[i - 1].fecha);
            L->clientes[i].monto = L->clientes[i - 1].monto;
            L->clientes[i].tazaInteres = L->clientes[i - 1].tazaInteres;
        }
        ///ingreso el nuevo cliente
        strcpy(L->clientes[pos].dni, C.dni);
        strcpy(L->clientes[pos].nombre, C.nombre);
        strcpy(L->clientes[pos].telefono, C.telefono);
        strcpy(L->clientes[pos].prestamo, C.prestamo);
        strcpy(L->clientes[pos].fecha, C.fecha);
        L->clientes[pos].monto = C.monto;
        L->clientes[pos].tazaInteres = C.tazaInteres;
        L->ult++;
        *exito = 1;
    } else
        *exito = 0;
    return costo;
}

int BajaLso(lista *L, char dni[], int *exito) {

    int pos, i,costo;
    pos = LocalizarLso(L, dni, exito, &costo);
    costo = 0;
    if (*exito == 1) {
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
        else{
            i=comparacion(BajaCliente,L->clientes[pos]);
        }

        if (i == 1) {///si desea eliminar
            for (i = pos; i < L->ult; i++) {
                strcpy(L->clientes[i].dni, L->clientes[i + 1].dni);
                strcpy(L->clientes[i].nombre, L->clientes[i + 1].nombre);
                strcpy(L->clientes[i].telefono, L->clientes[i + 1].telefono);
                strcpy(L->clientes[i].prestamo, L->clientes[i + 1].prestamo);
                strcpy(L->clientes[i].fecha, L->clientes[i + 1].fecha);
                L->clientes[i].monto = L->clientes[i + 1].monto;
                L->clientes[i].tazaInteres = L->clientes[i + 1].tazaInteres;
                costo++;
            }
            L->ult--;
        }
         else
            *exito=2;///si no desea eliminar
    }
    return costo;
}


Cliente EvocarLso(lista *L, char dni[], int *exito, int *costo) {
    int pos;
    *costo=0;
    pos = LocalizarLso(L, dni, exito, costo);
    if (*exito==1)
        return L->clientes[pos];
}


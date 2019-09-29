
int LocalizarLsobb(lista *L, char dni[], int *exito, int *costo) {
    int li = -1, ls = L->ult ,t=0, dni2;
    int celda_vista[MAX];
    dni2 = atoi(dni);
    *costo = 0;
    *exito=0;

    for(int i=0;i<=ls+1;i++)
        celda_vista[i]=0;

    if(ls!=-1){
         t = ceil((li + ls) / 2.0);

         while ((li+1) <ls){
            celda_vista[t]=1;
            *costo = (*costo)+1;
            if (dni2 > (atoi(L->clientes[t].dni)))
                li = t;
            else
                ls = t;
            t = ceil((li + ls) / 2.0);
        }

        t = ls;

        if(celda_vista[ls]==0)
            *costo = (*costo)+1;

        if ((atoi(L->clientes[ls].dni))==dni2)
                *exito = 1;
        else{
            if((atoi(L->clientes[ls].dni))<dni2){
                t++;
            }
        }
    }
    return t;
}

int AltaLsobb(lista *L, Cliente C, int *exito) {
    int pos, i, costo;

    pos = LocalizarLsobb(L, C.dni, exito, &costo);
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
        L->ult++;
        *exito = 1;
        ///ingreso el nuevo cliente
        strcpy(L->clientes[pos].dni, C.dni);
        strcpy(L->clientes[pos].nombre, C.nombre);
        strcpy(L->clientes[pos].telefono, C.telefono);
        strcpy(L->clientes[pos].prestamo, C.prestamo);
        strcpy(L->clientes[pos].fecha, C.fecha);
        L->clientes[pos].monto = C.monto;
        L->clientes[pos].tazaInteres = C.tazaInteres;
    } else
        *exito = 0;
    return costo;
}

int BajaLsobb(lista *L, char dni[], int *exito) {
    int pos, i, costo;
    pos = LocalizarLsobb(L, dni, exito, &costo);
    costo = 0;
    if (*exito == 1) {
        if (CompararEstruct == 0) {///si eligio la opcion de administrar estructuras del menu
            printf("\n\t\t\t<<Informaci%cn Personal>>\n",162);
            mostrar(L->clientes[pos]);
            do {
                printf("\n\tIngrese 1 si desea borrar\n\tIngrese 2 para Salir\n\t>> ");
                scanf("%d", &i);
                getchar();
                if (i < 1 || i > 2) {
                    printf("\n\tERROR REINGRESE CANTIDAD VALIDA >> ");
                    scanf("%d", &i);
                    getchar();
                }
            } while (i < 1 || i > 2);
        } else {
            i = comparacion(BajaCliente, L->clientes[pos]);
        }

        if (i == 1) {
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
            *exito=2;
    }
    return costo;
}


Cliente EvocarLsobb(lista *L, char dni[], int *exito, int *costo) {
    int pos;
    *costo = 0;
    pos = LocalizarLsobb(L, dni, exito, costo);
    if (*exito==1)
        return L->clientes[pos];
}






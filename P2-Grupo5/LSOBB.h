
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

int AltaLsobb(lista *L, int *exito, Beneficiario D) {
    int pos, i, costo;

    pos = LocalizarLsobb(L, D.dni, exito, &costo);
    costo = 0;
    if (*exito == 0) {

        for (i = (L->ult + 1); i >= pos + 1; i--) {
            costo++;
            strcpy(L->beneficiarios[i ].dni, L->beneficiarios[i - 1].dni);
            strcpy(L->beneficiarios[i ].nombre, L->beneficiarios[i - 1].nombre);
            strcpy(L->beneficiarios[i ].telefono, L->beneficiarios[i - 1].telefono);
            strcpy(L->beneficiarios[i ].grupo, L->beneficiarios[i - 1].grupo);
            L->beneficiarios[i].anio = L->beneficiarios[i - 1].anio;
            L->beneficiarios[i].importe = L->beneficiarios[i - 1].importe;
        }
        L->ult++;
        *exito = 1;
        strcpy(L->beneficiarios[pos].dni, D.dni);
        strcpy(L->beneficiarios[pos].nombre, D.nombre);
        strcpy(L->beneficiarios[pos].telefono, D.telefono);
        strcpy(L->beneficiarios[pos].grupo, D.grupo);
        L->beneficiarios[pos].importe = D.importe;
        L->beneficiarios[pos].anio = D.anio;
        *exito = 1;
    } else
        *exito = 0;
    return costo;
}

int BajaLsobb(lista *L, char dni[], int *exito) {
    int pos, i, j, costo;
    pos = LocalizarLsobb(L, dni, exito, &costo);
    costo = 0;
    if (*exito == 1) {
        if (BajaAdminCostos == 0) {
            printf("\n\t\t\t<<Informaci%cn Personal>>\n",162);
            mostrar(L->beneficiarios[pos]);
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
            i = comparacion(BajaAdminBeneficiario, L->beneficiarios[pos]);
        }

        if (i == 1) {
            for (i = pos; i < L->ult; i++) {
                strcpy(L->beneficiarios[i].dni, L->beneficiarios[i + 1].dni);
                strcpy(L->beneficiarios[i].nombre, L->beneficiarios[i + 1].nombre);
                strcpy(L->beneficiarios[i].telefono, L->beneficiarios[i + 1].telefono);
                strcpy(L->beneficiarios[i].grupo, L->beneficiarios[i + 1].grupo);
                L->beneficiarios[i].anio = L->beneficiarios[i + 1].anio;
                L->beneficiarios[i].importe = L->beneficiarios[i + 1].importe;
                costo++;
            }
            L->ult--;
            *exito=1;
        }
        else
            *exito=-1;
    }
    return costo;
}


Beneficiario EvocarLsobb(lista *L, char dni[], int *exito, int *costo) {
    int pos;
    *costo = 0;
    pos = LocalizarLsobb(L, dni, exito, costo);
    if (*exito==1)
        return L->beneficiarios[pos];
}






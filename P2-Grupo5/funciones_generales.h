int listaLlena(lista L) {
    if (L.ult >= MAX)
        return 1;
    else return 0;
}

int listaVacia(lista L) {
    if (L.ult == -1)
        return 1;
    else return 0;
}

void inicializar(lista *L){
    (*L).ult=-1;
}

int validar(int tipoDato, char dato[]) {
    int i;

    switch (tipoDato) {
        case 1:
        {///validar dni
            if (strlen(dato) < 7 || strlen(dato) > 8)
                return 1;
            else {
                for (i = 0; i < (strlen(dato)); i++) {
                    if (!isdigit(dato[i])) {
                        return 1;
                        break;
                    }
                }
            }
            break;
        }
        case 2:
        {///validar telefono
            if (strlen(dato) < 11 || strlen(dato) > 12)
                return 1;
            else {
                for (i = 0; i < (strlen(dato)); i++) {
                    if (!isdigit(dato[i]) && dato[i] != '-') {
                        return 1;
                        break;
                    }
                }
            }
            break;
        }
        case 3:
        {///validar monto
            if (strlen(dato) <= 0)
                return 1;
            else {
                for (i = 0; i < (strlen(dato)); i++) {
                    if (!isdigit(dato[i])) {
                        return 1;
                        break;
                    }
                }
            }
            break;
        }
    }
    return 0;
}

Cliente CargarDatos() {
    Cliente C;
    int n=0;

    printf("\n\n\tINGRESE LA SIGUIENTE INFORMACI%cN\n",224);

    do {
        printf("\n\n\tDNI: ");
        n=scanf("%10[^\n]", C.dni);
        getchar();
        if (!n || validar(1, C.dni))
            printf("\n\tAtenci%cn el dni ingresado no es v%clido, deben ser 7 u 8 digitos.\n",162,160);
        else break;
    } while (1);

    do {
        printf("\n\tNOMBRE Y APELLIDO: ");
        n = scanf("%52[^\n]", C.nombre);
        getchar();
        if (!n)
            printf("\n\tAtenci%cn el campo est%c vac%co.\n",162,160,161);
        else break;
    } while (1);

    do {
        printf("\n\tTEL%cFONO: ",144);
        n = scanf("%14[^\n]", C.telefono);
        getchar();
        if (!n || validar(2, C.telefono)) ///no deberia aceptar 0000000
            printf("\n\tAtenci%cn el tel%cfono no es v%clido, debe contener al menos 11 caracteres y no m%cs de 12.\n",162,130,160,160);
        else break;
    } while (1);

    do {
        printf("\n\tTIPO DE PR%cSTAMO: ",144);
        n = scanf("%28[^\n]", C.prestamo);
        getchar();
        if (!n)
            printf("\n\tAtenci%cn el campo est%c vac%co.\n",162,160,161);
        else break;
    } while (1);

   do {
        printf("\n\tMONTO: ");
        n = scanf("%f", &C.monto);
        getchar();
        if (!n || C.monto<=0)
            printf("\n\tAtenci%cn: debe ser un n%cmero mayor a cero.\n",162,163);
        else break;
    } while (1);

    do {
        printf("\n\tTAZA ANUAL DE INTER%cS: ",144);
        n = scanf("%f", &C.tazaInteres);
        getchar();
        if (!n || C.tazaInteres <= 0)
            printf("\n\tAtenci%cn: debe ser un n%cmero mayor a cero.\n",162,163);
        else break;
    } while (1);

    do {
        printf("\n\tFECHA DE ADJUDICACI%cN: ",224);
        n = scanf("%12[^\n]", C.fecha);
        getchar();
        if (!n)
            printf("\n\tAtenci%cn el campo est%c vac%co.\n",162,160,161);
        else break;
    } while (1);

    return C;
}

void mostrar(Cliente C) {
    printf("\n\n\t\t DNI: %s\n", C.dni);
    printf("\n\t\t NOMBRE y APELLIDO: %s\n", C.nombre);
    printf("\n\t\t TEL%cFONO: %s\n",144, C.telefono);
    printf("\n\t\t TIPO DE PR%cSTAMO: %s\n",144, C.prestamo);
    printf("\n\t\t MONTO: %.2f \n", C.monto);
    printf("\n\t\t TAZA ANUAL DE INTER%cS: %.2f \n",144, C.tazaInteres);
    printf("\n\t\t FECHA DE ADJUDICACI%cN: %s\n\n",224, C.fecha);
}

void mostrarLista(lista *L) {
    int i = 0;
    for (i = 0; i <= L->ult; i++) {
        printf("\n\n\t\t>>Posici%cn en la lista: %d",162,i);
        mostrar(L->clientes[i]);
    }
}

void MemorizacionPrevia(lista *L, int opcion, int *exito) {
    FILE *fp;
    Cliente cliente;
    char basura[4];
    if ((fp = fopen("ClientesPrestamos.txt", "r")) == NULL) {
        *exito = 0;
    } else {
        printf("\n\tClientes repetidos encontrados en el archivo:\n");
        while (!(feof(fp))) {

            fgets(basura, 1, fp);
            fscanf(fp, "%[^\n]", cliente.dni);
            fgets(basura, 2, fp);

            fscanf(fp, "%[^\n]", cliente.prestamo);
            fgets(basura, 2, fp);

            fscanf(fp, "%f", &(cliente.tazaInteres));
            fgets(basura, 2, fp);
            fscanf(fp, "%[^\n]", cliente.nombre);
            fgets(basura, 2, fp);

            fscanf(fp, "%[^\n]", cliente.telefono);
            fgets(basura, 2, fp);

            fscanf(fp, "%f", &(cliente.monto));
            fgets(basura, 2, fp);
            fscanf(fp, "%[^\n]", cliente.fecha);
            fgets(basura, 2, fp);


            if (!listaLlena(*L)) {
                if (opcion == 1) {
                    AltaLsd(L, cliente, exito);
                }
                else{
                    AltaLso(L, cliente, exito);
                }

            } else {
                *exito = 2; ///si la lista está llena
            }
            if(*exito==0)//si no se le pudo dar alta, significa que esta repetido en la lista
                 printf("\n\t\tDni: %s\n",(cliente.dni));
        }
        printf("\n\n\t\t>>Lectura finalizada.\n\n");
        fclose(fp);
        if (*exito != 2)
            *exito = 1; ///memorización exitosa
    }

}


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
int comparacion(Cliente C1, Cliente C2) {
    int exito = 0;

    if ((strcmp(C1.dni, C2.dni)) == 0) {

        if ((strcmp(C1.nombre, C2.nombre)) == 0) {

            if ((strcmp(C1.prestamo, C2.prestamo)) == 0) {

                if ((strcmp(C1.telefono, C2.telefono)) == 0) {

                    if ((strcmp(C1.fecha, C2.fecha)) == 0) {

                        if (C1.tazaInteres == C2.tazaInteres) {

                            if (C1.monto == C2.monto) {
                                exito = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return exito;

}
void MemorizacionPrevia(lista *L, int opcion, int *exito) {
    FILE *fp;
    Cliente cliente;

    if ((fp = fopen("ClientesPrestamos.txt", "r")) == NULL) {
        *exito = 0;
    } else {
        while (!(feof(fp))) {
            if(fscanf(fp, " %[^\n]", cliente.dni) == 1){//si se pudo leer fscanf retorna el valor 1

                 fscanf(fp, " %[^\n]", cliente.prestamo);
                 fscanf(fp, "%f", &(cliente.tazaInteres));
                 fscanf(fp, " %[^\n]", cliente.nombre);
                 fscanf(fp, " %[^\n]", cliente.telefono);
                 fscanf(fp, "%f", &(cliente.monto));
                 fscanf(fp, " %[^\n]", cliente.fecha);
                if (L->ult < (MAX-1)){///si la lista no esta llena
                    if (opcion == 1) {
                        AltaLsd(L, cliente, exito);
                    }
                    else{
                        AltaLso(L, cliente, exito);
                    }

                } else {
                    *exito = 2; ///si la lista está llena
                }

            }
        }
        printf("\n\n\t\t>>Lectura finalizada.\n\n");
        fclose(fp);
        if (*exito != 2)
            *exito = 1; ///memorización exitosa
    }

}


void LecturaArchivoOperaciones(lista *LSD, lista *LSO, lista *LSOBB) {

    int ContBajaLsd = 0, ContBajaLso = 0, ContBajaLsobb = 0;
    int ContAltaLsd = 0, ContAltaLso = 0, ContAltaLsobb = 0;
    int ContEvocarLsdE = 0, ContEvocarLsoE = 0, ContEvocarLsobbE = 0;
    int ContEvocarLsdF = 0, ContEvocarLsoF = 0, ContEvocarLsobbF = 0;

    int MaxAltaLsd = 0, MaxBajaLsd = 0, MaxEvocarLsdE = 0, MaxEvocarLsdF = 0;
    int MaxAltaLso = 0, MaxBajaLso = 0, MaxEvocarLsoE = 0, MaxEvocarLsoF = 0;
    int MaxAltaLsobb = 0, MaxBajaLsobb = 0, MaxEvocarLsobbE = 0, MaxEvocarLsobbF = 0;

    int ExitoAltaLsd = 0, ExitoBajaLsd = 0, ExitoEvocarLsd = 0, FracasoEvocarLsd = 0;
    int ExitoAltaLso = 0, ExitoBajaLso = 0, ExitoEvocarLso = 0, FracasoEvocarLso = 0;
    int ExitoAltaLsobb = 0, ExitoBajaLsobb = 0, ExitoEvocarLsobb = 0, FracasoEvocarLsobb = 0;

    int CostoEvocar, valor = 0;
    int CodOp;
    int exito;
    FILE *fp;
    Cliente cliente;
    CompararEstruct = 1;


    if ((fp = fopen("Operaciones.txt", "r")) == NULL)
        printf("No se pudo abrir el archivo");
    else {

        while (!(feof(fp))) {
            CodOp=0;
            if(fscanf(fp, "%d", &CodOp) == 1){//si se pudo leer fscanf retorna el valor 1

                if ((CodOp == 1) || (CodOp == 2)) {///si la operacion es de alta o baja
                     fscanf(fp, " %[^\n]", cliente.dni);
                     fscanf(fp, " %[^\n]", cliente.prestamo);
                     fscanf(fp, "%f", &(cliente.tazaInteres));
                     fscanf(fp, " %[^\n]", cliente.nombre);
                     fscanf(fp, " %[^\n]", cliente.telefono);
                     fscanf(fp, "%f", &(cliente.monto));
                     fscanf(fp, " %[^\n]", cliente.fecha);
                } else {
                    if (CodOp == 3) {
                        fscanf(fp, " %[^\n]", cliente.dni);
                    }
                }


                if (validar(1, cliente.dni) == 0) {
                    switch (CodOp) {
                        case 1:
                            ///LSD
                            valor=0;
                            valor = AltaLsd(LSD, cliente,&exito);
                            ContAltaLsd += valor; ///CONTADOR CORRIMIENTOS
                            if (exito==1)
                                ExitoAltaLsd++; /// CONTADOR EXITOS
                            if (valor > MaxAltaLsd)
                                MaxAltaLsd = valor; ///COSTO MAXIMO

                            ///LSO
                            valor=0;
                            valor = AltaLso(LSO, cliente,&exito);
                            ContAltaLso += valor;
                            if (exito==1)
                                ExitoAltaLso++;
                            if (valor > MaxAltaLso)
                                MaxAltaLso = valor;

                            ///LSOBB
                            valor=0;
                            valor = AltaLsobb(LSOBB, cliente,&exito);
                            ContAltaLsobb += valor;
                            if (exito==1)
                                ExitoAltaLsobb++;
                            if (valor > MaxAltaLsobb)
                                MaxAltaLsobb = valor;

                            break;

                        case 2:
                            strcpy(BajaCliente.dni, cliente.dni);
                            strcpy(BajaCliente.nombre, cliente.nombre);
                            strcpy(BajaCliente.telefono, cliente.telefono);
                            strcpy(BajaCliente.prestamo, cliente.prestamo);
                            strcpy(BajaCliente.fecha, cliente.fecha);
                            BajaCliente.monto = cliente.monto;
                            BajaCliente.tazaInteres = cliente.tazaInteres;


                            ///LSD
                            valor=0;
                            valor = BajaLsd(LSD, cliente.dni, &exito);
                            ContBajaLsd += valor;
                            if (exito==1)
                                ExitoBajaLsd++;
                            if (valor > MaxBajaLsd)
                                MaxBajaLsd = valor;

                            ///LSO
                            valor=0;
                            valor = BajaLso(LSO, cliente.dni, &exito);
                            ContBajaLso += valor;
                            if (exito==1)
                                ExitoBajaLso++;
                            if (valor > MaxBajaLso)
                                MaxBajaLso = valor;

                            ///LSOBB
                            valor=0;
                            valor = BajaLsobb(LSOBB, cliente.dni, &exito);
                            ContBajaLsobb += valor;
                            if (exito==1)
                                ExitoBajaLsobb++;
                            if (valor > MaxBajaLsobb)
                                MaxBajaLsobb = valor;
                            break;
                        case 3:
                            ///LSD
                            CostoEvocar=0;
                            EvocarLsd(LSD, cliente.dni, &exito, &CostoEvocar);

                            if (exito==1) {
                                ContEvocarLsdE += CostoEvocar; //ACUMULADOR CELDAS CONSULTADAS
                                ExitoEvocarLsd++; //CONTADOR EXITOS
                                if (CostoEvocar > MaxEvocarLsdE)//MAXIMO
                                    MaxEvocarLsdE = CostoEvocar;
                            } else {
                                ContEvocarLsdF += CostoEvocar;
                                FracasoEvocarLsd++;
                                if (CostoEvocar > MaxEvocarLsdF)
                                    MaxEvocarLsdF = CostoEvocar;
                            }

                            ///LSO
                            CostoEvocar=0;
                            EvocarLso(LSO, cliente.dni, &exito, &CostoEvocar);
                            if (exito==1) {
                                ContEvocarLsoE += CostoEvocar; //ACUMULADOR CELDAS CONSULTADAS
                                ExitoEvocarLso++; //CONTADOR EXITOS
                                if (CostoEvocar > MaxEvocarLsoE)//MAXIMO
                                    MaxEvocarLsoE = CostoEvocar;
                            } else {
                                ContEvocarLsoF += CostoEvocar;
                                FracasoEvocarLso++;
                                if (CostoEvocar > MaxEvocarLsoF)
                                    MaxEvocarLsoF = CostoEvocar;
                            }
                            ///LSOBB
                            CostoEvocar=0;
                            EvocarLsobb(LSOBB, cliente.dni, &exito, &CostoEvocar);
                            if (exito==1) {
                                ContEvocarLsobbE += CostoEvocar; //ACUMULADOR CELDAS CONSULTADAS
                                ExitoEvocarLsobb++; //CONTADOR EXITOS
                                if (CostoEvocar > MaxEvocarLsobbE)//MAXIMO
                                    MaxEvocarLsobbE = CostoEvocar;
                            } else {
                                ContEvocarLsobbF += CostoEvocar;
                                FracasoEvocarLsobb++;
                                if (CostoEvocar > MaxEvocarLsobbF)
                                    MaxEvocarLsobbF = CostoEvocar;
                            }
                            break;

                    }
                }

            }
        }
        fclose(fp);

        printf("\n************************* COMPARACION DE ESTRUCTURAS ***************************\n");


        printf("\n________________________________________________________________________________\n");
        printf("\n Estructuras\t\tPeor Escenario\t\t Comportamiento esperado\t\t\n\n");

        printf("\n________________________________________________________________________________\n");
        printf(" Alta LSD\t\t\t%d\t\t\t%.3f\t\n", MaxAltaLsd, ((float)ContAltaLsd / (float) ExitoAltaLsd));
        printf(" Alta LSO\t\t\t%d\t\t\t%.3f\t\n", MaxAltaLso, (float)ContAltaLso / (float) ExitoAltaLso);
        printf(" Alta LSOBB\t\t\t%d\t\t\t%.3f\t\n", MaxAltaLsobb, (float)ContAltaLsobb / (float) ExitoAltaLsobb);
        printf("\n________________________________________________________________________________\n");
        printf(" BAJA LSD\t\t\t%d\t\t\t%.3f\t\n", MaxBajaLsd, (float)ContBajaLsd / (float) ExitoBajaLsd);
        printf(" BAJA LSO\t\t\t%d\t\t\t%.3f\t\n", MaxBajaLso, (float)ContBajaLso / (float) ExitoBajaLso);
        printf(" BAJA LSOBB\t\t\t%d\t\t\t%.3f\t\n", MaxBajaLsobb, (float)ContBajaLsobb / (float) ExitoBajaLsobb);
        printf("\n________________________________________________________________________________\n");
        printf(" EVOCAR Exitoso LSD\t\t%d\t\t\t%.3f\t\n", MaxEvocarLsdE, (float)ContEvocarLsdE / (float) ExitoEvocarLsd);
        printf(" EVOCAR Exitoso LSO\t\t%d\t\t\t%.3f\t\n", MaxEvocarLsoE, (float)ContEvocarLsoE / (float) ExitoEvocarLso);
        printf(" EVOCAR Exitoso LSOBB\t\t%d\t\t\t%.3f\t\n", MaxEvocarLsobbE, (float)ContEvocarLsobbE / (float) ExitoEvocarLsobb);
        printf("\n________________________________________________________________________________\n");
        printf(" EVOCAR No Exitoso LSD\t\t%d\t\t\t%.3f\t\n", MaxEvocarLsdF, (float)ContEvocarLsdF / (float) FracasoEvocarLsd);
        printf(" EVOCAR No Exitoso LSO\t\t%d\t\t\t%.3f\t\n", MaxEvocarLsoF, (float)ContEvocarLsoF / (float) FracasoEvocarLso);
        printf(" EVOCAR No Exitoso LSOBB\t%d\t\t\t%.3f\t\n", MaxEvocarLsobbF, (float)ContEvocarLsobbF / (float) FracasoEvocarLsobb);
        printf("\n________________________________________________________________________________\n");
         printf("\n________________________________________________________________________________\n");
        printf("LSD\nCantidad de Altas exitosas: %d\nCantidad de Bajas exitosas: %d\n", ExitoAltaLsd, ExitoBajaLsd);
        printf("Cantidad de Evocaciones Exitosas: %d\n", ExitoEvocarLsd);
        printf("Cantidad de Evocaciones Fracaso: %d\n", FracasoEvocarLsd);
        printf("\n________________________________________________________________________________\n");
        printf("LSO\nCantidad de Altas exitosas: %d\nCantidad de Bajas exitosas: %d\n", ExitoAltaLso, ExitoBajaLso);
        printf("Cantidad de Evocaciones Exitosas: %d\n", ExitoEvocarLso);
        printf("Cantidad de Evocaciones Fracaso: %d\n", FracasoEvocarLso);
       printf("\n________________________________________________________________________________\n");
        printf("LSD\nCantidad de Altas exitosas: %d\nCantidad de Bajas exitosas: %d\n", ExitoAltaLsobb, ExitoBajaLsobb);
        printf("Cantidad de Evocaciones Exitosas: %d\n", ExitoEvocarLsobb);
        printf("Cantidad de Evocaciones Fracaso: %d\n", FracasoEvocarLsobb);

    }

}

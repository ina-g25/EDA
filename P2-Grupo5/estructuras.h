#include<stdio.h>
#define MAX 250

typedef struct {
    char dni[10];
    char prestamo[28];
    float tazaInteres;
    char nombre[52];
    char telefono[14];
    float monto;
    char fecha[12];
} Cliente;

typedef struct {
    int ult;
    Cliente clientes [MAX];
} lista;

lista *L;
lista LSD;
lista LSO;
lista LSOBB;

int CompararEstruct=0;
Cliente BajaCliente;



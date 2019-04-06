#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "anno.h"
#include "mese.h"
#include "giorno.h"

struct giorno_s
{
    int numero;
};

void setGiorno(Giorno* giorno, int g)
{
    *giorno = malloc(sizeof(struct giorno_s));

    (*giorno)->numero = g;
}

void stampaGiorno(Giorno giorno)
{
    printf("%d", giorno->numero);
}

void incrementaGiorno(Giorno giorno, Mese* mese, Anno anno, int quantita)
{
    giorno->numero+=quantita;
    int gMax = getGiorni(*mese);
    while(gMax < giorno->numero)
    {
        incrementaMese(mese, anno, 1);
        giorno->numero-=gMax;
        gMax = getGiorni(*mese);
    }
}

void liberaGiorno(Giorno giorno)
{
    free(giorno);
}
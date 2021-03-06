#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "anno.h"

struct anno_s
{
    int numero;
};

void setAnno(Anno* anno, int a)
{
    *anno = malloc(sizeof(struct anno_s));

    (*anno)->numero = a;
}

void stampaAnno(Anno anno)
{
    printf("%d", anno->numero);
}

void incrementaAnno(Anno anno, int quantita)
{
    anno->numero+=quantita;
}

void liberaAnno(Anno anno)
{
    free(anno);
}
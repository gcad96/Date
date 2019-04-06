#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "anno.h"
#include "mese.h"
#include "giorno.h"
#include "data.h"

#define MESI 12

#define L 20

typedef struct data_s
{
    Anno anno;
    Mese mese;
    Giorno giorno;
}* Data;

Data data;


void enableData()
{
    data = malloc(sizeof(struct data_s));

    setMesi();
}

void initData(char* str)
{
    int a, m, g;

    sscanf(str, "%d/%d/%d", &g, &m, &a);

    setAnno(&(data->anno), a);
    setMese(&(data->mese), m);
    setGiorno(&data->giorno, g);
}

void stampaData()
{
    stampaGiorno(data->giorno);
    printf(" ");
    stampaMese(data->mese);
    printf(" ");
    stampaAnno(data->anno);
    printf(" ");
}

void incrementaData(char* str)
{
    int quantita;
    char entita[L];

    sscanf(str, "%d %s", &quantita, entita);

    if( (strcmp(entita, "giorno")==0) || (strcmp(entita, "giorni")==0) )
    {
        incrementaGiorno(data->giorno, &(data->mese), data->anno, quantita);
    }

    if( (strcmp(entita, "mese")==0) || (strcmp(entita, "mesi")==0) )
    {
        incrementaMese(&(data->mese), data->anno, quantita);
    }

    if( (strcmp(entita, "anno")==0) || (strcmp(entita, "anni")==0) )
    {
        incrementaAnno(data->anno, quantita);
    }
}

void disableData()
{
    liberaAnno(data->anno);
    liberaGiorno(data->giorno);

    free(data);

    liberaMesi();
}



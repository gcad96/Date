#include <stdio.h>
#include <stdlib.h>
#include "data.h"


int main() 
{
    enableData();
    initData("gg/mm/aaaa");

    stampaData();
    printf("\n");

    incrementaData("x giorni");
    stampaData();
    disableData();

    return 0;
}
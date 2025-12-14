#include "../include/tp4.h"
#include <stdlib.h>
#include <stdio.h>

T_Index * initIndex() {
    T_Index * index;
    index = (T_Index*) malloc(sizeof(T_Index));
    index->racine = NULL;
    index->nbMotsDistincts = 0;
    index->nbMotsTotaux = 0;

    return index;
}
#include "../include/tp4.h"
#include <stdlib.h>
#include <stdio.h>
T_Index* initIndex(void) {
    T_Index* index = malloc(sizeof(T_Index));
    if (!index) return NULL;
    index->racine = NULL;
    index->nbMotsDistincts = 0;
    index->nbMotsTotaux = 0;
    return index;
}
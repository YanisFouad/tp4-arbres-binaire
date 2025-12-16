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
void freeIndex (T_Index * index){
    if (index == NULL) return ;
    freeNoeud (index->racine) ;
    free (index) ;  
}
void freeNoeud (T_Noeud * noeud){
    if (noeud == NULL) return ;
    freeNoeud (noeud->filsGauche) ;
    freeNoeud (noeud->filsDroit) ;

    
    T_Position * pos = noeud->listePositions ;
    while (pos != NULL){
        T_Position * temp = pos ;
        pos = pos->suivant ;
        free (temp) ;
    }

    free(noeud->mot);

    free (noeud) ;
}
#include "../include/tp4.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Initialise un nouvel index vide
 * @return Pointeur vers l'index créé, NULL en cas d'erreur d'allocation
 */
T_Index* initIndex(void) {
    T_Index* index = malloc(sizeof(T_Index));
    if (!index) return NULL;
    index->racine = NULL;
    index->nbMotsDistincts = 0;
    index->nbMotsTotaux = 0;
    return index;
}

/**
 * @brief Libère toute la mémoire d'un index
 * @details Libère récursivement tous les noeuds de l'arbre et leurs listes de positions
 * @param index Pointeur vers l'index à libérer
 */
void freeIndex(T_Index* index) {
    if (index == NULL) return;
    freeNoeud(index->racine);
    free(index);
}

/**
 * @brief Libère récursivement un noeud et tous ses descendants
 * @details Parcours post-ordre pour libérer les fils avant le père.
 *          Libère aussi la liste de positions et le mot associé.
 * @param noeud Noeud à libérer
 */
void freeNoeud(T_Noeud* noeud) {
    if (noeud == NULL) return;
    freeNoeud(noeud->filsGauche);
    freeNoeud(noeud->filsDroit);

    T_Position* pos = noeud->listePositions;
    while (pos != NULL) {
        T_Position* temp = pos;
        pos = pos->suivant;
        free(temp);
    }

    free(noeud->mot);

    free(noeud);
}
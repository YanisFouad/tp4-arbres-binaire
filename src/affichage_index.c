#include "../include/tp4.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void afficherIndex(T_Index index) {
    T_Noeud* current = index.racine;
    char lastletter = '\0';
    parcoursInfixeAffichage(current, &lastletter);
}

void parcoursInfixeAffichage(T_Noeud* noeud, char* lastletter) {
    if (noeud == NULL) {
        return;
    }

    parcoursInfixeAffichage(noeud->filsGauche, lastletter);
    affichageSpe(noeud, lastletter);
    parcoursInfixeAffichage(noeud->filsDroit, lastletter);
}

void affichageSpe(T_Noeud* noeud, char* lastletter) {
    if (noeud == NULL) {
        return;
    }

    char currentLetter = toupper(noeud->mot[0]);

    /* Affichage de la lettre si changement */
    if (*lastletter == '\0' || *lastletter != currentLetter) {
        printf("\n%c\n", currentLetter);
        *lastletter = currentLetter;
    }

    /* Affichage du mot */
    printf("|-- %s\n", noeud->mot);

    /* Affichage de toutes les positions */
    for (T_Position* pos = noeud->listePositions; pos != NULL; pos = pos->suivant) {
        printf("|---- (l:%d, o:%d, p:%d)\n", pos->numeroLigne, pos->ordre, pos->numeroPhrase);
    }
    printf("|\n");
}

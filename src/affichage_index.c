#include "../include/tp4.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/**
 * @brief Affiche l'index complet des mots
 * @details Affiche tous les mots triés alphabétiquement avec leurs positions
 * @param index Index à afficher
 */
void afficherIndex(T_Index index) {
    T_Noeud* current = index.racine;
    char lastletter = '\0';
    parcoursInfixeAffichage(current, &lastletter);
}

/**
 * @brief Parcours infixe de l'arbre pour affichage alphabétique
 * @param noeud Noeud actuel
 * @param lastletter Dernière lettre affichée (pour regrouper par lettre)
 */
void parcoursInfixeAffichage(T_Noeud* noeud, char* lastletter) {
    if (noeud == NULL) {
        return;
    }

    parcoursInfixeAffichage(noeud->filsGauche, lastletter);
    affichageSpe(noeud, lastletter);
    parcoursInfixeAffichage(noeud->filsDroit, lastletter);
}

/**
 * @brief Affiche un noeud avec toutes ses positions
 * @details Affiche la première lettre si elle change, puis le mot et ses positions
 * @param noeud Noeud à afficher
 * @param lastletter Dernière lettre affichée
 */
void affichageSpe(T_Noeud* noeud, char* lastletter) {
    if (noeud == NULL) {
        return;
    }

    char currentLetter = toupper(noeud->mot[0]);

    // Affichage de la lettre si changement
    if (*lastletter == '\0' || *lastletter != currentLetter) {
        printf("\n%c\n", currentLetter);
        *lastletter = currentLetter;
    }

    // Affichage du mot
    printf("|-- %s\n", noeud->mot);

    // Affichage de toutes les positions
    for (T_Position* pos = noeud->listePositions; pos != NULL; pos = pos->suivant) {
        printf("|---- (l:%d, o:%d, p:%d)\n", pos->numeroLigne, pos->ordre, pos->numeroPhrase);
    }
    printf("|\n");
}

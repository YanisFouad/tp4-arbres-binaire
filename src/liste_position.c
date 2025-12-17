#include "../include/tp4.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Crée une nouvelle position
 * @param ligne Numéro de ligne dans le fichier
 * @param ordre Position du mot dans la phrase (commence à 1)
 * @param phrase Numéro de la phrase dans la ligne
 * @return Pointeur vers la nouvelle position créée
 */
T_Position* creerPosition(int ligne, int ordre, int phrase) {
    T_Position* position = (T_Position*) malloc(sizeof(T_Position));

    position->numeroLigne = ligne;
    position->ordre = ordre;
    position->numeroPhrase = phrase;
    position->suivant = NULL;

    return position;
}

/**
 * @brief Ajoute une position dans une liste triée
 * @details La liste est triée par ligne puis par ordre.
 *          Évite les doublons (mêmes ligne, ordre et phrase).
 * @param listeP Liste existante (peut être NULL)
 * @param ligne Numéro de ligne
 * @param ordre Position dans la phrase
 * @param phrase Numéro de la phrase
 * @return Pointeur vers la tête de la liste mise à jour
 */
T_Position* ajouterPosition(T_Position* listeP, int ligne, int ordre, int phrase) {
    T_Position* position = creerPosition(ligne, ordre, phrase);

    if (listeP == NULL) {
        return position;
    }

    // Insertion en tête
    if (ligne < listeP->numeroLigne ||
        (ligne == listeP->numeroLigne && ordre < listeP->ordre)) {
        position->suivant = listeP;
        return position;
    }

    // Évite les doublons en tête
    if (listeP->numeroLigne == ligne && listeP->ordre == ordre && listeP->numeroPhrase == phrase) {
        free(position);
        return listeP;
    }

    T_Position* current = listeP;

    while (current->suivant != NULL) {
        T_Position* suivant = current->suivant;
        // Évite les doublons
        if (suivant->numeroLigne == ligne && suivant->ordre == ordre && suivant->numeroPhrase == phrase) {
            free(position);
            return listeP;
        }

        // Recherche de la bonne position d'insertion
        if (ligne < suivant->numeroLigne || (ligne == suivant->numeroLigne && ordre < suivant->ordre)) {
            position->suivant = suivant;
            current->suivant = position;
            return listeP;
        }

        current = suivant;
    }

    current->suivant = position;
    return listeP;
}
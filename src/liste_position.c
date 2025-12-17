#include "../include/tp4.h"
#include <stdlib.h>
#include <stdio.h>

T_Position* creerPosition(int ligne, int ordre, int phrase) {
    T_Position* position = (T_Position*) malloc(sizeof(T_Position));

    position->numeroLigne = ligne;
    position->ordre = ordre;
    position->numeroPhrase = phrase;
    position->suivant = NULL;

    return position;
}

T_Position* ajouterPosition(T_Position* listeP, int ligne, int ordre, int phrase) {
    T_Position* position = creerPosition(ligne, ordre, phrase);

    if (listeP == NULL) {
        return position;
    } else {
        T_Position* current = listeP;
        T_Position* suivant = current->suivant;

        while (current->suivant != NULL) {
            if (current->numeroLigne == ligne && current->ordre == ordre && current->numeroPhrase == phrase) {
                printf("Impossible d'insérer la posistion, elle est déjà présente dans la liste\n");
                free(position);

                return listeP;
            }

            if ((current->numeroLigne < ligne && ligne < suivant->numeroLigne) && (current->ordre < ordre && ordre < suivant->ordre)) {

            }

            current = current->suivant;
            suivant = current->suivant;
        }

        current->suivant = position;

        return listeP;
    }
}
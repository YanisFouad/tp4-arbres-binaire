#include "../include/tp4.h"
#include <stdlib.h>
#include <stdio.h>


T_Noeud* rechercherMot(T_Index index, char* mot) {
    T_Noeud* current = index.racine;
    while (current != NULL) {
        int cmp = compareMot(mot, current->mot);
        if (cmp == 0) {
            return current;  
        } else if (cmp < 0) {
            current = current->filsGauche;
        } else {
            current = current->filsDroit;
        }
    }
    return NULL; 
}

void construireTexte(T_Index index, char* filename) {
    char * phrases [255][255] = {NULL};
    int lignesPhrase[255];
    for (int i = 0; i < 255; i++) {
        lignesPhrase[i] = -1;
    }
 
    parcoursInfixeConstruction(index.racine,phrases,lignesPhrase);

    //printf("Construction du texte dans le fichier %s\n", filename);

    FILE* f = fopen(filename, "w");
    if (f == NULL) {
        perror("fopen");
        printf("Impossible de créer le fichier : %s\n", filename);
        return;
    }
    int currentLine = -1;

    for (int p = 0; p < 255; p++) {

        if (lignesPhrase[p] == -1) {
            continue;  // aucune phrase ici
        }

        /* saut de ligne uniquement si la ligne change */
        if (currentLine != -1 && lignesPhrase[p] != currentLine) {
            fprintf(f, "\n");
        }
        currentLine = lignesPhrase[p];

        int first = 1;

        for (int o = 0; o < 255; o++) {
            if (phrases[p][o] != NULL) {
                if (!first) {
                    fprintf(f, " ");
                }
                fprintf(f, "%s", phrases[p][o]);
                first = 0;
            }
        }

        if (!first) {
            fprintf(f, ". ");
        }
    }
    fprintf(f, "\n");
    fclose(f);
}


void parcoursInfixeConstruction(T_Noeud* noeud, char* phrases[255][255],int lignesPhrase[255]) {
     if (noeud == NULL) {
        return;
    }

    parcoursInfixeConstruction(noeud->filsGauche, phrases, lignesPhrase);

    /* Place toutes les occurrences du mot dans le tableau */
   for (T_Position* pos = noeud->listePositions; pos != NULL; pos = pos->suivant) {
    if (pos->numeroPhrase >= 0 && pos->numeroPhrase < 255 && pos->ordre >= 0 && pos->ordre < 255) {
        phrases[pos->numeroPhrase][pos->ordre] = noeud->mot;
        //printf("phrases[%d][%d] = %s\n", pos->numeroPhrase, pos->ordre, noeud->mot);
        lignesPhrase[pos->numeroPhrase] = pos->numeroLigne;
    }

}

    parcoursInfixeConstruction(noeud->filsDroit, phrases, lignesPhrase);
}


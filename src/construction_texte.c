#include "../include/tp4.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

/**
 * @brief Recherche un mot dans l'arbre binaire de recherche
 * @param index Index contenant l'arbre de mots
 * @param mot Mot à rechercher (insensible à la casse)
 * @return Pointeur vers le noeud contenant le mot, NULL si non trouvé
 */
T_Noeud* rechercherMot(T_Index index, char* mot) {
    T_Noeud* current = index.racine;
    while (current != NULL) {
        int cmp = strcasecmp(mot, current->mot);
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

/**
 * @brief Reconstruit le texte original à partir de l'index et l'écrit dans un fichier
 * @details Collecte les occurrences (O(m)), trie (O(m log m)), puis écrit (O(m))
 *          Complexité totale: O(m log m)
 * @param index Index contenant tous les mots et leurs positions
 * @param filename Chemin du fichier de sortie
 */
void construireTexte(T_Index index, char* filename) {
    // Collecter et trier toutes les occurrences
    T_ListeOccurrences* liste = creerListeOccurrences();
    collecterOccurrences(index.racine, liste);
    trierOccurrences(liste);

    // Ouverture du fichier
    FILE* f = fopen(filename, "w");
    if (f == NULL) {
        perror("fopen");
        printf("Impossible de créer le fichier : %s\n", filename);
        libererListeOccurrences(liste);
        return;
    }

    int currentLine = liste->occurrences[0].ligne;
    int currentPhrase = liste->occurrences[0].phrase;
    int isFirstWord = 1;

    // Écriture séquentielle - O(m)
    for (int i = 0; i < liste->nbOccurrences; i++) {
        T_Occurrence* occ = &liste->occurrences[i];

        // Nouvelle ligne
        if (occ->ligne != currentLine) {
            fprintf(f, ".\n");
            currentLine = occ->ligne;
            currentPhrase = occ->phrase;
            fprintf(f, "%s", occ->mot);
            isFirstWord = 0;
        }
        // Nouvelle phrase sur la même ligne
        else if (occ->phrase != currentPhrase) {
            fprintf(f, ". %s", occ->mot);
            currentPhrase = occ->phrase;
            isFirstWord = 0;
        }
        // Espace entre les mots
        else {
            if (isFirstWord) {
                fprintf(f, "%s", occ->mot);
                isFirstWord = 0;
            } else {
                fprintf(f, " %s", occ->mot);
            }
        }
    }

    fprintf(f, ".\n");
    fclose(f);
    libererListeOccurrences(liste);
}



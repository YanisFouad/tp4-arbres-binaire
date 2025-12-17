#include "../include/tp4.h"
#include <stdlib.h>
#include <stdio.h>  
#include <string.h>

/**
 * @brief Ajoute une occurrence d'un mot dans l'index
 * @details Si le mot existe déjà, ajoute la position à sa liste.
 *          Sinon, crée un nouveau noeud dans l'arbre binaire de recherche.
 * @param index Pointeur vers l'index à mettre à jour
 * @param mot Mot à ajouter (sera copié)
 * @param ligne Numéro de ligne du mot
 * @param ordre Position du mot dans la phrase
 * @param phrase Numéro de la phrase
 * @return 0 en cas de succès, -1 en cas d'erreur d'allocation
 */
int ajouterOccurence(T_Index* index, char* mot, int ligne, int ordre, int phrase) {
    T_Noeud* current = index->racine;
    T_Noeud* suivant = NULL;
    T_Noeud* nouveauNoeud = NULL;
    int compare = 10;

    if (current == NULL) { // arbre vide
        nouveauNoeud = (T_Noeud*) malloc(sizeof(T_Noeud));
        index->racine = nouveauNoeud;
        nouveauNoeud->mot = malloc((strlen(mot) + 1) * sizeof(char));
        strcpy(nouveauNoeud->mot, mot); // sinon nouveauNoeud->mot = mot ; // Nouveau noeud pointe vers la meme adresse que mot alors que  mot peut changer apres
        nouveauNoeud->nbOccurrences = 1;
        nouveauNoeud->listePositions = creerPosition(ligne, ordre, phrase);
        index->nbMotsTotaux += 1;
        index->nbMotsDistincts += 1;
        nouveauNoeud->filsDroit = NULL;
        nouveauNoeud->filsGauche = NULL;
        return 0;
    }

    while (current != NULL) {
        suivant = current;
        compare = strcasecmp(mot, current->mot);
        if (compare < 0) { // peut etre remplacer par strcmp(mot,current->mot)
            current = current->filsGauche;
        } else if (compare > 0) { //
            current = current->filsDroit;
        } else if (compare == 0) { // le mot est deja present dans l'arbre
            current->nbOccurrences += 1;
            current->listePositions = ajouterPosition(current->listePositions, ligne, ordre, phrase);
            index->nbMotsTotaux += 1;
            return 0;
        }

    }
    nouveauNoeud = (T_Noeud*) malloc(sizeof(T_Noeud));
    if (nouveauNoeud == NULL) {
        printf("Erreur d'allocation memoire\n");
        return -1;
    }

    if (compare < 0) {
        suivant->filsGauche = nouveauNoeud;
    } else if (compare > 0) {
        suivant->filsDroit = nouveauNoeud;
    }
    nouveauNoeud->mot = malloc((strlen(mot) + 1) * sizeof(char));
    strcpy(nouveauNoeud->mot, mot); // sinon nouveauNoeud->mot = mot ; // Nouveau noeud pointe vers la meme adresse que mot alors que  mot peut changer apres
    nouveauNoeud->nbOccurrences = 1;
    nouveauNoeud->listePositions = creerPosition(ligne, ordre, phrase);
    index->nbMotsTotaux += 1;
    index->nbMotsDistincts += 1;
    nouveauNoeud->filsDroit = NULL;
    nouveauNoeud->filsGauche = NULL;
    return 0;
}

/**
 * @brief Affiche toutes les occurrences d'un mot avec leur contexte (phrase complète)
 * @details Pour chaque occurrence, affiche la ligne, la position et la phrase entière
 *          dans laquelle le mot apparaît.
 * @param index Index contenant les mots
 * @param mot Mot dont on veut afficher les occurrences
 */
void afficherOccurencesMot(T_Index index, char* mot) {
    T_Noeud* node = rechercherMot(index, mot);

    if (node == NULL) {
        printf("Le mot '%s' n'est pas present dans l'index.\n\n", mot);
        return;
    }

    printf("Mot = \"%s\"\n", mot);
    printf("Occurences = %d\n\n", node->nbOccurrences);

    // Collecter et trier toutes les occurrences
    T_ListeOccurrences* liste = creerListeOccurrences();
    collecterOccurrences(index.racine, liste);
    trierOccurrences(liste);

    // Afficher chaque occurrence avec sa phrase
    for (T_Position* pos = node->listePositions; pos != NULL; pos = pos->suivant) {
        printf("| Ligne %d, mot %d : ", pos->numeroLigne + 1, pos->ordre);

        // Parcourir le tableau trié pour afficher la phrase - O(m) dans le pire cas
        int firstWord = 1;
        for (int i = 0; i < liste->nbOccurrences; i++) {
            T_Occurrence* occ = &liste->occurrences[i];
            if (occ->ligne == pos->numeroLigne && occ->phrase == pos->numeroPhrase) {
                if (!firstWord) {
                    printf(" ");
                }
                printf("%s", occ->mot);
                firstWord = 0;
            }
        }
        printf(".\n");
    }

    printf("\n");
    libererListeOccurrences(liste);
}
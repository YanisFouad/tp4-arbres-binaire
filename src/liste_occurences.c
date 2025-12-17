#include "../include/tp4.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Crée une nouvelle liste d'occurrences
 * @return Pointeur vers la liste créée, NULL en cas d'erreur
 */
T_ListeOccurrences* creerListeOccurrences() {
    T_ListeOccurrences* liste = (T_ListeOccurrences*) malloc(sizeof(T_ListeOccurrences));
    if (liste == NULL) return NULL;

    liste->occurrences = NULL;
    liste->nbOccurrences = 0;
    liste->capacite = 0;
    return liste;
}

/**
 * @brief Ajoute une occurrence dans le tableau dynamique
 * @details Le tableau double de taille quand il est plein
 * @param liste Liste d'occurrences
 * @param ligne Numéro de ligne dans le fichier
 * @param ordre Position du mot dans la phrase
 * @param phrase Numéro de la phrase
 * @param mot Pointeur vers le mot
 */
void ajouterOccurenceListe(T_ListeOccurrences* liste, int ligne, int ordre, int phrase, char* mot) {
    if (liste == NULL) return;

    // Réallocation si nécessaire
    if (liste->nbOccurrences >= liste->capacite) {
        liste->capacite = (liste->capacite == 0) ? CAPACITE_INITIALE_LISTE : liste->capacite * 2;
        liste->occurrences = realloc(liste->occurrences, liste->capacite * sizeof(T_Occurrence));
        if (liste->occurrences == NULL) {
            printf("Erreur d'allocation mémoire lors de l'ajout d'une occurrence.\n");
            liste->nbOccurrences = 0;
            liste->capacite = 0;
            return;
        }
    }

    liste->occurrences[liste->nbOccurrences].ligne = ligne;
    liste->occurrences[liste->nbOccurrences].phrase = phrase;
    liste->occurrences[liste->nbOccurrences].ordre = ordre;
    liste->occurrences[liste->nbOccurrences].mot = mot;
    liste->nbOccurrences++;
}

/**
 * @brief Fonction de comparaison pour qsort
 * @details Trie par ligne, puis phrase, puis ordre
 */
static int comparerOccurrences(const void* a, const void* b) {
    const T_Occurrence* oa = (const T_Occurrence*) a;
    const T_Occurrence* ob = (const T_Occurrence*) b;

    if (oa->ligne != ob->ligne) return oa->ligne - ob->ligne;
    if (oa->phrase != ob->phrase) return oa->phrase - ob->phrase;
    return oa->ordre - ob->ordre;
}

/**
 * @brief Trie les occurrence
 * @param liste Liste à trier
 */
void trierOccurrences(T_ListeOccurrences* liste) {
    if (liste == NULL || liste->nbOccurrences == 0) return;
    qsort(liste->occurrences, liste->nbOccurrences, sizeof(T_Occurrence), comparerOccurrences);
}

/**
 * @brief Parcourt l'arbre et collecte toutes les occurrences
 * @details Parcours infixe de l'arbre
 * @param noeud Noeud actuel de l'arbre
 * @param liste Liste où ajouter les occurrences
 */
void collecterOccurrences(T_Noeud* noeud, T_ListeOccurrences* liste) {
    if (noeud == NULL) return;

    collecterOccurrences(noeud->filsGauche, liste);

    // Ajouter toutes les occurrences du mot
    for (T_Position* pos = noeud->listePositions; pos != NULL; pos = pos->suivant) {
        ajouterOccurenceListe(liste, pos->numeroLigne, pos->ordre, pos->numeroPhrase, noeud->mot);
    }

    collecterOccurrences(noeud->filsDroit, liste);
}

/**
 * @brief Libère toute la mémoire d'une liste d'occurrences
 * @param liste Liste à libérer
 */
void libererListeOccurrences(T_ListeOccurrences* liste) {
    if (liste == NULL) return;
    free(liste->occurrences);
    free(liste);
}

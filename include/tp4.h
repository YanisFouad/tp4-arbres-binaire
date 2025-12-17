#ifndef TP4_H
#define TP4_H

#define FILE_READING_BUFFER 255
#define WORD_SPLIT_BUFFER 255
#define MAX_SENTENCES 255
#define MAX_WORDS_PER_SENTENCE 255
#define SENTENCE_BUFFER_MIN 128
#define SENTENCE_BUFFER_MAX 2048
#define CAPACITE_INITIALE_LISTE 64

typedef struct Position {
    int numeroLigne;
    int ordre;
    int numeroPhrase;
    struct Position* suivant;
} T_Position;

typedef struct Noeud {
    char* mot;
    int nbOccurrences;
    T_Position* listePositions;
    struct Noeud* filsGauche;
    struct Noeud* filsDroit;
} T_Noeud;

typedef struct T_index {
    T_Noeud* racine;
    int nbMotsDistincts;
    int nbMotsTotaux;
}T_Index;

typedef struct Occurrence {
    int ligne;
    int phrase;
    int ordre;
    char* mot;
} T_Occurrence;

typedef struct ListeOccurrences {
    T_Occurrence* occurrences;
    int nbOccurrences;
    int capacite;
} T_ListeOccurrences;

/*Fonctions demandées dans le TP*/
T_Position* ajouterPosition(T_Position* listeP, int ligne, int ordre, int phrase);
int ajouterOccurence(T_Index* index, char* mot, int ligne, int ordre, int phrase);
int indexerFichier(T_Index* index, char* filename);
void afficherIndex(T_Index index);
T_Noeud* rechercherMot(T_Index index, char* mot);
void afficherOccurencesMot(T_Index index, char* mot);
void construireTexte(T_Index index, char* filename);

/*Fonctions utilitaires*/
T_Position* creerPosition(int ligne, int ordre, int phrase);
char* split_first_word(char* to_split, char split_char);
void parcoursInfixeAffichage(T_Noeud* noeud, char* lastletter);
void affichageSpe(T_Noeud* noeud, char* lastletter);
T_Index* initIndex();
void freeIndex(T_Index* index);
void freeNoeud(T_Noeud* noeud);
void clear_terminal_output();

/*Fonctions pour liste_mots*/
T_ListeOccurrences* creerListeOccurrences();
void ajouterOccurenceListe(T_ListeOccurrences* liste, int ligne, int ordre, int phrase, char* mot);
void collecterOccurrences(T_Noeud* noeud, T_ListeOccurrences* liste);
void trierOccurrences(T_ListeOccurrences* liste);
void libererListeOccurrences(T_ListeOccurrences* liste);

#endif /* TP4_H */

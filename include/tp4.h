#ifndef TP4_H
#define TP4_H

#define FILE_READING_BUFFER 255
#define WORD_SPLIT_BUFFER 255

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

T_Position* ajouterPosition(T_Position* listeP, int ligne, int ordre, int phrase);
T_Position* creerPosition(int ligne, int ordre, int phrase);
char* split_first_word(char* to_split, char split_char);
int ajouterOccurence(T_Index* index, char* mot, int ligne, int ordre, int phrase);
int indexerFichier(T_Index* index, char* filename);
void afficherIndex(T_Index index);
void parcoursInfixeAffichage(T_Noeud* noeud, char * lastletter);
void parcoursInfixeConstruction(T_Noeud* noeud, char* phrases[255][255],int lignesPhrase[255]);
void affichageSpe(T_Noeud* noeud,char * lastletter);
T_Noeud* rechercherMot(T_Index index, char* mot);
void afficherOccurencesMot(T_Index index, char* mot);
void construireTexte(T_Index index, char* filename);

T_Index * initIndex();

int compareMot(char* mot1, char* mot2);

#endif /* TP4_H */
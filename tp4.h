#ifndef TP4_H
#define TP4_H
typedef struct Position {
    int numeroLigne;
    int ordre; 
    int numeroPhrase;
    struct Position* suivant
}T_Position;
typedef struct Noeud {
    char* mot ; 
    int nbOccurrences ;
    T_Position* listePositions ;
    struct Noeud* filsGauche ;
    struct Noeud* filsDroit ;
}T_Noeud; 

typedef struct T_index{
    T_Noeud* racine ;
    int nbMotsDistincts ;
    int nbMotsTotaux ;
}T_Index;

T_Position *ajouterPosition(T_Position *listeP, int ligne, int ordre, int phrase);
int ajouterOccurence(T_Index *index, char *mot, int ligne, int ordre, int phrase);
int indexerFichier(T_Index *index, char *filename);
void afficherIndex(T_Index index);
T_Noeud* rechercherMot(T_Index index, char *mot);
void afficherOccurencesMot(T_Index index, char *mot);
void construireTexte(T_Index index, char *filename);

#endif /* TP4_H */
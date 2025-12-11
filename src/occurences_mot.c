#include "../include/tp4.h"

int ajouterOccurence(T_Index *index, char *mot, int ligne, int ordre, int phrase) {
    T_Noeud *current = index->racine;
    T_Noeud * suivant = NULL;

    while(current != NULL){
        suivant = current ; 
        if (compareMot ==-1){ // peut etre remplacer par strcmp(mot,current->mot)
            current = current->filsGauche ;
        }
        else if (compareMot ==1){ //
            current = current->filsDroit ;
        }
        else { // le mot est deja present dans l'arbre
            current->nbOccurrences += 1 ;
            current->listePositions = ajouterPosition(current->listePositions, ligne, ordre, phrase);
            index->nbMotsTotaux += 1 ;
            return 0;
        }
        
    }


    return 0;
}
#include "../include/tp4.h"
#include <stdlib.h>
#include <stdio.h>  
#include <string.h>


int ajouterOccurence(T_Index *index, char *mot, int ligne, int ordre, int phrase) {
    T_Noeud *current = index->racine;
    T_Noeud * suivant = NULL;
    T_Noeud * nouveauNoeud = NULL ;
    int compare = 10  ;

    if(current == NULL){ // arbre vide
        nouveauNoeud = (T_Noeud *) malloc (sizeof (T_Noeud)) ;
        index->racine = nouveauNoeud ;
        nouveauNoeud->mot = malloc((strlen(mot)+1)*sizeof(char)) ;
        strcpy(nouveauNoeud->mot, mot) ; // sinon nouveauNoeud->mot = mot ; // Nouveau noeud pointe vers la meme adresse que mot alors que  mot peut changer apres
        nouveauNoeud->nbOccurrences = 1 ;
        nouveauNoeud->listePositions = creerPosition (ligne, ordre, phrase);
        index->nbMotsTotaux += 1 ;
        index->nbMotsDistincts += 1 ;
        nouveauNoeud->filsDroit = NULL ;
        nouveauNoeud->filsGauche = NULL ;
        return 0 ;
    }

    while(current != NULL){
        suivant = current ; 
        compare = strcasecmp(mot, current->mot) ;
        if (compare <0){ // peut etre remplacer par strcmp(mot,current->mot)
            current = current->filsGauche ;
        }
        else if (compare >0){ //
            current = current->filsDroit ;
        }
        else if(compare == 0) { // le mot est deja present dans l'arbre
            current->nbOccurrences += 1 ;
            current->listePositions = ajouterPosition(current->listePositions, ligne, ordre, phrase);
            index->nbMotsTotaux += 1 ;
            return 0;
        }
        
    }
    nouveauNoeud = (T_Noeud *) malloc (sizeof (T_Noeud)) ;
    if(nouveauNoeud == NULL){
        printf("Erreur d'allocation memoire\n");
        return -1 ;
    }

    if (compare < 0){
        suivant->filsGauche = nouveauNoeud ;
    }else if (compare >0){
        suivant->filsDroit = nouveauNoeud ;
    }
    nouveauNoeud->mot = malloc((strlen(mot)+1)*sizeof(char)) ;
    strcpy(nouveauNoeud->mot, mot) ; // sinon nouveauNoeud->mot = mot ; // Nouveau noeud pointe vers la meme adresse que mot alors que  mot peut changer apres
    nouveauNoeud->nbOccurrences = 1 ;
    nouveauNoeud->listePositions = creerPosition (ligne, ordre, phrase);
    index->nbMotsTotaux += 1 ;
    index->nbMotsDistincts += 1 ;
    nouveauNoeud->filsDroit = NULL ;
    nouveauNoeud->filsGauche = NULL ;
    return 0;
}

void afficherOccurencesMot(T_Index index, char* mot){
    
}
#include "stdio.h"
#include "stdlib.h"
#include "../include/tp4.h"

// int main()
// {
//     T_Index *index;
//     index = initIndex();
//     indexerFichier(index, "FileTest/sample.txt");
//     afficherIndex(*index);
//     printf(" Construction texte\n\n");
//     construireTexte(*index, "FileTest/output.txt");
//     printf("Texte construit dans FileTest/output.txt\n");
//     return 0;

// }
int main(){
    T_Index *index = initIndex();
    int choix = 0 ;

    printf("Bienvenue dans le programme d'indexation de texte !\n");
    printf("Veuillez choisir une option :\n");
    printf("1. Charger un fichier \n");
    printf("2. Afficher les caractèrisqtiques de l'index\n");
    printf("3. Afficher l'index \n");
    printf("4. Rechercher un mot\n");
    printf("5. Afficher les occurrences d'un mot\n");
    printf("6. Constuire le texte à partir de l'index\n");
    printf("7. Quitter\n");
    do{
        printf("Votre choix : ");
        scanf("%d", &choix);
        if (choix <1 || choix >7){
            printf("Choix invalide. Veuillez réessayer.\n");
            continue;
        }
        switch(choix){
            case 1:{
                char filename[100];
                printf("Entrez le nom du fichier à charger : ");
                scanf("%s", filename);
                /*Necessaire Au second chargement*/
                freeIndex(index);
                index = initIndex();

                indexerFichier(index, filename);
                break;
            }
            case 2:{
                printf("Nombre de mots distincts : %d\n", index->nbMotsDistincts);
                printf("Nombre total de mots : %d\n", index->nbMotsTotaux);
                break;
            }
            case 3:{
                afficherIndex(*index);
                break;
            }
            case 4:{
                char mot[100];
                printf("Entrez le mot à rechercher : ");
                scanf("%s", mot);
                T_Noeud* noeud = rechercherMot(*index, mot);
                if(noeud != NULL){
                    printf("Le mot '%s' a été trouvé avec %d occurrences.\n", mot, noeud->nbOccurrences);
                }else{
                    printf("Le mot '%s' n'a pas été trouvé dans l'index.\n", mot);
                }
                break;
            }
            case 5:{
                char mot[255];
                printf("Entrez le mot pour afficher ses occurrences : ");
                scanf("%s", mot);
                afficherOccurencesMot(*index, mot);
                break;
            }
            case 6:{
                char filename[100];
                printf("Entrez le nom du fichier de sortie : ");
                scanf("%s", filename);
                construireTexte(*index, filename);
                printf("Texte construit dans %s\n", filename);
                break;
            }
            case 7:{
                freeIndex(index);
                printf("Au revoir !\n");
                break;
            }
            default:{
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
            }
        }

    }while(choix != 7);
    return 0;
}

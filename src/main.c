#include "stdio.h"
#include "stdlib.h"
#include "../include/tp4.h"

int main() {
    printf("Bienvenue dans le programme d'indexation de texte !\n");
    clear_terminal_output();
    T_Index* index = initIndex();
    char choix;

    do {
        printf("Veuillez choisir une option :\n");
        printf("1. Charger un fichier \n");
        printf("2. Afficher les caractèrisqtiques de l'index\n");
        printf("3. Afficher l'index \n");
        printf("4. Rechercher un mot\n");
        printf("5. Afficher les occurrences d'un mot\n");
        printf("6. Constuire le texte à partir de l'index\n");
        printf("7. Quitter\n");
        printf("\nVotre choix : ");
        scanf(" %c", &choix);

        switch (choix) {
        case '1': {
            clear_terminal_output();
            char filename[100];
            printf("Entrez le nom du fichier à charger : ");
            scanf("%s", filename);
            // Necessaire Au second chargement
            freeIndex(index);
            index = initIndex();

            indexerFichier(index, filename);
            break;
        }
        case '2': {
            clear_terminal_output();
            printf("Nombre de mots distincts : %d\n", index->nbMotsDistincts);
            printf("Nombre total de mots : %d\n\n", index->nbMotsTotaux);
            break;
        }
        case '3': {
            clear_terminal_output();
            afficherIndex(*index);
            break;
        }
        case '4': {
            clear_terminal_output();
            char mot[100];
            printf("Entrez le mot à rechercher : ");
            scanf("%s", mot);
            clear_terminal_output();
            T_Noeud* noeud = rechercherMot(*index, mot);
            if (noeud != NULL) {
                printf("Le mot '%s' a été trouvé avec %d occurrences.\n\n", mot, noeud->nbOccurrences);
            } else {
                printf("Le mot '%s' n'a pas été trouvé dans l'index.\n\n", mot);
            }
            break;
        }
        case '5': {
            clear_terminal_output();
            char mot[255];
            printf("Entrez le mot pour afficher ses occurrences : ");
            scanf("%s", mot);
            clear_terminal_output();
            afficherOccurencesMot(*index, mot);
            break;
        }
        case '6': {
            clear_terminal_output();
            char filename[100];
            printf("Entrez le nom du fichier de sortie : ");
            scanf("%s", filename);
            clear_terminal_output();
            construireTexte(*index, filename);
            printf("Texte construit dans %s\n", filename);
            break;
        }
        case '7':
            freeIndex(index);
            printf("Au revoir !\n");
            break;
        default: {
            printf("Choix invalide. Veuillez réessayer.\n");
            break;
        }
        }

    } while (choix != '7');
    return 0;
}

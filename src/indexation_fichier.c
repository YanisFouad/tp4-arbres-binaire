#include "../include/tp4.h"
#include <stdio.h>
#include <stdlib.h>

int indexerFichier(T_Index* index, char* filename) {
    FILE* file = fopen(filename, "r");
    int nb_mots = 0;
    int ligne = 1;
    int occurence;
    int position;

    char buffer[FILE_READING_BUFFER];

    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier : %s\n", filename);
        return -1;
    }

    while (fgets(buffer, FILE_READING_BUFFER, file)) {
        char* char_cursor = buffer;

        // On itères sur tous les caractères de la ligne
        while (*char_cursor != '\0' && *char_cursor != '\n') {
            // Sauter les espaces
            while (*char_cursor == ' ' || *char_cursor == '\t') {
                char_cursor++;
            }

            // Fin de la ligne
            if (*char_cursor == '\0' || *char_cursor == '\n') {
                break;
            }

            // Extraire le mot
            char* word = split_first_word(char_cursor, ' ');

            if (word != NULL) {
                occurence++;
                ajouterOccurence(index, word, ligne, occurence, 0);
                nb_mots++;

                // On avance le curseur jusqu'à la fin du mot extrait
                while (*char_cursor != ' ' && *char_cursor != '\0' && *char_cursor != '\n') {
                    char_cursor++;
                }

                free(word);
            } else {
                char_cursor++;
            }
        }
    }

    fclose(file);
    return nb_mots;
}
#include "../include/tp4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Indexe tous les mots d'un fichier texte
 * @details Lit le fichier caractère par caractère, découpe en phrases (délimitées par '.'),
 *          puis en mots (séparés par des espaces), et indexe chaque mot avec sa position.
 *          Gère dynamiquement la taille des buffers de phrases.
 * @param index Pointeur vers l'index à remplir
 * @param filename Chemin du fichier à indexer
 * @return Nombre total de mots indexés, -1 en cas d'erreur
 */
int indexerFichier(T_Index* index, char* filename) {
    FILE* file = fopen(filename, "r");
    int total_words = 0;
    int nb_lines = 0;
    int nb_sentences = 0;

    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier : %s\n", filename);
        return -1;
    }

    while (!feof(file) && !ferror(file)) {
        int allocated = SENTENCE_BUFFER_MIN;
        char* sentence = malloc(SENTENCE_BUFFER_MIN * sizeof(char));
        int nb_chars = 0;
        int nb_words = 0;
        char current_char;

        // On itère sur tous les caractères jusqu'à la fin de la phrase ou du fichier
        while (!feof(file) && !ferror(file)) {
            if (ferror(file)) {
                printf("Erreur lors de la lecture d'un caractère.\n");
                break;
            }

            current_char = fgetc(file);
            if (current_char == EOF || current_char == '.' || current_char == '\n') {
                if (current_char == '.' || current_char == EOF) {
                    nb_sentences++;
                }

                if (current_char == '\n') {
                    nb_lines++;
                }

                sentence[nb_chars] = '\0';
                break;
            } else {
                // Réallocation de mémoire
                if (nb_chars > allocated) {
                    printf("Réallocation de mémoire pour la phrase...\n");
                    if (allocated >= SENTENCE_BUFFER_MAX) {
                        printf("Taille maximale de la phrase atteinte.\n");
                        break;
                    } else {
                        allocated *= 2;
                        sentence = realloc(sentence, allocated * sizeof(char));
                    }
                }
                sentence[nb_chars] = current_char;
                nb_chars++;
            }
        }

        // Split de la phrase en mots
        char* str_token = strtok(sentence, " ");
        while (str_token != NULL) {
            nb_words++;
            total_words++;
            ajouterOccurence(index, str_token, nb_lines, nb_words, nb_sentences);
            str_token = strtok(NULL, " ");
        }

        if (current_char == '\n') {
            nb_sentences = 0;
        }

        nb_words = 0;
        free(sentence);
    }

    if (ferror(file)) {
        printf("Erreur lors de la lecture du fichier.\n");
        fclose(file);
        return -1;
    } else {
        printf("Fichier indexé avec succès !\n\n");
    }

    fclose(file);
    return total_words;
}

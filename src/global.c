#include "../include/tp4.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* split_first_word(char* to_split, char split_char) {
    if (to_split == NULL || *to_split == '\0') {
        return NULL;
    }

    // Sauter les caractères de séparation au début
    while (*to_split == split_char) {
        to_split++;
    }

    if (*to_split == '\0') {
        return NULL;
    }

    // Trouver la fin du mot
    int i = 0;
    while (to_split[i] != '\0' && to_split[i] != split_char && to_split[i] != '\n' && to_split[i] !='.' && i < WORD_SPLIT_BUFFER - 1) {
        i++;
    }

    if (i == 0) {
        return NULL;
    }

    // On copie le mot dans une nouvelle string
    char* word = (char*) malloc((i + 1) * sizeof(char));
    if(word == NULL) {
        printf("Erreur d'allocation memoire\n");
        return NULL;
    }

    for (int j = 0; j < i; j++) {
        
         word[j] = to_split[j];
    }


    word[i] = '\0';

    return word;
}

int compareMot(char *mot1, char*mot2) {
    int result = strcasecmp(mot1, mot2); // ignore case during comparison
    if (result < 0) {
        printf(" strcmp = %d ; Le mot '%s' est avant le mot '%s'\n",result, mot1, mot2);
    } else if (result > 0) {
        printf(" strcmp = %d ; Le mot '%s' est apres le mot '%s'\n",result, mot1, mot2);
    } else {
        printf(" strcmp = %d Le mot '%s' est egal au mot '%s'\n",result, mot1, mot2);
    }
    return result; 
}
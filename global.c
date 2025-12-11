#include "tp4.h"
#include "stdio.h"
#include "stdlib.h"

int compareMot(char *mot1, char*mot2) {
    char* tolowerMot1 = tolower(mot1);
    char* tolowerMot2 = tolower(mot2);

    int result = strcmp(tolowerMot1, tolowerMot2);

    if (result < 0) {
        printf(" strcmp = -1 ; Le mot '%s' est avant le mot '%s'\n", mot1, mot2);
    } else if (result > 0) {
        printf(" strcmp = 1 ; Le mot '%s' est apres le mot '%s'\n", mot1, mot2);
    } else {
        printf(" strcmp = 0 Le mot '%s' est egal au mot '%s'\n", mot1, mot2);
    }
    return result; 
}


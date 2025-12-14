#include "stdio.h"
#include "stdlib.h"
#include "../include/tp4.h"

int main()
{
    T_Index *index;
    index = initIndex();
    indexerFichier(index, "FileTest/sample.txt");
    afficherIndex(*index);
    printf(" Construction texte\n\n");
    construireTexte(*index, "FileTest/output.txt");
    printf("Texte construit dans FileTest/output.txt\n");
    return 0;

}

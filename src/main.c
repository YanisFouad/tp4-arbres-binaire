#include "stdio.h"
#include "stdlib.h"
#include "../include/tp4.h"

int main()
{
    T_Index *index;
    index = initIndex();
    indexerFichier(index, "FileTest/sample.txt");
    afficherIndex(*index);
    return 0;
}

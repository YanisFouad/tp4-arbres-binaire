#include "../include/tp4.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief Efface l'affichage du terminal
 * @details Utilise la commande système "clear" (Linux/Unix)
 */
void clear_terminal_output() {
    system("clear");
}
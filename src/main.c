/**
 * @file main.c
 *
 * @brief Ceci est le main, vive le main
 * @date 04/03/2019
 * @author Nathan Le Granvallet
 *
 * @copyright Nexelis
 */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "example/example.h"
#include <unistd.h>

/**
 * @brief Fonction principale du programme
 */
int main (void)
{

    ExampleNew();

    printf("Hello world !\n");
    return 0;

}
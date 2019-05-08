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

    Example * example = ExampleNew();
    ExampleStart(example);
    sleep(1);
    ExampleEventOne(example, 12);
    sleep(1);
    ExampleEventOne(example, 14);
    sleep(1);
    ExampleEventTwo(example, 1);
    sleep(1);
    ExampleEventTwo(example, 10);
    sleep(1);

    ExampleStop(example);
    sleep(1);
    ExampleFree(example);

    printf("Hello world !\n");
    return 0;

}
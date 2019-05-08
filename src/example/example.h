/**
 * @file example.h
 *
 * @brief Ceci est un example d'une classe active
 *
 * Ceci est un exemple d'une classe active.
 *
 * Vous pouvez copier/coller ceci pour créer votre classe active.
 *
 * Vous pouvez expliquer ici comment utiliser votre classe (préconditions, etc.)
 *
 * Le code est en anglais, la documentation en français.
 *
 * @date 02/05/2019
 * @author Thomas Cravic, Nathan Le Granvallet
 * @copyright Nexelis
 *
 */

#ifndef EXAMPLE_H
#define EXAMPLE_H

#include "../util.h"
#include <string.h>
#include <stdlib.h>
#include "mqueue.h"

/**
 * @brief Objet Example
 */
typedef struct Example_t Example;

/* ----------------------- PROTOTYPES DES FONCTIONS D'ÉVÉNEMENT -----------------------*/

/**
 * @brief Fonction appelant l'événment E_EXAMPLE1
 *
 * @param this Adresse d'un Example
 * @param param Paramètre à passer au Message
 */
extern void ExampleEventOne(Example * this, int param);

/**
 * @brief Fonction appelant l'événment E_EXAMPLE2
 *
 * @param this Adresse d'un Example
 * @param param Paramètre à passer au Message
 */
extern void ExampleEventTwo(Example * this, float param);

/* ----------------------- NEW START STOP FREE -----------------------*/

/**
 * @brief Constructeur d'un Example.
 *
 * @return Adresse d'un Example
 */
extern Example * ExampleNew();

/**
 * @brief Démarre un Example
 *
 * @param this Adresse d'un Example
 * @return 0 Si le démarrage s'est bien passé
 * @return 1 Sinon
 */
extern int ExampleStart(Example * this);

/**
 * @brief Stoppe un Example
 *
 * @param this Adresse d'un Example
 * @return 0 Si l'arrêt s'est bien passé
 * @return 1 Sinon
 */
extern int ExampleStop (Example * this);

/**
 * @brief Libère la mémoire un Example
 *
 * @param this Adresse d'un Example
 * @return 0 Si la libération s'est bien passée
 * @return 1 Sinon
 */
extern int ExampleFree (Example * this);

#endif //EXAMPLE_H
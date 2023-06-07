/**
 * @file pile.c
 * @brief fichier d'implementation pour la gestion de pile
 * Autor : BOURDIAUX Pierre - VILLETTE Tristan 
 * Date : 07/06/2023  			
 * _____  _____ _____ __  __                     _____ _   _ _____  
 * |_   _|/ ____|_   _|  \/  |   /\              |_   _| \ | |  __ \ 
 *   | | | (___   | | | \  / |  /  \     ______    | | |  \| | |__) |
 *   | |  \___ \  | | | |\/| | / /\ \   |______|   | | | . ` |  ___/ 
 *  _| |_ ____) |_| |_| |  | |/ ____ \            _| |_| |\  | |     
 * |_____|_____/|_____|_|  |_/_/    \_\          |_____|_| \_|_|     
 *                                                              
 *   _____ _____  _____   
 * / ____|  __ \|  __ \ 
 * | (___ | |  | | |  | |
 *  \___ \| |  | | |  | |
 *  ____) | |__| | |__| |
 * |_____/|_____/|_____/  
 */
 
#include <stdlib.h>
#include "pile.h"

// Placer ici les fonctions de gestion de pile que vous avez ecrit en TP2 

/** TO DO
 * @brief Initialiser une pile du type pile_t
 *   - allocation de memoire pour une structure pile_t et un tableau de taille elements
 * @param [in] taille taille de la pile
 * @return l'adresse de la structure
 */
pile_t*  initPile( int taille)
{
    pile_t *pile = NULL;
    if(taille != 0){
        pile = (pile_t *)malloc(sizeof(pile_t));
        pile->taille = taille;
        pile->base= (eltType_pile*)malloc(sizeof(eltType_pile) * PILE_SZ);
        pile->sommet = -1;
    }
    return pile;
}


/** TO DO
 * @brief Liberer les memoires occupees par la pile
 * @param [in, out] adrPtPile l'adresse du pointeur de la structure pile_t
 */
 void libererPile(pile_t ** adrPtPile)
{
    if(*adrPtPile !=NULL){
        free((*adrPtPile)->base);
        free(*adrPtPile);
    }
    *adrPtPile = NULL;
}



/** TO DO
 * @brief Verifier si la pile est vide (aucun element dans la "base")
 * @param [in] ptPile l'adresse de la structure pile_t
 * @return 1 - vide, ou 0 - non vide
 */
 int estVidePile(pile_t * ptPile)
{
    if(ptPile->sommet < 0) return 1;
    return 0;
}


/** TO DO
 * @brief Entrer un element dans la pile
 * @param [in, out] ptPile l'adresse de la structure pile_t
 * @param [in] ptVal l'adresse de la valeur a empiler
 * @param [in, out] code : l'adresse du code de sortie
 *                     *code = 0 si reussi
 *                           = 1 si echec
 */
void empiler(pile_t *ptPile, eltType_pile *ptVal, int *code) {
    // Vérifier si la pile est pleine
    if (ptPile->sommet == ptPile->taille - 1) {
        *code = 1; // code d'erreur
        return;
    }

    // Incrémenter le sommet et ajouter l'élément
    ptPile->sommet++;
    ptPile->base[ptPile->sommet] = *ptVal;

    *code = 0; // code de succès
}


/** TO DO
 * @brief Sortir un element de la pile
 * @param [in, out] ptPile l'adresse de la structure pile_t
 * @param [out] ptRes l'adresse de l'element sorti
 * @param [in, out] code : l'adresse du code de sortie
 *                     *code = 0 si reussi
 *                           = 1 si echec
 */
void depiler(pile_t *ptPile, eltType_pile *ptRes, int *code) {
    // Vérifier si la pile est vide
    if (ptPile->sommet == -1) {
        *code = 1; // code d'erreur
        return;
    }

    // Récupérer l'élément en sommet, le stocker à l'adresse ptRes et décrémenter le sommet
    *ptRes = ptPile->base[ptPile->sommet];
    ptPile->sommet--;

    *code = 0; // code de succès
}

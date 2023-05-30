/**
 * @file eltPile.h
 * @brief fichier d'entete pour la gestion du type des elements de pile
 */
#ifndef __ELTPILE_H__
#define __ELTPILE_H__

#include "eltsArbre.h"

/** TO DO
 * @struct eltType_pile
 * @brief definir la SDD des elements de pile
 * 3 champs :
 *   - adrCell : l'adresse d'un point/cellule d'une arborescence
 *   - adrPrec : l'adresse du pointeur prec du point
 *   - nbFils_ou_Freres : le nombre de fils ou freres d'un point 
 */

typedef struct eltPile
{
    cell_lvlh_t  * adrCell;
    cell_lvlh_t ** adrPrec;
    int nbFils_ou_Freres;
}eltType_pile;



/**
 * @brief Ecrire une fonction de comparaison de 2 elements
 * @param [in] xxx l'adresse du 1er element du type 'eltType_pile'
 * @param [in] xxx l'adresse du 2eme element du type 'eltType_pile'
 * @return 1 si les 2 elements sont egaux; 0 s'ils sont differents
 */
 int compareElt(eltType_pile *fisrt , eltType_pile *second);

/**
 * @brief Copier la valeur d'un element dans un autre emplacement
 * @param [in] source l'adresse de l'element a copier
 * @param [in] destination l'adresse de la destination
 */
void copyElt(eltType_pile *source , eltType_pile *destination);




#endif
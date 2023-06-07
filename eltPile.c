/**
 * @file eltPile.c
 * @brief fichier d'implementation pour la gestion du type des elements de pile
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
#include <stdio.h>

#include "eltPile.h"

/** TO DO
 * @brief Copier la valeur d'un element dans un autre emplacement
 * @param [in] src l'adresse de l'element a copier
 * @param [in] dest l'adresse de la destination
 */
void copyElt(eltType_pile *source , eltType_pile *destination)
{
    destination->adrCell = source->adrCell;
    destination->adrPrec = source->adrPrec;
    destination->nbFils_ou_Freres = source->nbFils_ou_Freres;
    // je vais essayer d'installer ddd
    //si j'y arrive as je vous enverai 
    //Merci ! 
}




/**
 * @file arbres_parcours.h
 * @brief fichier d'entete du module pour le parcours d'arborescence
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

#ifndef __ARBRE_PARCOURS_H__
#define __ARBRE_PARCOURS_H__

#include "../eltsArbre.h"

/** TO DO
 * @brief calculer le nombre de fils ou freres d'un point
 * @param [in] ptCell pointeur vers le 1er frere
 * @return le nombre de fils ou freres
 */
int getNbFils_ou_Freres(cell_lvlh_t * ptCell);

/** TO DO
 * @brief parcours en profondeur postfixee
 * @param [in] file le flux de sortie
 * @param [in] racine la racine de l'arborescence
 */
void printPostfixee(FILE* file, cell_lvlh_t* racine);

#endif
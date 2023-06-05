/**
 * @file arbres_parcours.c
 * @brief fichier d'implementation du module pour le parcours d'arborescence
 */
#include <stdio.h>
#include <stdlib.h>

#include "../pile.h"
#include "../eltsArbre.h"
#include "arbres_parcours.h"


/** TO DO
 * @brief calculer le nombre de fils ou freres d'un point a partir du pointeur du debut de la liste
 * @param [in] ptCell pointeur vers le 1er frere
 * @return le nombre de fils ou freres
 */
int getNbFils_ou_Freres(cell_lvlh_t * ptCell)
{
    int i=0;
    while(ptCell != NULL){
        i++;
        ptCell = ptCell->lh;
    }
    return i;
}


/** TO DO
 * @brief parcours en profondeur postfixee
 * @param [in] file le flux de sortie
 * @param [in] racine la racine de l'arborescence
 */
void printPostfixee(FILE* file, cell_lvlh_t* racine)
{

    cell_lvlh_t * cour = racine;
    pile_t * pile = initPile(1028);
    int code;
    eltType_pile eltPile;
    int fin = 0;
    while(fin==0){
        while(cour!=NULL){
            eltPile.adrCell = cour;
            empiler(pile,&eltPile,&code);
            cour = cour->lv;
        }
        if(!estVidePile(pile)){
            depiler(pile,&eltPile, &code);
            cour = eltPile.adrCell;
            fprintf(file,"(%c,%d) ", cour->val, getNbFils_ou_Freres(cour->lv));
            cour = cour->lh;
        }
        else fin = 1;
    }
    if(racine != NULL) fprintf(file,"%d\n", getNbFils_ou_Freres(racine));
    libererPile(&pile);
}
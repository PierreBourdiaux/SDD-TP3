/**
 * @file arbres_insert.c
 * @brief fichier d'implementation du module pour l'insertion de valeur dans une arborescence
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
#include <stdlib.h>

#include "../pile.h"
#include "../eltsArbre.h"
#include "arbres_insert.h"
#include "../Seance1/arbres_construct.h"


/**
 * @brief rechercher un point de valeur v
 * @param [in] racine pointeur vers la racine de l'arborescence 
 * @return 
 *   - l'adresse du point contenant v si v existe dans l'arborescence
 *   - NULL, sinon
 */
cell_lvlh_t* rechercher_v(cell_lvlh_t * racine, char v)
{
    cell_lvlh_t * retour = NULL;
    cell_lvlh_t * cour = racine;
    pile_t * pile = initPile(1028);
    int code;
    eltType_pile eltPile;
    int fin = 0;
    while(fin==0){ // on fait le meme parcours en profondeur que pour l'affichage
        while(cour!=NULL){
            eltPile.adrCell = cour;
            empiler(pile,&eltPile,&code);
            cour = cour->lv;
        }
        if(!estVidePile(pile)){
            depiler(pile,&eltPile, &code);
            cour = eltPile.adrCell;
            if(cour->val == v){
                retour = cour;
                fin=1;          // on arrete le parcours dès la premiere rencontre de la valeur 
            }
            cour = cour->lh;
        }
        else fin = 1;
    }
    libererPile(&pile);
    return retour;
}

/**
 * @brief rechercher le double prec de w dans une liste de fils
 * @param [in] adrPere l'adresse du pere
 * @param [in] w la valeur a inserer
 * @return l'adresse du pointeur prec apres lequel w doit etre inseree
 */
cell_lvlh_t** rechercherPrecFilsTries(cell_lvlh_t * adrPere,char w)
{
    cell_lvlh_t * cour = adrPere->lv;
    cell_lvlh_t ** pprec= &(adrPere->lv);
    while(cour!=NULL && cour->val<w){ // recherche d'une valeur dans une liste chainé trié 
        pprec = &(cour->lh);          // par odre alphabétique 
        cour = cour->lh;
    }
    return pprec;
}

/** TO DO
 * @brief inserer une valeur w dans les fils d'un point de valeur v
 * @param [in] racine la racine de l'arborescence
 * @param [in] v la valeur d'un point auquel on va inserer la valeur w en fils
 * @param [in] w la valeur a inserer
 * @return 1 - insertion realisee; 0 - insertion n'a pas ete realisee
 */
int insererTrie(cell_lvlh_t* racine, char v, char w)
{
    int retour = 0; // 0 si raté / 1 si reussi
    cell_lvlh_t ** pprec=NULL;
    cell_lvlh_t * nouv=NULL;
    cell_lvlh_t * pere = rechercher_v(racine,v); // on cherche le pere 
    if(pere != NULL){
        pprec=rechercherPrecFilsTries(pere,w); //on cherche l'endroit dans la liste chainé des fils 
        if(pprec != NULL){                     // où on insere w 
            nouv = allocPoint(w);
            if(nouv!=NULL){  // si l'allocation a réussi, on rentre le maillon dans la liste
                nouv->lh = *pprec;
                *pprec = nouv;
                retour =1;
            }
            
        }
    }
    return retour;

}

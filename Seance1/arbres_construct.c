/**
 * @file arbres_construct.c
 * @brief fichier d'implementation du programme pour la construction d'une arborescence
 */
#include <stdio.h>
#include <stdlib.h>

#include "../pile.h"
#include "../eltsArbre.h"
#include "arbres_construct.h"

/**
 * @brief lire le fichier contenant la representation prefixee de l'arborescence
 * @param [in] fileName le nom du fichier contenant la representation prefixee
 * @param [in, out] tabEltPref tableau des elements de la representation prefixee
 * @param [in, out] nbEltsPref l'adresse memoire contenant le nombre des elements du tabEltPref
 * @return le nombre de racines
 */
int lirePref_fromFileName(char * fileName, eltPrefPostFixee_t * tabEltPref ,int * nbEltsPref)
{
   *nbEltsPref =0;
   int nbfils, racine=0;
   char val;
   FILE * flux = fopen(fileName, "r");
   fscanf(flux,"%d ", &racine);

   while(fscanf(flux,"%c %d ", &val, &nbfils) == 2){
      tabEltPref[*nbEltsPref].val = val;
      tabEltPref[*nbEltsPref].nbFils = nbfils;
      *nbEltsPref = *nbEltsPref + 1;
   }
   fclose(flux);
   return racine;
}

/** 
 * @brief afficher les elements de la representation prefixee sur un flux de sortie
 * "2 (A,3) (B,2) (E,0) (J,0) (D,0) (H,1) (G,0) (C,2) (F,3) (K,0) (M,0) (T,0) (I,0)\n"
 * @param file : le flux de sortie
 * @param [in, out] tabEltPref tableau des elements de la representation prefixee
 * @param [in, out] nbEltsPref le nombre des elements du tabEltPref
 */
void printTabEltPref(FILE *file, eltPrefPostFixee_t *tabEltPref, int nbEltsPref)
{
    for(int i=0; i<nbEltsPref-1; i++){
      fprintf(file, "(%c,%d) ", tabEltPref[i].val, tabEltPref[i].nbFils);
    }
   fprintf(file, "(%c,%d)\n", tabEltPref[nbEltsPref-1].val, tabEltPref[nbEltsPref-1].nbFils);
}

/** 
 * @brief creer et initialiser un nouveau point de l'arborescence
 * @param [in] val la valeur du point
 * @return l'adresse du nouveau point 
 */
cell_lvlh_t * allocPoint(char val)
 {  
    cell_lvlh_t * nouv = (cell_lvlh_t *)malloc(sizeof(cell_lvlh_t));
    nouv->val = val;
    nouv->lv = NULL;
    nouv->lh = NULL;
    return nouv;
 }

/** TO DO
 * @brief construire un arbre avec lvlh a partir de representation prefixee
 * @param [in] tabEltPref tableau des elements de la representation prefixee
 * @param [in] nbRacines nombre de racines de l'arborescence
 * @return : 
 *     - NULL si l'arbre resultatnt est vide
 *     - l'adresse de la racine de l'arbre sinon
*/
 cell_lvlh_t* pref2lvlh( eltPrefPostFixee_t *tabEltPref, int nbRacines)
{
   pile_t * pile = initPile(1028);
   cell_lvlh_t * tete = NULL;
   cell_lvlh_t* nouv;
   eltPrefPostFixee_t* courLc = tabEltPref;
   cell_lvlh_t ** pprec = &tete;
   int code;
   eltType_pile eltPile;

   int nb_fils_ou_frere = nbRacines;
   //courLc= courLc +1;
   while (nb_fils_ou_frere > 0 || !estVidePile(pile)){
      if(nb_fils_ou_frere > 0){
         nouv = allocPoint(courLc->val);
         *pprec = nouv;
         eltPile.nbFils_ou_Freres=nb_fils_ou_frere-1;
         //eltPile.adrCell = nouv;
         eltPile.adrPrec = &(nouv->lh);    
         
         empiler(pile, &eltPile,&code);
         pprec = &(nouv->lv);
         nb_fils_ou_frere = courLc->nbFils; 

         courLc = courLc +1;

      }
      else {
         if(!estVidePile(pile)){
            depiler(pile, &eltPile,&code);
            nb_fils_ou_frere = eltPile.nbFils_ou_Freres;
            pprec = eltPile.adrPrec;
         }
      }
   }
   libererPile(&pile);
   return tete;

}

/** TO DO
 * @brief liberer les blocs memoire d'un arbre
 * @param [in] adrPtRacine l'adresse du pointeur de la racine d'un arbre
 */
void libererArbre(cell_lvlh_t ** adrPtRacine )
{
   eltType_pile eltPile;
   pile_t * pile = initPile(128);
   cell_lvlh_t * cour = *adrPtRacine;
   cell_lvlh_t * tmp;
   int code = 1;
   if(*adrPtRacine != NULL){
      while(cour != NULL || !estVidePile(pile)){
         if(cour != NULL){
            eltPile.adrCell = cour;
            empiler(pile, &eltPile, &code);
            cour = cour->lv;

         }
         else{
              depiler(pile, &eltPile, &code);
              tmp = eltPile.adrCell;
              cour = tmp->lh;
              free(tmp);
         }
      }
   }
   libererPile(&pile);
   *adrPtRacine = NULL;
}


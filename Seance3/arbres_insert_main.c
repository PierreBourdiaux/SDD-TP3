/**
 * program for general linked list testing
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
#include <string.h>
#include "../pile.h"
#include "../eltsArbre.h"
#include "../Seance1/arbres_construct.h"
#include "../Seance2/arbres_parcours.h"
#include "arbres_insert.h"
#include "../teZZt.h"


BEGIN_TEST_GROUP(ARBRE_INSERT)

TEST(nouvCell) {
	cell_lvlh_t *new;

	new = allocPoint('A');
	REQUIRE( NULL != new ); 
	CHECK( 'A' == new->val );
	CHECK( NULL == new->lv );
	CHECK( NULL == new->lh );

	free(new);
}


TEST(rechercher_v) {
	int nbRacines = 0;
	int nbEltsPref = 0;
	eltPrefPostFixee_t tabEltPref[NB_ELTPREF_MAX];
	cell_lvlh_t *racine = NULL;
	cell_lvlh_t *pere = NULL;

	printf("\033[35m\nrechercher_v :");
	printf("\033[0m\n");

	nbRacines = lirePref_fromFileName("../pref_exTP.txt", tabEltPref, &nbEltsPref);
	racine = pref2lvlh(tabEltPref, nbRacines);

	pere = rechercher_v(racine, 'X');   // valeur inexistante
	CHECK( NULL == pere );

	pere = rechercher_v(racine, 'A');   // valeur a la racine
	REQUIRE( NULL != pere );
	CHECK( 'A' == pere->val );

	pere = rechercher_v(racine, 'B');   
	REQUIRE( NULL != pere );
	CHECK( 'B' == pere->val );

	pere = rechercher_v(racine, 'E');   
	REQUIRE( NULL != pere );
	CHECK( 'E' == pere->val );

	pere = rechercher_v(racine, 'J');   
	REQUIRE( NULL != pere );
	CHECK( 'J' == pere->val );

	pere = rechercher_v(racine, 'D');  
	REQUIRE( NULL != pere );
	CHECK( 'D' == pere->val );

	pere = rechercher_v(racine, 'H'); 
	REQUIRE( NULL != pere );
	CHECK( 'H' == pere->val );

	pere = rechercher_v(racine, 'G');  
	REQUIRE( NULL != pere );
	CHECK( 'G' == pere->val );

	pere = rechercher_v(racine, 'C'); 
	REQUIRE( NULL != pere );
	CHECK( 'C' == pere->val );

	pere = rechercher_v(racine, 'F');   
	REQUIRE( NULL != pere );
	CHECK( 'F' == pere->val );

	pere = rechercher_v(racine, 'K');  
	REQUIRE( NULL != pere );
	CHECK( 'K' == pere->val );

	pere = rechercher_v(racine, 'M');   
	REQUIRE( NULL != pere );
	CHECK( 'M' == pere->val );

	pere = rechercher_v(racine, 'T');  
	REQUIRE( NULL != pere );
	CHECK( 'T' == pere->val );

	pere = rechercher_v(racine, 'I');   
	REQUIRE( NULL != pere );
	CHECK( 'I' == pere->val );


	libererArbre(&racine);
}

TEST(rechercherPrecFilsTries) {
	int nbRacines = 0;
	int nbEltsPref = 0;
	eltPrefPostFixee_t tabEltPref[NB_ELTPREF_MAX];
	cell_lvlh_t *racine = NULL;
	cell_lvlh_t *pere = NULL;
	cell_lvlh_t **pprec = NULL;

	printf("\033[34m\nrechercherPrecFilsTries :");
	printf("\033[0m\n");
	nbRacines = lirePref_fromFileName("../pref_exTP.txt", tabEltPref, &nbEltsPref);
	racine = pref2lvlh(tabEltPref, nbRacines);

	pere = rechercher_v(racine, 'F');
	REQUIRE( NULL != pere );
	CHECK( 'F' == pere->val );

	pprec = rechercherPrecFilsTries(pere, 'A');
	REQUIRE( NULL != *pprec );
	CHECK( 'K' == (*pprec)->val );

	pere = rechercher_v(racine, 'B');
	REQUIRE( NULL != pere );
	CHECK( 'B' == pere->val );
	pprec = rechercherPrecFilsTries(pere, 'H');
	REQUIRE( NULL != *pprec );
	CHECK( 'J' == (*pprec)->val );

	pprec = rechercherPrecFilsTries(pere, 'Y');
	CHECK( NULL == *pprec ); // fin de liste
	

	pere = rechercher_v(racine, 'A');
	REQUIRE( NULL != pere );
	CHECK( 'A' == pere->val );
	pprec = rechercherPrecFilsTries(pere, 'F');
	REQUIRE( NULL != *pprec );
	CHECK( 'H' == (*pprec)->val );

	pere = rechercher_v(racine, 'G');
	REQUIRE( NULL != pere );
	CHECK( 'G' == pere->val );
	pprec = rechercherPrecFilsTries(pere, 'R');
	CHECK( NULL == *pprec ); // pas de fils 

	pere = rechercher_v(racine, 'C');
	REQUIRE( NULL != pere );
	CHECK( 'C' == pere->val );
	pprec = rechercherPrecFilsTries(pere, 'H');
	REQUIRE( NULL != *pprec );
	CHECK( 'I' == (*pprec)->val );


	libererArbre(&racine);
}

TEST(insererTrie) {
	int nbRacines = 0;
	int nbEltsPref = 0;
	eltPrefPostFixee_t tabEltPref[NB_ELTPREF_MAX];
	cell_lvlh_t *racine = NULL;
	cell_lvlh_t *pere = NULL;
	cell_lvlh_t *ajout = NULL;
	cell_lvlh_t **pprec = NULL;
	int code =0;

	printf("\033[34m\nrechercherPrecFilsTries :");
	printf("\033[0m\n");
	nbRacines = lirePref_fromFileName("../pref_exTP.txt", tabEltPref, &nbEltsPref);
	racine = pref2lvlh(tabEltPref, nbRacines);	


	code = insererTrie(racine, 'A','M'); // on devrait avoir B->C->D->H  (freres)
	REQUIRE(1 == code);
	ajout = rechercher_v(racine, 'M');
	REQUIRE( NULL != ajout );
	CHECK( 'M' == ajout->val );

	
	code = insererTrie(racine, 'X','Z'); //ne doit pas marcher, pere inexistant 
	CHECK(0 == code);

	code = insererTrie(racine, 'I','S'); //I n'a pas de fils de base 
	REQUIRE(1 == code);
	ajout = rechercher_v(racine, 'S');
	REQUIRE( NULL != ajout );
	CHECK( 'S' == ajout->val );

	// verification si il est au bon endroit
	pere = rechercher_v(racine, 'I');
	REQUIRE( NULL != pere );
	CHECK( 'I' == pere->val );
	pprec = rechercherPrecFilsTries(pere, 'P');
	REQUIRE( NULL != *pprec );
	CHECK( 'S' == (*pprec)->val );
	
	libererArbre(&racine);


}

END_TEST_GROUP(ARBRE_INSERT)

int main(void) {
	RUN_TEST_GROUP(ARBRE_INSERT);
	return EXIT_SUCCESS;
}

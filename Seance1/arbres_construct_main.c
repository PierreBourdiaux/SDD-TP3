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
#include "arbres_construct.h"
#include "../teZZt.h"


BEGIN_TEST_GROUP(ARBRE_CONSTRUCT)

TEST(nouvCell) {
	cell_lvlh_t *new;

	new = allocPoint('A');
	REQUIRE( NULL != new ); 
	CHECK( 'A' == new->val );
	CHECK( NULL == new->lv );
	CHECK( NULL == new->lh );

	free(new);
}


TEST(lirePref_fromFileName_exTP) {
	int nbRacines = 0;
	int nbEltsPref = 0;
	eltPrefPostFixee_t tabEltPref[NB_ELTPREF_MAX];

	nbRacines = lirePref_fromFileName("../pref_exTP.txt", tabEltPref, &nbEltsPref);

	printf("\033[34m\nlirePref_fromFileName_exTP :");
	printf("\033[0m\n");

	CHECK( 2 == nbRacines ); 
	CHECK( 13 == nbEltsPref );
	CHECK( 'A' == tabEltPref[0].val );
	CHECK( 3 == tabEltPref[0].nbFils );

	CHECK( 'B' == tabEltPref[1].val );
	CHECK( 2 == tabEltPref[1].nbFils );

	CHECK( 'C' == tabEltPref[7].val );
	CHECK( 2 == tabEltPref[7].nbFils );
	
	CHECK( 'I' == tabEltPref[nbEltsPref-1].val );
	CHECK( 0 == tabEltPref[nbEltsPref-1].nbFils );
}

TEST(printTabEltPref_exTP) {
	int nbRacines = 0;
	int nbEltsPref = 0;
	eltPrefPostFixee_t tabEltPref[NB_ELTPREF_MAX];

	char buffer[1024];
	FILE * file = fmemopen(buffer, 1024, "w");
	REQUIRE ( NULL != file);

	printf("\033[34m\nprintPref_exTP :");
	printf("\033[0m\n");

	nbRacines = lirePref_fromFileName("../pref_exTP.txt", tabEltPref, &nbEltsPref);
	fprintf(file, "%d ", nbRacines);
	printTabEltPref(file, tabEltPref, nbEltsPref);
	fclose(file);
	CHECK( 0 == strcmp(buffer, "2 (A,3) (B,2) (E,0) (J,0) (D,0) (H,1) (G,0) (C,2) (F,3) (K,0) (M,0) (T,0) (I,0)\n") ); 
}

// 2  (A,3)  (B,2)  (E,0)  (J,0)  (D,0)  (H,1) (G,0)  (C,2)  (F,3)  (K,0)  (M,0)  (T,0)  (I,0)
TEST(pref2lvlh1_exTP) {
	int nbRacines = 0;
	int nbEltsPref = 0;
	eltPrefPostFixee_t tabEltPref[NB_ELTPREF_MAX];
	cell_lvlh_t *racine = NULL;
	
	char buffer[1024];
	FILE * file = fmemopen(buffer, 1024, "w");
	REQUIRE ( NULL != file); 

	printf("\033[35m\npref2lvlh1_exTP :");
	printf("\033[0m\n");

	nbRacines = lirePref_fromFileName("../pref_exTP.txt", tabEltPref, &nbEltsPref);

	racine = pref2lvlh(tabEltPref, nbRacines);

	REQUIRE(racine != NULL);
	CHECK( 'A' == racine->val ); 

	REQUIRE(racine->lv != NULL);
	CHECK( 'B' == racine->lv->val );

	REQUIRE(racine->lv->lv != NULL);
	CHECK( 'E' == racine->lv->lv->val );
	
	REQUIRE(racine->lv->lv->lh != NULL);
	CHECK( 'J' == racine->lv->lv->lh->val );

	REQUIRE(racine->lv->lh != NULL);
	CHECK( 'D' == racine->lv->lh->val );

	REQUIRE(racine->lv->lh->lh != NULL);
	CHECK( 'H' == racine->lv->lh->lh->val );

	REQUIRE(racine->lv->lh->lh->lv != NULL);
	CHECK( 'G' == racine->lv->lh->lh->lv->val );

	REQUIRE(racine->lh!= NULL);
	CHECK( 'C' == racine->lh->val );	

	REQUIRE(racine->lh->lv->lv!= NULL);
	CHECK( 'K' == racine->lh->lv->lv->val );

	REQUIRE(racine->lh->lv->lv->lh!= NULL);
	CHECK( 'M' == racine->lh->lv->lv->lh->val );

	REQUIRE(racine->lh->lv->lv->lh->lh!= NULL);
	CHECK( 'T' == racine->lh->lv->lv->lh->lh->val );

	libererArbre(&racine);

	CHECK(racine == NULL);

	fclose(file);


}


END_TEST_GROUP(ARBRE_CONSTRUCT)

int main(void) {
	RUN_TEST_GROUP(ARBRE_CONSTRUCT);
	return EXIT_SUCCESS;
}

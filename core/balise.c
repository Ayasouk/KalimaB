#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "balise.h"

// Initialise une balise
void init_balise(T_balise*balise, char nom[T_N_MAX]){
	if(strlen(nom) < T_N_MAX){
		strcpy(balise->nom,nom);
	}
	balise->nbrvar=0;
}

void afficher_balise(T_balise balise){
	printf("Nom : %s\n",balise->nom);
	printf("Variables : ");
	afficher_variables(&balise);
	printf("\nContenu : %s\n", balise.contenu);
}

void afficher_variables(T_balise* balise){
	int i;
	printf("\n\nLISTE DES VARIABLES\n\n");
	for(i=0; i<balise->nbrvar;i++){
		printf("var %d : %s = %s\n", i, balise->liste_var[i][POS_NOM_VAR], balise->liste_var[i][POS_VAL_VAR]);
	}
}

// Ajoute une variable dans la liste des variables
int ajouter_var(T_balise* balise, char nomvar[T_N_MAX]){
	strcpy((balise->liste_var[balise->nbrvar][POS_NOM_VAR]), nomvar);
	strcpy((balise->liste_var[balise->nbrvar][POS_VAL_VAR]), "\0");
	balise->nbrvar=balise->nbrvar+1;	
	return 0;
}

// modifier la valeur d'une variable
int modifier_var(T_balise* balise, char nomvar[T_N_MAX], char valeur[T_N_MAX]){
	int i;
	for(i=0;i<balise->nbrvar;i++){
		if(strcmp(nomvar,(balise->liste_var[i][POS_NOM_VAR]))==0){
			strcpy((balise->liste_var[i][POS_VAL_VAR]),valeur);
			break;
		}
	}
	return 0;
}


// Ajoute le contenu de la balise
int ajouter_contenu(T_balise* balise, char contenu[T_C_MAX]){
	strcpy(balise->contenu, contenu);
}

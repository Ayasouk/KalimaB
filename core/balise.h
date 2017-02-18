#define T_N_MAX 32
#define T_C_MAX 256
#define POS_NOM_VAR 0
#define POS_VAL_VAR 1
#define N 20

typedef struct S_balise{
	char nom[T_N_MAX]; //nom de la balise
	char contenu[T_C_MAX]; // contenu compris entre la balise ouvrant et fermante
	char liste_var[N][2][T_N_MAX]; // listes de variables avec leurs valeurs
	int nbrvar; //nombre de variable
} T_balise;


void init_balise(T_balise*balise, char nom[T_N_MAX]);
void afficher_variables(T_balise* balise);
int ajouter_var(T_balise* balise, char nomvar[T_N_MAX]);
int modifier_var(T_balise* balise, char nomvar[T_N_MAX], char valeur[T_N_MAX]);
int ajouter_contenu(T_balise* balise, char contenu[T_C_MAX]);

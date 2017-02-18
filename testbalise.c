#include <stdlib.h>
#include "balise.h"
int main(){
	T_balise b;
	init(&b, "balise1");
	ajouter_var(&b, "variable1");
	ajouter_var(&b, "variable2");
	ajouter_var(&b, "variable3");
	modifier_var(&b,"variable2","valeurd");
	modifier_var(&b,"variable3","bjdskl");
	ajouter_contenu(&b, "contenut de la balise");
	afficher_variables(&b);
	return 0;
}



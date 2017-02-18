#include <stdio.h>
#include <stdlib.h>
#include "pilegener.h"
#include <string.h>


// initialise la pile 
void init(T_pile*pile){
    pile->top=0;
}

T_balise* top(T_pile*pile){
	if(pile->top>0)
		return pile->contenu[pile->top];
	return NULL;
}

int push(T_pile*pile,T_balise*obj){
	if(pile->top<20){
		pile->contenu[pile->top]=obj;
		pile->top+=1;
		return 0;
	}
	return 1;
}

T_balise* pop(T_pile*pile){
	if(pile->top>0){
		pile->top-=1;
		return pile->contenu[pile->top+1];
	}
	return NULL;
}

void destroy(T_pile*pile){
	int i;
	for(i=0;i<T;i++){
		pile->contenu[i]=NULL;
	}
}


int main(){
	T_pile*p;
	T_balise b1;
	T_balise b2;
	float f=5.2;
	
	init_pile(p);
	init_balise(&b1,"head");
	init_balise(&b2,"body");
	ajouter_var(&b1,"couleur");
	ajouter_var(&b2,"bold");
	modifier_var(&b1, "couleur", "bleu");
	modifier_var(&b2,"bold","epais");
	push(p,&b1);
	push(p,&b2);
	printf("balise tete : ");
	afficher_balise(pop(p));
	afficher_balise(pop(p));
	push(p,&f);
	printf("tete : %f %d %d\n", *((float*)pop(p)),*((int*)pop(p)),*((int*)pop(p)));
	return 0;
}

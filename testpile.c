#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pile.h"

int main(){
	char chaine[]="bjrncs";
	char chaine2[24];
	char chaine3[24];
	T_pile pile;
	
	init(&pile);
	printf("tete: %s\n", top(&pile));
	printf("push1");
	push(&pile,"jai pushe");
	printf("push2");	
	push(&pile,"51653jsns");
	printf("tete: %s\n",top(&pile));
	strcpy(chaine3,pop(&pile));
	printf("pop1");
	printf("tete: %s\n", chaine3);

}

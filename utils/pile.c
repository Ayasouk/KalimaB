#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include <string.h>

T_pile pile;

// initialise la pile 
void init(T_pile*pile){
    pile->top=0;
}

// Renvoi l'element en tete de pile
char * top(T_pile*pile){
	return pile->contenu[pile->top];
}

// Empile une chaine dans la pile
int push(T_pile*pile,char*c){
    if(pile->top<T){
		pile->top+=1;
		strcpy(pile->contenu[pile->top],c);
		return 0;
    }
    return -2;
    
}

// Renvoi l'element en tete de pile ou pointeur null
char* pop(T_pile*pile){
    if(pile->top>0)
    {
		pile->top-=1;
		return pile->contenu[pile->top];
    }
    else 
    return NULL;
}


// Detruit la pile 
void destroy(T_pile*pile){
	return;
}



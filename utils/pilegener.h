#ifndef __PILEGener_H__
    #define __PILEGener_H__
#endif // __PILEGener_H__

#define T 20 //taille de la pile generique
#include "balise.h"

typedef struct S_pile{
    int top;
    T_balise* contenu[T];
} T_pile;

void init_pile(T_pile*pile);
T_balise* top(T_pile*pile);
int push(T_pile*pile,T_balise*c);
T_balise* pop(T_pile*pile);
void destroy(T_pile*pile);

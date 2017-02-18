#ifndef __PILE_H__
    #define __PILE_H__
#endif // __PILE_H__

#define T 20 //taille de la pile
#define N 20  //taille d'une chaine d'une pile


typedef struct S_pile{
    int top;
    char contenu[T][N];
} T_pile;

void init(T_pile*pile);
char * top(T_pile*pile);
int push(T_pile*pile,char*c);
char* pop(T_pile*pile);
void destroy(T_pile*pile);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pile.h"

typedef enum Etats{
    E0_Debut, // etat de lecture de la chaine precedant la 1ere balise
    E1_Baliseo, // etat de lecture du nom de la balise
    E2_Contenubal, // etat relevant le contenu balisé
    E3_Balisef, // etat de lecture de la balise fermante
    E4_Variable, // etat de lecture du nom d'une variable
    E5_Valeurvar // etat de lecture d'une valeur d'une variable 
} E_Etats;

char * etat_str(E_Etats et){
	switch(et){
		case E0_Debut: return "E0_Debut";
		case E1_Baliseo : return "E1_Baliseo";
		case E2_Contenubal: return "E2_Contenubal";
		case E3_Balisef: return "E3_Balisef";
		case E4_Variable: return "E4_Variable";
		case E5_Valeurvar: return "E5_Valeurvar";
		
	}
}




int main(){
	// variables concernant le traitement du fichier
	FILE *fd=NULL;
    char c;
    int curseur=0;
    E_Etats etat_cur=E0_Debut;
    T_pile pile;
    
    // variables de chaines
    char chaine1[64]="";
    char nom_baliseo[64]="";
    char nom_balisef[64]="";
    char contenu[256]="";
	char fdc[1]="\0";
    char nomvariable[64]="";
    char valeurvariable[64]="";
    
    // initialisation 
    init(&pile);
    
    // Ouverture du fichier
	fd=fopen("/home/oukache/Bureau/parseur/data.txt", "r");
	if(fd!=NULL){
		do{
			// Saisi d'un caractere
			c=fgetc(fd);
			printf("saisi %d : %c  %s \n",curseur,c, etat_str(etat_cur));
			// Traitement du caracte en fonction de l'etat actuel
			switch(etat_cur){
				
				
				case E0_Debut: 
					if(c!='<'){
						sprintf(chaine1,"%s%c",chaine1,c);
						//printf("chaine saisi: %s\n",chaine1);
					}
					if(c=='<'){
						etat_cur=E1_Baliseo;
						// empiler la chaine lu et vider chaine1
						printf("chaine 1  : %s\n",chaine1);
						push(&pile,chaine1);
						strcpy(chaine1,"\0");
					}
					break;
				
				
				case E1_Baliseo:
					if((c=='>')||(c==' ')){
						printf("\nNouvel etat -- Fermeture d'une balise -- \n");
						etat_cur=E2_Contenubal;
						push(&pile,nom_baliseo);
						strcpy(nom_baliseo,fdc);
						if(c==' '){
							etat_cur=E4_Variable;
						}
					}
					if(c=='\\'){
						//empiler contenu
						printf("\nNouvel etat -- Ouverture d'une balise fermante -- \n");
						etat_cur=E3_Balisef;
					}
					if((c!='>')&&(c!='\\')){
						sprintf(nom_baliseo,"%s%c",nom_baliseo,c);
						printf("nom_balise : %s\n",nom_baliseo);
						
					}
					
					break;
				
				
				case E2_Contenubal: 
					if(c=='<'){
						etat_cur=E1_Baliseo;
						strcpy(contenu,fdc);
					}
					if(c!='<'){
						sprintf(contenu,"%s%c",contenu,c);
						printf("contenu : %s\n", contenu);
						
					}
					break;
				
				
				case E3_Balisef: 
					if(c!='>'){
						sprintf(nom_balisef,"%s%c",nom_balisef,c);
						printf("nom_balise : %s\n",nom_balisef);			
					}
					if(c=='>'){
						//si vide fin du programme sinon verifier si ce qui est en tete de pile est la meme que le nom de balise lu
						//sinon remettre l'etat a E0
						printf("nombalise : %s  et top de la pile %s\n",nom_balisef, top(&pile));
						if(strcmp(nom_balisef,top(&pile)) !=0){
							printf("Erreur, la balise de necorrespond pas\n");
							return 2;
						}
						else{
							pop(&pile);
							printf("Fin de lecture de la balise : %s\n", nom_balisef);
							etat_cur=E0_Debut;
						}
						strcpy(nom_balisef,fdc);
					}
					break;
					
				case E4_Variable:
					if(c!='='){
						sprintf(nomvariable,"%s%c",nomvariable,c);
						printf("nom variable : %s\n",nomvariable);		
					}
					if(c=='='){
						//push(&pile,nomvariable);
						etat_cur = E5_Valeurvar;
					}
					break;
				case E5_Valeurvar:
					if((c!=' ')||(c!='>')){
						sprintf(valeurvariable,"%s%c",valeurvariable,c);
						printf("variable : %s = %s\n",nomvariable,valeurvariable);
					}
					if(c==' '){
						//push(&pile, valeurvariable);
						etat_cur=E4_Variable;
						strcpy(valeurvariable,fdc);
					}
					if(c=='>'){
						//push(&pile, valeurvariable);
						etat_cur=E2_Contenubal;
						strcpy(valeurvariable,"\0");
					}
					break;
			}
			
			curseur++;
		}while(!feof(fd));
	}
	return 0;
}

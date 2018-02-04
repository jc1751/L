#include <stdio.h>
#include <stdlib.h>
#include "symboles.h"
#include "util.h"
#include "analyseur_syntaxique.h"
/*char yytext[100];ÀÀ				"
*/

char yytext[100];
FILE *yyin; 
int uniteCourante;
void F( void ) 
{
	if( uniteCourante == PARENTHESE_OUVRANTE) {
		
		uniteCourante = yylex();
		if(uniteCourante == FOIS  || uniteCourante == PLUS ||
		   uniteCourante == MOINS || uniteCourante == DIVISE){
			printf("Erreur syntaxe: opération après une parenthèse \n");
			exit(1);
		}
		
		E();
		
		
		if(uniteCourante != PARENTHESE_FERMANTE){
			printf( "Erreur de syntaxe: manque une parenthèse fermante\n" );
			exit(1);
		}
	}
	else if(uniteCourante == PARENTHESE_FERMANTE){
		printf("Erreur syntaxe:trop de parenthèse fermante\n");
		exit(1);
	}
	else if(uniteCourante == NOMBRE || uniteCourante == ID_VAR /*|| uniteCourante == ID_FCT*/) {
		
		uniteCourante = yylex();
		if (uniteCourante == NOMBRE || uniteCourante == ID_VAR /*|| uniteCourante == ID_FCT*/){
			printf("Erreur syntaxe: il faut des opérateur entres les éléments \n");
			exit(1);
		}
		
		switch(uniteCourante){
			case ID_VAR:
				uniteCourante = yylex();
					if(uniteCourante == CROCHET_OUVRANT){
						E();
						uniteCourante = yylex();
						if(uniteCourante != CROCHET_FERMANT){
							printf("Fermez votre crochet \n");
							exit(1);
						}else{
							printf("Crochet fermant \n");
						}
					}
				break;
			//case ID_FCT: ;break;;
			default:break;
		}
		
		if(uniteCourante == PARENTHESE_OUVRANTE){
			printf("Erreur manque une opération\n");
			exit(1);
		}
	}		 
	
}

void Tbis( void ) 
{		
	if( uniteCourante == FOIS || uniteCourante == DIVISE) {
		uniteCourante = yylex();
		if (uniteCourante == FOIS || uniteCourante == PLUS){
			printf("Erreur syntaxe: symboles à la suite \n");
			exit(1);
		}
		T();
	}
}

void T( void ) 
{
	F();
	Tbis();
}

void Ebis( void ) 
{
	
		
	if( uniteCourante == PLUS || uniteCourante == MOINS) {
		uniteCourante = yylex();
		if (uniteCourante == FOIS || uniteCourante == PLUS){
			printf("Erreur syntaxe: symboles à la suite \n");
		}
		E();
	}
}

void E( void ) 
{
	T();
	Ebis();
}

void Debug(){
	
}

#include <stdio.h>
#include <stdlib.h>
#include "symboles.h"
#include "util.h"
#include "analyseur_syntaxique.h"
/*char yytext[100];
FILE *yyin;
int uniteCourante;
*/
void F( void ) 
{
	if( uniteCourante == PARENTHESE_OUVRANTE) {
		uniteCourante = yylex();
		printf
		E();
		if(uniteCourante != PARENTHESE_FERMANTE){
			printf( "Erreur de syntaxe" );
		}
	}
	else if(uniteCourante == NOMBRE) {
			uniteCourante = yylex();
		}
		 
	
}

void Tbis( void ) 
{
	if( uniteCourante == FOIS ) {
		uniteCourante = yylex();
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
	if( uniteCourante == PLUS ) {
		uniteCourante = yylex();
		E();
	}
}

void E( void ) 
{
	T();
	Ebis();
}



#include <stdio.h>
#include <stdlib.h>
#include "symboles.h"
#include "util.h"
#include "analyseur_syntaxique.h"

char yytext[100];
FILE *yyin;
int uniteCourante;

int yylex();

int main(int argc, char **argv) {  
  yyin = fopen(argv[1], "r");
  if(yyin == NULL){
    fprintf(stderr, "impossible d'ouvrir le fichier %s\n", argv[1]);
    exit(1);
  }
  uniteCourante = yylex();
  //test_yylex_internal(yyin);
  
  E();
  uniteCourante = yylex();
  if(uniteCourante != FIN){
	printf("Didn't reach endOfFile \n");
	printf("\033[33;1m");
	test_yylex_internal(yyin);
	printf("\033[0m");
  }
  return 0;
}

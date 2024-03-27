#ifndef SYNTFUNC_H
#define SYNTFUNC_H
#include "color.h"

int                         yylex(void);
int                         yyerror(char *s);

/*Error functions --------------------------------------------------------------*/
int undeclaredIdf           (char* lex);
void doubleDeclarationIdf   (char* lex, char* type, char* cost);
void doubleDeclarationFunc  (char* lex, char* type, char* cost);
void doubleDeclarationIdfForFunc (char* lex, char* type, char* cost);
void typeMismatch           (char* type, char* var);
void changeConstValue       (char* Curr_const);
void zeroDiv                (bool zero);
void  affTypeError           (char* tempType, char* difName);
char* exprTypeError          (char* tempType, char* varType);


/*Structure return --------------------------------------------------------------*/
char* idfType               (char *lex);
bool  isIdfZero             (char *lex);

/*Find in symbole table ---------------------------------------------------------*/
int find(char lex[]);
int findInFunc(char lex[]);
/*Insert in symbole table -------------------------------------------------------*/

void insert                 (char lex[], char code[], char type[], char constStat[]);
void insertTypeConstToIdf   (int lexIndex, char type[], char constStat[]);
void insertInFunc            (char *lex);
void insertTypeConstToIdfForFunc(int lexIndex, char type[], char constStat[]);

/*Print symboles table ----------------------------------------------------------*/
void show();
void printTab();
void printEndTab();

int count_nl(const char *text, int length);

#endif
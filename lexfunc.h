#ifndef LEXFUNC_H
#define LEXFUNC_H
#include <stdio.h>
#include <string.h>
#include "color.h"
#include "synt.tab.h"
extern char* none;
extern int  numError;
extern int  nb_ligne, nb_colone;
bool        findError = false;
/*struct of symbole table -------------------------------------------------------*/
typedef struct {
    char lexName[13];
    char lexCode[20];
    char lexType[20];
    char lexConst[20];
    bool isFunc;
    int  ligne;
    int  column;
    //bool idfIsZero;
} STable;
STable ts[1000];
int cptSym=0;

STable fts[100][1000];
int cptFunc = 0;
int lexFuncIndex = 0;

/*Find in symbole table ---------------------------------------------------------*/
int find(char lex[]) {
    int i=0;
    while(i<cptSym) {
        if (strcmp(lex,ts[i].lexName)==0) return i;
        i++;
    }
    return -1;
}
/*Find in symbole table of function -------------------------------------------*/
int findInFunc(char lex[]) {
    int i=0;
    while(i<lexFuncIndex) {
        if (strcmp(lex,fts[cptFunc][i].lexName)==0) return i;
        i++;
    }
    return -1;//return i;
}

/*Type of identifier ------------------------------------------------------------*/
char* idfType (char *lex) {
    return ts[find(lex)].lexType;
}
/*
bool isIdfZero(char* lex) {
    return ts[find(lex)].idfIsZero;
}
void setIdfVal(int i, bool val) {
    ts[i].idfIsZero = val;
}
*/
/*Error function ----------------------------------------------------------------*/
void printfTab() {
    printf("_______________________________________________________________________________________________________________________________________________________\n");
    printf("|            |                                                       |                                                           |         |          |\n");
    printf("|Error Number|                     Error Message                     |                Information about the error                |  ligne  |  conone  |\n");
    printf("|____________|_______________________________________________________|___________________________________________________________|_________|__________|\n");
    printf("|            |                                                       |                                                           |         |          |\n");
}
void printEndTab() {
    if (findError) printf("|____________|_______________________________________________________|___________________________________________________________|_________|__________|\n");
    findError = false;
}
int error(char *s, char *what){
    if (numError == 0)    printfTab();
    printf("|    %3d     |" RED "  %50s   " WHITE "|" YELLOW "%56s   " WHITE "|  %4d   |   %4d   |\n", numError, s, what, nb_ligne, nb_colone);
    findError = true;
    numError ++;
}

/*Insert in symbole table -------------------------------------------------------*/
void insert(char lex[], char code[], char type[], char constStat[]) {
    if ( find(lex)==-1) {
        strcpy(ts[cptSym].lexName,lex);
        strcpy(ts[cptSym].lexCode,code);
        strcpy(ts[cptSym].lexType,type);
        strcpy(ts[cptSym].lexConst, constStat);
        ts[cptSym].ligne = nb_ligne;
        ts[cptSym].column = nb_colone;
        ts[cptSym].isFunc = false;
        /*ts[cptSym].idfIsZero = false;*/
        cptSym++;
    }
}

/*insert type and const state ------------------------------------------------*/
void insertTypeConstToIdf(int lexIndex, char type[], char constStat[]) {    
    //as we will need to verify that the type doesn't exist before calling this function we choose to give it the index of the idf to avoid mutiple declaration of the function find in our programe
    if (!strcmp(ts[lexIndex].lexCode, "idf")) {
        strcpy(ts[lexIndex].lexType,type);
        strcpy(ts[lexIndex].lexConst, constStat);
        ts[lexIndex].isFunc = false;
        //if (ts[lexIndex].lexConst == "True")    setIdfVal(lexIndex, val);
    }
}

void insertTypeConstToIdfForFunc(char* lex, char type[], char constStat[]) {    
    //as we will need to verify that the type doesn't exist before calling this function we choose to give it the index of the idf to avoid mutiple declaration of the function find in our programe
        strcpy(fts[cptFunc][lexFuncIndex].lexName, lex);
        strcpy(fts[cptFunc][lexFuncIndex].lexCode, "idf");
        strcpy(fts[cptFunc][lexFuncIndex].lexType,  type);
        strcpy(fts[cptFunc][lexFuncIndex].lexConst, constStat);
        fts[cptFunc][lexFuncIndex].isFunc = false;
        lexFuncIndex++;
}


void insertInFunc(char *lex){
    int i = find(lex);
    if (!strcmp(ts[i].lexCode, "idf"))   ts[i].isFunc = true; 

}
/*Undeclared identifier ---------------------------------------------------------*/
int undeclaredIdf (char* lex) {
    if (!strcmp(ts[find(lex)].lexType, none))   {
        char msg[50] = " -";
        strcat(msg, lex);
        strcat(msg, "- wasn't declared!");
        error("Undeclared identifier", msg);
        return 1;
    }
    return 0;
}

/*Duplicate declaration of identifier -------------------------------------------*/
void doubleDeclarationIdf (char* lex, char* type, char* cost) {
        int lexIndex = find(lex);                       //to avoid calling find multiple times
        if( !strcmp(ts[lexIndex].lexType, "_"))     insertTypeConstToIdf(lexIndex, type, cost);  
        else if (ts[lexIndex].isFunc) {
            char msg[50] = " ";
            strcat(msg, "you can't redeclare -");
            strcat(msg, lex);
            strcat(msg, "-");
            error("Connot redeclare a function as a variable", msg);
        }
        else{
            char msg[50] = " ";
            strcat(msg, "you can't redeclare -");
            strcat(msg, lex);
            strcat(msg, "- twice!");
            error("Duplicate declaration of identifier", msg);
        }
}

/*Duplicate declaration of identifier -------------------------------------------*/
void doubleDeclarationFunc (char* lex, char* type, char* cost) {
        int lexIndex = find(lex);                       //to avoid calling find multiple times
        if( !strcmp(ts[lexIndex].lexType, "_")) {
            insertTypeConstToIdf(lexIndex, type, cost);  
            insertInFunc(lex);
            cptFunc ++;
            lexFuncIndex = 0;
        }    
        else if (ts[lexIndex].isFunc) {
            char msg[50] = " ";
            strcat(msg, "you can't declare -");
            strcat(msg, lex);
            strcat(msg, "- twice!");
            error("Duplicate declaration of function", msg);
        }
        else{
            char msg[50] = " ";
            strcat(msg, "you can't declare -");
            strcat(msg, lex);
            strcat(msg, "- as a function its a ");
            strcat(msg, ts[lexIndex].lexType);

            error("Connot redeclare a variable name as a function", msg);
        }
}
/**/
void doubleDeclarationIdfForFunc (char* lex, char* type, char* cost) {
        int lexIndex = findInFunc(lex);                     //to avoid calling find multiple times
        //printf("curr_lex is : %s - %d - func: %d\n", lex, lexIndex, cptFunc);
        if(lexIndex == -1)                                  insertTypeConstToIdfForFunc(lex, type, cost);  
        else if (fts[cptFunc][lexIndex].isFunc) {
            char msg[50] = " ";
            strcat(msg, "you can't declare -");
            strcat(msg, lex);
            strcat(msg, "- as a function its a ");
            strcat(msg, fts[cptFunc][lexIndex].lexType);
            error("Connot redeclare a function as a variable", msg);
        }
        else{
            char msg[50] = " ";
            strcat(msg, "you can't declare -");
            strcat(msg, lex);
            strcat(msg, "- twice in the same function!");
            error("Duplicate declaration of identifier", msg);
        }
}

/*Type Mismatch -----------------------------------------------------------------*/
void typeMismatch (char* type, char* var) {
    bool existType = !(strcmp(type, "INT") && strcmp(type, "FLOAT") && strcmp(type, "BOOL") && strcmp(type, "CHAR") && strcmp(type, "STRING")); 
    char msg[50] = " ";
    strcat(msg, "can't affect -");
    strcat(msg, var);
    strcat(msg, "- to a -");
    strcat(msg, type);
    strcat(msg, "-");
    if (strcmp(type, var) && existType)             error("Type Mismatch", msg);
    //printf( "-Curr_type: %s, Var_type: %s --- %d \n", type, var, nb_ligne);
    //printf(RED"typeMismatchTexting\n"WHITE);//error("Type Mismatch");
}

/*Change the value of a constent ------------------------------------------------*/
void changeConstValue (char* lex) {
    char msg[50]=" ";
        strcat(msg, " can't change the value of -");
        strcat(msg, lex);
        strcat(msg, "-");
    if (!strcmp(ts[find(lex)].lexConst, "True"))    error("Cannot change the value of a constant", msg);
}

/*expretion type error ----------------------------------------------------------*/
void affTypeError (char* tempType, char* varType) {
    char msg[50] = " ";
    strcat(msg, "you can't affecte a -");
    strcat(msg, varType);
    strcat(msg, "- to -");
    strcat(msg, tempType);
    strcat(msg, "-");
    if (strcmp(tempType, varType)) error("affectation type error", msg);
}

/*expretion type error ----------------------------------------------------*/
char* exprTypeError (char* tempType, char* varType) {
    char msg[56] = " ";
    strcat(msg, "use of types -");
    strcat(msg, varType);
    strcat(msg, "- and -");
    strcat(msg, tempType);
    strcat(msg, "- at the same time");
    if (strcmp(tempType, varType)) {
        if(strcmp("exprTypeError", varType) && strcmp("exprTypeError", tempType)) error("expretion type error", msg);
        return "exprTypeError";
    }
    else {
        return tempType;
    }
}

/*Zero division -----------------------------------------------------------------*/
void zeroDiv (bool zero) {
    if (zero == true)         error("division by zero", "_");
}

/*verify the type of arithmitic excpretion  -------------------------------------*/


/*Print symboles table ----------------------------------------------------------*/
void show() {

    const char *t = "True", *f = "False";
    printf("\n\t*********************************************** symboles Table ***********************************************\n");
    printf("\t______________________________________________________________________________________________________________\n");
    printf("\t|                |                |                |                |           |             |              |\n");
    printf("\t|      Name      |      Code      |      Type      |      Const     | Function  | first ligne | first column |\n");
    printf("\t|________________|________________|________________|________________|___________|_____________|______________|\n");
    printf("\t|                |                |                |                |           |             |              |\n");
    int i=0;
    char* COLOR;
    while(i<cptSym) {
        strcpy(COLOR, !strcmp(ts[i].lexType, "VAL") ? YELLOW : !(strcmp(ts[i].lexType, "INT") && strcmp(ts[i].lexType, "BOOL") && strcmp(ts[i].lexType, "FLOAT") && strcmp(ts[i].lexType, "CHAR") && strcmp(ts[i].lexType, "STRING")) ? LIGHT_BLUE : !(strcmp(ts[i].lexType, "opLOGIC") && strcmp(ts[i].lexType, "opARITHMETIC")) ? PURPULE : !strcmp(ts[i].lexType, "SEPARATOR") ? RED : !strcmp(ts[i].lexType, "KEY_WORD") ? GREEN : WHITE);

        printf("\t|  %12s  |  %12s  |  %s%12s%s  |  %8s      |   %3s     |",ts[i].lexName,ts[i].lexCode, COLOR, ts[i].lexType, WHITE, ts[i].lexConst, ts[i].isFunc ? GRI"Yes"WHITE: "-");
        printf("   %5d     |   %5d      |\n", ts[i].ligne, ts[i].column);
        i++;
    }
    printf("\t|________________|________________|________________|________________|___________|_____________|______________|\n");
}

int count_nl(const char *text, int length) {
    int count = 0;
    for (int i=0; i < length; i++) {
        if (*text == '\n') {
            count++;
        }
        text++;
    }
    return count;
}

int yyerror (char *s) {
    if (numError != 0)  printEndTab();
    printf(RED"%s %d\n"WHITE, s, nb_ligne);
    numError ++;
}
#endif
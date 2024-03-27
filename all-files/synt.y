
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "color.h"
#include "syntfunc.h"

extern FILE* yyin;
extern int nb_ligne;
extern int nb_colone;
extern int cptFunc;
extern int lexFuncIndex;
extern char *f, *t, *none; 

int numError = 0;
char* Curr_type;
char* Curr_value_type;
char* Curr_expretion_type;
char* Curr_const = "_";
char* Curr_op;
char* idfTypeTemp;
bool  isZero = false;
%}

%union {
    float u_float;
    bool  u_bool;
    int   u_int;
    char* u_char;
    char* u_string;
    char* u_str;
    char  u_op;
}

%token  <u_str>    idf 
%token  <u_int>    int_val
%token  <u_bool>   bool_val
%token  <u_char>   char_val
%token  <u_float>  float_val
%token  <u_string> string_val
%token  void_func

%token op_sub op_add op_mul op_div short_add short_sub

%token less_eq greater_eq eq not_eq less greater assign aff

%token <u_str>t_int
%token <u_str>t_float
%token <u_str>t_bool 
%token <u_str>t_char
%token <u_str>t_string
%token <u_str>t_void
%token cost

%token func loop_for loop_do loop_while cond_if cond_else cond_else_if cond_switch cond_case cond_default
%token a_break a_continue a_return quote double_quote 

%token left_par right_par left_cur right_cur
%token inst_end sep double_point
%token end begin

%type  <u_string>VAL
%type  <u_string>VAL_IDF
%type  <u_string>OP_ARI_LIST
%type  <u_string>PAR
%type  <u_string>EXPR
%start S

%%
/*AXIOM _________________________________________________________________________________________________________________*/
S:  DECL begin INST end
    {if (numError == 0) printf("Syntax correcte \n nb_ligne = %d\n", nb_ligne);  YYACCEPT;}
;

/*TYPE __________________________________________________________________________________________________________________*/
VAR_TYPE:
        t_int                                           {Curr_type = "INT";     Curr_const = f; }
        |t_bool                                         {Curr_type = "BOOL";    Curr_const = f; }
        |t_char                                         {Curr_type = "CHAR";    Curr_const = f; }
        |t_float                                        {Curr_type = "FLOAT";   Curr_const = f; }
        |t_string                                       {Curr_type = "STRING";  Curr_const = f; }
;
CONST_TYPE:
        cost t_int                                      {Curr_type = "INT";     Curr_const = t; }
        |cost t_bool                                    {Curr_type = "BOOL";    Curr_const = t; }
        |cost t_char                                    {Curr_type = "CHAR";    Curr_const = t; }
        |cost t_float                                   {Curr_type = "FLOAT";   Curr_const = t; }
        |cost t_string                                  {Curr_type = "STRING";  Curr_const = t; }
;

/*VALUES ________________________________________________________________________________________________________________*/
VAL:    int_val                                         {Curr_value_type= "INT";      $$="INT";         isZero = ($1 == 0) ? true : false;      }
        |bool_val                                       {Curr_value_type= "BOOL";     $$="BOOL";        isZero = false;                         }
        |char_val                                       {Curr_value_type= "CHAR";     $$="CHAR";        isZero = false;                         }   
        |float_val                                      {Curr_value_type= "FLOAT";    $$="FLOAT";       isZero = ($1 == 0.0) ? true : false;    }
        |string_val                                     {Curr_value_type= "STRING";   $$="STRING";      isZero = false;                         }
;

/*DECLARATION ___________________________________________________________________________________________________________*/
DECL:   TERMINAL_DECL DECL
        |
;
TERMINAL_DECL: 
        VAR_DECL inst_end       
        |CONST_DECL inst_end
        |FUNC
;

/*VARIABLE DECLARATION __________________________________________________________________________________________________*/
VAR_DECL: 
        VAR_TYPE VAR_LIST             
;
VAR_LIST:
        idf sep VAR_LIST                                {doubleDeclarationIdf($1, Curr_type, Curr_const);}
        |idf                                            {doubleDeclarationIdf($1, Curr_type, Curr_const);}
;

/*CONSTENT DECLARATION __________________________________________________________________________________________________*/
CONST_DECL: 
        CONST_TYPE CONST_LIST                           
;
CONST_LIST:
        idf assign VAL sep CONST_LIST                   {
                                                                doubleDeclarationIdf($1, Curr_type, Curr_const);       
                                                                typeMismatch(Curr_type, Curr_value_type);
                                                        }        
        |idf assign VAL                                 {
                                                                doubleDeclarationIdf($1, Curr_type, Curr_const);       
                                                                typeMismatch(Curr_type, Curr_value_type);
                                                        }
;

/*FUNCTIONS _____________________________________________________________________________________________________________*/
FUNC:   VAR_TYPE func idf left_par ARGS right_par left_cur INST_DECL_IN_FUNC right_cur  {
                                                                                                doubleDeclarationFunc($3, Curr_type, Curr_const);
                                                                                        }
        |t_void func idf left_par ARGS right_par left_cur INST_DECL_IN_FUNC right_cur                {
                                                                                                doubleDeclarationFunc($3, Curr_type, Curr_const);
                                                                                        }
        /*|VAR_TYPE func idf left_par right_par left_cur INST right_cur
        |t_void func idf left_par ARGS right_par left_cur INST right_cur*/
        //VAR_TYPE left_cur INST right_cur            {doubleDeclarationIdf($3, Curr_type, Curr_const);}

;
INST_DECL_IN_FUNC:
        ARGS INST
        //we supose that the function will have two part _ a declartion part for variable at the top _ instruction part after declaration or nothing _
;
ARGS:   ARGS_T  LIST_FUNC
        |
;
ARGS_T:   VAR_DECL_FUNC 
        |CONST_DECL_FUNC
;

VAR_DECL_FUNC: 
        VAR_TYPE idf                                    {doubleDeclarationIdfForFunc($2, Curr_type, Curr_const);}
;

CONST_DECL_FUNC: 
        CONST_TYPE idf assign VAL_IDF                   {doubleDeclarationIdfForFunc($2, Curr_type, Curr_const);}
;

LIST_FUNC:
        sep VAR_TYPE idf LIST_FUNC                      {doubleDeclarationIdfForFunc($3, Curr_type, Curr_const);}
        |sep CONST_TYPE idf assign VAL LIST_FUNC        {doubleDeclarationIdfForFunc($3, Curr_type, Curr_const);}
        |
;

/*INSTRUCTION ___________________________________________________________________________________________________________*/
INST:   TERMINAL_INST INST
        |
;
TERMINAL_INST:      
        AFFECTATION inst_end
        |ALL_LOOP
        |ALL_IFS
        |a_break inst_end
        |a_continue inst_end
        |a_return EXPR inst_end
;

VAL_IDF: VAL                                            {$$ = $1;}
        |idf                                            {undeclaredIdf($1); strcpy($$, idfType($1));}
;

/*AFFECTATION ___________________________________________________________________________________________________________*/
AFFECTATION:    idf aff EXPR                            {       //printf("type = %s $1 = %s---AFFECTATION\n", /*idfType($1)*/"1", $1);
                                                                if (!undeclaredIdf($1)){
                                                                       changeConstValue($1);
                                                                       idfTypeTemp = idfType($1);
                                                                       affTypeError(idfTypeTemp, $3);
                                                                }
                                                        }

;

/*EXPRETION _____________________________________________________________________________________________________________*/
EXPR:    VAL_IDF                                        {$$ = $1;/*printf("%s\n", $1);*/}
        |VAL_IDF OP_ARI_LIST                            {$$ = exprTypeError($1, $2);}           //printf("%s -------- %d\n", $2, nb_ligne);}
        |left_par EXPR right_par                        {$$ = $2;}
        |left_par EXPR right_par OP_ARI EXPR            {$$ = exprTypeError($2, $5);}           //exprTypeError($2, $5);}
;

//{strcpy(Curr_expretion_type, Curr_value_type);}
/*ARITHMETIC OPERATIONS _________________________________________________________________________________________________*/
OP_ARI: op_sub
        |op_add
        |op_div
        |op_mul
OP_ARI_LIST: 
        op_sub  VAL_IDF                                 {$$ = $2;}  
        |op_add VAL_IDF                                 {$$ = $2;}//printf("OP_ARI_LIST %s \n", $$);}  
        |op_div VAL_IDF                                 {zeroDiv($2);       $$ = $2;}  
        |op_mul VAL_IDF                                 {$$ = $2;}  
        |op_sub VAL_IDF OP_ARI_LIST                     {$$ = exprTypeError($2, $3);}//exprTypeError(Curr_expretion_type, $2);}      
        |op_add VAL_IDF OP_ARI_LIST                     {$$ = exprTypeError($2, $3);}      
        |op_div VAL_IDF OP_ARI_LIST                     {zeroDiv($2);       $$ = exprTypeError($2, $3);}
        |op_mul VAL_IDF OP_ARI_LIST                     {$$ = exprTypeError($2, $3);}  
        |OP_ARI PAR                                     {$$ = $2;}
;
PAR:    left_par VAL_IDF OP_ARI_LIST right_par                  {$$ = exprTypeError($2, $3);;}
        |left_par VAL_IDF OP_ARI_LIST right_par OP_ARI_LIST     {$$ = (!strcmp($2, $3) && !strcmp($2, $5) )?  $2 : exprTypeError($2, "exprTypeError");}
;
SHORT_OP:   
        short_add
        |short_sub
;

/*CONDITIONS ____________________________________________________________________________________________________________*/
COND:   VAL_IDF OP_REL COND
        |VAL_IDF
        |left_par COND right_par
        |left_par COND right_par OP_REL COND
;

/*RELATIONNELS OPERATIONS _______________________________________________________________________________________________*/
OP_REL: eq
        |not_eq
        |less
        |less_eq
        |greater
        |greater_eq
;

/*LOOPS _________________________________________________________________________________________________________________*/
ALL_LOOP:   
        FOR_LOOP
        |WHILE_LOOP
        |DO_WHILE_LOOP
;

/*FOR ___________________________________________________________________________________________________________________*/
FOR_LOOP:   
        loop_for FOR_RULE left_cur INST right_cur
;

FOR_RULE: 
FOR_RULE: 
        left_par AFFECTATION inst_end COND inst_end CHANGE right_par
;
CHANGE: AFFECTATION
        |idf SHORT_OP                                   {undeclaredIdf($1);}
;

/*WHILE _________________________________________________________________________________________________________________*/
WHILE_LOOP:     
        loop_while WHILE_RULE left_cur INST right_cur
;
DO_WHILE_LOOP: 
        loop_do left_cur INST right_cur loop_while WHILE_RULE inst_end
;

WHILE_RULE: 
        left_par COND right_par
;

/*CONDITION STATMENT ____________________________________________________________________________________________________*/
ALL_IFS:IF
        |SWITCH
;

/*IF ____________________________________________________________________________________________________________________*/
IF:     IF_COND ELSE_IF_COND ELSE_COND
        |IF_COND ELSE_COND
        |IF_COND
;

/*IF PARTS ______________________________________________________________________________________________________________*/
IF_COND:
        cond_if left_par COND right_par left_cur INST right_cur
;
ELSE_IF_COND: 
        cond_else_if left_par COND right_par left_cur INST right_cur
        |cond_else_if left_par COND right_par left_cur INST right_cur ELSE_IF_COND
;
ELSE_COND:  
        cond_else left_cur INST right_cur
;

/*SWITCH ________________________________________________________________________________________________________________*/
SWITCH: SWITCH_COND left_cur CASE_COND DEFAULT_COND right_cur 
;

/*SWITCH PARTS __________________________________________________________________________________________________________*/
SWITCH_COND:
        cond_switch left_par VAL_IDF right_par
;
CASE_COND:  
        cond_case VAL_IDF double_point INST CASE_COND
        |
;
DEFAULT_COND:
        cond_default double_point INST
        |
;
%%

int main(int argc, char** argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            printf("Failed to open the file: %s\n", argv[1]);
            return 1;
        }
        else {
            printf("File is successfully opened\n", argv[1]);
        }
    } 
    else {
        printf("Error: No file detected\n");
    }
    system("");
    yyparse();
    if (numError == 0)  show();
    else                printEndTab();
    fclose(yyin);
    return 0;
}

int yywrap() {}
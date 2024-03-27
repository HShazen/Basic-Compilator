%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "color.h"
#include "lexfunc.h"
#include "synt.tab.h"
extern YYSTYPE yylval;

/*lex variables -------------------------------------------------------*/
int nb_ligne = 1;
int nb_colone = 1;
char* val = "VAL";

char *f = "False", *t = "True", *none = "_"; 
%}

%option noyywrap
%option yylineno

/*declaration ---------------------------------------------------------*/
letter      [a-zA-Z]
number      [0-9]

/*identifire ----------------------------------------------------------*/
IDF         [A-Z]({letter}|{number}|_{letter}|_{number})*

/*integer and float numbers -------------------------------------------*/
signe       ("+"|"-")?
CONSTInt    {signe}{number}+
CONSTFloat  {signe}{number}*\.{number}+
CONSTBool   "true"|"false"
CONSTChar   \'(\\.|[^'])\'
CONSTString \"(\\.|[^\"])*\"


/*commantess ----------------------------------------------------------*/
COMMANTER   "/*"[^"*/"]*"*/"

%%
"FLOAT"     {insert(yytext, "t_float",      "KEY_WORD", none);   nb_colone += yyleng;      return t_float;      }
"BOOL"      {insert(yytext, "t_bool",       "KEY_WORD", none);   nb_colone += yyleng;      return t_bool;       }
"INT"       {insert(yytext, "t_int",        "KEY_WORD", none);   nb_colone += yyleng;      return t_int;        }

"CHAR"      {insert(yytext, "t_char",       "KEY_WORD", none);   nb_colone += yyleng;      return t_char;       }
"STRING"    {insert(yytext, "t_string",     "KEY_WORD", none);   nb_colone += yyleng;      return t_string;     }

"VOID"      {insert(yytext, "t_void",       "KEY_WORD", none);   nb_colone += yyleng;      return t_void;       }

"CONST"     {insert(yytext, "cost",         "KEY_WORD", none);   nb_colone += yyleng;      return cost;         }

"BEGIN"     {insert(yytext, "begin",        "KEY_WORD", none);   nb_colone += yyleng;      return begin;        }
"END"       {insert(yytext, "end",          "KEY_WORD", none);   nb_colone += yyleng;      return end;          }

"Function"  {insert(yytext, "func",         "KEY_WORD", none);   nb_colone += yyleng;      return func;         }

"For"       {insert(yytext, "loop_for",     "KEY_WORD", none);   nb_colone += yyleng;      return loop_for;     }
"Do"        {insert(yytext, "loop_do",      "KEY_WORD", none);   nb_colone += yyleng;      return loop_do;      }
"While"     {insert(yytext, "loop_while",   "KEY_WORD", none);   nb_colone += yyleng;      return loop_while;   }

"If"        {insert(yytext, "cond_if",      "KEY_WORD", none);   nb_colone += yyleng;      return cond_if;      }
"elseIf"    {insert(yytext, "cond_else_if", "KEY_WORD", none);   nb_colone += yyleng;      return cond_else_if; } 
"else"      {insert(yytext, "cond_else",    "KEY_WORD", none);   nb_colone += yyleng;      return cond_else;    }

"Switch"    {insert(yytext, "cond_switch",  "KEY_WORD", none);   nb_colone += yyleng;      return cond_switch;  }
"Case"      {insert(yytext, "cond_case",    "KEY_WORD", none);   nb_colone += yyleng;      return cond_case;    }
"Default"   {insert(yytext, "cond_default", "KEY_WORD", none);   nb_colone += yyleng;      return cond_default; }

"Continue"  {insert(yytext, "a_continue",   "KEY_WORD", none);   nb_colone += yyleng;      return a_continue;   }
"Break"     {insert(yytext, "a_break",      "KEY_WORD", none);   nb_colone += yyleng;      return a_break;      }
"Return"    {insert(yytext, "a_return",     "KEY_WORD", none);   nb_colone += yyleng;      return a_return;     }

{IDF} {
    if (yyleng <= 10) {
        insert(yytext,      "idf",          none,       none);   nb_colone += yyleng;
        yylval.u_str = strdup(yytext);
        return idf;
    }else {
        printf("Error 1: Variable name shouldn't have more than 10 characters!\n");
    }
}
{CONSTInt} {
    insert(yytext, "int_val", val, none);       nb_colone += yyleng;
    yylval.u_int = atoi(yytext);
    return int_val;
}
{CONSTFloat} {
    insert(yytext, "float_val", val, none);     nb_colone += yyleng;
    yylval.u_float = atoi(yytext);
    return float_val;
}
{CONSTBool} {
    insert(yytext, "bool_val", val, none);      nb_colone += yyleng;
    yylval.u_bool = (strdup(yytext) == "true") ? true : false;
    return bool_val;
}
{CONSTChar} {
    insert(yytext, "char_val", val, none);      nb_colone += yyleng;
    yylval.u_char = strdup(yytext);
    return char_val;
}
{CONSTString} {
    insert(yytext, "string_val", val, none);    nb_colone += yyleng;
    yylval.u_string = strdup(yytext);
    return string_val;
}
{COMMANTER} {
    insert("/*", "commanter", "SEPARATOR", none);
    insert("*/", "commanter", "SEPARATOR", none);
    nb_ligne += count_nl(yytext, yyleng);   
    nb_colone += yyleng;
}

"+"     {insert(yytext, "op_add",       "opARITHMETIC", none);   nb_colone += yyleng;      return op_add;       }   //addition
"-"     {insert(yytext, "op_sub",       "opARITHMETIC", none);   nb_colone += yyleng;      return op_sub;       }   //subtraction
"*"     {insert(yytext, "op_mul",       "opARITHMETIC", none);   nb_colone += yyleng;      return op_mul;       }   //multiplication
"/"     {insert(yytext, "op_div",       "opARITHMETIC", none);   nb_colone += yyleng;      return op_div;       }   //division

"--"    {insert(yytext, "short_sub",    "opARITHMETIC", none);   nb_colone += yyleng;      return short_sub;    }   //-= 1
"++"    {insert(yytext, "short_add",    "opARITHMETIC", none);   nb_colone += yyleng;      return short_add;    }   //+= 1

"=="    {insert(yytext, "eq",           "opLOGIC",      none);   nb_colone += yyleng;      return eq;           }   //equal to 
"<>"    {insert(yytext, "not_eq",       "opLOGIC",      none);   nb_colone += yyleng;      return not_eq;       }   //not equal to
"<"     {insert(yytext, "less",         "opLOGIC",      none);   nb_colone += yyleng;      return less;         }   //less than
">"     {insert(yytext, "greater",      "opLOGIC",      none);   nb_colone += yyleng;      return greater;      }   //greater than
"<="    {insert(yytext, "less_eq",      "opLOGIC",      none);   nb_colone += yyleng;      return less_eq;      }   //less or equal than
">="    {insert(yytext, "greater_eq",   "opLOGIC",      none);   nb_colone += yyleng;      return greater_eq;   }   //greater or equal than 

"("     {insert(yytext, "left_par",     "SEPARATOR",    none);   nb_colone += yyleng;      return left_par;     }   //left parenteases
")"     {insert(yytext, "right_par",    "SEPARATOR",    none);   nb_colone += yyleng;      return right_par;    }   //right parenteases

"{"     {insert(yytext, "left_cur",     "SEPARATOR",    none);   nb_colone += yyleng;      return left_cur;     }   //left curly brace
"}"     {insert(yytext, "right_cur",    "SEPARATOR",    none);   nb_colone += yyleng;      return right_cur;    }   //right curly brace

"="     {insert(yytext, "assign",       "ASSIGN",       none);   nb_colone += yyleng;      return assign;       }   //assign
":="    {insert(yytext, "aff",          "AFFECTATION",  none);   nb_colone += yyleng;      return aff;          }   //affectation

":"     {insert(yytext, "double_point", "SEPARATOR",    none);   nb_colone += yyleng;      return double_point; }   //double point

,       {insert(yytext, "sep",          "SEPARATOR",    none);   nb_colone += yyleng;      return sep;          }   //separator
;       {insert(yytext, "inst_end",     "SEPARATOR",    none);   nb_colone += yyleng;      return inst_end;     }   //end of instruction

\'      {insert(yytext, "quote",        "KEY_WORD",     none);   nb_colone += yyleng;      return quote;        }
\"      {insert(yytext, "double_quote", "KEY_WORD",     none);   nb_colone += yyleng;      return double_quote; }

"\n"    {nb_ligne ++; nb_colone = 1;}                                                                               //line conter
[ \t]   nb_colone += yyleng;                                                                                        //skip all spaces

.       printf("erreur lexical a la ligne: %d et la colon: %d\n", nb_ligne, nb_colone);
%%

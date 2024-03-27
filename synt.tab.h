/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SYNT_TAB_H_INCLUDED
# define YY_YY_SYNT_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    idf = 258,                     /* idf  */
    int_val = 259,                 /* int_val  */
    bool_val = 260,                /* bool_val  */
    char_val = 261,                /* char_val  */
    float_val = 262,               /* float_val  */
    string_val = 263,              /* string_val  */
    void_func = 264,               /* void_func  */
    op_sub = 265,                  /* op_sub  */
    op_add = 266,                  /* op_add  */
    op_mul = 267,                  /* op_mul  */
    op_div = 268,                  /* op_div  */
    short_add = 269,               /* short_add  */
    short_sub = 270,               /* short_sub  */
    less_eq = 271,                 /* less_eq  */
    greater_eq = 272,              /* greater_eq  */
    eq = 273,                      /* eq  */
    not_eq = 274,                  /* not_eq  */
    less = 275,                    /* less  */
    greater = 276,                 /* greater  */
    assign = 277,                  /* assign  */
    aff = 278,                     /* aff  */
    t_int = 279,                   /* t_int  */
    t_float = 280,                 /* t_float  */
    t_bool = 281,                  /* t_bool  */
    t_char = 282,                  /* t_char  */
    t_string = 283,                /* t_string  */
    t_void = 284,                  /* t_void  */
    cost = 285,                    /* cost  */
    func = 286,                    /* func  */
    loop_for = 287,                /* loop_for  */
    loop_do = 288,                 /* loop_do  */
    loop_while = 289,              /* loop_while  */
    cond_if = 290,                 /* cond_if  */
    cond_else = 291,               /* cond_else  */
    cond_else_if = 292,            /* cond_else_if  */
    cond_switch = 293,             /* cond_switch  */
    cond_case = 294,               /* cond_case  */
    cond_default = 295,            /* cond_default  */
    a_break = 296,                 /* a_break  */
    a_continue = 297,              /* a_continue  */
    a_return = 298,                /* a_return  */
    quote = 299,                   /* quote  */
    double_quote = 300,            /* double_quote  */
    left_par = 301,                /* left_par  */
    right_par = 302,               /* right_par  */
    left_cur = 303,                /* left_cur  */
    right_cur = 304,               /* right_cur  */
    inst_end = 305,                /* inst_end  */
    sep = 306,                     /* sep  */
    double_point = 307,            /* double_point  */
    end = 308,                     /* end  */
    begin = 309                    /* begin  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "synt.y"

    float u_float;
    bool  u_bool;
    int   u_int;
    char* u_char;
    char* u_string;
    char* u_str;
    char  u_op;

#line 128 "synt.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SYNT_TAB_H_INCLUDED  */

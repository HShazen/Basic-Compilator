/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "synt.y"

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

#line 97 "synt.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "synt.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_idf = 3,                        /* idf  */
  YYSYMBOL_int_val = 4,                    /* int_val  */
  YYSYMBOL_bool_val = 5,                   /* bool_val  */
  YYSYMBOL_char_val = 6,                   /* char_val  */
  YYSYMBOL_float_val = 7,                  /* float_val  */
  YYSYMBOL_string_val = 8,                 /* string_val  */
  YYSYMBOL_void_func = 9,                  /* void_func  */
  YYSYMBOL_op_sub = 10,                    /* op_sub  */
  YYSYMBOL_op_add = 11,                    /* op_add  */
  YYSYMBOL_op_mul = 12,                    /* op_mul  */
  YYSYMBOL_op_div = 13,                    /* op_div  */
  YYSYMBOL_short_add = 14,                 /* short_add  */
  YYSYMBOL_short_sub = 15,                 /* short_sub  */
  YYSYMBOL_less_eq = 16,                   /* less_eq  */
  YYSYMBOL_greater_eq = 17,                /* greater_eq  */
  YYSYMBOL_eq = 18,                        /* eq  */
  YYSYMBOL_not_eq = 19,                    /* not_eq  */
  YYSYMBOL_less = 20,                      /* less  */
  YYSYMBOL_greater = 21,                   /* greater  */
  YYSYMBOL_assign = 22,                    /* assign  */
  YYSYMBOL_aff = 23,                       /* aff  */
  YYSYMBOL_t_int = 24,                     /* t_int  */
  YYSYMBOL_t_float = 25,                   /* t_float  */
  YYSYMBOL_t_bool = 26,                    /* t_bool  */
  YYSYMBOL_t_char = 27,                    /* t_char  */
  YYSYMBOL_t_string = 28,                  /* t_string  */
  YYSYMBOL_t_void = 29,                    /* t_void  */
  YYSYMBOL_cost = 30,                      /* cost  */
  YYSYMBOL_func = 31,                      /* func  */
  YYSYMBOL_loop_for = 32,                  /* loop_for  */
  YYSYMBOL_loop_do = 33,                   /* loop_do  */
  YYSYMBOL_loop_while = 34,                /* loop_while  */
  YYSYMBOL_cond_if = 35,                   /* cond_if  */
  YYSYMBOL_cond_else = 36,                 /* cond_else  */
  YYSYMBOL_cond_else_if = 37,              /* cond_else_if  */
  YYSYMBOL_cond_switch = 38,               /* cond_switch  */
  YYSYMBOL_cond_case = 39,                 /* cond_case  */
  YYSYMBOL_cond_default = 40,              /* cond_default  */
  YYSYMBOL_a_break = 41,                   /* a_break  */
  YYSYMBOL_a_continue = 42,                /* a_continue  */
  YYSYMBOL_a_return = 43,                  /* a_return  */
  YYSYMBOL_quote = 44,                     /* quote  */
  YYSYMBOL_double_quote = 45,              /* double_quote  */
  YYSYMBOL_left_par = 46,                  /* left_par  */
  YYSYMBOL_right_par = 47,                 /* right_par  */
  YYSYMBOL_left_cur = 48,                  /* left_cur  */
  YYSYMBOL_right_cur = 49,                 /* right_cur  */
  YYSYMBOL_inst_end = 50,                  /* inst_end  */
  YYSYMBOL_sep = 51,                       /* sep  */
  YYSYMBOL_double_point = 52,              /* double_point  */
  YYSYMBOL_end = 53,                       /* end  */
  YYSYMBOL_begin = 54,                     /* begin  */
  YYSYMBOL_YYACCEPT = 55,                  /* $accept  */
  YYSYMBOL_S = 56,                         /* S  */
  YYSYMBOL_VAR_TYPE = 57,                  /* VAR_TYPE  */
  YYSYMBOL_CONST_TYPE = 58,                /* CONST_TYPE  */
  YYSYMBOL_VAL = 59,                       /* VAL  */
  YYSYMBOL_DECL = 60,                      /* DECL  */
  YYSYMBOL_TERMINAL_DECL = 61,             /* TERMINAL_DECL  */
  YYSYMBOL_VAR_DECL = 62,                  /* VAR_DECL  */
  YYSYMBOL_VAR_LIST = 63,                  /* VAR_LIST  */
  YYSYMBOL_CONST_DECL = 64,                /* CONST_DECL  */
  YYSYMBOL_CONST_LIST = 65,                /* CONST_LIST  */
  YYSYMBOL_FUNC = 66,                      /* FUNC  */
  YYSYMBOL_INST_DECL_IN_FUNC = 67,         /* INST_DECL_IN_FUNC  */
  YYSYMBOL_ARGS = 68,                      /* ARGS  */
  YYSYMBOL_ARGS_T = 69,                    /* ARGS_T  */
  YYSYMBOL_VAR_DECL_FUNC = 70,             /* VAR_DECL_FUNC  */
  YYSYMBOL_CONST_DECL_FUNC = 71,           /* CONST_DECL_FUNC  */
  YYSYMBOL_LIST_FUNC = 72,                 /* LIST_FUNC  */
  YYSYMBOL_INST = 73,                      /* INST  */
  YYSYMBOL_TERMINAL_INST = 74,             /* TERMINAL_INST  */
  YYSYMBOL_VAL_IDF = 75,                   /* VAL_IDF  */
  YYSYMBOL_AFFECTATION = 76,               /* AFFECTATION  */
  YYSYMBOL_EXPR = 77,                      /* EXPR  */
  YYSYMBOL_OP_ARI = 78,                    /* OP_ARI  */
  YYSYMBOL_OP_ARI_LIST = 79,               /* OP_ARI_LIST  */
  YYSYMBOL_PAR = 80,                       /* PAR  */
  YYSYMBOL_SHORT_OP = 81,                  /* SHORT_OP  */
  YYSYMBOL_COND = 82,                      /* COND  */
  YYSYMBOL_OP_REL = 83,                    /* OP_REL  */
  YYSYMBOL_ALL_LOOP = 84,                  /* ALL_LOOP  */
  YYSYMBOL_FOR_LOOP = 85,                  /* FOR_LOOP  */
  YYSYMBOL_FOR_RULE = 86,                  /* FOR_RULE  */
  YYSYMBOL_CHANGE = 87,                    /* CHANGE  */
  YYSYMBOL_WHILE_LOOP = 88,                /* WHILE_LOOP  */
  YYSYMBOL_DO_WHILE_LOOP = 89,             /* DO_WHILE_LOOP  */
  YYSYMBOL_WHILE_RULE = 90,                /* WHILE_RULE  */
  YYSYMBOL_ALL_IFS = 91,                   /* ALL_IFS  */
  YYSYMBOL_IF = 92,                        /* IF  */
  YYSYMBOL_IF_COND = 93,                   /* IF_COND  */
  YYSYMBOL_ELSE_IF_COND = 94,              /* ELSE_IF_COND  */
  YYSYMBOL_ELSE_COND = 95,                 /* ELSE_COND  */
  YYSYMBOL_SWITCH = 96,                    /* SWITCH  */
  YYSYMBOL_SWITCH_COND = 97,               /* SWITCH_COND  */
  YYSYMBOL_CASE_COND = 98,                 /* CASE_COND  */
  YYSYMBOL_DEFAULT_COND = 99               /* DEFAULT_COND  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   232

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  219

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   309


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    74,    74,    80,    81,    82,    83,    84,    87,    88,
      89,    90,    91,    95,    96,    97,    98,    99,   103,   104,
     107,   108,   109,   114,   117,   118,   123,   126,   130,   137,
     140,   149,   152,   153,   155,   156,   160,   164,   168,   169,
     170,   174,   175,   178,   179,   180,   181,   182,   183,   186,
     187,   191,   202,   203,   204,   205,   210,   211,   212,   213,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   225,
     226,   229,   230,   234,   235,   236,   237,   241,   242,   243,
     244,   245,   246,   251,   252,   253,   258,   261,   263,   265,
     266,   271,   274,   278,   282,   283,   287,   288,   289,   294,
     297,   298,   301,   305,   310,   313,   314,   317,   318
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "idf", "int_val",
  "bool_val", "char_val", "float_val", "string_val", "void_func", "op_sub",
  "op_add", "op_mul", "op_div", "short_add", "short_sub", "less_eq",
  "greater_eq", "eq", "not_eq", "less", "greater", "assign", "aff",
  "t_int", "t_float", "t_bool", "t_char", "t_string", "t_void", "cost",
  "func", "loop_for", "loop_do", "loop_while", "cond_if", "cond_else",
  "cond_else_if", "cond_switch", "cond_case", "cond_default", "a_break",
  "a_continue", "a_return", "quote", "double_quote", "left_par",
  "right_par", "left_cur", "right_cur", "inst_end", "sep", "double_point",
  "end", "begin", "$accept", "S", "VAR_TYPE", "CONST_TYPE", "VAL", "DECL",
  "TERMINAL_DECL", "VAR_DECL", "VAR_LIST", "CONST_DECL", "CONST_LIST",
  "FUNC", "INST_DECL_IN_FUNC", "ARGS", "ARGS_T", "VAR_DECL_FUNC",
  "CONST_DECL_FUNC", "LIST_FUNC", "INST", "TERMINAL_INST", "VAL_IDF",
  "AFFECTATION", "EXPR", "OP_ARI", "OP_ARI_LIST", "PAR", "SHORT_OP",
  "COND", "OP_REL", "ALL_LOOP", "FOR_LOOP", "FOR_RULE", "CHANGE",
  "WHILE_LOOP", "DO_WHILE_LOOP", "WHILE_RULE", "ALL_IFS", "IF", "IF_COND",
  "ELSE_IF_COND", "ELSE_COND", "SWITCH", "SWITCH_COND", "CASE_COND",
  "DEFAULT_COND", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-177)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      62,  -177,  -177,  -177,  -177,  -177,   -22,    76,    21,    10,
      29,   -11,    62,    -2,    19,  -177,    50,  -177,  -177,  -177,
    -177,  -177,  -177,     9,    70,  -177,    52,  -177,     4,  -177,
    -177,  -177,    26,    77,    33,   111,    60,    36,    58,    38,
      61,    89,    48,    72,    22,    55,     4,    86,  -177,  -177,
    -177,  -177,  -177,  -177,    15,  -177,    97,    69,  -177,    69,
    -177,  -177,  -177,  -177,  -177,    95,    22,   144,   101,     4,
      59,   102,    59,   124,  -177,  -177,  -177,    22,  -177,    45,
     103,  -177,  -177,  -177,   104,   105,   118,  -177,   116,   153,
     154,   112,   107,  -177,  -177,   113,    29,  -177,   115,     4,
     114,    59,   123,   119,     4,   120,   121,   122,   124,   124,
     124,   124,   125,  -177,  -177,     4,    59,  -177,   124,   130,
    -177,   139,   126,    69,  -177,   127,  -177,    59,   128,   138,
     129,  -177,  -177,  -177,  -177,  -177,  -177,    59,  -177,   131,
     133,  -177,   100,    45,    45,    45,    45,   124,  -177,   134,
     132,   110,   135,   136,   124,    69,   170,   175,    69,   140,
    -177,    38,   123,  -177,  -177,     4,  -177,  -177,  -177,  -177,
      22,  -177,  -177,  -177,  -177,    45,  -177,   141,     4,     4,
    -177,  -177,   137,     4,   107,   160,   142,   181,   143,    59,
     145,  -177,   148,     4,   116,  -177,  -177,  -177,  -177,   111,
    -177,     8,  -177,   149,  -177,  -177,  -177,    45,   150,  -177,
     107,  -177,  -177,  -177,  -177,  -177,   151,  -177,  -177
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      19,     3,     6,     4,     5,     7,     0,     0,     0,     0,
       0,     0,    19,     0,     0,    22,     0,     8,    11,     9,
      10,    12,     1,    25,     0,    23,     0,    26,    42,    18,
      20,    21,     0,     0,     0,     0,     0,    87,     0,     0,
       0,     0,     0,     0,     0,     0,    42,     0,    44,    83,
      84,    85,    45,    94,    98,    95,     0,    33,    24,    33,
      13,    14,    15,    16,    17,    28,     0,     0,     0,    42,
       0,     0,     0,     0,    46,    47,    50,     0,    49,    52,
       0,     2,    41,    43,     0,     0,     0,    97,   106,     0,
       0,     0,    40,    34,    35,     0,     0,    51,     0,    42,
       0,     0,    74,     0,    42,     0,     0,     0,    56,    57,
      59,    58,     0,    53,    48,    42,     0,    96,     0,   108,
      36,     0,     0,     0,    32,     0,    27,     0,     0,     0,
       0,    80,    82,    77,    78,    79,    81,     0,    93,     0,
       0,   104,    54,    60,    61,    63,    62,     0,    68,     0,
       0,     0,     0,     0,     0,    33,     0,     0,    33,     0,
      86,     0,    75,    73,    91,    42,    56,    57,    59,    58,
       0,    64,    65,    67,    66,     0,   102,     0,    42,    42,
     103,    37,     0,    42,    40,     0,     0,     0,     0,     0,
       0,    55,     0,    42,   106,   107,    30,    31,    38,     0,
      29,     0,    89,     0,    92,    76,    99,    69,     0,   105,
      40,    71,    72,    90,    88,    70,   100,    39,   101
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -177,  -177,     2,     3,   -35,   180,  -177,  -177,   164,  -177,
     106,  -177,    40,   -47,  -177,  -177,  -177,  -176,   -45,  -177,
     -33,   -63,   -61,    63,  -126,  -177,  -177,   -66,    39,  -177,
    -177,  -177,  -177,  -177,  -177,    42,  -177,  -177,  -177,   -16,
     146,  -177,  -177,    12,  -177
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     8,    89,    90,    78,    11,    12,    13,    25,    14,
      27,    15,   182,   183,    92,    93,    94,   124,    45,    46,
     102,    47,    80,   112,   113,   148,   213,   103,   137,    48,
      49,    68,   203,    50,    51,    71,    52,    53,    54,    86,
      87,    55,    56,   119,   153
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      65,    82,     9,    10,    98,    97,   105,    36,   198,    16,
      91,    79,    95,    23,     9,    10,   107,   171,   172,   173,
     174,    22,   211,   212,   100,    76,    60,    61,    62,    63,
      64,    66,    26,    79,   217,   130,    37,    38,    39,    40,
     106,    24,    41,    28,    79,    42,    43,    44,    30,   192,
     150,    84,    85,    32,   128,   108,   109,   110,   111,   139,
      33,   159,    76,    60,    61,    62,    63,    64,    77,    31,
     149,   163,    57,    34,    35,   143,   144,   145,   146,    59,
      23,   215,    67,    66,    70,   151,     1,     2,     3,     4,
       5,     6,     7,     1,     2,     3,     4,     5,    74,     7,
      17,    18,    19,    20,    21,   101,    69,    72,    81,   191,
     166,   167,   168,   169,   175,    60,    61,    62,    63,    64,
     190,   181,    75,   205,   202,   156,   157,    76,    60,    61,
      62,    63,    64,   194,   195,    73,    83,    79,   197,   131,
     132,   133,   134,   135,   136,    88,    96,    36,   208,    99,
     104,   116,   115,   114,    84,   118,   120,   121,   123,   122,
     125,   154,   178,   129,   210,   127,   138,   140,   141,   142,
     152,   147,   161,   184,   155,   158,   162,   160,   185,   177,
     164,   165,   199,   176,   201,   180,   196,   179,    85,   193,
     187,   200,    29,   204,   206,   207,   214,    58,   186,   216,
     218,   189,   126,   188,     0,   170,   209,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   117
};

static const yytype_int16 yycheck[] =
{
      35,    46,     0,     0,    67,    66,    72,     3,   184,    31,
      57,    44,    59,     3,    12,    12,    77,   143,   144,   145,
     146,     0,    14,    15,    69,     3,     4,     5,     6,     7,
       8,    23,     3,    66,   210,   101,    32,    33,    34,    35,
      73,    31,    38,    54,    77,    41,    42,    43,    50,   175,
     116,    36,    37,     3,    99,    10,    11,    12,    13,   104,
      51,   127,     3,     4,     5,     6,     7,     8,    46,    50,
     115,   137,    46,     3,    22,   108,   109,   110,   111,    46,
       3,   207,    46,    23,    46,   118,    24,    25,    26,    27,
      28,    29,    30,    24,    25,    26,    27,    28,    50,    30,
      24,    25,    26,    27,    28,    46,    48,    46,    53,   170,
      10,    11,    12,    13,   147,     4,     5,     6,     7,     8,
     165,   154,    50,   189,   187,   123,   123,     3,     4,     5,
       6,     7,     8,   178,   179,    46,    50,   170,   183,    16,
      17,    18,    19,    20,    21,    48,    51,     3,   193,    48,
      48,    46,    48,    50,    36,    39,     3,     3,    51,    47,
      47,    22,    52,    49,   199,    50,    47,    47,    47,    47,
      40,    46,    34,     3,    48,    48,    47,    49,     3,    47,
      49,    48,    22,    49,     3,    49,    49,    52,    37,    48,
      50,    49,    12,    50,    49,    47,    47,    33,   158,    49,
     216,   162,    96,   161,    -1,   142,   194,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    24,    25,    26,    27,    28,    29,    30,    56,    57,
      58,    60,    61,    62,    64,    66,    31,    24,    25,    26,
      27,    28,     0,     3,    31,    63,     3,    65,    54,    60,
      50,    50,     3,    51,     3,    22,     3,    32,    33,    34,
      35,    38,    41,    42,    43,    73,    74,    76,    84,    85,
      88,    89,    91,    92,    93,    96,    97,    46,    63,    46,
       4,     5,     6,     7,     8,    59,    23,    46,    86,    48,
      46,    90,    46,    46,    50,    50,     3,    46,    59,    75,
      77,    53,    73,    50,    36,    37,    94,    95,    48,    57,
      58,    68,    69,    70,    71,    68,    51,    77,    76,    48,
      73,    46,    75,    82,    48,    82,    75,    77,    10,    11,
      12,    13,    78,    79,    50,    48,    46,    95,    39,    98,
       3,     3,    47,    51,    72,    47,    65,    50,    73,    49,
      82,    16,    17,    18,    19,    20,    21,    83,    47,    73,
      47,    47,    47,    75,    75,    75,    75,    46,    80,    73,
      82,    75,    40,    99,    22,    48,    57,    58,    48,    82,
      49,    34,    47,    82,    49,    48,    10,    11,    12,    13,
      78,    79,    79,    79,    79,    75,    49,    47,    52,    52,
      49,    75,    67,    68,     3,     3,    67,    50,    90,    83,
      73,    77,    79,    48,    73,    73,    49,    73,    72,    22,
      49,     3,    76,    87,    50,    82,    49,    47,    73,    98,
      59,    14,    15,    81,    47,    79,    49,    72,    94
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    57,    57,    57,    57,    57,    58,    58,
      58,    58,    58,    59,    59,    59,    59,    59,    60,    60,
      61,    61,    61,    62,    63,    63,    64,    65,    65,    66,
      66,    67,    68,    68,    69,    69,    70,    71,    72,    72,
      72,    73,    73,    74,    74,    74,    74,    74,    74,    75,
      75,    76,    77,    77,    77,    77,    78,    78,    78,    78,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    80,
      80,    81,    81,    82,    82,    82,    82,    83,    83,    83,
      83,    83,    83,    84,    84,    84,    85,    86,    86,    87,
      87,    88,    89,    90,    91,    91,    92,    92,    92,    93,
      94,    94,    95,    96,    97,    98,    98,    99,    99
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     2,     0,
       2,     2,     1,     2,     3,     1,     2,     5,     3,     9,
       9,     2,     2,     0,     1,     1,     2,     4,     4,     6,
       0,     2,     0,     2,     1,     1,     2,     2,     3,     1,
       1,     3,     1,     2,     3,     5,     1,     1,     1,     1,
       2,     2,     2,     2,     3,     3,     3,     3,     2,     4,
       5,     1,     1,     3,     1,     3,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     0,     7,     1,
       2,     5,     7,     3,     1,     1,     3,     2,     1,     7,
       7,     8,     4,     5,     4,     5,     0,     3,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* S: DECL begin INST end  */
#line 75 "synt.y"
    {if (numError == 0) printf("Syntax correcte \n nb_ligne = %d\n", nb_ligne);  YYACCEPT;}
#line 1337 "synt.tab.c"
    break;

  case 3: /* VAR_TYPE: t_int  */
#line 80 "synt.y"
                                                        {Curr_type = "INT";     Curr_const = f; }
#line 1343 "synt.tab.c"
    break;

  case 4: /* VAR_TYPE: t_bool  */
#line 81 "synt.y"
                                                        {Curr_type = "BOOL";    Curr_const = f; }
#line 1349 "synt.tab.c"
    break;

  case 5: /* VAR_TYPE: t_char  */
#line 82 "synt.y"
                                                        {Curr_type = "CHAR";    Curr_const = f; }
#line 1355 "synt.tab.c"
    break;

  case 6: /* VAR_TYPE: t_float  */
#line 83 "synt.y"
                                                        {Curr_type = "FLOAT";   Curr_const = f; }
#line 1361 "synt.tab.c"
    break;

  case 7: /* VAR_TYPE: t_string  */
#line 84 "synt.y"
                                                        {Curr_type = "STRING";  Curr_const = f; }
#line 1367 "synt.tab.c"
    break;

  case 8: /* CONST_TYPE: cost t_int  */
#line 87 "synt.y"
                                                        {Curr_type = "INT";     Curr_const = t; }
#line 1373 "synt.tab.c"
    break;

  case 9: /* CONST_TYPE: cost t_bool  */
#line 88 "synt.y"
                                                        {Curr_type = "BOOL";    Curr_const = t; }
#line 1379 "synt.tab.c"
    break;

  case 10: /* CONST_TYPE: cost t_char  */
#line 89 "synt.y"
                                                        {Curr_type = "CHAR";    Curr_const = t; }
#line 1385 "synt.tab.c"
    break;

  case 11: /* CONST_TYPE: cost t_float  */
#line 90 "synt.y"
                                                        {Curr_type = "FLOAT";   Curr_const = t; }
#line 1391 "synt.tab.c"
    break;

  case 12: /* CONST_TYPE: cost t_string  */
#line 91 "synt.y"
                                                        {Curr_type = "STRING";  Curr_const = t; }
#line 1397 "synt.tab.c"
    break;

  case 13: /* VAL: int_val  */
#line 95 "synt.y"
                                                        {Curr_value_type= "INT";      (yyval.u_string)="INT";         isZero = ((yyvsp[0].u_int) == 0) ? true : false;      }
#line 1403 "synt.tab.c"
    break;

  case 14: /* VAL: bool_val  */
#line 96 "synt.y"
                                                        {Curr_value_type= "BOOL";     (yyval.u_string)="BOOL";        isZero = false;                         }
#line 1409 "synt.tab.c"
    break;

  case 15: /* VAL: char_val  */
#line 97 "synt.y"
                                                        {Curr_value_type= "CHAR";     (yyval.u_string)="CHAR";        isZero = false;                         }
#line 1415 "synt.tab.c"
    break;

  case 16: /* VAL: float_val  */
#line 98 "synt.y"
                                                        {Curr_value_type= "FLOAT";    (yyval.u_string)="FLOAT";       isZero = ((yyvsp[0].u_float) == 0.0) ? true : false;    }
#line 1421 "synt.tab.c"
    break;

  case 17: /* VAL: string_val  */
#line 99 "synt.y"
                                                        {Curr_value_type= "STRING";   (yyval.u_string)="STRING";      isZero = false;                         }
#line 1427 "synt.tab.c"
    break;

  case 24: /* VAR_LIST: idf sep VAR_LIST  */
#line 117 "synt.y"
                                                        {doubleDeclarationIdf((yyvsp[-2].u_str), Curr_type, Curr_const);}
#line 1433 "synt.tab.c"
    break;

  case 25: /* VAR_LIST: idf  */
#line 118 "synt.y"
                                                        {doubleDeclarationIdf((yyvsp[0].u_str), Curr_type, Curr_const);}
#line 1439 "synt.tab.c"
    break;

  case 27: /* CONST_LIST: idf assign VAL sep CONST_LIST  */
#line 126 "synt.y"
                                                        {
                                                                doubleDeclarationIdf((yyvsp[-4].u_str), Curr_type, Curr_const);       
                                                                typeMismatch(Curr_type, Curr_value_type);
                                                        }
#line 1448 "synt.tab.c"
    break;

  case 28: /* CONST_LIST: idf assign VAL  */
#line 130 "synt.y"
                                                        {
                                                                doubleDeclarationIdf((yyvsp[-2].u_str), Curr_type, Curr_const);       
                                                                typeMismatch(Curr_type, Curr_value_type);
                                                        }
#line 1457 "synt.tab.c"
    break;

  case 29: /* FUNC: VAR_TYPE func idf left_par ARGS right_par left_cur INST_DECL_IN_FUNC right_cur  */
#line 137 "synt.y"
                                                                                        {
                                                                                                doubleDeclarationFunc((yyvsp[-6].u_str), Curr_type, Curr_const);
                                                                                        }
#line 1465 "synt.tab.c"
    break;

  case 30: /* FUNC: t_void func idf left_par ARGS right_par left_cur INST_DECL_IN_FUNC right_cur  */
#line 140 "synt.y"
                                                                                                     {
                                                                                                doubleDeclarationFunc((yyvsp[-6].u_str), Curr_type, Curr_const);
                                                                                        }
#line 1473 "synt.tab.c"
    break;

  case 36: /* VAR_DECL_FUNC: VAR_TYPE idf  */
#line 160 "synt.y"
                                                        {doubleDeclarationIdfForFunc((yyvsp[0].u_str), Curr_type, Curr_const);}
#line 1479 "synt.tab.c"
    break;

  case 37: /* CONST_DECL_FUNC: CONST_TYPE idf assign VAL_IDF  */
#line 164 "synt.y"
                                                        {doubleDeclarationIdfForFunc((yyvsp[-2].u_str), Curr_type, Curr_const);}
#line 1485 "synt.tab.c"
    break;

  case 38: /* LIST_FUNC: sep VAR_TYPE idf LIST_FUNC  */
#line 168 "synt.y"
                                                        {doubleDeclarationIdfForFunc((yyvsp[-1].u_str), Curr_type, Curr_const);}
#line 1491 "synt.tab.c"
    break;

  case 39: /* LIST_FUNC: sep CONST_TYPE idf assign VAL LIST_FUNC  */
#line 169 "synt.y"
                                                        {doubleDeclarationIdfForFunc((yyvsp[-3].u_str), Curr_type, Curr_const);}
#line 1497 "synt.tab.c"
    break;

  case 49: /* VAL_IDF: VAL  */
#line 186 "synt.y"
                                                        {(yyval.u_string) = (yyvsp[0].u_string);}
#line 1503 "synt.tab.c"
    break;

  case 50: /* VAL_IDF: idf  */
#line 187 "synt.y"
                                                        {undeclaredIdf((yyvsp[0].u_str)); strcpy((yyval.u_string), idfType((yyvsp[0].u_str)));}
#line 1509 "synt.tab.c"
    break;

  case 51: /* AFFECTATION: idf aff EXPR  */
#line 191 "synt.y"
                                                        {       //printf("type = %s $1 = %s---AFFECTATION\n", /*idfType($1)*/"1", $1);
                                                                if (!undeclaredIdf((yyvsp[-2].u_str))){
                                                                       changeConstValue((yyvsp[-2].u_str));
                                                                       idfTypeTemp = idfType((yyvsp[-2].u_str));
                                                                       affTypeError(idfTypeTemp, (yyvsp[0].u_string));
                                                                }
                                                        }
#line 1521 "synt.tab.c"
    break;

  case 52: /* EXPR: VAL_IDF  */
#line 202 "synt.y"
                                                        {(yyval.u_string) = (yyvsp[0].u_string);/*printf("%s\n", $1);*/}
#line 1527 "synt.tab.c"
    break;

  case 53: /* EXPR: VAL_IDF OP_ARI_LIST  */
#line 203 "synt.y"
                                                        {(yyval.u_string) = exprTypeError((yyvsp[-1].u_string), (yyvsp[0].u_string));}
#line 1533 "synt.tab.c"
    break;

  case 54: /* EXPR: left_par EXPR right_par  */
#line 204 "synt.y"
                                                        {(yyval.u_string) = (yyvsp[-1].u_string);}
#line 1539 "synt.tab.c"
    break;

  case 55: /* EXPR: left_par EXPR right_par OP_ARI EXPR  */
#line 205 "synt.y"
                                                        {(yyval.u_string) = exprTypeError((yyvsp[-3].u_string), (yyvsp[0].u_string));}
#line 1545 "synt.tab.c"
    break;

  case 60: /* OP_ARI_LIST: op_sub VAL_IDF  */
#line 215 "synt.y"
                                                        {(yyval.u_string) = (yyvsp[0].u_string);}
#line 1551 "synt.tab.c"
    break;

  case 61: /* OP_ARI_LIST: op_add VAL_IDF  */
#line 216 "synt.y"
                                                        {(yyval.u_string) = (yyvsp[0].u_string);}
#line 1557 "synt.tab.c"
    break;

  case 62: /* OP_ARI_LIST: op_div VAL_IDF  */
#line 217 "synt.y"
                                                        {zeroDiv((yyvsp[0].u_string));       (yyval.u_string) = (yyvsp[0].u_string);}
#line 1563 "synt.tab.c"
    break;

  case 63: /* OP_ARI_LIST: op_mul VAL_IDF  */
#line 218 "synt.y"
                                                        {(yyval.u_string) = (yyvsp[0].u_string);}
#line 1569 "synt.tab.c"
    break;

  case 64: /* OP_ARI_LIST: op_sub VAL_IDF OP_ARI_LIST  */
#line 219 "synt.y"
                                                        {(yyval.u_string) = exprTypeError((yyvsp[-1].u_string), (yyvsp[0].u_string));}
#line 1575 "synt.tab.c"
    break;

  case 65: /* OP_ARI_LIST: op_add VAL_IDF OP_ARI_LIST  */
#line 220 "synt.y"
                                                        {(yyval.u_string) = exprTypeError((yyvsp[-1].u_string), (yyvsp[0].u_string));}
#line 1581 "synt.tab.c"
    break;

  case 66: /* OP_ARI_LIST: op_div VAL_IDF OP_ARI_LIST  */
#line 221 "synt.y"
                                                        {zeroDiv((yyvsp[-1].u_string));       (yyval.u_string) = exprTypeError((yyvsp[-1].u_string), (yyvsp[0].u_string));}
#line 1587 "synt.tab.c"
    break;

  case 67: /* OP_ARI_LIST: op_mul VAL_IDF OP_ARI_LIST  */
#line 222 "synt.y"
                                                        {(yyval.u_string) = exprTypeError((yyvsp[-1].u_string), (yyvsp[0].u_string));}
#line 1593 "synt.tab.c"
    break;

  case 68: /* OP_ARI_LIST: OP_ARI PAR  */
#line 223 "synt.y"
                                                        {(yyval.u_string) = (yyvsp[0].u_string);}
#line 1599 "synt.tab.c"
    break;

  case 69: /* PAR: left_par VAL_IDF OP_ARI_LIST right_par  */
#line 225 "synt.y"
                                                                {(yyval.u_string) = exprTypeError((yyvsp[-2].u_string), (yyvsp[-1].u_string));;}
#line 1605 "synt.tab.c"
    break;

  case 70: /* PAR: left_par VAL_IDF OP_ARI_LIST right_par OP_ARI_LIST  */
#line 226 "synt.y"
                                                                {(yyval.u_string) = (!strcmp((yyvsp[-3].u_string), (yyvsp[-2].u_string)) && !strcmp((yyvsp[-3].u_string), (yyvsp[0].u_string)) )?  (yyvsp[-3].u_string) : exprTypeError((yyvsp[-3].u_string), "exprTypeError");}
#line 1611 "synt.tab.c"
    break;

  case 90: /* CHANGE: idf SHORT_OP  */
#line 266 "synt.y"
                                                        {undeclaredIdf((yyvsp[-1].u_str));}
#line 1617 "synt.tab.c"
    break;


#line 1621 "synt.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 320 "synt.y"


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

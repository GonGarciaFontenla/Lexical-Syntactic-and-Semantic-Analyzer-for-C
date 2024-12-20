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
#line 1 "src/parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "general.h"

extern int yylex(void);
void yyerror(const char *s);

/* Declaracion de variables */
GenericNode* variable = NULL;
GenericNode* function = NULL;
GenericNode* error_list = NULL;
GenericNode* sentencias = NULL;
GenericNode* semantic_errors = NULL;
GenericNode* symbol_table = NULL;

t_variable* data_variable = NULL;
t_arguments* invocated_arguments = NULL;
t_function* data_function = NULL;
t_parameter data_parameter;
t_sent_or_unrecognised_token* data_sent = NULL;
t_semantic_error* data_sem_error = NULL; 
t_symbol_table* data_symbol = NULL;

int declaration_flag = 0; // Si está en declaracion
int semicolon_flag = 0; // Si hay un punto y coma
int parameter_flag = 0; // Si está dentro de los parametros de X funcion
int quantity_parameters = 0; // Cantidad de parametros
int assign_void_flag = 0; // Si se asigna una variable a una funcion void
int string_flag = 0;
char* type_aux = "";
int position = 1;


#line 108 "obj/src/parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFICADOR = 3,              /* IDENTIFICADOR  */
  YYSYMBOL_LITERAL_CADENA = 4,             /* LITERAL_CADENA  */
  YYSYMBOL_CONSTANTE = 5,                  /* CONSTANTE  */
  YYSYMBOL_ENUM = 6,                       /* ENUM  */
  YYSYMBOL_STRUCT = 7,                     /* STRUCT  */
  YYSYMBOL_UNION = 8,                      /* UNION  */
  YYSYMBOL_RETURN = 9,                     /* RETURN  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_DO = 13,                        /* DO  */
  YYSYMBOL_FOR = 14,                       /* FOR  */
  YYSYMBOL_DEFAULT = 15,                   /* DEFAULT  */
  YYSYMBOL_CASE = 16,                      /* CASE  */
  YYSYMBOL_CONTINUE = 17,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 18,                     /* BREAK  */
  YYSYMBOL_GOTO = 19,                      /* GOTO  */
  YYSYMBOL_SWITCH = 20,                    /* SWITCH  */
  YYSYMBOL_SIZEOF = 21,                    /* SIZEOF  */
  YYSYMBOL_ENTERO = 22,                    /* ENTERO  */
  YYSYMBOL_NUM = 23,                       /* NUM  */
  YYSYMBOL_ADD_ASSIGN = 24,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 25,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 26,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 27,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 28,                /* MOD_ASSIGN  */
  YYSYMBOL_EQ = 29,                        /* EQ  */
  YYSYMBOL_NEQ = 30,                       /* NEQ  */
  YYSYMBOL_LE = 31,                        /* LE  */
  YYSYMBOL_GE = 32,                        /* GE  */
  YYSYMBOL_AND = 33,                       /* AND  */
  YYSYMBOL_OR = 34,                        /* OR  */
  YYSYMBOL_PTR_OP = 35,                    /* PTR_OP  */
  YYSYMBOL_INC_OP = 36,                    /* INC_OP  */
  YYSYMBOL_DEC_OP = 37,                    /* DEC_OP  */
  YYSYMBOL_ELIPSIS = 38,                   /* ELIPSIS  */
  YYSYMBOL_INT_TYPE = 39,                  /* INT_TYPE  */
  YYSYMBOL_FLOAT = 40,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 41,                    /* DOUBLE  */
  YYSYMBOL_CHAR = 42,                      /* CHAR  */
  YYSYMBOL_VOID = 43,                      /* VOID  */
  YYSYMBOL_SHORT = 44,                     /* SHORT  */
  YYSYMBOL_LONG = 45,                      /* LONG  */
  YYSYMBOL_UNSIGNED = 46,                  /* UNSIGNED  */
  YYSYMBOL_SIGNED = 47,                    /* SIGNED  */
  YYSYMBOL_CONST = 48,                     /* CONST  */
  YYSYMBOL_VOLATILE = 49,                  /* VOLATILE  */
  YYSYMBOL_TYPEDEF = 50,                   /* TYPEDEF  */
  YYSYMBOL_STATIC = 51,                    /* STATIC  */
  YYSYMBOL_EXTERN = 52,                    /* EXTERN  */
  YYSYMBOL_AUTO = 53,                      /* AUTO  */
  YYSYMBOL_REGISTER = 54,                  /* REGISTER  */
  YYSYMBOL_THEN = 55,                      /* THEN  */
  YYSYMBOL_VACIO = 56,                     /* VACIO  */
  YYSYMBOL_57_ = 57,                       /* ','  */
  YYSYMBOL_58_ = 58,                       /* '='  */
  YYSYMBOL_59_ = 59,                       /* ';'  */
  YYSYMBOL_60_ = 60,                       /* ')'  */
  YYSYMBOL_AUXSENTENCIA = 61,              /* AUXSENTENCIA  */
  YYSYMBOL_IDENT_PREC = 62,                /* IDENT_PREC  */
  YYSYMBOL_63_ = 63,                       /* '('  */
  YYSYMBOL_64_ = 64,                       /* '{'  */
  YYSYMBOL_65_ = 65,                       /* '}'  */
  YYSYMBOL_66_ = 66,                       /* ':'  */
  YYSYMBOL_67_ = 67,                       /* '?'  */
  YYSYMBOL_68_ = 68,                       /* '<'  */
  YYSYMBOL_69_ = 69,                       /* '>'  */
  YYSYMBOL_70_ = 70,                       /* '+'  */
  YYSYMBOL_71_ = 71,                       /* '-'  */
  YYSYMBOL_72_ = 72,                       /* '*'  */
  YYSYMBOL_73_ = 73,                       /* '/'  */
  YYSYMBOL_74_ = 74,                       /* '%'  */
  YYSYMBOL_75_ = 75,                       /* '&'  */
  YYSYMBOL_76_ = 76,                       /* '!'  */
  YYSYMBOL_77_ = 77,                       /* '['  */
  YYSYMBOL_78_ = 78,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 79,                  /* $accept  */
  YYSYMBOL_programa = 80,                  /* programa  */
  YYSYMBOL_unidadTraduccion = 81,          /* unidadTraduccion  */
  YYSYMBOL_sentencia = 82,                 /* sentencia  */
  YYSYMBOL_sentCompuesta = 83,             /* sentCompuesta  */
  YYSYMBOL_84_1 = 84,                      /* $@1  */
  YYSYMBOL_listaDeclaraciones = 85,        /* listaDeclaraciones  */
  YYSYMBOL_listaDeclaracionOp = 86,        /* listaDeclaracionOp  */
  YYSYMBOL_listaSentencias = 87,           /* listaSentencias  */
  YYSYMBOL_listaSentenciasOp = 88,         /* listaSentenciasOp  */
  YYSYMBOL_sentExpresion = 89,             /* sentExpresion  */
  YYSYMBOL_opcionExpresion = 90,           /* opcionExpresion  */
  YYSYMBOL_sentSeleccion = 91,             /* sentSeleccion  */
  YYSYMBOL_92_2 = 92,                      /* $@2  */
  YYSYMBOL_sentIteracion = 93,             /* sentIteracion  */
  YYSYMBOL_expresionOp = 94,               /* expresionOp  */
  YYSYMBOL_sentEtiquetadas = 95,           /* sentEtiquetadas  */
  YYSYMBOL_sentSalto = 96,                 /* sentSalto  */
  YYSYMBOL_expresion = 97,                 /* expresion  */
  YYSYMBOL_expAsignacion = 98,             /* expAsignacion  */
  YYSYMBOL_operAsignacion = 99,            /* operAsignacion  */
  YYSYMBOL_expCondicional = 100,           /* expCondicional  */
  YYSYMBOL_expOr = 101,                    /* expOr  */
  YYSYMBOL_expAnd = 102,                   /* expAnd  */
  YYSYMBOL_expIgualdad = 103,              /* expIgualdad  */
  YYSYMBOL_opcionIgualdad = 104,           /* opcionIgualdad  */
  YYSYMBOL_expRelacional = 105,            /* expRelacional  */
  YYSYMBOL_opcionRelacional = 106,         /* opcionRelacional  */
  YYSYMBOL_expAditiva = 107,               /* expAditiva  */
  YYSYMBOL_opcionAditiva = 108,            /* opcionAditiva  */
  YYSYMBOL_expMultiplicativa = 109,        /* expMultiplicativa  */
  YYSYMBOL_expUnaria = 110,                /* expUnaria  */
  YYSYMBOL_opcionIncDec = 111,             /* opcionIncDec  */
  YYSYMBOL_operUnario = 112,               /* operUnario  */
  YYSYMBOL_expPostfijo = 113,              /* expPostfijo  */
  YYSYMBOL_opcionPostfijo = 114,           /* opcionPostfijo  */
  YYSYMBOL_115_3 = 115,                    /* $@3  */
  YYSYMBOL_listaArgumentosNoVacia = 116,   /* listaArgumentosNoVacia  */
  YYSYMBOL_masListaArgumentos = 117,       /* masListaArgumentos  */
  YYSYMBOL_expPrimaria = 118,              /* expPrimaria  */
  YYSYMBOL_tipoDato = 119,                 /* tipoDato  */
  YYSYMBOL_nombreTipo = 120,               /* nombreTipo  */
  YYSYMBOL_declaracionExterna = 121,       /* declaracionExterna  */
  YYSYMBOL_definicionFuncion = 122,        /* definicionFuncion  */
  YYSYMBOL_declaracion = 123,              /* declaracion  */
  YYSYMBOL_especificadorDeclaracion = 124, /* especificadorDeclaracion  */
  YYSYMBOL_especificadorDeclaracionOp = 125, /* especificadorDeclaracionOp  */
  YYSYMBOL_especificadorCompleto = 126,    /* especificadorCompleto  */
  YYSYMBOL_tipoAlmacenamiento = 127,       /* tipoAlmacenamiento  */
  YYSYMBOL_calificadorTipo = 128,          /* calificadorTipo  */
  YYSYMBOL_listaDeclaradores = 129,        /* listaDeclaradores  */
  YYSYMBOL_declarador = 130,               /* declarador  */
  YYSYMBOL_opcionPostDeclarador = 131,     /* opcionPostDeclarador  */
  YYSYMBOL_opcionComa = 132,               /* opcionComa  */
  YYSYMBOL_listaInicializadores = 133,     /* listaInicializadores  */
  YYSYMBOL_inicializador = 134,            /* inicializador  */
  YYSYMBOL_especificadorTipo = 135,        /* especificadorTipo  */
  YYSYMBOL_especificadorStructUnion = 136, /* especificadorStructUnion  */
  YYSYMBOL_structUnion = 137,              /* structUnion  */
  YYSYMBOL_cuerpoEspecificador = 138,      /* cuerpoEspecificador  */
  YYSYMBOL_cuerpoStructOp = 139,           /* cuerpoStructOp  */
  YYSYMBOL_listaDeclaracionesStruct = 140, /* listaDeclaracionesStruct  */
  YYSYMBOL_declaracionStruct = 141,        /* declaracionStruct  */
  YYSYMBOL_listaCalificadores = 142,       /* listaCalificadores  */
  YYSYMBOL_listaCalificadoresOp = 143,     /* listaCalificadoresOp  */
  YYSYMBOL_declaradoresStruct = 144,       /* declaradoresStruct  */
  YYSYMBOL_declaStruct = 145,              /* declaStruct  */
  YYSYMBOL_declaSi = 146,                  /* declaSi  */
  YYSYMBOL_expConstanteOp = 147,           /* expConstanteOp  */
  YYSYMBOL_decla = 148,                    /* decla  */
  YYSYMBOL_punteroOp = 149,                /* punteroOp  */
  YYSYMBOL_puntero = 150,                  /* puntero  */
  YYSYMBOL_listaCalificadoresTipoOp = 151, /* listaCalificadoresTipoOp  */
  YYSYMBOL_listaCalificadoresTipo = 152,   /* listaCalificadoresTipo  */
  YYSYMBOL_declaradorDirecto = 153,        /* declaradorDirecto  */
  YYSYMBOL_continuacionDeclaradorDirecto = 154, /* continuacionDeclaradorDirecto  */
  YYSYMBOL_opcional = 155,                 /* opcional  */
  YYSYMBOL_listaTiposParametros = 156,     /* listaTiposParametros  */
  YYSYMBOL_opcionalListaParametros = 157,  /* opcionalListaParametros  */
  YYSYMBOL_listaParametros = 158,          /* listaParametros  */
  YYSYMBOL_declaracionParametro = 159,     /* declaracionParametro  */
  YYSYMBOL_opcionesDecla = 160,            /* opcionesDecla  */
  YYSYMBOL_listaIdentificadores = 161,     /* listaIdentificadores  */
  YYSYMBOL_especificadorEnum = 162,        /* especificadorEnum  */
  YYSYMBOL_opcionalEspecificadorEnum = 163, /* opcionalEspecificadorEnum  */
  YYSYMBOL_opcionalListaEnumeradores = 164, /* opcionalListaEnumeradores  */
  YYSYMBOL_listaEnumeradores = 165,        /* listaEnumeradores  */
  YYSYMBOL_enumerador = 166,               /* enumerador  */
  YYSYMBOL_opcionalEnumerador = 167        /* opcionalEnumerador  */
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
typedef yytype_int16 yy_state_t;

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

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  37
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   679

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  89
/* YYNRULES -- Number of rules.  */
#define YYNRULES  203
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  322

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   313


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
       2,     2,     2,    76,     2,     2,     2,    74,    75,     2,
      63,    60,    72,    70,    57,    71,     2,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    66,    59,
      68,    58,    69,    67,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    77,     2,    78,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,     2,    65,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    61,    62
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    89,    89,    93,    94,    98,    99,   100,   101,   102,
     103,   107,   107,   111,   112,   116,   117,   121,   122,   126,
     127,   131,   132,   136,   137,   141,   142,   143,   143,   147,
     148,   149,   153,   154,   158,   159,   160,   164,   170,   171,
     172,   176,   177,   181,   182,   189,   193,   194,   195,   196,
     197,   198,   202,   203,   207,   208,   212,   213,   217,   218,
     222,   223,   227,   228,   232,   233,   234,   235,   239,   240,
     244,   245,   249,   250,   255,   256,   260,   261,   262,   263,
     264,   268,   269,   273,   274,   275,   276,   280,   281,   282,
     295,   308,   309,   309,   310,   314,   320,   323,   327,   345,
     353,   361,   369,   378,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   396,   400,   401,   405,   416,   417,   429,
     436,   437,   441,   442,   443,   447,   448,   452,   453,   454,
     455,   456,   460,   466,   475,   479,   480,   490,   491,   495,
     496,   500,   501,   505,   506,   507,   511,   515,   515,   519,
     520,   524,   525,   529,   530,   534,   538,   539,   543,   544,
     548,   549,   553,   554,   558,   562,   563,   567,   571,   572,
     576,   580,   581,   585,   586,   590,   596,   597,   601,   602,
     606,   607,   608,   609,   617,   621,   622,   626,   629,   635,
     650,   651,   657,   658,   662,   666,   667,   671,   672,   676,
     677,   681,   685,   686
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFICADOR",
  "LITERAL_CADENA", "CONSTANTE", "ENUM", "STRUCT", "UNION", "RETURN", "IF",
  "ELSE", "WHILE", "DO", "FOR", "DEFAULT", "CASE", "CONTINUE", "BREAK",
  "GOTO", "SWITCH", "SIZEOF", "ENTERO", "NUM", "ADD_ASSIGN", "SUB_ASSIGN",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "EQ", "NEQ", "LE", "GE", "AND",
  "OR", "PTR_OP", "INC_OP", "DEC_OP", "ELIPSIS", "INT_TYPE", "FLOAT",
  "DOUBLE", "CHAR", "VOID", "SHORT", "LONG", "UNSIGNED", "SIGNED", "CONST",
  "VOLATILE", "TYPEDEF", "STATIC", "EXTERN", "AUTO", "REGISTER", "THEN",
  "VACIO", "','", "'='", "';'", "')'", "AUXSENTENCIA", "IDENT_PREC", "'('",
  "'{'", "'}'", "':'", "'?'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'&'", "'!'", "'['", "']'", "$accept", "programa",
  "unidadTraduccion", "sentencia", "sentCompuesta", "$@1",
  "listaDeclaraciones", "listaDeclaracionOp", "listaSentencias",
  "listaSentenciasOp", "sentExpresion", "opcionExpresion", "sentSeleccion",
  "$@2", "sentIteracion", "expresionOp", "sentEtiquetadas", "sentSalto",
  "expresion", "expAsignacion", "operAsignacion", "expCondicional",
  "expOr", "expAnd", "expIgualdad", "opcionIgualdad", "expRelacional",
  "opcionRelacional", "expAditiva", "opcionAditiva", "expMultiplicativa",
  "expUnaria", "opcionIncDec", "operUnario", "expPostfijo",
  "opcionPostfijo", "$@3", "listaArgumentosNoVacia", "masListaArgumentos",
  "expPrimaria", "tipoDato", "nombreTipo", "declaracionExterna",
  "definicionFuncion", "declaracion", "especificadorDeclaracion",
  "especificadorDeclaracionOp", "especificadorCompleto",
  "tipoAlmacenamiento", "calificadorTipo", "listaDeclaradores",
  "declarador", "opcionPostDeclarador", "opcionComa",
  "listaInicializadores", "inicializador", "especificadorTipo",
  "especificadorStructUnion", "structUnion", "cuerpoEspecificador",
  "cuerpoStructOp", "listaDeclaracionesStruct", "declaracionStruct",
  "listaCalificadores", "listaCalificadoresOp", "declaradoresStruct",
  "declaStruct", "declaSi", "expConstanteOp", "decla", "punteroOp",
  "puntero", "listaCalificadoresTipoOp", "listaCalificadoresTipo",
  "declaradorDirecto", "continuacionDeclaradorDirecto", "opcional",
  "listaTiposParametros", "opcionalListaParametros", "listaParametros",
  "declaracionParametro", "opcionesDecla", "listaIdentificadores",
  "especificadorEnum", "opcionalEspecificadorEnum",
  "opcionalListaEnumeradores", "listaEnumeradores", "enumerador",
  "opcionalEnumerador", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-289)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-191)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     603,    16,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,
    -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,
      14,   603,  -289,  -289,  -289,  -289,   -47,  -289,   603,   603,
     603,  -289,    17,  -289,    -9,    59,  -289,  -289,  -289,   113,
      41,  -289,   446,    26,  -289,  -289,  -289,  -289,  -289,    27,
     625,  -289,    59,  -289,    39,    -6,  -289,  -289,   -47,   113,
     -47,  -289,  -289,   345,  -289,  -289,    38,   554,   -47,  -289,
    -289,   -47,   -19,   625,  -289,   625,   625,   473,  -289,    29,
      31,   402,  -289,    59,  -289,  -289,  -289,  -289,    50,   -24,
    -289,  -289,    54,  -289,  -289,  -289,  -289,   402,   345,  -289,
    -289,  -289,  -289,  -289,  -289,   -13,    94,   141,   -22,   149,
     114,   148,   127,   402,    89,  -289,  -289,  -289,  -289,  -289,
     167,    73,   527,    69,  -289,   500,  -289,  -289,  -289,  -289,
    -289,   402,    56,  -289,  -289,    69,  -289,  -289,    83,  -289,
     144,    91,   402,  -289,   138,    95,   103,  -289,   402,   402,
     402,   402,   402,  -289,   402,   402,   402,   402,  -289,   402,
     402,  -289,   402,   402,   402,  -289,  -289,  -289,  -289,  -289,
    -289,    82,   139,  -289,  -289,  -289,  -289,   554,  -289,  -289,
    -289,   108,    -8,  -289,   129,   170,  -289,     0,   402,   123,
    -289,  -289,    29,  -289,  -289,   402,  -289,  -289,   402,   152,
    -289,   173,  -289,   345,   176,    94,  -289,   177,   141,   -22,
     -22,   149,   149,   149,   149,   114,   114,  -289,  -289,  -289,
    -289,  -289,   195,  -289,  -289,  -289,  -289,   576,  -289,   239,
    -289,  -289,  -289,  -289,  -289,  -289,   184,  -289,  -289,  -289,
    -289,   402,  -289,    71,   374,   182,   183,   300,   185,   181,
     402,   190,   191,   249,   192,  -289,  -289,   195,  -289,  -289,
     188,  -289,  -289,  -289,  -289,  -289,    25,  -289,  -289,  -289,
     199,  -289,  -289,   300,  -289,   402,   402,   245,   402,   271,
     194,  -289,  -289,   202,   402,  -289,  -289,  -289,  -289,  -289,
     402,  -289,   203,   204,   205,   206,  -289,  -289,   271,  -289,
     209,  -289,   300,   300,   402,   402,  -289,  -289,   251,  -289,
     213,   218,   300,   300,   219,   402,  -289,  -289,  -289,   222,
     300,  -289
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,   147,   148,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   125,   126,   127,   128,   129,   130,   131,
       0,     2,   143,     3,   114,   115,   169,   119,   121,   121,
     121,   144,     0,   145,   198,     0,   194,     1,     4,   172,
       0,   132,     0,     0,   168,   122,   120,   124,   123,   152,
       0,   146,     0,   195,   203,     0,   199,   173,   169,   171,
     169,   117,    14,     0,   118,    15,     0,     0,   169,   134,
     175,   169,   167,     0,   150,   159,   159,     0,   153,   169,
       0,     0,   201,     0,   196,   170,   174,   133,   135,    98,
     102,   101,     0,    99,   100,    81,    82,     0,     0,    85,
      84,    83,    86,   141,    43,    52,    54,    56,    58,    62,
      68,    72,     0,     0,    76,    87,   136,    11,   116,    13,
     135,     0,     0,   166,   177,     0,   158,   157,   156,   149,
     154,     0,     0,   160,   162,   166,   197,   202,    41,   200,
       0,    92,     0,    89,     0,     0,   138,   139,     0,     0,
       0,     0,     0,    59,     0,     0,     0,     0,    63,     0,
       0,    69,     0,     0,     0,    47,    48,    49,    50,    51,
      46,     0,    77,    79,    98,    78,    88,     0,   176,   192,
     180,   143,   169,   179,     0,   186,   187,     0,     0,     0,
     151,   163,   169,   155,   164,     0,    94,    90,     0,     0,
     113,     0,   103,   137,     0,    55,    72,     0,    57,    60,
      61,    66,    67,    64,    65,    70,    71,    73,    74,    75,
      45,    44,     0,   183,   191,   189,   181,     0,   184,     0,
     182,   165,   178,   161,    42,    97,     0,    91,    80,   140,
     142,     0,    18,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    20,    21,     0,     5,    19,
       0,     6,     7,     8,     9,    10,     0,   185,   188,   193,
      95,    93,    53,     0,    37,     0,     0,     0,    33,     0,
       0,    38,    39,     0,     0,    17,    12,    24,    23,    22,
       0,    34,     0,     0,     0,     0,    32,    36,     0,    40,
       0,    96,     0,     0,     0,    33,    35,    27,    25,    29,
       0,     0,     0,     0,     0,    33,    28,    26,    30,     0,
       0,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -289,  -289,  -289,  -174,   229,  -289,   -61,  -289,  -267,    40,
      35,  -289,  -289,  -289,  -289,  -288,  -289,  -289,   -81,   -62,
    -289,    55,  -289,   150,   151,  -289,    70,  -289,   -34,  -289,
      76,   -85,   186,  -289,   187,  -289,  -289,  -289,  -289,   -96,
    -109,  -289,   281,  -289,    22,     2,   208,   163,  -289,   -35,
    -289,   246,  -289,  -289,  -289,   -93,   -43,  -289,  -289,  -289,
    -289,   238,   -69,   164,   248,  -289,   133,  -289,   193,   -23,
     268,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,
     100,  -289,  -289,  -289,  -289,  -289,   277,   250,  -289
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    20,    21,   257,   258,   177,    65,    66,   259,   260,
     261,   289,   262,   312,   263,   295,   264,   265,   266,   138,
     171,   104,   105,   106,   107,   153,   108,   158,   109,   161,
     110,   111,   112,   113,   114,   143,   198,   236,   270,   115,
      22,   201,    23,    24,    67,    68,    45,    27,    28,    29,
      40,    41,    69,   204,   146,   116,    30,    31,    32,    51,
      74,    77,    78,    79,   127,   132,   133,   134,   189,   135,
      43,    44,    58,    59,    72,   124,   183,   184,   228,   185,
     186,   225,   187,    33,    36,    53,    55,    56,    82
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     137,   103,    26,    42,    57,   147,   119,    76,   130,   154,
     155,   140,   297,   181,    37,    75,   145,   311,   176,    34,
      49,   148,    25,    26,    86,    39,   287,   319,   173,    70,
      76,   306,    76,    76,    76,   200,   103,    88,    75,   141,
      75,    75,    75,    25,   122,   120,   156,   157,   121,  -190,
     191,    83,  -190,   142,   149,    52,   130,   229,   123,    84,
     230,   199,    54,   206,    39,   206,   206,   206,   207,   206,
     206,   206,   206,   277,   206,   206,   176,   217,   218,   219,
      35,    50,    76,   220,   288,    89,    90,    91,    83,    71,
      75,    73,   174,    90,    91,   131,   136,    81,    60,   291,
      61,    39,   117,    92,    93,    94,   140,   231,    63,   221,
     239,    93,    94,   192,   234,   193,   222,   144,    95,    96,
     211,   212,   213,   214,   182,    95,    96,   150,   308,   309,
      89,    90,    91,   178,   141,   188,   235,   273,   316,   317,
     195,   103,   174,    90,    91,    97,   321,   196,   142,    93,
      94,   197,    97,    99,   100,   202,   206,   101,   102,   224,
     203,    93,    94,    15,    16,    17,    18,    19,   223,   280,
     151,   152,   165,   166,   167,   168,   169,     4,     5,     6,
       7,     8,     9,    10,    11,    12,   162,   163,   164,   226,
      97,    46,    46,    46,   292,   293,   242,   296,   243,    90,
      91,   232,    97,   300,   244,   245,   170,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    92,    93,    94,   159,
     160,   209,   210,   310,   296,    63,    64,   227,   301,   182,
     237,    95,    96,   238,   296,   215,   216,    47,    48,   126,
     126,   240,   269,   241,   271,   275,   276,   279,   278,   281,
     282,   255,   283,   286,   256,   284,   290,   294,    97,   117,
     298,   299,   313,   302,   303,   305,    99,   100,   304,   307,
     101,   102,   242,   314,   243,    90,    91,   315,   318,   274,
     244,   245,   320,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    92,    93,    94,   118,   272,   285,   205,   172,
     175,   208,    38,   243,    90,    91,    87,    95,    96,   244,
     245,   125,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    92,    93,    94,   128,   233,    85,   268,   194,    80,
     256,     0,     0,   139,    97,   117,    95,    96,     0,     0,
       0,     0,    99,   100,     0,     0,   101,   102,    89,    90,
      91,     0,     0,     0,     0,     0,     0,     0,     0,   256,
       0,     0,     0,    97,   117,     0,    92,    93,    94,     0,
       0,    99,   100,     0,     0,   101,   102,    89,    90,    91,
       0,    95,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,    93,    94,     0,     0,
       0,     0,     0,     0,     0,    89,    90,    91,    97,    98,
      95,    96,     0,     0,     0,     0,    99,   100,     0,     0,
     101,   102,     0,    92,    93,    94,     0,     0,     0,     0,
       0,     0,     0,   256,     0,     0,     0,    97,    95,    96,
       0,     0,     0,     0,     0,    99,   100,    62,     0,   101,
     102,     0,     1,     2,     3,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,     0,     0,     0,     0,
       0,     0,     0,    99,   100,     0,     0,   101,   102,     1,
       2,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,     0,     0,  -135,    63,    64,     1,     2,     3,     0,
     -16,     0,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,     0,    15,    16,    17,    18,    19,     0,     0,
     179,     0,     0,     1,     2,     3,     0,     0,   129,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     0,     0,
      15,    16,    17,    18,    19,    62,     0,     0,     0,     0,
       1,     2,     3,     0,     0,   190,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     1,     2,     3,     0,     0,   180,     0,     0,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     1,
       2,     3,     0,     0,   267,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,     1,     2,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,    15,    16,    17,    18,    19
};

static const yytype_int16 yycheck[] =
{
      81,    63,     0,    26,    39,    98,    67,    50,    77,    31,
      32,    35,   279,   122,     0,    50,    97,   305,   114,     3,
       3,    34,     0,    21,    59,    72,     1,   315,   113,     3,
      73,   298,    75,    76,    77,   144,    98,    60,    73,    63,
      75,    76,    77,    21,    63,    68,    68,    69,    71,    57,
     131,    57,    60,    77,    67,    64,   125,    57,    77,    65,
      60,   142,     3,   148,    72,   150,   151,   152,   149,   154,
     155,   156,   157,   247,   159,   160,   172,   162,   163,   164,
      64,    64,   125,     1,    59,     3,     4,     5,    57,    63,
     125,    64,     3,     4,     5,    66,    65,    58,    57,   273,
      59,    72,    64,    21,    22,    23,    35,   188,    58,   171,
     203,    22,    23,    57,   195,    59,   177,    63,    36,    37,
     154,   155,   156,   157,   122,    36,    37,    33,   302,   303,
       3,     4,     5,    60,    63,    66,   198,    66,   312,   313,
      57,   203,     3,     4,     5,    63,   320,     3,    77,    22,
      23,    60,    63,    71,    72,    60,   241,    75,    76,   182,
      57,    22,    23,    50,    51,    52,    53,    54,    60,   250,
      29,    30,    24,    25,    26,    27,    28,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    72,    73,    74,    60,
      63,    28,    29,    30,   275,   276,     1,   278,     3,     4,
       5,    78,    63,   284,     9,    10,    58,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    70,
      71,   151,   152,   304,   305,    58,    59,    57,   290,   227,
      78,    36,    37,    60,   315,   159,   160,    29,    30,    75,
      76,    65,     3,    66,    60,    63,    63,    66,    63,    59,
      59,    56,     3,    65,    59,    63,    57,    12,    63,    64,
      66,    59,    11,    60,    60,    59,    71,    72,    63,    60,
      75,    76,     1,    60,     3,     4,     5,    59,    59,   244,
       9,    10,    60,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    66,   241,   257,   148,   112,
     114,   150,    21,     3,     4,     5,    60,    36,    37,     9,
      10,    73,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    76,   192,    58,   227,   135,    52,
      59,    -1,    -1,    83,    63,    64,    36,    37,    -1,    -1,
      -1,    -1,    71,    72,    -1,    -1,    75,    76,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    -1,    63,    64,    -1,    21,    22,    23,    -1,
      -1,    71,    72,    -1,    -1,    75,    76,     3,     4,     5,
      -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    63,    64,
      36,    37,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,
      75,    76,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    -1,    -1,    -1,    63,    36,    37,
      -1,    -1,    -1,    -1,    -1,    71,    72,     1,    -1,    75,
      76,    -1,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    -1,    -1,    75,    76,     6,
       7,     8,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    -1,    57,    58,    59,     6,     7,     8,    -1,
      64,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    50,    51,    52,    53,    54,    -1,    -1,
       3,    -1,    -1,     6,     7,     8,    -1,    -1,    65,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      50,    51,    52,    53,    54,     1,    -1,    -1,    -1,    -1,
       6,     7,     8,    -1,    -1,    65,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,     6,     7,     8,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,     6,
       7,     8,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    50,    51,    52,    53,    54
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      80,    81,   119,   121,   122,   123,   124,   126,   127,   128,
     135,   136,   137,   162,     3,    64,   163,     0,   121,    72,
     129,   130,   148,   149,   150,   125,   126,   125,   125,     3,
      64,   138,    64,   164,     3,   165,   166,   128,   151,   152,
      57,    59,     1,    58,    59,    85,    86,   123,   124,   131,
       3,    63,   153,    64,   139,   128,   135,   140,   141,   142,
     165,    58,   167,    57,    65,   149,   128,   130,   148,     3,
       4,     5,    21,    22,    23,    36,    37,    63,    64,    71,
      72,    75,    76,    98,   100,   101,   102,   103,   105,   107,
     109,   110,   111,   112,   113,   118,   134,    64,    83,    85,
     148,   148,    63,    77,   154,   140,   142,   143,   143,    65,
     141,    66,   144,   145,   146,   148,    65,    97,    98,   166,
      35,    63,    77,   114,    63,    97,   133,   134,    34,    67,
      33,    29,    30,   104,    31,    32,    68,    69,   106,    70,
      71,   108,    72,    73,    74,    24,    25,    26,    27,    28,
      58,    99,   113,   110,     3,   111,   118,    84,    60,     3,
      60,   119,   124,   155,   156,   158,   159,   161,    66,   147,
      65,    97,    57,    59,   147,    57,     3,    60,   115,    97,
     119,   120,    60,    57,   132,   102,   110,    97,   103,   105,
     105,   107,   107,   107,   107,   109,   109,   110,   110,   110,
       1,    98,    85,    60,   148,   160,    60,    57,   157,    57,
      60,    97,    78,   145,    97,    98,   116,    78,    60,   134,
      65,    66,     1,     3,     9,    10,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    56,    59,    82,    83,    87,
      88,    89,    91,    93,    95,    96,    97,    38,   159,     3,
     117,    60,   100,    66,    89,    63,    63,    82,    63,    66,
      97,    59,    59,     3,    63,    88,    65,     1,    59,    90,
      57,    82,    97,    97,    12,    94,    97,    87,    66,    59,
      97,    98,    60,    60,    63,    59,    87,    60,    82,    82,
      97,    94,    92,    11,    60,    59,    82,    82,    59,    94,
      60,    82
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    79,    80,    81,    81,    82,    82,    82,    82,    82,
      82,    84,    83,    85,    85,    86,    86,    87,    87,    88,
      88,    89,    89,    90,    90,    91,    91,    92,    91,    93,
      93,    93,    94,    94,    95,    95,    95,    96,    96,    96,
      96,    97,    97,    98,    98,    98,    99,    99,    99,    99,
      99,    99,   100,   100,   101,   101,   102,   102,   103,   103,
     104,   104,   105,   105,   106,   106,   106,   106,   107,   107,
     108,   108,   109,   109,   109,   109,   110,   110,   110,   110,
     110,   111,   111,   112,   112,   112,   112,   113,   113,   113,
     113,   114,   115,   114,   114,   116,   117,   117,   118,   118,
     118,   118,   118,   118,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   120,   121,   121,   122,   123,   123,   124,
     125,   125,   126,   126,   126,   127,   127,   128,   128,   128,
     128,   128,   129,   129,   130,   131,   131,   132,   132,   133,
     133,   134,   134,   135,   135,   135,   136,   137,   137,   138,
     138,   139,   139,   140,   140,   141,   142,   142,   143,   143,
     144,   144,   145,   145,   146,   147,   147,   148,   149,   149,
     150,   151,   151,   152,   152,   153,   153,   153,   154,   154,
     155,   155,   155,   155,   156,   157,   157,   158,   158,   159,
     160,   160,   161,   161,   162,   163,   163,   164,   164,   165,
     165,   166,   167,   167
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     0,     5,     2,     1,     1,     0,     2,     1,     1,
       1,     1,     2,     1,     1,     5,     7,     0,     6,     5,
       7,     9,     1,     0,     3,     4,     3,     2,     2,     2,
       3,     1,     3,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     5,     1,     3,     1,     3,     1,     2,
       2,     2,     1,     2,     2,     2,     2,     2,     1,     2,
       2,     2,     1,     3,     3,     3,     1,     2,     2,     2,
       4,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     3,     0,     4,     2,     2,     3,     0,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     3,     3,     1,
       1,     0,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     0,     2,     1,     0,     1,
       3,     1,     4,     1,     1,     1,     2,     1,     1,     3,
       2,     3,     0,     1,     2,     3,     2,     2,     1,     0,
       1,     3,     1,     2,     2,     2,     0,     2,     1,     0,
       3,     1,     0,     1,     2,     1,     3,     2,     3,     2,
       1,     2,     2,     2,     2,     2,     0,     1,     3,     2,
       0,     1,     1,     3,     2,     2,     3,     3,     0,     1,
       3,     2,     2,     0
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

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* unidadTraduccion: declaracionExterna  */
#line 93 "src/parser.y"
                         {reset_token_buffer();}
#line 1982 "obj/src/parser.tab.c"
    break;

  case 4: /* unidadTraduccion: unidadTraduccion declaracionExterna  */
#line 94 "src/parser.y"
                                          {reset_token_buffer();}
#line 1988 "obj/src/parser.tab.c"
    break;

  case 5: /* sentencia: sentCompuesta  */
#line 98 "src/parser.y"
                    {reset_token_buffer();}
#line 1994 "obj/src/parser.tab.c"
    break;

  case 6: /* sentencia: sentExpresion  */
#line 99 "src/parser.y"
                    {reset_token_buffer();}
#line 2000 "obj/src/parser.tab.c"
    break;

  case 7: /* sentencia: sentSeleccion  */
#line 100 "src/parser.y"
                    {reset_token_buffer();}
#line 2006 "obj/src/parser.tab.c"
    break;

  case 8: /* sentencia: sentIteracion  */
#line 101 "src/parser.y"
                    {reset_token_buffer();}
#line 2012 "obj/src/parser.tab.c"
    break;

  case 9: /* sentencia: sentEtiquetadas  */
#line 102 "src/parser.y"
                      {reset_token_buffer();}
#line 2018 "obj/src/parser.tab.c"
    break;

  case 10: /* sentencia: sentSalto  */
#line 103 "src/parser.y"
                {reset_token_buffer();}
#line 2024 "obj/src/parser.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 107 "src/parser.y"
          {parameter_flag = 0;}
#line 2030 "obj/src/parser.tab.c"
    break;

  case 18: /* listaSentencias: error  */
#line 122 "src/parser.y"
            {yyerrok;}
#line 2036 "obj/src/parser.tab.c"
    break;

  case 21: /* sentExpresion: ';'  */
#line 131 "src/parser.y"
          { semicolon_flag = 1;}
#line 2042 "obj/src/parser.tab.c"
    break;

  case 24: /* opcionExpresion: error  */
#line 137 "src/parser.y"
            {yerror((yylsp[-1])); yyerrok;}
#line 2048 "obj/src/parser.tab.c"
    break;

  case 25: /* sentSeleccion: IF '(' expresion ')' sentencia  */
#line 141 "src/parser.y"
                                                {add_sent("if", (yylsp[-4]).first_line, (yylsp[-4]).first_column);}
#line 2054 "obj/src/parser.tab.c"
    break;

  case 26: /* sentSeleccion: IF '(' expresion ')' sentencia ELSE sentencia  */
#line 142 "src/parser.y"
                                                    {add_sent("if/else", (yylsp[-6]).first_line, (yylsp[-6]).first_column);}
#line 2060 "obj/src/parser.tab.c"
    break;

  case 27: /* $@2: %empty  */
#line 143 "src/parser.y"
                               {reset_token_buffer(); }
#line 2066 "obj/src/parser.tab.c"
    break;

  case 28: /* sentSeleccion: SWITCH '(' expresion ')' $@2 sentencia  */
#line 143 "src/parser.y"
                                                                  {add_sent((yyvsp[-5].string_type), (yylsp[-5]).first_line, (yylsp[-5]).first_column); }
#line 2072 "obj/src/parser.tab.c"
    break;

  case 29: /* sentIteracion: WHILE '(' expresion ')' sentencia  */
#line 147 "src/parser.y"
                                        {add_sent((yyvsp[-4].string_type), (yylsp[-4]).first_line, (yylsp[-4]).first_column);}
#line 2078 "obj/src/parser.tab.c"
    break;

  case 30: /* sentIteracion: DO sentencia WHILE '(' expresion ')' ';'  */
#line 148 "src/parser.y"
                                               {add_sent("do/while", (yylsp[-6]).first_line, (yylsp[-6]).first_column);}
#line 2084 "obj/src/parser.tab.c"
    break;

  case 31: /* sentIteracion: FOR '(' expresionOp ';' expresionOp ';' expresionOp ')' sentencia  */
#line 149 "src/parser.y"
                                                                        {add_sent((yyvsp[-8].string_type), (yylsp[-8]).first_line, (yylsp[-8]).first_column);}
#line 2090 "obj/src/parser.tab.c"
    break;

  case 35: /* sentEtiquetadas: CASE expresion ':' listaSentencias  */
#line 159 "src/parser.y"
                                         {add_sent((yyvsp[-3].string_type), (yylsp[-3]).first_line, (yylsp[-3]).first_column);}
#line 2096 "obj/src/parser.tab.c"
    break;

  case 36: /* sentEtiquetadas: DEFAULT ':' listaSentencias  */
#line 160 "src/parser.y"
                                  {add_sent((yyvsp[-2].string_type), (yylsp[-2]).first_line, (yylsp[-2]).first_column);}
#line 2102 "obj/src/parser.tab.c"
    break;

  case 37: /* sentSalto: RETURN sentExpresion  */
#line 164 "src/parser.y"
                           {add_sent((yyvsp[-1].string_type), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        t_symbol_table* existing_symbol = (t_symbol_table*)get_element(FUNCTION, data_function->name, compare_char_and_ID_function);
        if(existing_symbol) {
            return_conflict_types(existing_symbol, (yylsp[-1]).first_line, (yylsp[-1]).last_column);
        }
    }
#line 2113 "obj/src/parser.tab.c"
    break;

  case 38: /* sentSalto: CONTINUE ';'  */
#line 170 "src/parser.y"
                   {add_sent((yyvsp[-1].string_type), (yylsp[-1]).first_line, (yylsp[-1]).first_column);}
#line 2119 "obj/src/parser.tab.c"
    break;

  case 39: /* sentSalto: BREAK ';'  */
#line 171 "src/parser.y"
                {add_sent((yyvsp[-1].string_type), (yylsp[-1]).first_line, (yylsp[-1]).first_column);}
#line 2125 "obj/src/parser.tab.c"
    break;

  case 40: /* sentSalto: GOTO IDENTIFICADOR ';'  */
#line 172 "src/parser.y"
                            {add_sent((yyvsp[-2].string_type), (yylsp[-2]).first_line, (yylsp[-2]).first_column);}
#line 2131 "obj/src/parser.tab.c"
    break;

  case 43: /* expAsignacion: expCondicional  */
#line 181 "src/parser.y"
                     { (yyval.var_val) = (yyvsp[0].var_val);}
#line 2137 "obj/src/parser.tab.c"
    break;

  case 44: /* expAsignacion: expUnaria operAsignacion expAsignacion  */
#line 182 "src/parser.y"
                                             {
        if(assign_void_flag) {
            _asprintf(&data_sem_error->msg, "%i:%i: No se ignora el valor de retorno void como deberia ser", (yylsp[-2]).first_line, (yylsp[-1]).first_column);
            insert_node(&semantic_errors, data_sem_error, sizeof(t_semantic_error));
            assign_void_flag = 0;
        } else{check_assignation_types ((yyvsp[-2].var_val), (yyvsp[0].var_val), (yylsp[0]).first_line, (yylsp[0]).first_column);}
    }
#line 2149 "obj/src/parser.tab.c"
    break;

  case 52: /* expCondicional: expOr  */
#line 202 "src/parser.y"
            { (yyval.var_val) = (yyvsp[0].var_val);}
#line 2155 "obj/src/parser.tab.c"
    break;

  case 54: /* expOr: expAnd  */
#line 207 "src/parser.y"
             { (yyval.var_val) = (yyvsp[0].var_val);}
#line 2161 "obj/src/parser.tab.c"
    break;

  case 56: /* expAnd: expIgualdad  */
#line 212 "src/parser.y"
                  { (yyval.var_val) = (yyvsp[0].var_val);}
#line 2167 "obj/src/parser.tab.c"
    break;

  case 58: /* expIgualdad: expRelacional  */
#line 217 "src/parser.y"
                    { (yyval.var_val) = (yyvsp[0].var_val);}
#line 2173 "obj/src/parser.tab.c"
    break;

  case 62: /* expRelacional: expAditiva  */
#line 227 "src/parser.y"
                 { (yyval.var_val) = (yyvsp[0].var_val);}
#line 2179 "obj/src/parser.tab.c"
    break;

  case 68: /* expAditiva: expMultiplicativa  */
#line 239 "src/parser.y"
                        { (yyval.var_val) = (yyvsp[0].var_val);}
#line 2185 "obj/src/parser.tab.c"
    break;

  case 72: /* expMultiplicativa: expUnaria  */
#line 249 "src/parser.y"
                { (yyval.var_val) = (yyvsp[0].var_val); }
#line 2191 "obj/src/parser.tab.c"
    break;

  case 73: /* expMultiplicativa: expMultiplicativa '*' expUnaria  */
#line 250 "src/parser.y"
                                      { 

        check_multiplication((yyvsp[-2].var_val), (yyvsp[0].var_val), (yylsp[-2]).first_line, (yylsp[-1]).first_column);
        
    }
#line 2201 "obj/src/parser.tab.c"
    break;

  case 76: /* expUnaria: expPostfijo  */
#line 260 "src/parser.y"
                  { (yyval.var_val) = (yyvsp[0].var_val);}
#line 2207 "obj/src/parser.tab.c"
    break;

  case 79: /* expUnaria: operUnario expUnaria  */
#line 263 "src/parser.y"
                            { (yyval.var_val) = (yyvsp[0].var_val);}
#line 2213 "obj/src/parser.tab.c"
    break;

  case 87: /* expPostfijo: expPrimaria  */
#line 280 "src/parser.y"
                   { (yyval.var_val) = (yyvsp[0].var_val);}
#line 2219 "obj/src/parser.tab.c"
    break;

  case 89: /* expPostfijo: IDENTIFICADOR opcionPostfijo  */
#line 282 "src/parser.y"
                                  { 
        insert_sem_error_invocate_function((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_type), quantity_parameters);
        manage_conflict_arguments((yyvsp[-1].string_type)); 
        free_invocated_arguments();

        if(fetch_element(FUNCTION, (yyvsp[-1].string_type), compare_void_function)) {
            assign_void_flag = 1;
        }
        quantity_parameters = 0;

        (yyval.var_val).value.id_val = strdup((yyvsp[-1].string_type));
        (yyval.var_val).type = ID;
    }
#line 2237 "obj/src/parser.tab.c"
    break;

  case 90: /* expPostfijo: IDENTIFICADOR '(' ')'  */
#line 295 "src/parser.y"
                            {
                quantity_parameters = 0;
                insert_sem_error_invocate_function((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].string_type), quantity_parameters);
                (yyval.var_val).value.id_val = strdup((yyvsp[-2].string_type));
                (yyval.var_val).type = ID;

                if(fetch_element(FUNCTION, (yyvsp[-2].string_type), compare_void_function)) {
                    assign_void_flag = 1;
                }
           }
#line 2252 "obj/src/parser.tab.c"
    break;

  case 92: /* $@3: %empty  */
#line 309 "src/parser.y"
          { parameter_flag = 1;}
#line 2258 "obj/src/parser.tab.c"
    break;

  case 93: /* opcionPostfijo: '(' $@3 listaArgumentosNoVacia ')'  */
#line 309 "src/parser.y"
                                                            { parameter_flag = 0; }
#line 2264 "obj/src/parser.tab.c"
    break;

  case 95: /* listaArgumentosNoVacia: expAsignacion masListaArgumentos  */
#line 314 "src/parser.y"
                                       { 
        quantity_parameters++; 
    }
#line 2272 "obj/src/parser.tab.c"
    break;

  case 96: /* masListaArgumentos: masListaArgumentos ',' expAsignacion  */
#line 320 "src/parser.y"
                                           { 
        quantity_parameters++; 
    }
#line 2280 "obj/src/parser.tab.c"
    break;

  case 98: /* expPrimaria: IDENTIFICADOR  */
#line 327 "src/parser.y"
                                     {
        if(!declaration_flag) {
            if(!fetch_element(VARIABLE, (yyvsp[0].string_type), compare_ID_parameter) && !fetch_parameter((yyvsp[0].string_type)) && !fetch_element(FUNCTION, (yyvsp[0].string_type), compare_char_and_ID_function)) {
               _asprintf(&data_sem_error -> msg, "%i:%i: '%s' sin declarar", (yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].string_type));
               insert_node(&semantic_errors, data_sem_error, sizeof(semantic_errors));
            }
        }
        declaration_flag = 0;
        string_flag = 0;
        type_aux = strdup((yyvsp[0].string_type));
        
        if(parameter_flag) {
            add_argument((yylsp[0]).first_line, (yylsp[0]).first_column, ID);
        }

        (yyval.var_val).value.id_val = strdup((yyvsp[0].string_type));
        (yyval.var_val).type = ID;
    }
#line 2303 "obj/src/parser.tab.c"
    break;

  case 99: /* expPrimaria: ENTERO  */
#line 345 "src/parser.y"
                        { 
        if(parameter_flag) {  
            add_argument((yylsp[0]).first_line, (yylsp[0]).first_column, INT);
        }

        (yyval.var_val).value.int_val = (yyvsp[0].int_type);
        (yyval.var_val).type = INT;
    }
#line 2316 "obj/src/parser.tab.c"
    break;

  case 100: /* expPrimaria: NUM  */
#line 353 "src/parser.y"
                        { 
        if(parameter_flag){
            add_argument((yylsp[0]).first_line, (yylsp[0]).first_column, NUMBER);
        }   

        (yyval.var_val).value.double_val = (yyvsp[0].double_type);
        (yyval.var_val).type = NUMBER;
    }
#line 2329 "obj/src/parser.tab.c"
    break;

  case 101: /* expPrimaria: CONSTANTE  */
#line 361 "src/parser.y"
                        {
        if(parameter_flag) {
            add_argument((yylsp[0]).first_line, (yylsp[0]).first_column, INT);
        }

        (yyval.var_val).value.int_val = (yyvsp[0].int_type);
        (yyval.var_val).type = INT;
    }
#line 2342 "obj/src/parser.tab.c"
    break;

  case 102: /* expPrimaria: LITERAL_CADENA  */
#line 369 "src/parser.y"
                        { 
        if(parameter_flag) {
            add_argument((yylsp[0]).first_line, (yylsp[0]).first_column, STRING);
        }
        string_flag = 1;

        (yyval.var_val).value.string_val = strdup((yyvsp[0].string_type));
        (yyval.var_val).type = STRING; 
    }
#line 2356 "obj/src/parser.tab.c"
    break;

  case 103: /* expPrimaria: '(' expresion ')'  */
#line 378 "src/parser.y"
                        {
        (yyval.var_val).type = NUMBER;
    }
#line 2364 "obj/src/parser.tab.c"
    break;

  case 104: /* tipoDato: INT_TYPE  */
#line 384 "src/parser.y"
                { (yyval.string_type) = "int";}
#line 2370 "obj/src/parser.tab.c"
    break;

  case 105: /* tipoDato: FLOAT  */
#line 385 "src/parser.y"
                { (yyval.string_type) = "float";}
#line 2376 "obj/src/parser.tab.c"
    break;

  case 106: /* tipoDato: DOUBLE  */
#line 386 "src/parser.y"
                { (yyval.string_type) = "double";}
#line 2382 "obj/src/parser.tab.c"
    break;

  case 107: /* tipoDato: CHAR  */
#line 387 "src/parser.y"
                { (yyval.string_type) = "char";}
#line 2388 "obj/src/parser.tab.c"
    break;

  case 108: /* tipoDato: VOID  */
#line 388 "src/parser.y"
                { (yyval.string_type) = "void";}
#line 2394 "obj/src/parser.tab.c"
    break;

  case 109: /* tipoDato: SHORT  */
#line 389 "src/parser.y"
                { (yyval.string_type) = "short";}
#line 2400 "obj/src/parser.tab.c"
    break;

  case 110: /* tipoDato: LONG  */
#line 390 "src/parser.y"
                { (yyval.string_type) = "long";}
#line 2406 "obj/src/parser.tab.c"
    break;

  case 111: /* tipoDato: UNSIGNED  */
#line 391 "src/parser.y"
                { (yyval.string_type) = "unsigned";}
#line 2412 "obj/src/parser.tab.c"
    break;

  case 112: /* tipoDato: SIGNED  */
#line 392 "src/parser.y"
                { (yyval.string_type) = "signed";}
#line 2418 "obj/src/parser.tab.c"
    break;

  case 116: /* definicionFuncion: especificadorDeclaracion decla listaDeclaracionOp sentCompuesta  */
#line 405 "src/parser.y"
                                                                      {
        if(fetch_element(FUNCTION, (yyvsp[-2].string_type), compare_ID_functions)) {
            handle_function_redefinition((yylsp[-2]).first_line,(yylsp[-2]).first_column+1, (yyvsp[-2].string_type));
        } else {
            save_function("definicion", (yyvsp[-3].string_type), (yyvsp[-2].string_type));
            manage_conflict_types((yylsp[-2]).first_line, (yylsp[-2]).first_column + 1);
        }
    }
#line 2431 "obj/src/parser.tab.c"
    break;

  case 118: /* declaracion: especificadorDeclaracion decla ';'  */
#line 417 "src/parser.y"
                                         {
        if (parameter_flag) {
            save_function("declaracion", (yyvsp[-2].string_type), (yyvsp[-1].string_type));
            manage_conflict_types((yylsp[-1]).first_line, (yylsp[-1]).first_column + 1);
        } else {
            insert_node(&variable, data_variable, sizeof(t_variable));
            insert_symbol(VARIABLE);
        }
    }
#line 2445 "obj/src/parser.tab.c"
    break;

  case 119: /* especificadorDeclaracion: especificadorCompleto  */
#line 429 "src/parser.y"
                            {
        (yyval.string_type) = strdup((yyvsp[0].string_type));
        data_variable->type = strdup((yyvsp[0].string_type));
    }
#line 2454 "obj/src/parser.tab.c"
    break;

  case 120: /* especificadorDeclaracionOp: especificadorCompleto  */
#line 436 "src/parser.y"
                            { (yyval.string_type) = strdup((yyvsp[0].string_type));}
#line 2460 "obj/src/parser.tab.c"
    break;

  case 121: /* especificadorDeclaracionOp: %empty  */
#line 437 "src/parser.y"
                { (yyval.string_type) = NULL;}
#line 2466 "obj/src/parser.tab.c"
    break;

  case 122: /* especificadorCompleto: tipoAlmacenamiento especificadorDeclaracionOp  */
#line 441 "src/parser.y"
                                                       { (yyval.string_type) = concat_strings((yyvsp[-1].string_type), (yyvsp[0].string_type));}
#line 2472 "obj/src/parser.tab.c"
    break;

  case 123: /* especificadorCompleto: especificadorTipo especificadorDeclaracionOp  */
#line 442 "src/parser.y"
                                                        { (yyval.string_type) = concat_strings((yyvsp[-1].string_type), (yyvsp[0].string_type));}
#line 2478 "obj/src/parser.tab.c"
    break;

  case 124: /* especificadorCompleto: calificadorTipo especificadorDeclaracionOp  */
#line 443 "src/parser.y"
                                                       { (yyval.string_type) = concat_strings((yyvsp[-1].string_type), (yyvsp[0].string_type));}
#line 2484 "obj/src/parser.tab.c"
    break;

  case 125: /* tipoAlmacenamiento: CONST  */
#line 447 "src/parser.y"
                { (yyval.string_type) = "const";}
#line 2490 "obj/src/parser.tab.c"
    break;

  case 126: /* tipoAlmacenamiento: VOLATILE  */
#line 448 "src/parser.y"
                { (yyval.string_type) = "volatile";}
#line 2496 "obj/src/parser.tab.c"
    break;

  case 127: /* calificadorTipo: TYPEDEF  */
#line 452 "src/parser.y"
                { (yyval.string_type) = "typedef";}
#line 2502 "obj/src/parser.tab.c"
    break;

  case 128: /* calificadorTipo: STATIC  */
#line 453 "src/parser.y"
                { (yyval.string_type) = "static";}
#line 2508 "obj/src/parser.tab.c"
    break;

  case 129: /* calificadorTipo: EXTERN  */
#line 454 "src/parser.y"
                { (yyval.string_type) = "extern";}
#line 2514 "obj/src/parser.tab.c"
    break;

  case 130: /* calificadorTipo: AUTO  */
#line 455 "src/parser.y"
                { (yyval.string_type) = "auto";}
#line 2520 "obj/src/parser.tab.c"
    break;

  case 131: /* calificadorTipo: REGISTER  */
#line 456 "src/parser.y"
                { (yyval.string_type) = "register";}
#line 2526 "obj/src/parser.tab.c"
    break;

  case 132: /* listaDeclaradores: declarador  */
#line 460 "src/parser.y"
                 { 
        int redeclaration_line = data_variable->line;
        int redeclaration_column = data_variable->column;
        handle_redeclaration(redeclaration_line, redeclaration_column, data_variable->variable);
        insert_if_not_exists();
    }
#line 2537 "obj/src/parser.tab.c"
    break;

  case 133: /* listaDeclaradores: listaDeclaradores ',' declarador  */
#line 466 "src/parser.y"
                                       {
        int redeclaration_line = data_variable->line;
        int redeclaration_column = data_variable->column;
        handle_redeclaration(redeclaration_line, redeclaration_column, data_variable->variable);
        insert_if_not_exists();
    }
#line 2548 "obj/src/parser.tab.c"
    break;

  case 136: /* opcionPostDeclarador: '=' inicializador  */
#line 480 "src/parser.y"
                        {
        t_variable_value var_val;
        var_val.type = ID;
        var_val.value.id_val = strdup((yyvsp[-2].string_type));
        
        check_assignation_types(var_val, (yyvsp[0].var_val), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2560 "obj/src/parser.tab.c"
    break;

  case 141: /* inicializador: expAsignacion  */
#line 500 "src/parser.y"
                    {declaration_flag = 1; (yyval.var_val) = (yyvsp[0].var_val);}
#line 2566 "obj/src/parser.tab.c"
    break;

  case 167: /* decla: punteroOp declaradorDirecto  */
#line 567 "src/parser.y"
                                  { (yyval.string_type) = strdup((yyvsp[0].string_type));}
#line 2572 "obj/src/parser.tab.c"
    break;

  case 175: /* declaradorDirecto: IDENTIFICADOR  */
#line 590 "src/parser.y"
                    {
        (yyval.string_type) = strdup((yyvsp[0].string_type));
        data_variable->variable = strdup((yyvsp[0].string_type));
        data_variable->line = data_symbol->line = yylloc.first_line;
        data_variable->column =  data_symbol->column = yylloc.first_column;
    }
#line 2583 "obj/src/parser.tab.c"
    break;

  case 177: /* declaradorDirecto: declaradorDirecto continuacionDeclaradorDirecto  */
#line 597 "src/parser.y"
                                                      { data_function->line = yylloc.first_line; parameter_flag = 1;}
#line 2589 "obj/src/parser.tab.c"
    break;

  case 183: /* opcional: tipoDato ')'  */
#line 609 "src/parser.y"
                   { 
        data_parameter.type = strdup((yyvsp[-1].string_type));
        data_parameter.name = NULL;
        insert_node((GenericNode**)&(data_function->parameters), &data_parameter, sizeof(t_parameter));
        }
#line 2599 "obj/src/parser.tab.c"
    break;

  case 187: /* listaParametros: declaracionParametro  */
#line 626 "src/parser.y"
                            {
        insert_node((GenericNode**)&(data_function->parameters), &data_parameter, sizeof(t_parameter));
    }
#line 2607 "obj/src/parser.tab.c"
    break;

  case 188: /* listaParametros: listaParametros ',' declaracionParametro  */
#line 629 "src/parser.y"
                                               {
        insert_node((GenericNode**)&(data_function->parameters), &data_parameter, sizeof(t_parameter));
    }
#line 2615 "obj/src/parser.tab.c"
    break;

  case 189: /* declaracionParametro: especificadorDeclaracion opcionesDecla  */
#line 635 "src/parser.y"
                                             {
        data_parameter.type = strdup((yyvsp[-1].string_type));
        data_parameter.line = (yylsp[-1]).first_line;
        data_parameter.column = (yylsp[-1]).first_column;
        if((yyvsp[0].string_type)){
            data_parameter.name_line= (yylsp[0]).first_line;
            data_parameter.name_column= (yylsp[0]).first_column+1;
        }else{
            data_parameter.name_line= (yylsp[-1]).first_line;
            data_parameter.name_column= (yylsp[-1]).first_column;
        }        
    }
#line 2632 "obj/src/parser.tab.c"
    break;

  case 190: /* opcionesDecla: %empty  */
#line 650 "src/parser.y"
             {data_parameter.name = (char*)malloc(1); data_parameter.name = '\0';}
#line 2638 "obj/src/parser.tab.c"
    break;

  case 191: /* opcionesDecla: decla  */
#line 651 "src/parser.y"
            { 
        data_parameter.name = strdup((yyvsp[0].string_type)); 
        }
#line 2646 "obj/src/parser.tab.c"
    break;


#line 2650 "obj/src/parser.tab.c"

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
  *++yylsp = yyloc;

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 689 "src/parser.y"


int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            printf("Error abriendo el archivo de entrada");
            return 1;
        }
        yyin = file;
    }
    
    init_structures();
    
    yyparse();

    print_lists();

    if (yyin && yyin != stdin) {
        fclose(yyin);
    }
    
    free_all_lists(); 
    free(yylval.string_type);

    return 0;
}

void yyerror(const char *s) {
    // fprintf(stderr, "Error de sintaxis: %s\n", s);
}

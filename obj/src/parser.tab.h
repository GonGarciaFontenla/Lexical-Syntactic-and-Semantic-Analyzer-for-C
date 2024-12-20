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

#ifndef YY_YY_OBJ_SRC_PARSER_TAB_H_INCLUDED
# define YY_YY_OBJ_SRC_PARSER_TAB_H_INCLUDED
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
    IDENTIFICADOR = 258,           /* IDENTIFICADOR  */
    LITERAL_CADENA = 259,          /* LITERAL_CADENA  */
    CONSTANTE = 260,               /* CONSTANTE  */
    ENUM = 261,                    /* ENUM  */
    STRUCT = 262,                  /* STRUCT  */
    UNION = 263,                   /* UNION  */
    RETURN = 264,                  /* RETURN  */
    IF = 265,                      /* IF  */
    ELSE = 266,                    /* ELSE  */
    WHILE = 267,                   /* WHILE  */
    DO = 268,                      /* DO  */
    FOR = 269,                     /* FOR  */
    DEFAULT = 270,                 /* DEFAULT  */
    CASE = 271,                    /* CASE  */
    CONTINUE = 272,                /* CONTINUE  */
    BREAK = 273,                   /* BREAK  */
    GOTO = 274,                    /* GOTO  */
    SWITCH = 275,                  /* SWITCH  */
    SIZEOF = 276,                  /* SIZEOF  */
    ENTERO = 277,                  /* ENTERO  */
    NUM = 278,                     /* NUM  */
    ADD_ASSIGN = 279,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 280,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 281,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 282,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 283,              /* MOD_ASSIGN  */
    EQ = 284,                      /* EQ  */
    NEQ = 285,                     /* NEQ  */
    LE = 286,                      /* LE  */
    GE = 287,                      /* GE  */
    AND = 288,                     /* AND  */
    OR = 289,                      /* OR  */
    PTR_OP = 290,                  /* PTR_OP  */
    INC_OP = 291,                  /* INC_OP  */
    DEC_OP = 292,                  /* DEC_OP  */
    ELIPSIS = 293,                 /* ELIPSIS  */
    INT_TYPE = 294,                /* INT_TYPE  */
    FLOAT = 295,                   /* FLOAT  */
    DOUBLE = 296,                  /* DOUBLE  */
    CHAR = 297,                    /* CHAR  */
    VOID = 298,                    /* VOID  */
    SHORT = 299,                   /* SHORT  */
    LONG = 300,                    /* LONG  */
    UNSIGNED = 301,                /* UNSIGNED  */
    SIGNED = 302,                  /* SIGNED  */
    CONST = 303,                   /* CONST  */
    VOLATILE = 304,                /* VOLATILE  */
    TYPEDEF = 305,                 /* TYPEDEF  */
    STATIC = 306,                  /* STATIC  */
    EXTERN = 307,                  /* EXTERN  */
    AUTO = 308,                    /* AUTO  */
    REGISTER = 309,                /* REGISTER  */
    THEN = 310,                    /* THEN  */
    VACIO = 311,                   /* VACIO  */
    AUXSENTENCIA = 312,            /* AUXSENTENCIA  */
    IDENT_PREC = 313               /* IDENT_PREC  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 41 "src/parser.y"

    char* string_type;
    int int_type;
    double double_type;
    char char_type;
    t_variable_value var_val;

#line 130 "obj/src/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_OBJ_SRC_PARSER_TAB_H_INCLUDED  */

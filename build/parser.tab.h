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

#ifndef YY_YY_BUILD_PARSER_TAB_H_INCLUDED
# define YY_YY_BUILD_PARSER_TAB_H_INCLUDED
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
    T_IDENTIFIER = 258,            /* T_IDENTIFIER  */
    T_INT_LIT = 259,               /* T_INT_LIT  */
    T_FLOAT_LIT = 260,             /* T_FLOAT_LIT  */
    T_CHAR_LIT = 261,              /* T_CHAR_LIT  */
    T_STRING_LIT = 262,            /* T_STRING_LIT  */
    T_TYPEDEF_NAME = 263,          /* T_TYPEDEF_NAME  */
    T_PREPROC = 264,               /* T_PREPROC  */
    T_LEXERR = 265,                /* T_LEXERR  */
    T_INT = 266,                   /* T_INT  */
    T_CHAR = 267,                  /* T_CHAR  */
    T_SHORT = 268,                 /* T_SHORT  */
    T_LONG = 269,                  /* T_LONG  */
    T_FLOAT = 270,                 /* T_FLOAT  */
    T_DOUBLE = 271,                /* T_DOUBLE  */
    T_VOID = 272,                  /* T_VOID  */
    T_SIGNED = 273,                /* T_SIGNED  */
    T_UNSIGNED = 274,              /* T_UNSIGNED  */
    T_IF = 275,                    /* T_IF  */
    T_ELSE = 276,                  /* T_ELSE  */
    T_WHILE = 277,                 /* T_WHILE  */
    T_FOR = 278,                   /* T_FOR  */
    T_DO = 279,                    /* T_DO  */
    T_SWITCH = 280,                /* T_SWITCH  */
    T_CASE = 281,                  /* T_CASE  */
    T_DEFAULT = 282,               /* T_DEFAULT  */
    T_BREAK = 283,                 /* T_BREAK  */
    T_CONTINUE = 284,              /* T_CONTINUE  */
    T_RETURN = 285,                /* T_RETURN  */
    T_GOTO = 286,                  /* T_GOTO  */
    T_STRUCT = 287,                /* T_STRUCT  */
    T_UNION = 288,                 /* T_UNION  */
    T_ENUM = 289,                  /* T_ENUM  */
    T_TYPEDEF = 290,               /* T_TYPEDEF  */
    T_SIZEOF = 291,                /* T_SIZEOF  */
    T_CONST = 292,                 /* T_CONST  */
    T_VOLATILE = 293,              /* T_VOLATILE  */
    T_STATIC = 294,                /* T_STATIC  */
    T_EXTERN = 295,                /* T_EXTERN  */
    T_REGISTER = 296,              /* T_REGISTER  */
    T_AUTO = 297,                  /* T_AUTO  */
    T_ELLIPSIS = 298,              /* T_ELLIPSIS  */
    T_ARROW = 299,                 /* T_ARROW  */
    T_INC = 300,                   /* T_INC  */
    T_DEC = 301,                   /* T_DEC  */
    T_SHL = 302,                   /* T_SHL  */
    T_SHR = 303,                   /* T_SHR  */
    T_LE = 304,                    /* T_LE  */
    T_GE = 305,                    /* T_GE  */
    T_EQ = 306,                    /* T_EQ  */
    T_NE = 307,                    /* T_NE  */
    T_ANDAND = 308,                /* T_ANDAND  */
    T_OROR = 309,                  /* T_OROR  */
    T_MUL_ASSIGN = 310,            /* T_MUL_ASSIGN  */
    T_DIV_ASSIGN = 311,            /* T_DIV_ASSIGN  */
    T_MOD_ASSIGN = 312,            /* T_MOD_ASSIGN  */
    T_ADD_ASSIGN = 313,            /* T_ADD_ASSIGN  */
    T_SUB_ASSIGN = 314,            /* T_SUB_ASSIGN  */
    T_SHL_ASSIGN = 315,            /* T_SHL_ASSIGN  */
    T_SHR_ASSIGN = 316,            /* T_SHR_ASSIGN  */
    T_AND_ASSIGN = 317,            /* T_AND_ASSIGN  */
    T_XOR_ASSIGN = 318,            /* T_XOR_ASSIGN  */
    T_OR_ASSIGN = 319,             /* T_OR_ASSIGN  */
    LOWER_THAN_ELSE = 320,         /* LOWER_THAN_ELSE  */
    UNARY = 321                    /* UNARY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BUILD_PARSER_TAB_H_INCLUDED  */

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
#line 6 "src/parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "common.h"
#include "token_stream.h"
#include "parse.h"
#include "typedefs.h"

int  yylex(void);
void yyerror(const char *msg);

#line 84 "build/parser.tab.c"

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
  YYSYMBOL_T_IDENTIFIER = 3,               /* T_IDENTIFIER  */
  YYSYMBOL_T_INT_LIT = 4,                  /* T_INT_LIT  */
  YYSYMBOL_T_FLOAT_LIT = 5,                /* T_FLOAT_LIT  */
  YYSYMBOL_T_CHAR_LIT = 6,                 /* T_CHAR_LIT  */
  YYSYMBOL_T_STRING_LIT = 7,               /* T_STRING_LIT  */
  YYSYMBOL_T_TYPEDEF_NAME = 8,             /* T_TYPEDEF_NAME  */
  YYSYMBOL_T_PREPROC = 9,                  /* T_PREPROC  */
  YYSYMBOL_T_LEXERR = 10,                  /* T_LEXERR  */
  YYSYMBOL_T_INT = 11,                     /* T_INT  */
  YYSYMBOL_T_CHAR = 12,                    /* T_CHAR  */
  YYSYMBOL_T_SHORT = 13,                   /* T_SHORT  */
  YYSYMBOL_T_LONG = 14,                    /* T_LONG  */
  YYSYMBOL_T_FLOAT = 15,                   /* T_FLOAT  */
  YYSYMBOL_T_DOUBLE = 16,                  /* T_DOUBLE  */
  YYSYMBOL_T_VOID = 17,                    /* T_VOID  */
  YYSYMBOL_T_SIGNED = 18,                  /* T_SIGNED  */
  YYSYMBOL_T_UNSIGNED = 19,                /* T_UNSIGNED  */
  YYSYMBOL_T_IF = 20,                      /* T_IF  */
  YYSYMBOL_T_ELSE = 21,                    /* T_ELSE  */
  YYSYMBOL_T_WHILE = 22,                   /* T_WHILE  */
  YYSYMBOL_T_FOR = 23,                     /* T_FOR  */
  YYSYMBOL_T_DO = 24,                      /* T_DO  */
  YYSYMBOL_T_SWITCH = 25,                  /* T_SWITCH  */
  YYSYMBOL_T_CASE = 26,                    /* T_CASE  */
  YYSYMBOL_T_DEFAULT = 27,                 /* T_DEFAULT  */
  YYSYMBOL_T_BREAK = 28,                   /* T_BREAK  */
  YYSYMBOL_T_CONTINUE = 29,                /* T_CONTINUE  */
  YYSYMBOL_T_RETURN = 30,                  /* T_RETURN  */
  YYSYMBOL_T_GOTO = 31,                    /* T_GOTO  */
  YYSYMBOL_T_STRUCT = 32,                  /* T_STRUCT  */
  YYSYMBOL_T_UNION = 33,                   /* T_UNION  */
  YYSYMBOL_T_ENUM = 34,                    /* T_ENUM  */
  YYSYMBOL_T_TYPEDEF = 35,                 /* T_TYPEDEF  */
  YYSYMBOL_T_SIZEOF = 36,                  /* T_SIZEOF  */
  YYSYMBOL_T_CONST = 37,                   /* T_CONST  */
  YYSYMBOL_T_VOLATILE = 38,                /* T_VOLATILE  */
  YYSYMBOL_T_STATIC = 39,                  /* T_STATIC  */
  YYSYMBOL_T_EXTERN = 40,                  /* T_EXTERN  */
  YYSYMBOL_T_REGISTER = 41,                /* T_REGISTER  */
  YYSYMBOL_T_AUTO = 42,                    /* T_AUTO  */
  YYSYMBOL_T_ELLIPSIS = 43,                /* T_ELLIPSIS  */
  YYSYMBOL_T_ARROW = 44,                   /* T_ARROW  */
  YYSYMBOL_T_INC = 45,                     /* T_INC  */
  YYSYMBOL_T_DEC = 46,                     /* T_DEC  */
  YYSYMBOL_T_SHL = 47,                     /* T_SHL  */
  YYSYMBOL_T_SHR = 48,                     /* T_SHR  */
  YYSYMBOL_T_LE = 49,                      /* T_LE  */
  YYSYMBOL_T_GE = 50,                      /* T_GE  */
  YYSYMBOL_T_EQ = 51,                      /* T_EQ  */
  YYSYMBOL_T_NE = 52,                      /* T_NE  */
  YYSYMBOL_T_ANDAND = 53,                  /* T_ANDAND  */
  YYSYMBOL_T_OROR = 54,                    /* T_OROR  */
  YYSYMBOL_T_MUL_ASSIGN = 55,              /* T_MUL_ASSIGN  */
  YYSYMBOL_T_DIV_ASSIGN = 56,              /* T_DIV_ASSIGN  */
  YYSYMBOL_T_MOD_ASSIGN = 57,              /* T_MOD_ASSIGN  */
  YYSYMBOL_T_ADD_ASSIGN = 58,              /* T_ADD_ASSIGN  */
  YYSYMBOL_T_SUB_ASSIGN = 59,              /* T_SUB_ASSIGN  */
  YYSYMBOL_T_SHL_ASSIGN = 60,              /* T_SHL_ASSIGN  */
  YYSYMBOL_T_SHR_ASSIGN = 61,              /* T_SHR_ASSIGN  */
  YYSYMBOL_T_AND_ASSIGN = 62,              /* T_AND_ASSIGN  */
  YYSYMBOL_T_XOR_ASSIGN = 63,              /* T_XOR_ASSIGN  */
  YYSYMBOL_T_OR_ASSIGN = 64,               /* T_OR_ASSIGN  */
  YYSYMBOL_LOWER_THAN_ELSE = 65,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_66_ = 66,                       /* '='  */
  YYSYMBOL_67_ = 67,                       /* '?'  */
  YYSYMBOL_68_ = 68,                       /* ':'  */
  YYSYMBOL_69_ = 69,                       /* '|'  */
  YYSYMBOL_70_ = 70,                       /* '^'  */
  YYSYMBOL_71_ = 71,                       /* '&'  */
  YYSYMBOL_72_ = 72,                       /* '<'  */
  YYSYMBOL_73_ = 73,                       /* '>'  */
  YYSYMBOL_74_ = 74,                       /* '+'  */
  YYSYMBOL_75_ = 75,                       /* '-'  */
  YYSYMBOL_76_ = 76,                       /* '*'  */
  YYSYMBOL_77_ = 77,                       /* '/'  */
  YYSYMBOL_78_ = 78,                       /* '%'  */
  YYSYMBOL_UNARY = 79,                     /* UNARY  */
  YYSYMBOL_80_ = 80,                       /* '('  */
  YYSYMBOL_81_ = 81,                       /* '['  */
  YYSYMBOL_82_ = 82,                       /* '.'  */
  YYSYMBOL_83_ = 83,                       /* ';'  */
  YYSYMBOL_84_ = 84,                       /* '{'  */
  YYSYMBOL_85_ = 85,                       /* '}'  */
  YYSYMBOL_86_ = 86,                       /* ','  */
  YYSYMBOL_87_ = 87,                       /* ')'  */
  YYSYMBOL_88_ = 88,                       /* ']'  */
  YYSYMBOL_89_ = 89,                       /* '~'  */
  YYSYMBOL_90_ = 90,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 91,                  /* $accept  */
  YYSYMBOL_program = 92,                   /* program  */
  YYSYMBOL_translation_unit = 93,          /* translation_unit  */
  YYSYMBOL_external_declaration = 94,      /* external_declaration  */
  YYSYMBOL_function_definition = 95,       /* function_definition  */
  YYSYMBOL_declaration = 96,               /* declaration  */
  YYSYMBOL_declaration_specifiers = 97,    /* declaration_specifiers  */
  YYSYMBOL_sq = 98,                        /* sq  */
  YYSYMBOL_sq_list = 99,                   /* sq_list  */
  YYSYMBOL_tag_specifiers = 100,           /* tag_specifiers  */
  YYSYMBOL_basic_specifiers = 101,         /* basic_specifiers  */
  YYSYMBOL_storage_class_specifier = 102,  /* storage_class_specifier  */
  YYSYMBOL_basic_type = 103,               /* basic_type  */
  YYSYMBOL_tag_type = 104,                 /* tag_type  */
  YYSYMBOL_type_qualifier = 105,           /* type_qualifier  */
  YYSYMBOL_struct_or_union_specifier = 106, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 107,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 108,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 109,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 110, /* specifier_qualifier_list  */
  YYSYMBOL_tag_sq = 111,                   /* tag_sq  */
  YYSYMBOL_basic_sq = 112,                 /* basic_sq  */
  YYSYMBOL_struct_declarator_list = 113,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 114,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 115,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 116,          /* enumerator_list  */
  YYSYMBOL_enumerator = 117,               /* enumerator  */
  YYSYMBOL_init_declarator_list = 118,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 119,          /* init_declarator  */
  YYSYMBOL_initializer = 120,              /* initializer  */
  YYSYMBOL_initializer_list = 121,         /* initializer_list  */
  YYSYMBOL_declarator = 122,               /* declarator  */
  YYSYMBOL_direct_declarator = 123,        /* direct_declarator  */
  YYSYMBOL_pointer = 124,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 125,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 126,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 127,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 128,    /* parameter_declaration  */
  YYSYMBOL_type_name = 129,                /* type_name  */
  YYSYMBOL_abstract_declarator = 130,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 131, /* direct_abstract_declarator  */
  YYSYMBOL_statement = 132,                /* statement  */
  YYSYMBOL_labeled_statement = 133,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 134,       /* compound_statement  */
  YYSYMBOL_block_item_list = 135,          /* block_item_list  */
  YYSYMBOL_block_item = 136,               /* block_item  */
  YYSYMBOL_expression_statement = 137,     /* expression_statement  */
  YYSYMBOL_selection_statement = 138,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 139,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 140,           /* jump_statement  */
  YYSYMBOL_expression = 141,               /* expression  */
  YYSYMBOL_argument_list = 142,            /* argument_list  */
  YYSYMBOL_string_list = 143,              /* string_list  */
  YYSYMBOL_expr = 144                      /* expr  */
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
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   9447

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  209
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  359

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   321


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
       2,     2,     2,    90,     2,     2,     2,    78,    71,     2,
      80,    87,    76,    74,    86,    75,    82,    77,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    68,    83,
      72,    66,    73,    67,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    81,     2,    88,    70,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    84,    69,    85,    89,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    79
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    65,    65,    66,    70,    71,    75,    76,    80,    86,
      87,    91,    92,    93,    98,    99,   103,   104,   109,   110,
     111,   116,   117,   118,   119,   123,   124,   125,   126,   127,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   143,
     144,   145,   149,   150,   154,   155,   156,   160,   161,   165,
     166,   170,   174,   175,   179,   180,   181,   185,   186,   187,
     188,   192,   193,   198,   199,   200,   204,   205,   206,   207,
     208,   212,   213,   217,   218,   222,   223,   227,   228,   232,
     233,   234,   238,   239,   245,   246,   250,   251,   252,   253,
     254,   255,   259,   260,   261,   262,   266,   267,   271,   272,
     276,   277,   281,   282,   283,   287,   288,   292,   293,   294,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   312,
     313,   314,   315,   316,   317,   321,   322,   323,   327,   328,
     332,   333,   337,   338,   342,   343,   347,   348,   349,   353,
     354,   355,   356,   357,   358,   362,   363,   364,   365,   366,
     372,   373,   377,   378,   382,   383,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "T_IDENTIFIER", "T_INT_LIT",
  "T_FLOAT_LIT", "T_CHAR_LIT", "T_STRING_LIT", "T_TYPEDEF_NAME",
  "T_PREPROC", "T_LEXERR", "T_INT", "T_CHAR", "T_SHORT", "T_LONG",
  "T_FLOAT", "T_DOUBLE", "T_VOID", "T_SIGNED", "T_UNSIGNED", "T_IF",
  "T_ELSE", "T_WHILE", "T_FOR", "T_DO", "T_SWITCH", "T_CASE", "T_DEFAULT",
  "T_BREAK", "T_CONTINUE", "T_RETURN", "T_GOTO", "T_STRUCT", "T_UNION",
  "T_ENUM", "T_TYPEDEF", "T_SIZEOF", "T_CONST", "T_VOLATILE", "T_STATIC",
  "T_EXTERN", "T_REGISTER", "T_AUTO", "T_ELLIPSIS", "T_ARROW", "T_INC",
  "T_DEC", "T_SHL", "T_SHR", "T_LE", "T_GE", "T_EQ", "T_NE", "T_ANDAND",
  "T_OROR", "T_MUL_ASSIGN", "T_DIV_ASSIGN", "T_MOD_ASSIGN", "T_ADD_ASSIGN",
  "T_SUB_ASSIGN", "T_SHL_ASSIGN", "T_SHR_ASSIGN", "T_AND_ASSIGN",
  "T_XOR_ASSIGN", "T_OR_ASSIGN", "LOWER_THAN_ELSE", "'='", "'?'", "':'",
  "'|'", "'^'", "'&'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "UNARY", "'('", "'['", "'.'", "';'", "'{'", "'}'", "','", "')'", "']'",
  "'~'", "'!'", "$accept", "program", "translation_unit",
  "external_declaration", "function_definition", "declaration",
  "declaration_specifiers", "sq", "sq_list", "tag_specifiers",
  "basic_specifiers", "storage_class_specifier", "basic_type", "tag_type",
  "type_qualifier", "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "tag_sq", "basic_sq",
  "struct_declarator_list", "struct_declarator", "enum_specifier",
  "enumerator_list", "enumerator", "init_declarator_list",
  "init_declarator", "initializer", "initializer_list", "declarator",
  "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "type_name", "abstract_declarator", "direct_abstract_declarator",
  "statement", "labeled_statement", "compound_statement",
  "block_item_list", "block_item", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "expression", "argument_list", "string_list", "expr", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-201)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-210)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    9107,  5056,  4749,  4828,  4907,  4986,  5065,  5144,  5223,  5302,
    5381,    17,    20,    24,  4156,  3994,  4075,  4212,  4268,  4324,
    4380,    36,  9143,  9179,  9215,  9251,   149,  4436,  4492,  3849,
    5460,  4548,  5493,  4100,  4604,  5135,    65,  5214,  3413,    42,
    -201,  9287,   283,   167,   181,   473,   -58,   144,   -24,   366,
       4,  4660,  5546,  4819,  4898,  5579,  5632,  3980,  9409,    42,
     -16,   -22,    26,  5672,   100,   357,   -40,   561,   181,  3562,
    2899,  9323,  6042,  3608,   454,  9409,  3962,  5112,  4115,  6119,
     143,  5191,  4796,  9409,   206,  3868,  5293,     5,  5713,   192,
     542,   166,   -12,  6203,  6248,  6293,  6338,  5833,  3914,  3868,
    3868,  3868,  3868,  3868,  3868,  3515,  3562,  3868,  3868,   172,
    5891,  8856,  8899,    -5,    -3,    71,  3551,    75,  3868,   110,
     -27,    74,  3654,   186,   649,   297,  2987,   149,  3075,   825,
     913,  3163,  3251,  1001,  1089,  1177,  1265,   180,  8543,   630,
      85,   104,   212,   258,   718,  8633,  6147,  5372,  6159,  3868,
     271,   362,    -7,  5270,  4875,  4954,  5033,  5349,  5698,    14,
    8942,  5766,   289,  3515,  6383,  6428,  6473,  6518,  6563,  6608,
    6653,   120,   116,   342,   298,   354,  6698,  6743,  5949,   203,
    6788,  6833,  3868,  3868,  3868,  3868,  3868,  3868,  3868,  3868,
    3868,  3868,  3868,  3868,  3868,  3868,  3868,  3868,  3868,  3868,
    3868,  3868,  3868,  3868,  3868,  3868,  3868,  3868,  3868,  3868,
    3868,  3868,  3665,  3868,   219,  3551,  3868,  3868,  3427,   190,
    3868,  9322,  3551,  1353,  1441,  1529,   368,   148,   385,  3339,
     737,  3868,  4716,  3702,   380,   207,   396,    88,   806,  9397,
     894,  5780,  8985,  6197,   143,  3868,  5789,   146,  6030,   194,
     155,  3868,  6878,   293,     7,  6923,  6968,  7013,  7058,  7103,
    7148,  7193,  7238,  7283,  7328,  7373,  7418,  7463,  7508,  7553,
    7598,  7643,  7688,  7733,  7778,   -46,  7823,  7868,  7913,  7958,
    8003,  8048,  8093,  8138,  8183,  8228,  8273,   430,  8768,   -62,
    8318,  1617,   441,   464,  3713,  3713,   164,   468,  3551,  1705,
    1793,  1881,  8588,   112,   177,   184,   134,  8678,   209,  6081,
    3759,   189,   484,   450,  9028,  1931,  8363,   460,   386,  3868,
    3868,  8408,  8453,  3551,  3551,  3805,  3822,  3868,  3551,  2019,
     260,   272,   275,   355,   199,   377,  8723,  8498,  8812,  2107,
    2195,  3551,   518,  3551,   525,   527,  2283,   443,   445,  3551,
    2371,  3551,  2459,  3551,   176,  2547,  2635,  2723,  2811
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -201,  -201,  -201,   284,  -201,   -65,    19,   188,  -201,  -201,
    -201,  -201,    27,   119,   202,  -201,  -201,   387,    89,   -96,
    -201,  -201,  -201,   106,  -201,   435,   -66,  -201,   453,  -100,
    -201,    18,   -47,     8,   412,   -70,  -201,   300,   379,  -125,
    -177,  -115,  -201,   504,  -201,   428,  -200,  -201,  -201,  -201,
     -57,  -201,  -201,   -69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    21,    22,    23,    24,    25,   140,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    78,    79,    80,
      81,    82,   150,   151,    37,    61,    62,    46,    47,   109,
     175,    66,    49,    50,    83,   304,   142,   143,   172,   305,
     237,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   287,   110,   138
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     111,   219,   141,    74,   145,   126,   174,    42,    60,   171,
      93,    94,    95,    96,    97,   236,   160,    60,   295,    26,
     -47,   162,   319,   -48,   231,    67,   322,    38,    68,   164,
     165,   166,   167,   168,   169,   170,    40,   111,   176,   177,
     231,    26,    69,    98,    48,    60,   250,    90,   173,   221,
      85,    64,    99,   100,    69,    52,   223,    56,   308,   -77,
      70,   245,   -77,    86,    87,   226,   126,   171,    57,   -73,
     -73,   -77,   308,    89,   -77,   216,   -63,   217,   101,   -63,
     242,   102,   103,   104,    44,    76,    92,   105,    42,   127,
     161,   106,   317,   162,   325,   326,   107,   108,   152,   246,
     291,   -47,    76,   -94,   -48,    76,   173,   299,    39,   154,
     156,   -71,   -71,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,    76,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   288,   275,    92,    42,    53,   235,    58,
     127,   218,    42,   294,   318,   220,   289,   224,   234,   292,
     293,    43,   302,   297,   307,   232,   233,   148,   309,   310,
     -92,  -104,  -104,    76,  -108,  -108,   314,    77,   222,   249,
     -94,   -94,   316,   329,    42,   111,   -94,   -94,    74,   227,
      76,   238,  -115,  -115,    77,   -95,    43,    77,  -115,  -115,
     248,   233,   157,   251,    15,    16,   255,  -105,   339,   340,
      42,   149,   296,   346,  -111,  -111,    51,    54,    55,    43,
    -111,  -111,   290,    44,    77,    43,   350,   -75,   352,    44,
     -75,   301,    45,   315,   355,   148,   356,   127,   357,   334,
     235,   336,  -106,    43,   327,    63,   316,   -92,   -92,   -76,
     337,   338,   -76,   -92,   -92,   -78,   249,    43,   -78,   358,
      63,    44,   152,   230,   330,    77,   231,    88,   342,   344,
     345,   331,   -95,   -95,   248,   233,   -99,    63,   -95,   -95,
      63,  -107,    77,   153,   155,    88,   347,   232,   233,   309,
     310,   158,   159,  -107,  -107,  -109,  -109,  -128,   239,   -98,
    -128,  -128,  -128,  -128,  -128,  -128,    41,    63,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,
    -116,  -116,  -128,  -128,  -100,  -100,  -116,  -116,    63,   -86,
     313,   -86,  -110,  -110,   243,  -112,  -112,   244,  -110,  -110,
     -93,  -112,  -112,   -86,   -86,    63,   -86,   -86,  -128,   -86,
     -86,  -128,  -128,  -128,   -72,   -72,   -80,  -128,   -80,   -80,
    -128,  -128,  -128,   -82,   -82,  -129,  -128,  -128,  -129,  -129,
    -129,  -129,  -129,  -129,    15,    16,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,   231,   252,
    -129,  -129,   -85,    43,   -85,  -117,  -117,   -93,   -93,   253,
     254,  -117,  -117,   -93,   -93,   -61,    72,    73,   -61,   -85,
     -85,   300,   -85,   -85,   231,    65,  -129,  -113,  -113,  -129,
    -129,  -129,   146,  -113,  -113,  -129,  -102,  -102,  -129,  -129,
    -129,   -83,   -83,    -9,  -129,  -129,    -9,    -9,    -9,    -9,
      -9,    -9,  -103,  -103,    -9,    -9,    -9,    -9,    -9,    -9,
      -9,    -9,    -9,    -9,    84,    -9,    -9,    -9,    -9,    -9,
      -9,    -9,    -9,    -9,    -9,    -9,    -9,    -9,    -9,    -9,
      -9,    -9,    -9,    -9,    -9,    -9,   320,   321,    -9,    -9,
     -84,    91,   -84,  -118,  -118,  -114,  -114,   231,   323,  -118,
    -118,  -114,  -114,   -62,    72,    73,   -62,   -84,   -84,   312,
     -84,   -84,   247,   -81,    -9,   -81,   -81,    -9,    -9,    -9,
     231,   324,    71,    -9,   231,   328,    -9,    -9,    -9,   229,
       0,   -10,    -9,    -9,   -10,   -10,   -10,   -10,   -10,   -10,
    -101,  -101,   -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,
     -10,   -10,     0,   -10,   -10,   -10,   -10,   -10,   -10,   -10,
     -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,
     -10,   -10,   -10,   -10,   231,   351,   -10,   -10,   -87,     0,
     -87,   231,   353,   231,   354,     0,     0,     0,     0,     0,
       0,     0,   -87,   -87,     0,   -87,   -87,     0,   -87,   -87,
       0,     0,   -10,     0,     0,   -10,   -10,   -10,     0,     0,
       0,   -10,     0,     0,   -10,   -10,   -10,     0,     0,     0,
     -10,   -10,  -134,  -134,  -134,  -134,  -134,  -134,     0,     0,
    -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,
    -134,  -134,     0,     0,  -134,  -134,   -91,     0,   -91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -91,   -91,     0,   -91,   -91,     0,   -91,   -91,     0,     0,
    -134,     0,     0,  -134,  -134,  -134,     0,     0,     0,  -134,
       0,     0,  -134,  -134,  -134,     0,  -134,     0,  -134,  -134,
    -135,  -135,  -135,  -135,  -135,  -135,     0,     0,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
       0,     0,  -135,  -135,   -89,     0,   -89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -89,   -89,
       0,   -89,   -89,     0,   -89,   -89,     0,     0,  -135,     0,
       0,  -135,  -135,  -135,     0,     0,     0,  -135,     0,     0,
    -135,  -135,  -135,     0,  -135,     0,  -135,  -135,  -119,  -119,
    -119,  -119,  -119,  -119,     0,     0,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,     0,     0,
    -119,  -119,   -90,     0,   -90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -90,   -90,     0,   -90,
     -90,     0,   -90,   -90,     0,     0,  -119,     0,     0,  -119,
    -119,  -119,     0,     0,     0,  -119,     0,     0,  -119,  -119,
    -119,     0,     0,     0,  -119,  -119,  -120,  -120,  -120,  -120,
    -120,  -120,     0,     0,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,     0,     0,  -120,  -120,
     -88,     0,   -88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -88,   -88,     0,   -88,   -88,     0,
     -88,   -88,     0,     0,  -120,     0,     0,  -120,  -120,  -120,
       0,     0,     0,  -120,     0,     0,  -120,  -120,  -120,     0,
       0,     0,  -120,  -120,  -121,  -121,  -121,  -121,  -121,  -121,
       0,     0,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,     0,     0,  -121,  -121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -121,     0,     0,  -121,  -121,  -121,     0,     0,
       0,  -121,     0,     0,  -121,  -121,  -121,     0,     0,     0,
    -121,  -121,  -122,  -122,  -122,  -122,  -122,  -122,     0,     0,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,     0,     0,  -122,  -122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -122,     0,     0,  -122,  -122,  -122,     0,     0,     0,  -122,
       0,     0,  -122,  -122,  -122,     0,     0,     0,  -122,  -122,
    -123,  -123,  -123,  -123,  -123,  -123,     0,     0,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
       0,     0,  -123,  -123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -123,     0,
       0,  -123,  -123,  -123,     0,     0,     0,  -123,     0,     0,
    -123,  -123,  -123,     0,     0,     0,  -123,  -123,  -124,  -124,
    -124,  -124,  -124,  -124,     0,     0,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,     0,     0,
    -124,  -124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -124,     0,     0,  -124,
    -124,  -124,     0,     0,     0,  -124,     0,     0,  -124,  -124,
    -124,     0,     0,     0,  -124,  -124,  -147,  -147,  -147,  -147,
    -147,  -147,     0,     0,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,     0,     0,  -147,  -147,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -147,     0,     0,  -147,  -147,  -147,
       0,     0,     0,  -147,     0,     0,  -147,  -147,  -147,     0,
       0,     0,  -147,  -147,  -146,  -146,  -146,  -146,  -146,  -146,
       0,     0,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,     0,     0,  -146,  -146,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -146,     0,     0,  -146,  -146,  -146,     0,     0,
       0,  -146,     0,     0,  -146,  -146,  -146,     0,     0,     0,
    -146,  -146,  -148,  -148,  -148,  -148,  -148,  -148,     0,     0,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,     0,     0,  -148,  -148,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -148,     0,     0,  -148,  -148,  -148,     0,     0,     0,  -148,
       0,     0,  -148,  -148,  -148,     0,     0,     0,  -148,  -148,
    -125,  -125,  -125,  -125,  -125,  -125,     0,     0,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
       0,     0,  -125,  -125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -125,     0,
       0,  -125,  -125,  -125,     0,     0,     0,  -125,     0,     0,
    -125,  -125,  -125,     0,     0,     0,  -125,  -125,  -127,  -127,
    -127,  -127,  -127,  -127,     0,     0,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,     0,     0,
    -127,  -127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -127,     0,     0,  -127,
    -127,  -127,     0,     0,     0,  -127,     0,     0,  -127,  -127,
    -127,     0,     0,     0,  -127,  -127,  -149,  -149,  -149,  -149,
    -149,  -149,     0,     0,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,     0,     0,  -149,  -149,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -149,     0,     0,  -149,  -149,  -149,
       0,     0,     0,  -149,     0,     0,  -149,  -149,  -149,     0,
       0,     0,  -149,  -149,  -145,  -145,  -145,  -145,  -145,  -145,
       0,     0,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,     0,     0,  -145,  -145,     0,     0,
       0,     0,     0,     0,    93,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -145,     0,     0,  -145,  -145,  -145,     0,     0,
       0,  -145,     0,     0,  -145,  -145,  -145,    98,     0,     0,
    -145,  -145,     0,     0,     0,  -178,    99,   100,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,     0,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
       0,   105,  -178,  -178,  -178,     0,  -178,  -178,  -178,  -178,
     107,   108,  -126,  -126,  -126,  -126,  -126,  -126,     0,     0,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,     0,     0,  -126,  -126,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -126,     0,     0,  -126,  -126,  -126,     0,     0,     0,  -126,
       0,     0,  -126,  -126,  -126,     0,     0,     0,  -126,  -126,
    -136,  -136,  -136,  -136,  -136,  -136,     0,     0,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,   349,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
       0,     0,  -136,  -136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -136,     0,
       0,  -136,  -136,  -136,     0,     0,     0,  -136,     0,     0,
    -136,  -136,  -136,     0,     0,     0,  -136,  -136,  -139,  -139,
    -139,  -139,  -139,  -139,     0,     0,  -139,  -139,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,     0,     0,
    -139,  -139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -139,     0,     0,  -139,
    -139,  -139,     0,     0,     0,  -139,     0,     0,  -139,  -139,
    -139,     0,     0,     0,  -139,  -139,  -138,  -138,  -138,  -138,
    -138,  -138,     0,     0,  -138,  -138,  -138,  -138,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,     0,     0,  -138,  -138,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -138,     0,     0,  -138,  -138,  -138,
       0,     0,     0,  -138,     0,     0,  -138,  -138,  -138,     0,
       0,     0,  -138,  -138,  -143,  -143,  -143,  -143,  -143,  -143,
       0,     0,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,     0,     0,  -143,  -143,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -143,     0,     0,  -143,  -143,  -143,     0,     0,
       0,  -143,     0,     0,  -143,  -143,  -143,     0,     0,     0,
    -143,  -143,  -141,  -141,  -141,  -141,  -141,  -141,     0,     0,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,     0,     0,  -141,  -141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -141,     0,     0,  -141,  -141,  -141,     0,     0,     0,  -141,
       0,     0,  -141,  -141,  -141,     0,     0,     0,  -141,  -141,
    -137,  -137,  -137,  -137,  -137,  -137,     0,     0,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
       0,     0,  -137,  -137,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -137,     0,
       0,  -137,  -137,  -137,     0,     0,     0,  -137,     0,     0,
    -137,  -137,  -137,     0,     0,     0,  -137,  -137,  -144,  -144,
    -144,  -144,  -144,  -144,     0,     0,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,     0,     0,
    -144,  -144,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -144,     0,     0,  -144,
    -144,  -144,     0,     0,     0,  -144,     0,     0,  -144,  -144,
    -144,     0,     0,     0,  -144,  -144,  -142,  -142,  -142,  -142,
    -142,  -142,     0,     0,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,     0,     0,  -142,  -142,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -142,     0,     0,  -142,  -142,  -142,
       0,     0,     0,  -142,     0,     0,  -142,  -142,  -142,     0,
       0,     0,  -142,  -142,  -140,  -140,  -140,  -140,  -140,  -140,
       0,     0,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,     0,     0,  -140,  -140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -140,     0,     0,  -140,  -140,  -140,     0,     0,
       0,  -140,     0,     0,  -140,  -140,  -140,     0,     0,     0,
    -140,  -140,   112,    94,    95,    96,    97,     1,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,   113,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,    11,    12,    13,    14,    98,    15,    16,    17,    18,
      19,    20,     0,     0,    99,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     101,     0,     0,   102,   103,   104,     0,     0,     0,   105,
       0,     0,   124,    70,   125,     0,     0,     0,   107,   108,
    -132,  -132,  -132,  -132,  -132,  -132,     0,     0,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,     0,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
       0,     0,  -132,  -132,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -132,     0,
       0,  -132,  -132,  -132,     0,     0,     0,  -132,     0,     0,
    -132,  -132,  -132,     0,     0,     0,  -132,  -132,  -133,  -133,
    -133,  -133,  -133,  -133,     0,     0,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,     0,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,     0,     0,
    -133,  -133,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -133,     0,     0,  -133,
    -133,  -133,     0,     0,     0,  -133,     0,     0,  -133,  -133,
    -133,     0,     0,     0,  -133,  -133,   112,    94,    95,    96,
      97,     1,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,   113,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,    11,    12,    13,    14,    98,
      15,    16,    17,    18,    19,    20,     0,     0,    99,   100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   101,     0,     0,   102,   103,   104,
       0,     0,     0,   105,     0,     0,   124,    70,   228,     0,
       0,     0,   107,   108,  -130,  -130,  -130,  -130,  -130,  -130,
       0,     0,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,     0,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,     0,     0,  -130,  -130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -130,     0,     0,  -130,  -130,  -130,     0,     0,
       0,  -130,     0,     0,  -130,  -130,  -130,     0,     0,     0,
    -130,  -130,  -131,  -131,  -131,  -131,  -131,  -131,     0,     0,
    -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
       0,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,     0,     0,  -131,  -131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -131,     0,     0,  -131,  -131,  -131,   -70,     0,     0,  -131,
       0,     0,  -131,  -131,  -131,     0,     0,     0,  -131,  -131,
      93,    94,    95,    96,    97,     1,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,     0,   -70,     0,
     -70,   -70,   -70,   -70,   -70,   -70,     0,     0,     0,    11,
      12,    13,    14,    98,    15,    16,    17,    18,    19,    20,
       0,     0,    99,   100,     0,     0,     0,     0,     0,     0,
       0,   -70,     0,     0,     0,     0,     0,     0,     0,   -70,
       0,     0,     0,   -70,   -70,     0,   -70,    59,   101,   -70,
     -70,   102,   103,   104,     0,     0,     0,   105,     0,     0,
     124,     0,     0,     0,     0,     0,   107,   108,    93,    94,
      95,    96,    97,     1,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,    12,    13,
       0,    98,    15,    16,   112,    94,    95,    96,    97,     0,
      99,   100,     0,     0,     0,    93,    94,    95,    96,    97,
       0,   113,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,     0,     0,     0,   101,    98,     0,   102,
     103,   104,     0,     0,     0,   105,    99,   100,    98,     0,
       0,     0,     0,     0,   107,   108,     0,    99,   100,     0,
       0,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,   101,     0,     0,   102,   103,   104,     0,     0,
       0,   105,     0,   101,   124,    70,   102,   103,   104,     0,
     107,   108,   105,     0,    98,     0,   106,     0,     0,     0,
       0,   107,   108,    99,   100,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    93,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,   101,
       0,     0,   102,   103,   104,     0,     0,     0,   105,     0,
      98,     0,     0,     0,     0,     0,   144,   107,   108,    99,
     100,    98,     0,     0,     0,    93,    94,    95,    96,    97,
      99,   100,     0,     0,     0,     0,    93,    94,    95,    96,
      97,     0,     0,     0,     0,   101,     0,     0,   102,   103,
     104,     0,     0,     0,   105,     0,   101,   225,    98,   102,
     103,   104,     0,   107,   108,   105,     0,    99,   100,    98,
       0,     0,   286,     0,   107,   108,     0,     0,    99,   100,
       0,     0,    93,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,   101,     0,     0,   102,   103,   104,     0,
       0,     0,   105,     0,   101,     0,     0,   102,   103,   104,
     306,   107,   108,   105,     0,    98,   124,     0,     0,     0,
       0,     0,   107,   108,    99,   100,     0,     0,    93,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,    94,    95,    96,    97,
     101,     0,     0,   102,   103,   104,     0,     0,     0,   105,
       0,    98,     0,     0,     0,     0,     0,   335,   107,   108,
      99,   100,   -12,     0,     0,     0,     0,     0,    98,     0,
       0,     0,     0,     0,     0,     0,     0,    99,   100,     0,
       0,    93,    94,    95,    96,    97,   101,     0,     0,   102,
     103,   104,     0,     0,    14,   105,    15,    16,    17,    18,
      19,    20,   341,   101,   107,   108,   102,   103,   104,     0,
       0,     0,   105,     0,    98,     0,     0,     0,     0,   343,
       0,   107,   108,    99,   100,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,   -12,     0,     0,     0,   -12,
     -12,     0,   -12,     0,     0,   -12,   -12,     0,     0,   101,
       0,     0,   102,   103,   104,     0,     0,     0,   105,     0,
      98,     0,     0,     0,     0,     0,     0,   107,   108,    99,
     100,     0,     0,     0,     0,   -57,     0,     0,     0,     0,
       0,     0,     0,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,     0,   -46,     0,   101,     0,     0,   102,   103,
     104,     0,     0,     0,   163,     0,     0,   -42,     0,   -57,
     -57,     0,   -42,   107,   108,   -42,   -42,   -42,   -42,   -42,
     -42,   -42,   -42,   -42,     0,   -46,     0,   -46,   -46,   -46,
     -46,   -46,   -46,     0,     0,     0,   -42,   -42,   -42,   -42,
     -57,   -42,   -42,   -42,   -42,   -42,   -42,     0,   -57,     0,
       0,     0,   -57,   -57,     0,     0,     0,     0,   -46,   -57,
       0,     0,     0,     0,     0,     0,   -46,     0,     0,     0,
     -46,   -46,   -42,   -46,    75,     0,   -46,   -46,     0,     0,
     -42,     0,     0,     0,   -42,   -42,     0,   -42,   -43,     0,
     -42,   -42,     0,   -43,     0,     0,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,     0,     0,     0,     0,     0,
       0,     0,     0,   -18,     0,     0,     0,   -43,   -43,   -43,
     -43,     0,   -43,   -43,   -43,   -43,   -43,   -43,     0,     0,
       0,     0,     0,     1,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,   -18,     0,   -18,   -18,   -18,
     -18,   -18,   -18,   -43,     0,     0,     0,    11,    12,    13,
       0,   -43,    15,    16,     0,   -43,   -43,     0,   -43,   -25,
       0,   -43,   -43,     0,   -25,     0,     0,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -18,     0,     0,     0,
     -18,   -18,     0,   -18,     0,     0,   -18,   -18,   -25,   -25,
     -25,   -25,     0,   -25,   -25,   -25,   -25,   -25,   -25,     0,
     147,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -26,     0,     0,     0,     0,
     -26,     0,     0,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
     -26,   -26,   -25,     0,     0,     0,   -25,   -25,     0,   -25,
       0,     0,   -25,   -25,   -26,   -26,   -26,   -26,     0,   -26,
     -26,   -26,   -26,   -26,   -26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -27,     0,     0,     0,     0,   -27,     0,     0,   -27,
     -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -26,     0,
       0,     0,   -26,   -26,     0,   -26,     0,     0,   -26,   -26,
     -27,   -27,   -27,   -27,     0,   -27,   -27,   -27,   -27,   -27,
     -27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -28,     0,     0,
       0,     0,   -28,     0,     0,   -28,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,   -27,     0,     0,     0,   -27,   -27,
       0,   -27,     0,     0,   -27,   -27,   -28,   -28,   -28,   -28,
       0,   -28,   -28,   -28,   -28,   -28,   -28,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -29,     0,     0,     0,     0,   -29,     0,
       0,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -28,     0,     0,     0,   -28,   -28,     0,   -28,     0,     0,
     -28,   -28,   -29,   -29,   -29,   -29,     0,   -29,   -29,   -29,
     -29,   -29,   -29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -16,
       0,     0,     0,     0,   -16,     0,     0,   -16,   -16,   -16,
     -16,   -16,   -16,   -16,   -16,   -16,   -29,     0,     0,     0,
     -29,   -29,     0,   -29,     0,     0,   -29,   -29,   -16,   -16,
     -16,   -16,     0,   -16,   -16,   -16,   -16,   -16,   -16,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -11,     0,     0,     0,     0,
       1,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,   -16,     0,     0,     0,   -16,   -16,     0,   -16,
       0,     0,   -16,   -16,    11,    12,    13,    14,     0,    15,
      16,    17,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -14,     0,     0,     0,     0,   -14,     0,     0,   -14,
     -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -11,     0,
       0,     0,   -11,   -11,     0,   -11,     0,     0,   -11,   -11,
     -14,   -14,   -14,   -14,     0,   -14,   -14,   -14,   -14,   -14,
     -14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -15,     0,     0,
       0,     0,   -15,     0,     0,   -15,   -15,   -15,   -15,   -15,
     -15,   -15,   -15,   -15,   -14,     0,     0,     0,   -14,   -14,
       0,   -14,     0,     0,   -14,   -14,   -15,   -15,   -15,   -15,
       0,   -15,   -15,   -15,   -15,   -15,   -15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -17,     0,     0,     0,     0,   -17,     0,
       0,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -15,     0,     0,     0,   -15,   -15,     0,   -15,     0,     0,
     -15,   -15,   -17,   -17,   -17,   -17,     0,   -17,   -17,   -17,
     -17,   -17,   -17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,     0,     1,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,   -17,     0,     0,     0,
     -17,   -17,     0,   -17,     0,     0,   -17,   -17,    11,    12,
      13,    14,   -33,    15,    16,    17,    18,    19,    20,     0,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -33,     0,   -33,   -33,   -33,   -33,
     -33,   -33,    43,     0,     0,     0,   232,   233,     0,   -53,
       0,     0,     0,   303,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,   -33,     0,     0,
       0,     0,   -19,     0,     0,   -33,     0,     0,     0,   -33,
     -33,   -31,   -33,    15,    16,   -33,   -33,     0,     0,   -31,
     -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,     0,     0,
       0,     0,     0,     0,   -19,     0,   -19,   -19,   -19,   -19,
     -19,   -19,     0,   -31,   -53,   -31,   -31,   -31,   -31,   -31,
     -31,     0,   -53,     0,     0,     0,   -53,   -53,   -59,     0,
       0,     0,     0,   -53,     0,     0,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   -19,   -31,     0,     0,   -19,
     -19,   -20,   -19,     0,   -31,   -19,   -19,     0,   -31,   -31,
     -32,   -31,   -59,   -59,   -31,   -31,     0,     0,   -32,   -32,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,     0,     0,     0,
       0,     0,     0,   -20,     0,   -20,   -20,   -20,   -20,   -20,
     -20,     0,   -32,   -59,   -32,   -32,   -32,   -32,   -32,   -32,
       0,   -59,     0,     0,     0,   -59,   -59,   -60,     0,     0,
       0,     0,   -59,     0,     0,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -20,   -32,     0,     0,   -20,   -20,
       0,   -20,     0,   -32,   -20,   -20,     0,   -32,   -32,   -34,
     -32,   -60,   -60,   -32,   -32,     0,     0,   -34,   -34,   -34,
     -34,   -34,   -34,   -34,   -34,   -34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -34,   -60,   -34,   -34,   -34,   -34,   -34,   -34,     0,
     -60,     0,     0,     0,   -60,   -60,   -58,     0,     0,     0,
       0,   -60,     0,     0,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,     0,   -34,     0,     0,     0,     0,   -41,
       0,     0,   -34,     0,     0,     0,   -34,   -34,   -35,   -34,
     -58,   -58,   -34,   -34,     0,     0,   -35,   -35,   -35,   -35,
     -35,   -35,   -35,   -35,   -35,     0,     0,     0,     0,     0,
       0,   -41,     0,   -41,   -41,   -41,   -41,   -41,   -41,     0,
     -35,   -58,   -35,   -35,   -35,   -35,   -35,   -35,     0,   -58,
       0,     0,     0,   -58,   -58,   -54,     0,     0,     0,     0,
     -58,     0,     0,     0,   -41,     0,     0,     0,     0,     0,
       0,     0,   -41,   -35,     0,     0,   -41,   -41,   -39,   -41,
       0,   -35,   -41,   -41,     0,   -35,   -35,   -36,   -35,   -54,
     -54,   -35,   -35,     0,     0,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,   -36,     0,     0,     0,     0,     0,     0,
     -39,     0,   -39,   -39,   -39,   -39,   -39,   -39,     0,   -36,
     -54,   -36,   -36,   -36,   -36,   -36,   -36,     0,   -54,     0,
       0,     0,   -54,   -54,   -52,     0,     0,     0,     0,   -54,
       0,     0,     0,   -39,     0,     0,     0,     0,     0,     0,
       0,   -39,   -36,     0,     0,   -39,   -39,   -40,   -39,     0,
     -36,   -39,   -39,     0,   -36,   -36,   -30,   -36,    15,    16,
     -36,   -36,     0,     0,   -30,   -30,   -30,   -30,   -30,   -30,
     -30,   -30,   -30,     0,     0,     0,     0,     0,     0,   -40,
       0,   -40,   -40,   -40,   -40,   -40,   -40,     0,   -30,   -52,
     -30,   -30,   -30,   -30,   -30,   -30,     0,   -52,     0,     0,
       0,   -52,   -52,   -56,     0,     0,     0,     0,   -52,     0,
       0,     0,   -40,     0,     0,     0,     0,     0,     0,     0,
     -40,   -30,     0,     0,   -40,   -40,   -68,   -40,     0,   -30,
     -40,   -40,     0,   -30,   -30,   -37,   -30,   -56,   -56,   -30,
     -30,     0,     0,   -37,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,     0,     0,     0,     0,     0,     0,   -68,     0,
     -68,   -68,   -68,   -68,   -68,   -68,     0,   -37,   -56,   -37,
     -37,   -37,   -37,   -37,   -37,     0,   -56,     0,     0,     0,
     -56,   -56,   -55,     0,     0,     0,     0,   -56,     0,     0,
       0,   -68,     0,     0,     0,     0,     0,     0,     0,   -68,
     -37,     0,     0,   -68,   -68,   -45,   -68,     0,   -37,   -68,
     -68,     0,   -37,   -37,   -38,   -37,   -55,   -55,   -37,   -37,
       0,     0,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,     0,     0,     0,     0,     0,     0,   -45,     0,   -45,
     -45,   -45,   -45,   -45,   -45,     0,   -38,   -55,   -38,   -38,
     -38,   -38,   -38,   -38,     0,   -55,     0,     0,     0,   -55,
     -55,     0,     0,     0,     0,     0,   -55,     0,     0,     0,
     -45,     0,     0,     0,     0,     0,     0,     0,   -45,   -38,
       0,     0,   -45,   -45,     0,   -45,     0,   -38,   -45,   -45,
       0,   -38,   -38,   -13,   -38,     0,     0,   -38,   -38,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,   -21,    15,    16,    17,
      18,    19,    20,     0,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -21,     0,
     -21,   -21,   -21,   -21,   -21,   -21,   -13,     0,     0,     0,
     -13,   -13,     0,   -13,     0,     0,   -13,   -13,     0,   -22,
       0,     0,     0,     0,     0,     0,     0,   -22,   -22,   -22,
     -22,   -22,   -22,   -22,   -22,   -22,     0,     0,     0,   -21,
       0,     0,     0,   -21,   -21,     0,   -21,     0,     0,   -21,
     -21,   -22,   -24,   -22,   -22,   -22,   -22,   -22,   -22,     0,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -24,     0,   -24,   -24,   -24,   -24,
     -24,   -24,   -22,     0,     0,     0,   -22,   -22,     0,   -22,
       0,     0,   -22,   -22,     0,   -23,     0,     0,     0,     0,
       0,     0,     0,   -23,   -23,   -23,   -23,   -23,   -23,   -23,
     -23,   -23,     0,     0,     0,   -24,     0,     0,     0,   -24,
     -24,     0,   -24,     0,     0,   -24,   -24,   -23,     0,   -23,
     -23,   -23,   -23,   -23,   -23,   -96,     0,     0,     0,     0,
     -96,     0,     0,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -66,     0,     0,   -96,   -96,   -96,     0,   -23,   -96,
     -96,     0,   -23,   -23,     0,   -23,   -97,     0,   -23,   -23,
       0,   -97,     0,     0,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -97,   -66,     0,   -66,   -66,   -66,   -66,   -66,
     -66,     0,     0,     0,     0,   -97,   -97,   -97,   -96,     0,
     -97,   -97,   -96,   -96,     0,     0,     0,     0,   -96,   -96,
       0,     0,     0,     0,     0,     0,   -66,     0,     0,   -69,
       0,     0,     0,     0,   -66,     0,     0,     0,   -66,   -66,
       0,   -66,     0,   -44,   -66,   -66,     0,     0,     0,   -97,
       0,     0,   -67,   -97,   -97,     0,     0,     0,     0,   -97,
     -97,   -69,     0,   -69,   -69,   -69,   -69,   -69,   -69,     0,
       0,     0,     0,     0,     0,   -44,     0,   -44,   -44,   -44,
     -44,   -44,   -44,     0,   -67,     0,   -67,   -67,   -67,   -67,
     -67,   -67,     0,     0,   -69,     0,     0,     0,     0,     0,
    -154,     0,   -69,     0,     0,     0,   -69,   -69,   -44,   -69,
       0,     0,   -69,   -69,     0,     0,   -44,   -67,     0,     0,
     -44,   -44,     0,   -44,     0,   -67,   -44,   -44,     0,   -67,
     -67,     0,   -67,     0,     0,   -67,   -67,  -154,  -154,  -154,
    -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,
    -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,   178,  -154,
    -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,
    -154,  -154,     0,  -154,  -154,  -154,  -154,     0,  -154,  -154,
    -154,  -154,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,  -160,  -155,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
       0,  -160,  -160,  -160,  -160,     0,  -160,  -160,  -160,  -160,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,     0,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,     0,  -155,
    -155,  -155,  -155,     0,  -155,  -155,  -155,  -155,     1,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       1,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     0,    15,    16,    17,
      18,    19,    20,     0,    11,    12,    13,    14,     0,    15,
      16,    17,    18,    19,    20,     0,     0,     0,     0,     1,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,     0,     0,     0,     0,     0,    43,     0,     0,     0,
     248,   233,     0,    11,    12,    13,    14,   303,    15,    16,
      17,    18,    19,    20,     0,     0,     0,   -49,     0,   139,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -49,   -49,   -49,     0,     1,   -49,   -49,     2,     3,
       4,     5,     6,     7,     8,     9,    10,   -50,   333,     0,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,    11,
      12,    13,     0,     0,    15,    16,     0,     0,     0,     0,
       0,   -50,   -50,   -50,     0,     0,   -50,   -50,     0,     0,
       0,     0,     0,     0,   -49,   -51,     0,     0,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -51,
     -51,   -51,   241,     0,   -51,   -51,     0,     0,     0,     0,
       0,     0,     0,     0,   -50,     0,     0,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,     0,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,   -51,  -156,  -156,  -156,  -156,     0,  -156,  -156,
    -156,  -156,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,     0,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,     0,  -157,  -157,
    -157,  -157,     0,  -157,  -157,  -157,  -157,  -158,  -158,  -158,
    -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,
    -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,     0,  -158,
    -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,
    -158,  -158,     0,  -158,  -158,  -158,  -158,     0,  -158,  -158,
    -158,  -158,  -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,
    -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,
    -159,  -159,  -159,     0,  -159,  -159,  -159,  -159,  -159,  -159,
    -159,  -159,  -159,  -159,  -159,  -159,  -159,     0,  -159,  -159,
    -159,  -159,     0,  -159,  -159,  -159,  -159,   179,   180,   181,
    -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,
    -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,     0,  -177,
    -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,
    -177,  -177,     0,   212,   213,   214,  -177,     0,  -177,  -177,
    -177,  -177,   179,   180,   181,  -169,  -169,  -169,  -169,  -169,
    -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,
    -169,  -169,  -169,     0,  -169,  -169,  -169,  -169,  -169,  -169,
    -169,  -169,  -169,  -169,  -169,  -169,  -169,     0,   212,   213,
     214,  -169,     0,  -169,  -169,  -169,  -169,   179,   180,   181,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,     0,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,     0,   212,   213,   214,  -170,     0,  -170,  -170,
    -170,  -170,   179,   180,   181,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,  -171,     0,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,  -171,  -171,  -171,  -171,  -171,     0,   212,   213,
     214,  -171,     0,  -171,  -171,  -171,  -171,   179,   180,   181,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,     0,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,     0,   212,   213,   214,  -173,     0,  -173,  -173,
    -173,  -173,   179,   180,   181,  -174,  -174,  -174,  -174,  -174,
    -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,
    -174,  -174,  -174,     0,  -174,  -174,  -174,  -174,  -174,  -174,
    -174,  -174,  -174,  -174,  -174,  -174,  -174,     0,   212,   213,
     214,  -174,     0,  -174,  -174,  -174,  -174,   179,   180,   181,
    -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,
    -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,     0,  -172,
    -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,
    -172,  -172,     0,   212,   213,   214,  -172,     0,  -172,  -172,
    -172,  -172,   179,   180,   181,  -175,  -175,  -175,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,
    -175,  -175,  -175,     0,  -175,  -175,  -175,  -175,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,     0,   212,   213,
     214,  -175,     0,  -175,  -175,  -175,  -175,   179,   180,   181,
    -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
    -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,     0,  -176,
    -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
    -176,  -176,     0,   212,   213,   214,  -176,     0,  -176,  -176,
    -176,  -176,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,     0,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,     0,  -167,  -167,
    -167,  -167,     0,  -167,  -167,  -167,  -167,  -168,  -168,  -168,
    -168,  -168,  -168,  -168,  -168,  -168,  -168,  -168,  -168,  -168,
    -168,  -168,  -168,  -168,  -168,  -168,  -168,  -168,     0,  -168,
    -168,  -168,  -168,  -168,  -168,  -168,  -168,  -168,  -168,  -168,
    -168,  -168,     0,  -168,  -168,  -168,  -168,     0,  -168,  -168,
    -168,  -168,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,     0,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,  -161,  -161,  -161,  -161,     0,  -161,  -161,
    -161,  -161,     0,  -161,  -161,  -161,  -161,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,     0,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,     0,  -166,  -166,  -166,  -166,     0,  -166,  -166,
    -166,  -166,   179,   180,   181,  -185,  -185,  -185,  -185,  -185,
    -185,  -185,  -185,  -185,  -185,  -185,  -185,  -185,  -185,  -185,
    -185,  -185,  -185,     0,  -185,  -185,  -185,  -185,  -185,  -185,
    -185,  -185,   207,   208,   209,   210,   211,     0,   212,   213,
     214,  -185,     0,  -185,  -185,  -185,  -185,   179,   180,   181,
    -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,     0,  -186,
    -186,  -186,  -186,  -186,  -186,  -186,  -186,   207,   208,   209,
     210,   211,     0,   212,   213,   214,  -186,     0,  -186,  -186,
    -186,  -186,   179,   180,   181,   182,   183,  -189,  -189,  -189,
    -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,
    -189,  -189,  -189,     0,  -189,  -189,  -189,  -189,  -189,  -189,
    -189,  -189,   207,   208,   209,   210,   211,     0,   212,   213,
     214,  -189,     0,  -189,  -189,  -189,  -189,   179,   180,   181,
     182,   183,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,     0,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,   207,   208,   209,
     210,   211,     0,   212,   213,   214,  -190,     0,  -190,  -190,
    -190,  -190,   179,   180,   181,   182,   183,   184,   185,  -191,
    -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,
    -191,  -191,  -191,     0,  -191,  -191,  -191,  -191,  -191,  -191,
     205,   206,   207,   208,   209,   210,   211,     0,   212,   213,
     214,  -191,     0,  -191,  -191,  -191,  -191,   179,   180,   181,
     182,   183,   184,   185,  -192,  -192,  -192,  -192,  -192,  -192,
    -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,     0,  -192,
    -192,  -192,  -192,  -192,  -192,   205,   206,   207,   208,   209,
     210,   211,     0,   212,   213,   214,  -192,     0,  -192,  -192,
    -192,  -192,   179,   180,   181,   182,   183,   184,   185,   186,
     187,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,     0,  -196,  -196,  -196,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,     0,   212,   213,
     214,  -196,     0,  -196,  -196,  -196,  -196,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,     0,  -197,
    -197,  -197,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,     0,   212,   213,   214,  -197,     0,  -197,  -197,
    -197,  -197,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,     0,   200,   201,  -200,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,     0,   212,   213,
     214,  -200,     0,  -200,  -200,  -200,  -200,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,     0,   200,
     201,  -201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,     0,   212,   213,   214,  -201,     0,  -201,  -201,
    -201,  -201,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,     0,   200,   201,  -202,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,     0,   212,   213,
     214,  -202,     0,  -202,  -202,  -202,  -202,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,     0,   200,
     201,  -203,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,     0,   212,   213,   214,  -203,     0,  -203,  -203,
    -203,  -203,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,     0,   200,   201,  -204,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,     0,   212,   213,
     214,  -204,     0,  -204,  -204,  -204,  -204,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,  -205,  -205,
    -205,  -205,  -205,   195,   196,   197,   198,   199,     0,  -205,
     201,  -205,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,     0,   212,   213,   214,  -205,     0,  -205,  -205,
    -205,  -205,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,  -206,  -206,  -206,  -206,  -206,   195,   196,
     197,   198,   199,     0,  -206,   201,  -206,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,     0,   212,   213,
     214,  -206,     0,  -206,  -206,  -206,  -206,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,  -207,  -207,
    -207,  -207,  -207,   195,   196,   197,   198,   199,     0,  -207,
     201,  -207,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,     0,   212,   213,   214,  -207,     0,  -207,  -207,
    -207,  -207,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,  -208,  -208,  -208,  -208,  -208,   195,   196,
     197,   198,   199,     0,  -208,   201,  -208,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,     0,   212,   213,
     214,  -208,     0,  -208,  -208,  -208,  -208,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,  -209,  -209,
    -209,  -209,  -209,   195,   196,   197,   198,   199,     0,  -209,
     201,  -209,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,     0,   212,   213,   214,  -209,     0,  -209,  -209,
    -209,  -209,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,     0,   200,   201,  -199,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,     0,   212,   213,
     214,  -199,     0,  -199,  -199,  -199,  -199,   179,   180,   181,
     182,   183,   184,   185,   186,   187,  -195,  -195,  -195,  -195,
    -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,     0,  -195,
    -195,  -195,  -195,   203,   204,   205,   206,   207,   208,   209,
     210,   211,     0,   212,   213,   214,  -195,     0,  -195,  -195,
    -195,  -195,   179,   180,   181,   182,   183,   184,   185,   186,
     187,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,     0,  -194,  -194,  -194,  -194,  -194,   204,
     205,   206,   207,   208,   209,   210,   211,     0,   212,   213,
     214,  -194,     0,  -194,  -194,  -194,  -194,   179,   180,   181,
     182,   183,   184,   185,   186,   187,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,     0,  -193,
    -193,  -193,  -193,  -193,  -193,   205,   206,   207,   208,   209,
     210,   211,     0,   212,   213,   214,  -193,     0,  -193,  -193,
    -193,  -193,   179,   180,   181,   182,   183,  -187,  -187,  -187,
    -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,     0,  -187,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,   207,   208,   209,   210,   211,     0,   212,   213,
     214,  -187,     0,  -187,  -187,  -187,  -187,   179,   180,   181,
     182,   183,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,     0,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,   207,   208,   209,
     210,   211,     0,   212,   213,   214,  -188,     0,  -188,  -188,
    -188,  -188,   179,   180,   181,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,     0,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,   209,   210,   211,     0,   212,   213,
     214,  -183,     0,  -183,  -183,  -183,  -183,   179,   180,   181,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,     0,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,   209,
     210,   211,     0,   212,   213,   214,  -184,     0,  -184,  -184,
    -184,  -184,   179,   180,   181,  -180,  -180,  -180,  -180,  -180,
    -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,
    -180,  -180,  -180,     0,  -180,  -180,  -180,  -180,  -180,  -180,
    -180,  -180,  -180,  -180,  -180,  -180,  -180,     0,   212,   213,
     214,  -180,     0,  -180,  -180,  -180,  -180,   179,   180,   181,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,     0,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,     0,   212,   213,   214,  -181,     0,  -181,  -181,
    -181,  -181,   179,   180,   181,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,     0,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,     0,   212,   213,
     214,  -182,     0,  -182,  -182,  -182,  -182,  -163,  -163,  -163,
    -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,
    -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,     0,  -163,
    -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,
    -163,  -163,     0,  -163,  -163,  -163,  -163,     0,  -163,  -163,
    -163,  -163,  -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,
    -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,
    -165,  -165,  -165,     0,  -165,  -165,  -165,  -165,  -165,  -165,
    -165,  -165,  -165,  -165,  -165,  -165,  -165,     0,  -165,  -165,
    -165,  -165,     0,  -165,  -165,  -165,  -165,   179,   180,   181,
    -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,     0,  -179,
    -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,
    -179,  -179,     0,   212,   213,   214,  -179,     0,  -179,  -179,
    -179,  -179,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,     0,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,     0,  -164,  -164,
    -164,  -164,     0,  -164,  -164,  -164,  -164,  -162,  -162,  -162,
    -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,
    -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,     0,  -162,
    -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,
    -162,  -162,     0,  -162,  -162,  -162,  -162,     0,  -162,  -162,
    -162,  -162,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,  -198,     0,  -198,   201,  -198,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,     0,   212,   213,
     214,  -198,     0,  -198,  -198,  -198,  -198,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,     0,   200,
     201,  -150,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,     0,   212,   213,   214,  -150,     0,     0,  -150,
    -150,  -150,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,     0,   200,   201,  -151,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,     0,   212,   213,
     214,  -151,     0,     0,  -151,  -151,  -151,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,     0,   200,
     201,     0,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,     0,   212,   213,   214,     0,     0,     0,     0,
       0,   240,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,     0,   200,   201,     0,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,     0,   212,   213,
     214,     0,     0,     0,     0,     0,   332,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,     0,   200,
     201,     0,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,     0,   212,   213,   214,     0,     0,     0,     0,
       0,   348,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,     0,   200,   201,     0,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,     0,   212,   213,
     214,     0,     0,     0,  -152,  -152,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,     0,   200,   201,
       0,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,     0,   212,   213,   214,     0,     0,     0,  -153,  -153,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,     0,   200,   201,     0,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,     0,   212,   213,   214,   -79,
       0,   -79,   -79,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,     0,  -156,  -156,   215,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,     0,  -156,
    -156,  -156,  -156,     0,     0,  -156,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,     0,   200,   201,
       0,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,     0,   212,   213,   214,     0,     0,   -74,   -74,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
       0,   200,   201,     0,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,     0,   212,   213,   214,   -64,     0,
       0,   -64,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,     0,   200,   201,     0,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,    -2,   212,   213,
     214,   -65,     0,     0,   -65,     1,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      12,    13,    14,    -3,    15,    16,    17,    18,    19,    20,
       0,     1,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,    12,    13,    14,    -4,
      15,    16,    17,    18,    19,    20,     0,    -4,     0,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    -4,    -4,    -4,    -4,    -6,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -6,     0,     0,    -6,    -6,    -6,    -6,
      -6,    -6,    -6,    -6,    -6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    -6,    -6,    -6,
      -6,    -7,    -6,    -6,    -6,    -6,    -6,    -6,     0,    -7,
       0,     0,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    -7,    -7,    -7,    -7,    -5,    -7,    -7,
      -7,    -7,    -7,    -7,     0,    -5,     0,     0,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    -5,
      -5,    -5,    -5,    -8,    -5,    -5,    -5,    -5,    -5,    -5,
       0,    -8,     0,     0,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    -8,    -8,    -8,    -8,     0,
      -8,    -8,    -8,    -8,    -8,    -8,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     298,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,     0,   212,   213,   214,     1,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,     1,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,    15,    16,    17,    18,    19,    20,
     311,    11,    12,    13,     0,     0,    15,    16
};

static const yytype_int16 yycheck[] =
{
      69,   116,    72,    50,    73,    70,   106,     3,     3,   105,
       3,     4,     5,     6,     7,   140,    85,     3,   218,     0,
       3,    87,    68,     3,    86,    83,    88,     3,    86,    98,
      99,   100,   101,   102,   103,   104,     0,   106,   107,   108,
      86,    22,    66,    36,    26,     3,   171,    87,   105,   118,
      66,    43,    45,    46,    66,    28,    83,    30,   235,    83,
      84,    68,    86,    85,    86,   122,   131,   163,     3,    85,
      86,    83,   249,    65,    86,    80,    83,    80,    71,    86,
     149,    74,    75,    76,    80,    58,    68,    80,     3,    70,
      85,    84,    85,   159,   294,   295,    89,    90,    80,    85,
     215,    84,    75,     3,    84,    78,   163,   222,    84,    82,
      83,    85,    86,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   105,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   201,   127,     3,    28,   140,    84,
     131,    80,     3,   218,   254,    80,   213,    83,   140,   216,
     217,    76,   231,   220,   233,    80,    81,    78,    80,    81,
       3,    86,    87,   146,    86,    87,   245,    58,    68,   171,
      80,    81,   251,   298,     3,   254,    86,    87,   235,     3,
     163,    87,    80,    81,    75,     3,    76,    78,    86,    87,
      80,    81,    83,    87,    37,    38,     3,    87,   323,   324,
       3,    68,    22,   328,    80,    81,    28,    29,    30,    76,
      86,    87,     3,    80,   105,    76,   341,    83,   343,    80,
      86,    83,    83,    87,   349,   146,   351,   218,   353,   309,
     232,   310,    87,    76,    80,    43,   315,    80,    81,    83,
     319,   320,    86,    86,    87,    83,   248,    76,    86,    83,
      58,    80,   244,    83,    87,   146,    86,    65,   325,   326,
     327,    87,    80,    81,    80,    81,    87,    75,    86,    87,
      78,    87,   163,    81,    82,    83,    87,    80,    81,    80,
      81,    85,    86,    86,    87,    86,    87,     0,    86,    87,
       3,     4,     5,     6,     7,     8,    22,   105,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      80,    81,    45,    46,    86,    87,    86,    87,   146,    66,
     244,    68,    80,    81,    83,    80,    81,    86,    86,    87,
       3,    86,    87,    80,    81,   163,    83,    84,    71,    86,
      87,    74,    75,    76,    85,    86,    83,    80,    85,    86,
      83,    84,    85,    85,    86,     0,    89,    90,     3,     4,
       5,     6,     7,     8,    37,    38,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    86,    87,
      45,    46,    66,    76,    68,    80,    81,    80,    81,    85,
      86,    86,    87,    86,    87,    83,    80,    81,    86,    83,
      84,    83,    86,    87,    86,    43,    71,    80,    81,    74,
      75,    76,    75,    86,    87,    80,    86,    87,    83,    84,
      85,    85,    86,     0,    89,    90,     3,     4,     5,     6,
       7,     8,    86,    87,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    59,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    86,    87,    45,    46,
      66,    68,    68,    80,    81,    80,    81,    86,    87,    86,
      87,    86,    87,    83,    80,    81,    86,    83,    84,   239,
      86,    87,   163,    83,    71,    85,    86,    74,    75,    76,
      86,    87,    48,    80,    86,    87,    83,    84,    85,   131,
      -1,     0,    89,    90,     3,     4,     5,     6,     7,     8,
      86,    87,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    86,    87,    45,    46,    66,    -1,
      68,    86,    87,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    81,    -1,    83,    84,    -1,    86,    87,
      -1,    -1,    71,    -1,    -1,    74,    75,    76,    -1,    -1,
      -1,    80,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,
      89,    90,     3,     4,     5,     6,     7,     8,    -1,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    45,    46,    66,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    81,    -1,    83,    84,    -1,    86,    87,    -1,    -1,
      71,    -1,    -1,    74,    75,    76,    -1,    -1,    -1,    80,
      -1,    -1,    83,    84,    85,    -1,    87,    -1,    89,    90,
       3,     4,     5,     6,     7,     8,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    45,    46,    66,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,
      -1,    83,    84,    -1,    86,    87,    -1,    -1,    71,    -1,
      -1,    74,    75,    76,    -1,    -1,    -1,    80,    -1,    -1,
      83,    84,    85,    -1,    87,    -1,    89,    90,     3,     4,
       5,     6,     7,     8,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      45,    46,    66,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    83,
      84,    -1,    86,    87,    -1,    -1,    71,    -1,    -1,    74,
      75,    76,    -1,    -1,    -1,    80,    -1,    -1,    83,    84,
      85,    -1,    -1,    -1,    89,    90,     3,     4,     5,     6,
       7,     8,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    45,    46,
      66,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    81,    -1,    83,    84,    -1,
      86,    87,    -1,    -1,    71,    -1,    -1,    74,    75,    76,
      -1,    -1,    -1,    80,    -1,    -1,    83,    84,    85,    -1,
      -1,    -1,    89,    90,     3,     4,     5,     6,     7,     8,
      -1,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    74,    75,    76,    -1,    -1,
      -1,    80,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,
      89,    90,     3,     4,     5,     6,     7,     8,    -1,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    74,    75,    76,    -1,    -1,    -1,    80,
      -1,    -1,    83,    84,    85,    -1,    -1,    -1,    89,    90,
       3,     4,     5,     6,     7,     8,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    74,    75,    76,    -1,    -1,    -1,    80,    -1,    -1,
      83,    84,    85,    -1,    -1,    -1,    89,    90,     3,     4,
       5,     6,     7,     8,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,
      75,    76,    -1,    -1,    -1,    80,    -1,    -1,    83,    84,
      85,    -1,    -1,    -1,    89,    90,     3,     4,     5,     6,
       7,     8,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    75,    76,
      -1,    -1,    -1,    80,    -1,    -1,    83,    84,    85,    -1,
      -1,    -1,    89,    90,     3,     4,     5,     6,     7,     8,
      -1,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    74,    75,    76,    -1,    -1,
      -1,    80,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,
      89,    90,     3,     4,     5,     6,     7,     8,    -1,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    74,    75,    76,    -1,    -1,    -1,    80,
      -1,    -1,    83,    84,    85,    -1,    -1,    -1,    89,    90,
       3,     4,     5,     6,     7,     8,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    74,    75,    76,    -1,    -1,    -1,    80,    -1,    -1,
      83,    84,    85,    -1,    -1,    -1,    89,    90,     3,     4,
       5,     6,     7,     8,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,
      75,    76,    -1,    -1,    -1,    80,    -1,    -1,    83,    84,
      85,    -1,    -1,    -1,    89,    90,     3,     4,     5,     6,
       7,     8,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    75,    76,
      -1,    -1,    -1,    80,    -1,    -1,    83,    84,    85,    -1,
      -1,    -1,    89,    90,     3,     4,     5,     6,     7,     8,
      -1,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    74,    75,    76,    -1,    -1,
      -1,    80,    -1,    -1,    83,    84,    85,    36,    -1,    -1,
      89,    90,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      -1,    80,    81,    82,    83,    -1,    85,    86,    87,    88,
      89,    90,     3,     4,     5,     6,     7,     8,    -1,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    74,    75,    76,    -1,    -1,    -1,    80,
      -1,    -1,    83,    84,    85,    -1,    -1,    -1,    89,    90,
       3,     4,     5,     6,     7,     8,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    74,    75,    76,    -1,    -1,    -1,    80,    -1,    -1,
      83,    84,    85,    -1,    -1,    -1,    89,    90,     3,     4,
       5,     6,     7,     8,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,
      75,    76,    -1,    -1,    -1,    80,    -1,    -1,    83,    84,
      85,    -1,    -1,    -1,    89,    90,     3,     4,     5,     6,
       7,     8,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    75,    76,
      -1,    -1,    -1,    80,    -1,    -1,    83,    84,    85,    -1,
      -1,    -1,    89,    90,     3,     4,     5,     6,     7,     8,
      -1,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    74,    75,    76,    -1,    -1,
      -1,    80,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,
      89,    90,     3,     4,     5,     6,     7,     8,    -1,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    74,    75,    76,    -1,    -1,    -1,    80,
      -1,    -1,    83,    84,    85,    -1,    -1,    -1,    89,    90,
       3,     4,     5,     6,     7,     8,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    74,    75,    76,    -1,    -1,    -1,    80,    -1,    -1,
      83,    84,    85,    -1,    -1,    -1,    89,    90,     3,     4,
       5,     6,     7,     8,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,
      75,    76,    -1,    -1,    -1,    80,    -1,    -1,    83,    84,
      85,    -1,    -1,    -1,    89,    90,     3,     4,     5,     6,
       7,     8,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    75,    76,
      -1,    -1,    -1,    80,    -1,    -1,    83,    84,    85,    -1,
      -1,    -1,    89,    90,     3,     4,     5,     6,     7,     8,
      -1,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    74,    75,    76,    -1,    -1,
      -1,    80,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,
      89,    90,     3,     4,     5,     6,     7,     8,    -1,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    74,    75,    76,    -1,    -1,    -1,    80,
      -1,    -1,    83,    84,    85,    -1,    -1,    -1,    89,    90,
       3,     4,     5,     6,     7,     8,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    74,    75,    76,    -1,    -1,    -1,    80,    -1,    -1,
      83,    84,    85,    -1,    -1,    -1,    89,    90,     3,     4,
       5,     6,     7,     8,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,
      75,    76,    -1,    -1,    -1,    80,    -1,    -1,    83,    84,
      85,    -1,    -1,    -1,    89,    90,     3,     4,     5,     6,
       7,     8,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    75,    76,
      -1,    -1,    -1,    80,    -1,    -1,    83,    84,    85,    -1,
      -1,    -1,    89,    90,     3,     4,     5,     6,     7,     8,
      -1,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    74,    75,    76,    -1,    -1,
      -1,    80,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,
      89,    90,     3,     4,     5,     6,     7,     8,    -1,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    74,    75,    76,     3,    -1,    -1,    80,
      -1,    -1,    83,    84,    85,    -1,    -1,    -1,    89,    90,
       3,     4,     5,     6,     7,     8,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    35,    -1,
      37,    38,    39,    40,    41,    42,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    80,    81,    -1,    83,    84,    71,    86,
      87,    74,    75,    76,    -1,    -1,    -1,    80,    -1,    -1,
      83,    -1,    -1,    -1,    -1,    -1,    89,    90,     3,     4,
       5,     6,     7,     8,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      -1,    36,    37,    38,     3,     4,     5,     6,     7,    -1,
      45,    46,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    20,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    -1,    -1,    71,    36,    -1,    74,
      75,    76,    -1,    -1,    -1,    80,    45,    46,    36,    -1,
      -1,    -1,    -1,    -1,    89,    90,    -1,    45,    46,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    74,    75,    76,    -1,    -1,
      -1,    80,    -1,    71,    83,    84,    74,    75,    76,    -1,
      89,    90,    80,    -1,    36,    -1,    84,    -1,    -1,    -1,
      -1,    89,    90,    45,    46,    -1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    74,    75,    76,    -1,    -1,    -1,    80,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,    45,
      46,    36,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      45,    46,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    75,
      76,    -1,    -1,    -1,    80,    -1,    71,    83,    36,    74,
      75,    76,    -1,    89,    90,    80,    -1,    45,    46,    36,
      -1,    -1,    87,    -1,    89,    90,    -1,    -1,    45,    46,
      -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    74,    75,    76,    -1,
      -1,    -1,    80,    -1,    71,    -1,    -1,    74,    75,    76,
      88,    89,    90,    80,    -1,    36,    83,    -1,    -1,    -1,
      -1,    -1,    89,    90,    45,    46,    -1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      71,    -1,    -1,    74,    75,    76,    -1,    -1,    -1,    80,
      -1,    36,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      45,    46,     3,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,
      -1,     3,     4,     5,     6,     7,    71,    -1,    -1,    74,
      75,    76,    -1,    -1,    35,    80,    37,    38,    39,    40,
      41,    42,    87,    71,    89,    90,    74,    75,    76,    -1,
      -1,    -1,    80,    -1,    36,    -1,    -1,    -1,    -1,    87,
      -1,    89,    90,    45,    46,    -1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    76,    -1,    -1,    -1,    80,
      81,    -1,    83,    -1,    -1,    86,    87,    -1,    -1,    71,
      -1,    -1,    74,    75,    76,    -1,    -1,    -1,    80,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    45,
      46,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,     3,    -1,    71,    -1,    -1,    74,    75,
      76,    -1,    -1,    -1,    80,    -1,    -1,     3,    -1,    37,
      38,    -1,     8,    89,    90,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    35,    -1,    37,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    32,    33,    34,    35,
      68,    37,    38,    39,    40,    41,    42,    -1,    76,    -1,
      -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    68,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      80,    81,    68,    83,    84,    -1,    86,    87,    -1,    -1,
      76,    -1,    -1,    -1,    80,    81,    -1,    83,     3,    -1,
      86,    87,    -1,     8,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    -1,    -1,    32,    33,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,     8,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    35,    -1,    37,    38,    39,
      40,    41,    42,    68,    -1,    -1,    -1,    32,    33,    34,
      -1,    76,    37,    38,    -1,    80,    81,    -1,    83,     3,
      -1,    86,    87,    -1,     8,    -1,    -1,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    76,    -1,    -1,    -1,
      80,    81,    -1,    83,    -1,    -1,    86,    87,    32,    33,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    -1,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,
       8,    -1,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    76,    -1,    -1,    -1,    80,    81,    -1,    83,
      -1,    -1,    86,    87,    32,    33,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    -1,    -1,    -1,     8,    -1,    -1,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    76,    -1,
      -1,    -1,    80,    81,    -1,    83,    -1,    -1,    86,    87,
      32,    33,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    76,    -1,    -1,    -1,    80,    81,
      -1,    83,    -1,    -1,    86,    87,    32,    33,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,     8,    -1,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      76,    -1,    -1,    -1,    80,    81,    -1,    83,    -1,    -1,
      86,    87,    32,    33,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    76,    -1,    -1,    -1,
      80,    81,    -1,    83,    -1,    -1,    86,    87,    32,    33,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,
       8,    -1,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    76,    -1,    -1,    -1,    80,    81,    -1,    83,
      -1,    -1,    86,    87,    32,    33,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    -1,    -1,    -1,     8,    -1,    -1,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    76,    -1,
      -1,    -1,    80,    81,    -1,    83,    -1,    -1,    86,    87,
      32,    33,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    76,    -1,    -1,    -1,    80,    81,
      -1,    83,    -1,    -1,    86,    87,    32,    33,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,     8,    -1,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      76,    -1,    -1,    -1,    80,    81,    -1,    83,    -1,    -1,
      86,    87,    32,    33,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    76,    -1,    -1,    -1,
      80,    81,    -1,    83,    -1,    -1,    86,    87,    32,    33,
      34,    35,     3,    37,    38,    39,    40,    41,    42,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    37,    38,    39,    40,
      41,    42,    76,    -1,    -1,    -1,    80,    81,    -1,     3,
      -1,    -1,    -1,    87,    -1,    -1,    -1,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    68,    -1,    -1,
      -1,    -1,     3,    -1,    -1,    76,    -1,    -1,    -1,    80,
      81,     3,    83,    37,    38,    86,    87,    -1,    -1,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    37,    38,    39,    40,
      41,    42,    -1,    35,    68,    37,    38,    39,    40,    41,
      42,    -1,    76,    -1,    -1,    -1,    80,    81,     3,    -1,
      -1,    -1,    -1,    87,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    76,    68,    -1,    -1,    80,
      81,     3,    83,    -1,    76,    86,    87,    -1,    80,    81,
       3,    83,    37,    38,    86,    87,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    37,    38,    39,    40,    41,
      42,    -1,    35,    68,    37,    38,    39,    40,    41,    42,
      -1,    76,    -1,    -1,    -1,    80,    81,     3,    -1,    -1,
      -1,    -1,    87,    -1,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    76,    68,    -1,    -1,    80,    81,
      -1,    83,    -1,    76,    86,    87,    -1,    80,    81,     3,
      83,    37,    38,    86,    87,    -1,    -1,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    68,    37,    38,    39,    40,    41,    42,    -1,
      76,    -1,    -1,    -1,    80,    81,     3,    -1,    -1,    -1,
      -1,    87,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    68,    -1,    -1,    -1,    -1,     3,
      -1,    -1,    76,    -1,    -1,    -1,    80,    81,     3,    83,
      37,    38,    86,    87,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    37,    38,    39,    40,    41,    42,    -1,
      35,    68,    37,    38,    39,    40,    41,    42,    -1,    76,
      -1,    -1,    -1,    80,    81,     3,    -1,    -1,    -1,    -1,
      87,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    68,    -1,    -1,    80,    81,     3,    83,
      -1,    76,    86,    87,    -1,    80,    81,     3,    83,    37,
      38,    86,    87,    -1,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    37,    38,    39,    40,    41,    42,    -1,    35,
      68,    37,    38,    39,    40,    41,    42,    -1,    76,    -1,
      -1,    -1,    80,    81,     3,    -1,    -1,    -1,    -1,    87,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    68,    -1,    -1,    80,    81,     3,    83,    -1,
      76,    86,    87,    -1,    80,    81,     3,    83,    37,    38,
      86,    87,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    37,    38,    39,    40,    41,    42,    -1,    35,    68,
      37,    38,    39,    40,    41,    42,    -1,    76,    -1,    -1,
      -1,    80,    81,     3,    -1,    -1,    -1,    -1,    87,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    68,    -1,    -1,    80,    81,     3,    83,    -1,    76,
      86,    87,    -1,    80,    81,     3,    83,    37,    38,    86,
      87,    -1,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      37,    38,    39,    40,    41,    42,    -1,    35,    68,    37,
      38,    39,    40,    41,    42,    -1,    76,    -1,    -1,    -1,
      80,    81,     3,    -1,    -1,    -1,    -1,    87,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      68,    -1,    -1,    80,    81,     3,    83,    -1,    76,    86,
      87,    -1,    80,    81,     3,    83,    37,    38,    86,    87,
      -1,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    37,
      38,    39,    40,    41,    42,    -1,    35,    68,    37,    38,
      39,    40,    41,    42,    -1,    76,    -1,    -1,    -1,    80,
      81,    -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    68,
      -1,    -1,    80,    81,    -1,    83,    -1,    76,    86,    87,
      -1,    80,    81,     3,    83,    -1,    -1,    86,    87,    -1,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,     3,    37,    38,    39,
      40,    41,    42,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      37,    38,    39,    40,    41,    42,    76,    -1,    -1,    -1,
      80,    81,    -1,    83,    -1,    -1,    86,    87,    -1,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    80,    81,    -1,    83,    -1,    -1,    86,
      87,    35,     3,    37,    38,    39,    40,    41,    42,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    37,    38,    39,    40,
      41,    42,    76,    -1,    -1,    -1,    80,    81,    -1,    83,
      -1,    -1,    86,    87,    -1,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,    -1,    76,    -1,    -1,    -1,    80,
      81,    -1,    83,    -1,    -1,    86,    87,    35,    -1,    37,
      38,    39,    40,    41,    42,     3,    -1,    -1,    -1,    -1,
       8,    -1,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    -1,    32,    33,    34,    -1,    76,    37,
      38,    -1,    80,    81,    -1,    83,     3,    -1,    86,    87,
      -1,     8,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    35,    -1,    37,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    32,    33,    34,    76,    -1,
      37,    38,    80,    81,    -1,    -1,    -1,    -1,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,     3,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    80,    81,
      -1,    83,    -1,     3,    86,    87,    -1,    -1,    -1,    76,
      -1,    -1,     3,    80,    81,    -1,    -1,    -1,    -1,    86,
      87,    35,    -1,    37,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    37,    38,    39,
      40,    41,    42,    -1,    35,    -1,    37,    38,    39,    40,
      41,    42,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
       7,    -1,    76,    -1,    -1,    -1,    80,    81,    68,    83,
      -1,    -1,    86,    87,    -1,    -1,    76,    68,    -1,    -1,
      80,    81,    -1,    83,    -1,    76,    86,    87,    -1,    80,
      81,    -1,    83,    -1,    -1,    86,    87,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     7,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     7,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      -1,    80,    81,    82,    83,    -1,    85,    86,    87,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    -1,    80,
      81,    82,    83,    -1,    85,    86,    87,    88,     8,    -1,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       8,    -1,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    32,    33,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    -1,    32,    33,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,     8,
      -1,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      80,    81,    -1,    32,    33,    34,    35,    87,    37,    38,
      39,    40,    41,    42,    -1,    -1,    -1,     8,    -1,    87,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    -1,     8,    37,    38,    11,    12,
      13,    14,    15,    16,    17,    18,    19,     8,    87,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    32,
      33,    34,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    85,     8,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    85,    -1,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    85,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    -1,    86,
      87,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    -1,    86,    87,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    -1,    -1,    -1,    -1,
      -1,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    -1,    -1,    -1,    -1,    -1,    88,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    -1,    -1,    -1,    -1,
      -1,    88,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    -1,    -1,    -1,    86,    87,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    -1,    80,    81,    82,    -1,    -1,    -1,    86,    87,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    -1,    80,    81,    82,    83,
      -1,    85,    86,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    -1,    80,
      81,    82,    83,    -1,    -1,    86,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    -1,    80,    81,    82,    -1,    -1,    85,    86,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      -1,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    -1,    80,    81,    82,    83,    -1,
      -1,    86,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,     0,    80,    81,
      82,    83,    -1,    -1,    86,     8,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,     0,    37,    38,    39,    40,    41,    42,
      -1,     8,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,     0,
      37,    38,    39,    40,    41,    42,    -1,     8,    -1,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,     0,    37,    38,    39,    40,
      41,    42,    -1,     8,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,     0,    37,    38,    39,    40,    41,    42,    -1,     8,
      -1,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,     0,    37,    38,
      39,    40,    41,    42,    -1,     8,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,     0,    37,    38,    39,    40,    41,    42,
      -1,     8,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    -1,    80,    81,    82,     8,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,     8,    -1,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    32,
      33,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    32,    33,    34,    -1,    -1,    37,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    32,    33,    34,    35,    37,    38,    39,    40,    41,
      42,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   115,     3,    84,
       0,    94,     3,    76,    80,    83,   118,   119,   122,   123,
     124,    98,   103,   104,    98,    98,   103,     3,    84,    84,
       3,   116,   117,   105,   124,   125,   122,    83,    86,    66,
      84,   134,    80,    81,   123,    84,   103,   104,   108,   109,
     110,   111,   112,   125,   116,    66,    85,    86,   105,   124,
      87,   119,   122,     3,     4,     5,     6,     7,    36,    45,
      46,    71,    74,    75,    76,    80,    84,    89,    90,   120,
     143,   144,     3,    20,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    83,    85,    96,    97,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   144,    87,
      97,   126,   127,   128,    88,   144,   108,    85,   109,    68,
     113,   114,   122,   105,   103,   105,   103,   104,    85,    86,
     144,    85,   117,    80,   144,   144,   144,   144,   144,   144,
     144,   110,   129,   141,   120,   121,   144,   144,     7,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      66,    67,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    80,    81,    82,    68,    80,    80,    80,   132,
      80,   144,    68,    83,    83,    83,   141,     3,    85,   136,
      83,    86,    80,    81,   122,   124,   130,   131,    87,    86,
      88,    85,   144,    83,    86,    68,    85,   129,    80,   124,
     130,    87,    87,    85,    86,     3,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   141,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,    87,   142,   144,   141,
       3,   132,   141,   141,    96,   137,    22,   141,    68,   132,
      83,    83,   144,    87,   126,   130,    88,   144,   131,    80,
      81,    43,   128,   114,   144,    87,   144,    85,   120,    68,
      86,    87,    88,    87,    87,   137,   137,    80,    87,   132,
      87,    87,    88,    87,   126,    88,   144,   144,   144,   132,
     132,    87,   141,    87,   141,   141,   132,    87,    88,    21,
     132,    87,   132,    87,    87,   132,   132,   132,    83
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    91,    92,    92,    93,    93,    94,    94,    95,    96,
      96,    97,    97,    97,    98,    98,    99,    99,   100,   100,
     100,   101,   101,   101,   101,   102,   102,   102,   102,   102,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   104,
     104,   104,   105,   105,   106,   106,   106,   107,   107,   108,
     108,   109,   110,   110,   111,   111,   111,   112,   112,   112,
     112,   113,   113,   114,   114,   114,   115,   115,   115,   115,
     115,   116,   116,   117,   117,   118,   118,   119,   119,   120,
     120,   120,   121,   121,   122,   122,   123,   123,   123,   123,
     123,   123,   124,   124,   124,   124,   125,   125,   126,   126,
     127,   127,   128,   128,   128,   129,   129,   130,   130,   130,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   132,
     132,   132,   132,   132,   132,   133,   133,   133,   134,   134,
     135,   135,   136,   136,   137,   137,   138,   138,   138,   139,
     139,   139,   139,   139,   139,   140,   140,   140,   140,   140,
     141,   141,   142,   142,   143,   143,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     1,     3,     2,
       3,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       2,     1,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     4,     2,     1,     1,     1,
       2,     3,     1,     1,     1,     2,     2,     1,     2,     2,
       2,     1,     3,     1,     2,     3,     5,     6,     4,     5,
       2,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     4,     1,     3,     2,     1,     1,     3,     4,     3,
       4,     3,     1,     2,     2,     3,     1,     2,     1,     3,
       1,     3,     2,     2,     1,     1,     2,     1,     1,     2,
       3,     2,     3,     3,     4,     2,     3,     3,     4,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     2,     3,
       1,     2,     1,     1,     1,     2,     5,     7,     5,     5,
       7,     6,     7,     6,     7,     3,     2,     2,     2,     3,
       1,     3,     1,     3,     1,     2,     1,     1,     1,     1,
       1,     3,     4,     3,     4,     3,     3,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     4,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
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




/* The kind of the lookahead of this context.  */
static yysymbol_kind_t
yypcontext_token (const yypcontext_t *yyctx) YY_ATTRIBUTE_UNUSED;

static yysymbol_kind_t
yypcontext_token (const yypcontext_t *yyctx)
{
  return yyctx->yytoken;
}



/* User defined function to report a syntax error.  */
static int
yyreport_syntax_error (const yypcontext_t *yyctx);

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

#line 3357 "build/parser.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        if (yyreport_syntax_error (&yyctx) == 2)
          YYNOMEM;
      }
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

#line 443 "src/parser.y"


/* ======================= C code that connects the parser to our token array ======================= */

static const TokenStream *g_ts;    /* the tokens being parsed                        */
static size_t             g_pos;   /* index of the next token to hand to the parser  */
static size_t             g_last;  /* index of the token most recently handed over   */
static ParseResult       *g_res;   /* where to store error details                   */
static int               *g_eff;   /* token type the parser sees, per token (typedef names resolved) */

/* Bison calls this to get the next token. Returns 0 at end of input. */
int yylex(void)
{
    while (g_pos < g_ts->count) {
        int type = g_eff[g_pos];
        g_last = g_pos;
        g_pos++;
        if (type == T_PREPROC || type == T_LEXERR) {
            continue;                       /* not part of the grammar */
        }
        return type;                        /* EOF has type 0 */
    }
    return 0;
}

/* Only used for fatal problems such as "memory exhausted". */
void yyerror(const char *msg)
{
    fprintf(stderr, "parser error: %s\n", msg);
}

/* Called by Bison when it finds a syntax error. We store the details
 * (bad token + list of tokens that would have been valid) instead of printing. */
int yyreport_syntax_error(const yypcontext_t *ctx)
{
    yysymbol_kind_t expected[YYNTOKENS];
    int n = yypcontext_expected_tokens(ctx, expected, YYNTOKENS);
    int i;

    if (n < 0) {
        return n;                           /* out of memory: let yyparse report it */
    }
    g_res->found = 1;
    g_res->token_index = g_last;
    g_res->expected_count = 0;
    for (i = 0; i < n && g_res->expected_count < PARSE_MAX_EXPECTED; i++) {
        g_res->expected[g_res->expected_count++] = yysymbol_name(expected[i]);
    }
    return 0;
}

int parse_tokens(const TokenStream *ts, ParseResult *res)
{
    int rc;

    g_ts = ts;
    g_pos = 0;
    g_last = 0;
    g_res = res;
    res->found = 0;
    res->token_index = 0;
    res->expected_count = 0;

    g_eff = malloc((ts->count ? ts->count : 1) * sizeof *g_eff);
    if (g_eff == NULL) {
        return 2;
    }
    if (classify_typedef_names(ts, g_eff) != 0) {
        free(g_eff);
        g_eff = NULL;
        return 2;
    }
    rc = yyparse();
    free(g_eff);
    g_eff = NULL;
    return rc;
}

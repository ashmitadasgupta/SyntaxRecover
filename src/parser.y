%require "3.6"
%define parse.error custom
%define lr.type ielr
%define lr.default-reduction accepting

%{
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "common.h"
#include "token_stream.h"
#include "parse.h"
#include "typedefs.h"

int  yylex(void);
void yyerror(const char *msg);
%}

/* ---- literals and names ---- */
%token T_IDENTIFIER T_INT_LIT T_FLOAT_LIT T_CHAR_LIT T_STRING_LIT

/* ---- an identifier that names a typedef (created by typedefs.c, not by the lexer) ---- */
%token T_TYPEDEF_NAME

/* ---- special tokens (never reach the grammar: yylex skips them) ---- */
%token T_PREPROC T_LEXERR

/* ---- keywords ---- */
%token T_INT T_CHAR T_SHORT T_LONG T_FLOAT T_DOUBLE T_VOID T_SIGNED T_UNSIGNED
%token T_IF T_ELSE T_WHILE T_FOR T_DO T_SWITCH T_CASE T_DEFAULT
%token T_BREAK T_CONTINUE T_RETURN T_GOTO
%token T_STRUCT T_UNION T_ENUM T_TYPEDEF T_SIZEOF
%token T_CONST T_VOLATILE T_STATIC T_EXTERN T_REGISTER T_AUTO

/* ---- multi-character operators ---- */
%token T_ELLIPSIS T_ARROW T_INC T_DEC T_SHL T_SHR
%token T_LE T_GE T_EQ T_NE T_ANDAND T_OROR
%token T_MUL_ASSIGN T_DIV_ASSIGN T_MOD_ASSIGN T_ADD_ASSIGN T_SUB_ASSIGN
%token T_SHL_ASSIGN T_SHR_ASSIGN T_AND_ASSIGN T_XOR_ASSIGN T_OR_ASSIGN

/* ---- precedence: lowest first, highest last ---- */
%nonassoc LOWER_THAN_ELSE
%nonassoc T_ELSE
%right '=' T_ADD_ASSIGN T_SUB_ASSIGN T_MUL_ASSIGN T_DIV_ASSIGN T_MOD_ASSIGN
%right T_SHL_ASSIGN T_SHR_ASSIGN T_AND_ASSIGN T_XOR_ASSIGN T_OR_ASSIGN
%right '?' ':'
%left  T_OROR
%left  T_ANDAND
%left  '|'
%left  '^'
%left  '&'
%left  T_EQ T_NE
%left  '<' '>' T_LE T_GE
%left  T_SHL T_SHR
%left  '+' '-'
%left  '*' '/' '%'
%right UNARY
%left  T_INC T_DEC '(' '[' '.' T_ARROW

%start program

%%

program
    : %empty
    | translation_unit
    ;

translation_unit
    : external_declaration
    | translation_unit external_declaration
    ;

external_declaration
    : function_definition
    | declaration
    ;

function_definition
    : declaration_specifiers declarator compound_statement
    ;

/* ------------------------------------------------------------ declarations */

declaration
    : declaration_specifiers ';'
    | declaration_specifiers init_declarator_list ';'
    ;

declaration_specifiers
    : sq_list
    | tag_specifiers
    | basic_specifiers
    ;

/* a storage class (static, extern, ...) or a qualifier (const, volatile) */
sq
    : storage_class_specifier
    | type_qualifier
    ;

sq_list
    : sq
    | sq_list sq
    ;

/* exactly ONE struct/union/enum/typedef-name, plus storage classes and qualifiers */
tag_specifiers
    : tag_type
    | sq_list tag_type
    | tag_specifiers sq
    ;

/* one or more basic types (unsigned long int ...), plus storage classes and qualifiers */
basic_specifiers
    : basic_type
    | sq_list basic_type
    | basic_specifiers basic_type
    | basic_specifiers sq
    ;

storage_class_specifier
    : T_TYPEDEF
    | T_STATIC
    | T_EXTERN
    | T_REGISTER
    | T_AUTO
    ;

basic_type
    : T_VOID
    | T_CHAR
    | T_SHORT
    | T_INT
    | T_LONG
    | T_FLOAT
    | T_DOUBLE
    | T_SIGNED
    | T_UNSIGNED
    ;

tag_type
    : struct_or_union_specifier
    | enum_specifier
    | T_TYPEDEF_NAME
    ;

type_qualifier
    : T_CONST
    | T_VOLATILE
    ;

struct_or_union_specifier
    : struct_or_union T_IDENTIFIER '{' struct_declaration_list '}'
    | struct_or_union '{' struct_declaration_list '}'
    | struct_or_union T_IDENTIFIER
    ;

struct_or_union
    : T_STRUCT
    | T_UNION
    ;

struct_declaration_list
    : struct_declaration
    | struct_declaration_list struct_declaration
    ;

struct_declaration
    : specifier_qualifier_list struct_declarator_list ';'
    ;

specifier_qualifier_list
    : tag_sq
    | basic_sq
    ;

tag_sq
    : tag_type
    | type_qualifier_list tag_type
    | tag_sq type_qualifier
    ;

basic_sq
    : basic_type
    | type_qualifier_list basic_type
    | basic_sq basic_type
    | basic_sq type_qualifier
    ;

struct_declarator_list
    : struct_declarator
    | struct_declarator_list ',' struct_declarator
    ;

/* a member, possibly a bit-field:  int x;   unsigned flag : 1;   unsigned : 3; */
struct_declarator
    : declarator
    | ':' expr
    | declarator ':' expr
    ;

enum_specifier
    : T_ENUM T_IDENTIFIER '{' enumerator_list '}'
    | T_ENUM T_IDENTIFIER '{' enumerator_list ',' '}'
    | T_ENUM '{' enumerator_list '}'
    | T_ENUM '{' enumerator_list ',' '}'
    | T_ENUM T_IDENTIFIER
    ;

enumerator_list
    : enumerator
    | enumerator_list ',' enumerator
    ;

enumerator
    : T_IDENTIFIER
    | T_IDENTIFIER '=' expr
    ;

init_declarator_list
    : init_declarator
    | init_declarator_list ',' init_declarator
    ;

init_declarator
    : declarator
    | declarator '=' initializer
    ;

initializer
    : expr
    | '{' initializer_list '}'
    | '{' initializer_list ',' '}'
    ;

initializer_list
    : initializer
    | initializer_list ',' initializer
    ;

/* ------------------------------------------------------------- declarators */

declarator
    : pointer direct_declarator
    | direct_declarator
    ;

direct_declarator
    : T_IDENTIFIER
    | '(' declarator ')'
    | direct_declarator '[' expr ']'
    | direct_declarator '[' ']'
    | direct_declarator '(' parameter_type_list ')'
    | direct_declarator '(' ')'
    ;

pointer
    : '*'
    | '*' type_qualifier_list
    | '*' pointer
    | '*' type_qualifier_list pointer
    ;

type_qualifier_list
    : type_qualifier
    | type_qualifier_list type_qualifier
    ;

parameter_type_list
    : parameter_list
    | parameter_list ',' T_ELLIPSIS
    ;

parameter_list
    : parameter_declaration
    | parameter_list ',' parameter_declaration
    ;

parameter_declaration
    : declaration_specifiers declarator
    | declaration_specifiers abstract_declarator
    | declaration_specifiers
    ;

type_name
    : specifier_qualifier_list
    | specifier_qualifier_list abstract_declarator
    ;

abstract_declarator
    : pointer
    | direct_abstract_declarator
    | pointer direct_abstract_declarator
    ;

direct_abstract_declarator
    : '(' abstract_declarator ')'
    | '[' ']'
    | '[' expr ']'
    | direct_abstract_declarator '[' ']'
    | direct_abstract_declarator '[' expr ']'
    | '(' ')'
    | '(' parameter_type_list ')'
    | direct_abstract_declarator '(' ')'
    | direct_abstract_declarator '(' parameter_type_list ')'
    ;

/* -------------------------------------------------------------- statements */

statement
    : labeled_statement
    | compound_statement
    | expression_statement
    | selection_statement
    | iteration_statement
    | jump_statement
    ;

labeled_statement
    : T_IDENTIFIER ':' statement
    | T_CASE expr ':' statement
    | T_DEFAULT ':' statement
    ;

compound_statement
    : '{' '}'
    | '{' block_item_list '}'
    ;

block_item_list
    : block_item
    | block_item_list block_item
    ;

block_item
    : declaration
    | statement
    ;

expression_statement
    : ';'
    | expression ';'
    ;

selection_statement
    : T_IF '(' expression ')' statement %prec LOWER_THAN_ELSE
    | T_IF '(' expression ')' statement T_ELSE statement
    | T_SWITCH '(' expression ')' statement
    ;

iteration_statement
    : T_WHILE '(' expression ')' statement
    | T_DO statement T_WHILE '(' expression ')' ';'
    | T_FOR '(' expression_statement expression_statement ')' statement
    | T_FOR '(' expression_statement expression_statement expression ')' statement
    | T_FOR '(' declaration expression_statement ')' statement
    | T_FOR '(' declaration expression_statement expression ')' statement
    ;

jump_statement
    : T_GOTO T_IDENTIFIER ';'
    | T_CONTINUE ';'
    | T_BREAK ';'
    | T_RETURN ';'
    | T_RETURN expression ';'
    ;

/* ------------------------------------------------------------- expressions */

expression
    : expr
    | expression ',' expr
    ;

argument_list
    : expr
    | argument_list ',' expr
    ;

string_list
    : T_STRING_LIT
    | string_list T_STRING_LIT
    ;

expr
    : T_IDENTIFIER
    | T_INT_LIT
    | T_FLOAT_LIT
    | T_CHAR_LIT
    | string_list
    | '(' expression ')'
    | expr '[' expression ']'
    | expr '(' ')'
    | expr '(' argument_list ')'
    | expr '.' T_IDENTIFIER
    | expr T_ARROW T_IDENTIFIER
    | expr T_INC
    | expr T_DEC
    | T_INC expr %prec UNARY
    | T_DEC expr %prec UNARY
    | '&' expr %prec UNARY
    | '*' expr %prec UNARY
    | '+' expr %prec UNARY
    | '-' expr %prec UNARY
    | '~' expr %prec UNARY
    | '!' expr %prec UNARY
    | T_SIZEOF expr %prec UNARY
    | T_SIZEOF '(' type_name ')' %prec UNARY
    | '(' type_name ')' expr %prec UNARY
    | expr '*' expr
    | expr '/' expr
    | expr '%' expr
    | expr '+' expr
    | expr '-' expr
    | expr T_SHL expr
    | expr T_SHR expr
    | expr '<' expr
    | expr '>' expr
    | expr T_LE expr
    | expr T_GE expr
    | expr T_EQ expr
    | expr T_NE expr
    | expr '&' expr
    | expr '^' expr
    | expr '|' expr
    | expr T_ANDAND expr
    | expr T_OROR expr
    | expr '?' expression ':' expr
    | expr '=' expr
    | expr T_MUL_ASSIGN expr
    | expr T_DIV_ASSIGN expr
    | expr T_MOD_ASSIGN expr
    | expr T_ADD_ASSIGN expr
    | expr T_SUB_ASSIGN expr
    | expr T_SHL_ASSIGN expr
    | expr T_SHR_ASSIGN expr
    | expr T_AND_ASSIGN expr
    | expr T_XOR_ASSIGN expr
    | expr T_OR_ASSIGN expr
    ;

%%

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
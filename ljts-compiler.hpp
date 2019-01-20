#ifndef LTJS_COMPILER_HPP
#define LTJS_COMPILER_HPP

#include <iostream>

/* YYSTYPE defintion */
#include <string>
#include <variant>

typedef std::variant<int, std::string> YYSTYPE;

#define YYSTYPE YYSTYPE

/* Extern declarations. */
extern "C" int yylex();
extern "C" YYSTYPE yylval;

extern int yylineno;
extern char* yytext;

void yyerror (char const *s);

/* Token type. */
#ifndef YYTOKENTYPE
#define YYTOKENTYPE
enum yytokentype {
    ASSIGNMENT = 258,
    CLASS = 259,
    DEF = 260,
    ELSE = 261,
    EXTENDS = 262,
    IDENTIFIER = 263,
    IF = 264,
    INTEGER = 265,
    IS = 266,
    NEW = 267,
    OBJECT = 268,
    OVERRIDE = 269,
    RELATIONAL_OPERATOR = 270,
    RETURN = 271,
    STRING = 272,
    THEN = 273,
    TYPENAME = 274,
    VAR = 275,
    unary = 276
};
#endif

/**
 * Enumération des différentes opérations.
 */
enum Operation : int {
	/* MISCELLANEOUS */
	ternary_conditional,
	/* ARITHMETIC */
	unary_plus, unary_substract,
	multiplication, division,
	addition, substraction,
	/* RELATIONAL_OPERATOR */
	less_strict, less_equal, greater_strict, greater_equal,
	equal, not_equal
};

#endif
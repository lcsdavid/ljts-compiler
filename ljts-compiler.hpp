#ifndef LTJS_COMPILER_HPP
#define LTJS_COMPILER_HPP

#include <iostream>
#include <string>
#include <variant>

#include "utils/Structures.hpp"

/* YYSTYPE defintion */
typedef std::variant<bool, int, std::string> YYSTYPE;

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
enum operation : int {
	/* DECLS */
	class_decl, object_decl,
	/* CLASSES & OBJECTS */
	instanciation, cast, member_access, object_member_access, method_call, object_method_call,
	/* ASSIGNMENT */
	assignment,
	/* ARITHMETIC */
	unary_plus, unary_substract,
	multiplication, division,
	addition, substraction,
	/* RELATIONAL_OPERATOR */
	less_strict, inf_equal, greater_strict, sup_equal,
	equalite, not_equal,
	/* MISCELLANEOUS */
	if_then_else, return_call, inst_block,
	/* CONSTS & IDENTIFIER */
	integer, string, identifier, typename_identifier
};

#endif
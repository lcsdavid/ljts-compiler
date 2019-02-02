#ifndef LTJS_COMPILER_HPP
#define LTJS_COMPILER_HPP

#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include "utils/Structures.hpp"

typedef union {
	bool Boolean;			/* Valeur booléenne. */
	char Char;			/* Caractère isolé. */
	char *String;		/* Chaîne de caractère. */
	int Integer;	/* Valeur entière. */
	
	std::vector<Variable> *VarList;
	Variable *PVar;
	
	std::vector<Type*> *PTypeList;
	Type *PType;
	Class *PClass;
	Object *PObject;
	
	std::vector<Method> *MethodList;
	Method *PMethod;
	
	std::vector<Tree*> *PTreeList;
	Tree *PTree;
	Block *PBlock;
} YYSTYPE;

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
	THIS = 274,
	TYPENAME = 275,
	VAR = 276,
	unary = 277
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
	less_strict, less_equal, greater_strict, greater_equal,
	equal, not_equal,
	/* MISCELLANEOUS */
	if_then_else, return_call, inst_block,
	/* CONSTS & IDENTIFIER */
	integer, string, identifier, typename_identifier
};

using namespace std::string_literals;

#endif
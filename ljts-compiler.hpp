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

#include "yytokentype.hpp"

#include "optype.hpp"

#endif
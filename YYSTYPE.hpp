#ifndef YYSTYPE_HPP
#define YYSTYPE_HPP

#include "utils/Structures.hpp"

typedef union {
	bool Boolean;			/* Valeur booléenne. */
	char Char;				/* Caractère isolé. */
	int Integer;			/* Valeur entière. */
	std::string *String;	/* Chaîne de caractère. */
	
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

#endif
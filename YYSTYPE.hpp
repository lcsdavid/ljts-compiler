#ifndef YYSTYPE_HPP
#define YYSTYPE_HPP

#include "utils/Structures.hpp"

typedef union {
	bool Boolean;			/* Valeur bool�enne. */
	char Char;				/* Caract�re isol�. */
	int Integer;			/* Valeur enti�re. */
	std::string *String;	/* Cha�ne de caract�re. */
	
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
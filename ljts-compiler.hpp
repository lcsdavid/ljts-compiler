#ifndef LTJS_COMPILER_HPP
#define LTJS_COMPILER_HPP

enum class token : int {
	END_OF_FILE,
	ASSIGNMENT, CLASS, DEF, ELSE, EXTENDS,
	IDENTIFIER, IF, INTEGER, IS, MINUS,
	OBJECT, OVERRIDE, PLUS, POINT, RELATIONAL_OPERATOR,
	RETURN, SLASH, STAR, THEN, VAR
};

enum keywords {
	TERNARY_CONDITIONAL
};

enum arithmetic {
	UNARY_PLUS, UNARY_SUBSTRACT,
	MULTIPLICATION, DIVISION,
	ADDITION, SUBSTRACTION
};

enum relational {
	LESS_STRICT, LESS_EQUAL, GREATER_STRICT, GREATER_EQUAL,
	EQUAL, NOT_EQUAL
};



/* AST definition */
//#include "utils/abstract_syntax_tree.hpp"

/* YYSTYPE defintion */
#include <string>
#include <variant>

typedef std::variant<int, std::string> YYSTYPE;

#define YYSTYPE YYSTYPE

/* la structure d'un arbre (noeud ou feuille) */
  typedef struct _Tree {
  short op;         /* etiquette de l'operateur courant */
  short nbChildren; /* nombre de sous-arbres */
  union {
    char *str;      /* valeur de la feuille si op = ID */
    int val;        /* valeur de la feuille si op = CST */
    struct _Tree **children; /* tableau des sous-arbres d'un noeud interne */
  } u;
} Tree, *TreeP;

/* la structure ci-dessous permet de cosntruire des listes de paires
 * (variable, valeur entiere).
 * On va construire des listes de la forme { (x 5), (y, 27) } au fur
 * et a mesure qu'on interprete les declarations dans un programme source.
 */
typedef struct _Decl
{ char *name;
  int val;
  struct _Decl *next;
} VarDecl, *VarDeclP;

#endif
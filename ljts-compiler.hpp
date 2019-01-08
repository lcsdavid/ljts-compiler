#ifndef LTJS_COMPILER_HPP
#define LTJS_COMPILER_HPP

enum token : int {
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
#include <variant>

typedef std::variant<int, std::string> YYSTYPE;

#define YYSTYPE YYSTYPE

#endif
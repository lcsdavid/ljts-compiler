#include "ljts-compiler.hpp"

void yyerror (char const *s) {
	std::cerr << "Error: " << s << " at line " << yylineno << std::endl;
	exit(1);
}
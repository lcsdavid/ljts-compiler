#include "ljts-compiler.hpp"

#include <cstdlib>
#include <ctime>

void yyerror (char const *s) {
	std::cerr << "Error: " << s << " at line " << yylineno << std::endl;
	exit(1);
}

int main() {
	std::srand(std::time(nullptr));
	
}
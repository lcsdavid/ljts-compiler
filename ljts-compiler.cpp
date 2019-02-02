#include "ljts-compiler.hpp"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <cstdlib>
#include <ctime>

extern int yyparse();

void yyerror (char const *s) {
	std::cout << "\033[91merror:\033[0m " << s << " at line " << yylineno << std::endl << yytext << std::endl;
	exit(1);
}

int main(int argc, char **argv) {
	std::srand(std::time(nullptr));
	int fi;
	if ((fi = open(argv[1], O_RDONLY)) == -1) {
		std::cerr << "Erreur: fichier inaccessible " << argv[1] << std::endl;
		exit(1);
	}
	std::cout << "Fichier " << argv[1] << " chargé correctement." << std::endl;
	close(0); dup(fi); close(fi);
	if (yyparse() == 0) {
		std::cout << "Compilation succeed!" << std::endl;
		return 0;
	}
	return -1;
}
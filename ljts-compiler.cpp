#include "ljts-compiler.hpp"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <cstdlib>
#include <cstring>
#include <ctime>

extern int yyparse();

void yyerror(const char *s) {
	std::cout << "\033[91merror:\033[0m " << s << " at line " << yylineno << std::endl;
	exit(1);
}

bool do_print = false;

void help();
void version();

int main(int argc, char **argv) {
	std::srand(std::time(nullptr));
	if (argc >= 2) {
		for (int i = 1; i < argc; i++) {
			switch (argv[i][0]) {
				case '-':
					std::cout << "Test" << std::endl;
					if (argv[i][1] == 'p')
						do_print = true;
					else if (std::strcmp(&argv[i][1], "-version") == 0)
						version();
					else if (std::strcmp(&argv[i][1], "-help") == 0)
						help();
					break;
				default:
					int fi;
					if ((fi = open(argv[i], O_RDONLY)) == -1) {
						std::cerr << "Erreur: fichier inaccessible " << argv[i] << std::endl;
						exit(1);
					}
					std::cout << "Fichier " << argv[i] << " chargé correctement." << std::endl;
					close(0); dup(fi); close(fi);
					if (yyparse() != 0) {
						std::cout << "Compilation failed!" << std::endl;
						return -1;
					}
					std::cout << "Compilation succeed!" << std::endl;
					return 0;
			}
		}
	}
	return 0;
}

void help() {
	std::cout << "compiler pre-alpha 0.1 (amd64)" << std::endl
		<< "Usage: compiler [OPTION]... FILE" << std::endl
		<< "ça compile, mais ça ne compile pas." << std::endl << std::endl

		<< "  -p, --print         print the AST generated." << std::endl
		<< "      --help     display this help and exit." << std::endl
		<< "      --version  output version information and exit." << std::endl;
}

void version() {
	std::cout << "compiler pre-alpha 0.1" << std::endl
		<< "Copyright (C) 2019 Free Lucas Théo Jules Sullivan' Software Foundation, Inc." << std::endl
		<< "License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>." << std::endl
		<< "This is free software: you are free to change and redistribute it." << std::endl
		<< "There is NO WARRANTY, to the extent permitted by law." << std::endl << std::endl

		<< "Written by Lucas V. David, Théo Legars, Jules Vittone & Sullivan Honnet" << std::endl;
}
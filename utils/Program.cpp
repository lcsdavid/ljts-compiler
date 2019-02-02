#include "Program.hpp"

Program::Program(const std::vector<Type*> typesDecls, Block *main) : typesDecls(typesDecls), main(main) {}

Program::~Program() {
	for (auto it = typesDecls.begin(); it != typesDecls.end(); it++)
		delete *it;
	delete main;
}

std::ostream &operator<<(std::ostream &os, const Program &program) {
	os << "Déclarations:" << std::endl;
	for (auto it = typesDecls.begin(); it != typesDecls.end(); it++)
		os << *it << std::endl;
	return os << std::endl << "main():" << std::endl << main;
}

#include "Program.hpp"

#include "types/Type.hpp"
#include "types/classes/Class.hpp"
#include "types/objects/Object.hpp"

#include "trees/Block.hpp"

#include "Environment.hpp"

Program::Program(const std::vector<Type*> typesDecls, Block *main) : typesDecls(typesDecls), main(main) {}

Program::~Program() {
	for (auto it = typesDecls.begin(); it != typesDecls.end(); it++)
		delete (*it);
	delete main;
}

void Program::contextualCheck() const {
	Environment env;
	for (auto it = typesDecls.begin(); it != typesDecls.end(); it++)
		if ((*it)->correctDecl(env))
			env.env[(*it)->identifier] = *it;

	/* Vérife de main */
}

std::ostream &operator<<(std::ostream &os, const Program &p) {
	os << "Déclarations:" << std::endl;
	for (auto it = p.typesDecls.begin(); it != p.typesDecls.end(); it++)
		os << **it << std::endl;
	return os << "main():" << std::endl << *p.main;
}

#ifndef COMPILER_PROGRAM_HPP
#define COMPILER_PROGRAM_HPP

#include <vector>

struct Block;
struct Type;

struct Program {
    std::vector<Type*> typesDecls;	/* Liste [optionnelle] de déclarations des types. */
    Block *main;					/* Le bloc d'opération principal e.g. main(). */
	
	Program(const std::vector<Type*> typesDecls, Block *main);
	~Program();
	
	void contextualCheck() const;
};

std::ostream &operator<<(std::ostream &os, const Program &program);

#endif 
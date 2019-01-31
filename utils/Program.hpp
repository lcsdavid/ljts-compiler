#ifndef COMPILER_ENVIRONMENT_H
#define COMPILER_ENVIRONMENT_H

struct Block;
struct Type;

struct Programme {
    std::vector<Type*> declarations;	/* Liste [optionnelle] de déclarations des types. */
    Block *main;						/* Le bloc d'opération principal e.g. main. */
	
	Programme(const std::vector<Type*> declarations, Block *main);
	~Programme() = default;
	
	
};

#endif COMPILER_ENVIRONMENT_H
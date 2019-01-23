#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>
#include <vector>
#include <map>

#include "Variable.hpp"
#include "Tree.hpp"


struct Block {
	std::vector<Variable> decls;

	Tree inst ;

	Block(std::vector<Variable>& const decls, Tree& inst);
	virtual ~Block() = default ;

	bool correctDecl(std::map<std::string, Type>* environnement) const;
	
}; 

#endif
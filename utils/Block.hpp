#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>
#include <vector>

#include "Variable.hpp"
#include "Tree.hpp"


struct Block {
	std::vector<Variable> decls;

	Tree inst ;

	Block()= default ;

	
}; 

#endif
#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>
#include <vector>
#include <map>

#include "../Variable.hpp"
#include "../Environment.hpp"

struct Type;
struct Tree;

struct Block {
	std::vector<Variable> varDecls;
	std::vector<Tree*> insts;

	Block(const std::vector<Variable> &varDecls, const std::vector<Tree*> &insts);
	~Block() = default;

	bool correctDecl(Environment env) const;
};

std::ostream &operator<<(std::ostream &os, const Block &b);

#endif
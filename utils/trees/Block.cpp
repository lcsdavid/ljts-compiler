#include "Block.hpp"

#include "../types/Type.hpp"
#include "Tree.hpp"

Block::Block(std::vector<Variable> const &varDecls, std::vector<Tree*> const &insts): varDecls(varDecls), insts(insts) {}

bool Block::correctDecl(Environment env) const {/* Dans le cas d'un bloc */
    if(varDecls.empty())
        return true;
    /*for (Variable const &varDecl : varDecls) {
        if(env.find(varDecl.identifier) == env.end())
            return false;
    }*/
    return true;
}

std::ostream &operator<<(std::ostream &os, const Block &b) {
	os << "block:" << std::endl;
	for (auto it = b.varDecls.begin(); it != b.varDecls.end(); it++)
		os << "  " << *it << std::endl;
	std::cout << "---" << std::endl;
	for (auto it = b.insts.begin(); it != b.insts.end(); it++)
		os << "  " << **it << std::endl;
	return os;
}

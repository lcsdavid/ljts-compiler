#include "Block.hpp"

#include "../types/Type.hpp"

Block::Block(std::vector<Parameter> const &varDecls, std::vector<Tree*> const &insts): varDecls(varDecls), insts(insts) {}

bool Block::correctDecl(std::map <std::string, Type*> &env) const {/* Dans le cas d'un bloc */
    if(varDecls.empty())
        return true;
    for (Parameter const &varDecl : varDecls) {
        if(env.find(varDecl.identifier) == env.end())
            return false;
    }
    return true;
}
#include "Block.hpp"

#include "Type.hpp"

Block::Block(std::vector<Variable*> const &varDecls, std::vector<Tree*> const &insts): varDecls(varDecls), insts(insts) {}

bool Block::correctDecl(std::map <std::string, Type*> *environnement) const {/* Dans le cas d'un bloc */
    if(varDecls.empty())
        return true;
    for (Variable const *varDecl : varDecls) {
        if(environnement->find(varDecl->identifier) == environnement->end())
            return false;
    }
    return true;
}
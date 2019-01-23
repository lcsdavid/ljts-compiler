#include "Block.hpp"

Block::Block(const std::vector <Variable> &decls, Tree &inst): decls(decls), inst(inst) {}

bool Block::correctDecl(std::map <std::string, Type> *environnement) const {/* Dans le cas d'un bloc */

    if(decls == nullptr)
        return true;

    for (Variable const &decl : decls) {

        if(environnement->find(decl.identifier) == environnement->end())
            return false;

    }

    
    return true;
}
#ifndef STRUCTURES_HPP
#define STRUCTURES_HPP

#include "trees/Block.hpp"
#include "trees/Tree.hpp"

#include "variables/Parameter.hpp"
	
#include "types/Type.hpp"
	#include "types/classes/Class.hpp"
	#include "types/objects/Object.hpp"

#include "types/Method.hpp"
#include "types/Constructor.hpp"


struct Programme {
    std::vector<Type *> decls;//la liste optionnelle de declarations
    Tree tree;//le bloc d'opéraction
};
/*
void regressionTesting(); */

#endif

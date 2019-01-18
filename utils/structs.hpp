#ifndef LJTS_COMPILER_CLASS_STRUCT_HPP
#define LJTS_COMPILER_CLASS_STRUCT_HPP

#include <string>
#include <type_traits>
#include <variant>
#include <vector>
#include <map>

/*
struct Bloc {
	std::vector<Variable*> variables;
	std::vector<Instruction*> instructions;
	
	Bloc(
};*/


struct Tree;

struct Tree {
	int ligne;
	int operation;
	std::vector<std::variant<Parameter, Class, Object, Tree>> children;
	
	//template <typename ...Args>
	//Tree(int operation, Args&... args); 
};

/*

template <typename ...Args>
Tree::Tree(int operation, Args&... args) : operation(operation), children(args...) {
	static_assert(std::disjunction<std::is_same<Parameter, Args>..., std::is_same<Class, Args>..., std::is_same<Object, Args>..., std::is_same<Tree, Args>...>::value);
}

*/

struct Programme {
    std::vector<Type *> decls;//la liste optionnelle de declarations
    Tree tree;//le bloc d'opéraction
};

void regressionTesting();

#endif

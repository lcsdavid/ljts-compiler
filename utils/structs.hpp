#ifndef LJTS_COMPILER_CLASS_STRUCT_HPP
#define LJTS_COMPILER_CLASS_STRUCT_HPP

#include <string>
#include <type_traits>
#include <variant>
#include <vector>

/*
struct Bloc {
	std::vector<Variable*> variables;
	std::vector<Instruction*> instructions;
	
	Bloc(
};*/

struct Parameter {
    std::string identifier;     /* Identifiant du paramètre. */
    std::string typeIdentifier; /* Identifiant du type du paramètre. */
	bool var;                   /* Est-ce que c'est un paramètre 'var'. */
	
	Parameter(const std::string &identifier, const std::string &type, bool var);
};

struct Field {
	std::string identifier;     /* Identifiant. */
    std::string typeIdentifier; /* Identifiant du type du champ. */
	
	Field(const std::string &identifier, const std::string &typeIdentifier);
};

struct Method {
    std::string identifier;         /* Identifiant de la méthode. */
    std::vector<Parameter*> parameters; /* Liste de paramètre. */
    //std::tree* m_bloc_instruction;
	
	Method(const std::string &identifier, const std::vector<Parameter*> parameters);
};

struct Constructor {
    std::string identifier;             /* Identifiant. */
    std::vector<Parameter*> parameters; /* Liste de paramètre. */
    Constructor *superConstructor;      /* Super constructeur [optionnel]. */
    //tree *m_bloc_instruction; Pas mieux de faire une struct Bloc ?
	
	Constructor(const std::string &identifier, const std::vector<Parameter*> &parameters, Constructor *superConstructor);
};

//struct Type {
//	std::string identifier;       /* Identifiant de la classe. */
//	std::vector<Field*> fields;   /* Liste de champs de la classe. */
//	std::vector<Method*> methods; /* Liste de méthodes de la classe. */
//};

struct Class /* : Type */ {
    std::string identifier;             /* Identifiant de la classe. */
	std::vector<Parameter*> parameters; /* Liste de paramètres de la classe. */
	Class *superClass;                  /* Super-classe de la classe [optionnel]. */
	std::vector<Field*> fields;         /* Liste de champs de la classe. */
	std::vector<Method*> methods;       /* Liste de méthodes de la classe. */
	Constructor &constructor;           /* Constructeur de la classe. */
  
	Class(const std::string &identifier, const std::vector<Parameter*> &parameters, Class *superClass, const std::vector<Field*> &fields,
	    const std::vector<Method*> &methods, Constructor &constructor);
};

struct Object /* : Type */ {
    std::string identifier;       /* Identifiant de l'objet. */
    std::vector<Field*> fields;   /* Liste de champs de l'objet. */
    std::vector<Method*> methods; /* Liste de méthodes de l'objet. */
	
	Object(const std::string &identifier, const std::vector<Field*> &fields, const std::vector<Method*> &methods);
};

struct Tree;

struct Tree {
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


void regressionTesting();

#endif
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

struct Parameter {
    std::string identifier;     /* Identifiant du paramètre. */
    std::string typeIdentifier; /* Identifiant du type du paramètre. */
	bool var;                   /* Est-ce que c'est un paramètre 'var'. */
	
	Parameter(const std::string &identifier, const std::string &type, bool var);
};

/** 
 * Surcharge de '==' pour les Parameter.
 */
bool operator==(const Parameter &lhs, const Parameter &rhs);

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

/** 
 * Surcharge de '==' pour les Method.
 */
bool operator ==(const Method &lhs, const Method &rhs);

/**
 * Surcharge de '+' entre Method et Parameter.
 * Ajout d'un Parameter sur une Method.
 */
Method operator+(Method &lhs, Parameter *rhs);


struct SuperConstructeur{
    std::string identifier;             /* Identifiant. */
    std::vector<std::string*> parameters; /* Liste de paramètre. */
    SuperConstructeur *superConstructor;      /* Super constructeur [optionnel]. */
};

struct Constructor {
    std::string identifier;             /* Identifiant. */
    std::vector<Parameter*> parameters; /* Liste de paramètre. */
    SuperConstructeur *superConstructor;      /* Super constructeur [optionnel]. */
    //tree *m_bloc_instruction; Pas mieux de faire une struct Bloc ?
	
	Constructor(const std::string &identifier, const std::vector<Parameter*> &parameters, Constructor *superConstructor);
    bool isCorrect(const std::vector<Parameter *> &parameters);
};

struct Type {
	std::string identifier;       /* Identifiant de la classe. */
	std::vector<Field*> fields;   /* Liste de champs de la classe. */
	Constructor &constructor;     /* Constructeur de la classe. */
	std::vector<Method*> methods; /* Liste de méthodes de la classe. */

    Type(std::string const &identifier, std::vector<Field*> const &fields, Constructor const &constructor, std::vector<Method*> const &methods);
	
    bool typeCorrect(std::map<std::string, Type>* environnement);//vérifie que le Type créer est correct par rapport à l'environnement existant
	
    std::string getSuperClass()=0;
};



struct Class;

struct Class : Type  {
	std::vector<Parameter*> parameters; /* Liste de paramètres de la classe. */
	std::string *superClassIdentifier;  /* Identifiant de la super-classe de la classe [optionnel]. */

	Class(std::string const &identifier, std::vector<Parameter*> const &parameters, std::string const &superClassIdentifier, std::vector<Field*> const &fields,
	    Constructor &constructor, const std::vector<Method*> &methods);
	std::string getSuperClass() {
	    if(this->superClass == nullptr)
	        return "";
	    return this->superClass->identifier;
	}
};

struct Object : Type  {
	Object(std::string const &identifier, std::vector<Field*> const &fields, Constructor const &constructor, std::vector<Method*> const &methods);
	
	std::string getSuperClass(){
	    return "";
	}
};

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

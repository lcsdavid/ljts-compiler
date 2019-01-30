#ifndef COMPILER_OBJECTCONSTRUCTOR_HPP
#define COMPILER_OBJECTCONSTRUCTOR_HPP

#include "../Constructor.hpp"

struct ObjectConstructor : Constructor {
	ObjectConstructor(std::string const &identifier, Block *body);
	ObjectConstructor(ObjectConstructor const &other);
	ObjectConstructor(ObjectConstructor &&other);
	~ObjectConstructor() override;
	
	ObjectConstructor &operator=(ObjectConstructor const &other);
	ObjectConstructor &operator=(ObjectConstructor &&other);
	
	bool correctDecl(Environment env) const override {
		return true;
	}
};

#endif

#ifdef lel
MethodCall : IDENTIFIER '.' Expr '(' LOptExpr ')' 	{ $$ = new Tree(yylineno, method_call, { $1, $3, $5 }); }
 | STRING '.' Expr '(' LOptExpr ')'					{ $$ = new Tree(yylineno, method_call, $1, $3); }
 | TYPENAME '.' Expr '(' LOptExpr ')'				{ $$ = new Tree(yylineno, method_call, { $1, $3, $5 }); }
;
#endif
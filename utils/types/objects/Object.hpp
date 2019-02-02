#ifndef COMPILER_OBJECT_HPP
#define COMPILER_OBJECT_HPP

#include "../Type.hpp"
#include "ObjectConstructor.hpp"

struct Object : Type {
	Object(const std::string &identifier, const std::vector<Parameter> &fields, ObjectConstructor &constructor,
		const std::vector<Method> &methods);
	Object(const Object &other) = default;
	Object(Object &&other) = default;
	~Object() override = default;
	
	virtual bool isStatic() const {
		return true;
	}
	
	virtual bool hasSuper() const {
		throw NotInheritableException("Bah c'est un objet du coup il a pas de super....");
	}
	
	virtual std::string super() const {
		throw NotInheritableException();
	}
	
	bool isInheritable() const override {
		return false;
	}
	
	bool isDuplicable() const override {
		return false;
	}
		
	bool correctDecl(const Environment &env) const override;
};

#endif
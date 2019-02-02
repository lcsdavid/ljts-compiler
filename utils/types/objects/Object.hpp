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
		throw std::logic_error(identifier + " est un object (static class) donc elle ne peut être dérivée d'une autre classe.");
	}
	
	virtual std::string super() const {
		throw std::logic_error(identifier + " est un object (static class) donc elle ne peut être dérivée d'une autre classe.");
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
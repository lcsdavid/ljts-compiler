#ifndef COMPILER_OBJECT_HPP
#define COMPILER_OBJECT_HPP

#include "../Type.hpp"
#include "ObjectConstructor.hpp"

struct Object : Type {
	Object(const std::string &identifier, const std::vector<Variable> &fields, ObjectConstructor &constructor,
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
		
	bool correctDecl(const Environment &env) const override;
	
	std::ostream &print(std::ostream &os) const override;
};

std::ostream &operator<<(std::ostream &os, const Object &o);

#endif
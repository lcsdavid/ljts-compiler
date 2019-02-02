#ifndef OPTYPE_HPP
#define OPTYPE_HPP

/* Op type. */
enum optype {
	/* DECLS */
	class_decl, object_decl,
	/* CLASSES & OBJECTS */
	instanciation, cast, member_access, method_call,
	/* ASSIGNMENT */
	assignment,
	/* ARITHMETIC */
	unary_plus, unary_substract,
	multiplication, division,
	addition, substraction,
	/* RELATIONAL_OPERATOR */
	less_strict, less_equal, greater_strict, greater_equal,
	equal, not_equal,
	/* MISCELLANEOUS */
	if_then_else, return_call, inst_block,
	/* CONSTS & IDENTIFIER */
	integer, string, identifier
};

#endif
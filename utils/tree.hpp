#ifndef TREE_HPP
#define TREE_HPP

#include <variant>
#include <vector>

#include "Block.hpp"
#include "Parameter.hpp"
#include "Type.hpp"

struct Tree;

struct Tree {
	int ligne;
	int operation;
	std::vector<std::variant<Class, Object, Block, Tree>> children;
	
	Tree(int operation); 
};

/*
#ifdef TEMPLATE_TREE

#include <tuple>

namespace std {
	template<class... Types>
	using tree = std::tuple<Types...>;

	template<class... Types>
	constexpr tree<typename std::decay<Types>::type...> (*make_tree)(Types &&...args) = &std::make_tuple;
}

#endif
*/

#endif
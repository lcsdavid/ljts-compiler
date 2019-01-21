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
	std::vector<std::variant<Class, Object, Block, int, std::string, Tree>> children;
	
	Tree(int operation);
	Tree(Tree const &other) = default;
	~Tree() = default;
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

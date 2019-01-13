#ifndef TREE_HPP
#define TREE_HPP

class Tree {
	
	
};











#ifdef TEMPLATE_TREE

#include <tuple>

namespace std {
	template<class... Types>
	using tree = std::tuple<Types...>;

	template<class... Types>
	constexpr tree<typename std::decay<Types>::type...> (*make_tree)(Types &&...args) = &std::make_tuple;
}

#endif

#endif
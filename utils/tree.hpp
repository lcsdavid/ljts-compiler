#ifndef TREE_HPP
#define TREE_HPP

struct Parameter;
struct Class;
struct Object;
struct Tree;

struct Tree {
	int ligne;
	int operation;
	std::vector<std::variant<Parameter*, Class*, Object*, Tree*>> children;
	
	//template <typename ...Args>
	//Tree(int operation, Args&... args); 
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
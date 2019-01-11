#include <iostream>

#include "tree.hpp"

int main() {
	auto t = make_tree(1, 1., 1.f, "a");
	std::cout << std::get<0>(t) << "  " << get<1>(t) << "  " << get<2>(t) << "  " << get<3>(t) << std::endl;
	return 0;
}
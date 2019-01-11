#include <iostream>

#include "tree.hpp"

int main() {
	std::tree<int> t = std::make_tuple(1);
	auto tr = std::make_tuple(1, 1., 1.f, "a");
	std::cout << std::get<0>(tr); // << "  " << std::get<1>(t) << "  " << std::get<2>(t) << "  " << std::get<3>(t) << std::endl;
	return 0;
}
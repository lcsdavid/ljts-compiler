#ifndef TREE_HPP
#define TREE_HPP

#include <tuple>

template<class... Types>
class tree : public std::tuple<Types...> {
public:
    explicit tree(const Types &...args);
    tree(const tree &other) = default;
    tree(tree &&other) noexcept = default;

    tree &operator=(const tree &other);
    tree &operator=(tree &&other) noexcept(std::is_nothrow_move_assignable<tree>::value);
};

#include "tree.tcc"

#endif

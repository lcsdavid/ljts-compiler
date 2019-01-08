#ifndef ABSTRACT_SYNTAX_TREE_HPP
#define ABSTRACT_SYNTAX_TREE_HPP

#include "tree.hpp"

enum operation_label : int;

template<class... Types>
class abstract_syntax_tree : public tree<Types...> {
private:
    operation_label m_label;

public:
    explicit abstract_syntax_tree(operation_label label, const Types &...args);
    abstract_syntax_tree(const abstract_syntax_tree &other) = default;
    abstract_syntax_tree(abstract_syntax_tree &&other) noexcept = default;

    abstract_syntax_tree &operator=(const abstract_syntax_tree &other);
    abstract_syntax_tree &operator=(abstract_syntax_tree &&other) noexcept(std::is_nothrow_move_assignable<abstract_syntax_tree>::value);

    operation_label &label();
    const operation_label &label() const;

    constexpr std::size_t size() const;
};

#include "abstract_syntax_tree.tcc"

#endif
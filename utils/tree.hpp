#ifndef TREE_HPP
#define TREE_HPP

#include <tuple>

template<class... Types>
class tree : private std::tuple<Types...> {
public:
    explicit tree(const Types &...args);
    tree(const tree &other) = default;
    tree(tree &&other) noexcept = default;
    tree &operator=(const tree &other);
    tree &operator=(tree &&other) noexcept(std::is_nothrow_move_assignable<tree>::value);
};

template<class... Types>
constexpr tree<typename std::decay<Types>::type...> make_tree(Types &&...args);

template<std::size_t I, class... Types>
constexpr typename std::tuple_element<I, tree<Types...>>::type &get(tree<Types...> &t) noexcept;

template<std::size_t I, class... Types>
constexpr typename std::tuple_element<I, tree<Types...>>::type &&get(tree<Types...> &&t) noexcept;

template<std::size_t I, class... Types>
constexpr typename std::tuple_element<I, tree<Types...>>::type const &get(const tree<Types...> &t) noexcept;

template<std::size_t I, class... Types>
constexpr typename std::tuple_element<I, tree<Types...>>::type const &&get(const tree<Types...> &&t) noexcept;

template<class T, class... Types>
constexpr T &get(tree<Types...> &t) noexcept;

template<class T, class... Types>
constexpr T &&get(tree<Types...> &&t) noexcept;

template<class T, class... Types>
constexpr const T &get(const tree<Types...> &t) noexcept;

template<class T, class... Types>
constexpr const T &&get(const tree<Types...> &&t) noexcept;

#include "tree.tcc"

#endif
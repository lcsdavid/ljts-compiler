template<class... Types>
tree<Types...>::tree(const Types &...args) : std::tuple<Types...>(args...) {}

template<class... Types>
tree<Types...> &tree<Types...>::operator=(const tree &other) {
    static_cast<std::tuple<Types...>&>(*this) = other;
    return *this;
}

template<class... Types>
tree<Types...> &tree<Types...>::operator=(tree &&other) noexcept(std::is_nothrow_move_assignable<tree>::value) {
    static_cast<std::tuple<Types...>&>(*this) = std::move(other);
    return *this;
}

template<class... Types>
constexpr tree<typename std::decay<Types>::type...> make_tree(Types &&...args) {
	typedef tree<typename std::decay<Types>::type...> result_type;
	return result_type(std::forward<Types>(args)...);
}

template<std::size_t I, class... Types>
constexpr typename std::tuple_element<I, tree<Types...>>::type &get(tree<Types...> &t) noexcept {
	return std::get<I>(dynamic_cast<std::tuple<Types...> &>(t));
}

template<std::size_t I, class... Types>
constexpr typename std::tuple_element<I, tree<Types...>>::type &&get(tree<Types...> &&t) noexcept {
	return std::get<I>(dynamic_cast<std::tuple<Types...> &&>(t));
}

template<std::size_t I, class... Types>
constexpr const typename std::tuple_element<I, tree<Types...>>::type &get(const tree<Types...> &t) noexcept {
	return std::get<I>(dynamic_cast<const std::tuple<Types...> &>(t));
}

template<std::size_t I, class... Types>
constexpr const typename std::tuple_element<I, tree<Types...>>::type &&get(const tree<Types...> &&t) noexcept {
	return std::get<I>(dynamic_cast<const std::tuple<Types...> &&>(t));
}

template<class T, class... Types>
constexpr T &get(tree<Types...> &t) noexcept {
	return std::get<T>(dynamic_cast<std::tuple<Types...> &>(t));
}

template<class T, class... Types>
constexpr T &&get(tree<Types...> &&t) noexcept {
	return std::get<T>(dynamic_cast<std::tuple<Types...> &&>(t));
}

template<class T, class... Types>
constexpr const T &get(const tree<Types...> &t) noexcept {
	return std::get<T>(dynamic_cast<const std::tuple<Types...> &>(t));
}

template<class T, class... Types>
constexpr const T &&get(const tuple<Types...> &&t) noexcept {
	return std::get<T>(dynamic_cast<const std::tuple<Types...> &&>(t));
}
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
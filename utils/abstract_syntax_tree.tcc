template<class... Types>
abstract_syntax_tree<Types...>::abstract_syntax_tree(operation_label label, const Types &...args) : tree<Types...>(args...), m_label(label) {}

template<class... Types>
abstract_syntax_tree<Types...> &abstract_syntax_tree<Types...>::operator=(const abstract_syntax_tree &other) {
    static_cast<abstract_syntax_tree<Types...>&>(*this) = other;
    return *this;
}

template<class... Types>
abstract_syntax_tree<Types...> &abstract_syntax_tree<Types...>::operator=(abstract_syntax_tree &&other) noexcept(std::is_nothrow_move_assignable<abstract_syntax_tree>::value) {
    static_cast<abstract_syntax_tree<Types...>&>(*this) = std::move(other);
    return *this;
}

template<class... Types>
operation_label &abstract_syntax_tree<Types...>::label() {
    return m_label;
}

template<class... Types>
const operation_label &abstract_syntax_tree<Types...>::label() const {
    return m_label;
}

template<class... Types>
constexpr std::size_t abstract_syntax_tree<Types...>::size() const {
    return std::tuple_size<std::tuple<Types...>>::value;
}

template<class... Types>
constexpr abstract_syntax_tree<typename std::decay<Types>::type...> make_abstract_syntax_tree(operation_label label, Types &&...args) {
    typedef abstract_syntax_tree<typename std::decay<Types>::type...> result_type;
    return result_type(label, std::forward<Types>(args)...);
}
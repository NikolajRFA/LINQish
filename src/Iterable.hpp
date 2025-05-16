#ifndef ITERABLE_HPP
#define ITERABLE_HPP

#include <list>
#include <functional>

template<typename T>
using predicate_t = std::function<bool(const T&)>;

template<typename T>
std::list<T> filter(std::list<T> list, const predicate_t<T>& predicate) {
    std::list<T> result;
    for (const auto& item : list)
    {
        if (predicate(item))
        {
            result.push_back(item);
        }
    }

    return result;
}

#endif // ITERABLE_HPP
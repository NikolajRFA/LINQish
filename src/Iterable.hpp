#ifndef ITERABLE_HPP
#define ITERABLE_HPP

#include <list>
#include <functional>

template<typename T>
using predicate_t = std::function<bool(const T&)>;

template<typename T1, typename T2>
using mapper_t = std::function<T1(const T2&)>;

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

template<typename T1, typename T2>
std::list<T1> map(std::list<T2> list, const mapper_t<T1, T2>& mapper)
{
    std::list<T1> result;
    for (const auto& item : list)
    {
        result.push_back(mapper(item));
    }

    return result;
}

#endif // ITERABLE_HPP
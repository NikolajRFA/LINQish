#ifndef ITERABLE_HPP
#define ITERABLE_HPP

#include <list>
#include <functional>

template <typename T>
using predicate_t = std::function<bool(const T &)>;

template <typename TSource, typename TResult>
using mapper_t = std::function<TResult(const TSource &)>;

template <typename T>
T *first(std::list<T> &list, const predicate_t<T> predicate = nullptr)
{
    if (!predicate)
    {
        return list.empty() ? nullptr : &list.front();
    }

    for (auto &item : list)
    {
        if (predicate(item))
        {
            return &item;
        }
    }

    return nullptr;
}

template <typename T>
T *last(std::list<T> &list, const predicate_t<T> predicate = nullptr)
{
    if (!predicate)
    {
        return list.empty() ? nullptr : &list.back();
    }

    for (auto it = list.rbegin(); it != list.rend(); ++it)
    {
        if (predicate(*it))
        {
            return &(*it); // Get the address of the element
        }
    }

    return nullptr;
}

#endif // ITERABLE_HPP

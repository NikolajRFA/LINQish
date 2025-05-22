#ifndef ITERABLE_HPP
#define ITERABLE_HPP

#include <list>
#include <functional>

template<typename T>
using predicate_t = std::function<bool(const T&)>;

template<typename TSource, typename TResult>
using mapper_t = std::function<TResult(const TSource&)>;

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

template<typename TSource, typename TResult>
std::list<TResult> map(std::list<TSource> list, const mapper_t<TSource, TResult>& mapper)
{
    std::list<TResult> result;
    for (const auto& item : list)
    {
        result.push_back(mapper(item));
    }

    return result;
}

template<typename T>
bool any(std::list<T> list, const predicate_t<T>& predicate)
{
    for (const auto& item : list)
    {
        if (predicate(item))
        {
            return true;
        }
    }

    return false;
}

template<typename T>
bool all(std::list<T> list, const predicate_t<T>& predicate)
{
    for (const auto& item : list)
    {
        if (!predicate(item))
        {
            return false;
        }
    }

    return true;
}

template<typename T>
T* first(std::list<T>& list, const predicate_t<T> predicate = nullptr)
{
    if (!predicate)
    {
        return list.empty() ? nullptr : &list.front();
    }

    for (auto& item : list)
    {
        if (predicate(item))
        {
            return &item;
        }
    }

    return nullptr;
}

#endif // ITERABLE_HPP
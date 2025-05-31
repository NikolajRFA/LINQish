#ifndef LINQISH_H
#define LINQISH_H
#include <algorithm>

template <typename T>
using predicate_t = std::function<bool(const T &)>;

template <typename TSource, typename TResult>
using mapper_t = std::function<TResult(const TSource &)>;

template <typename T>
class LINQish
{
private:
    std::list<T> data;

public:
    LINQish() {}
    LINQish(std::initializer_list<T> values) : data(values) {}
    LINQish(std::list<T> values) : data(values) {}

    std::list<T> toList()
    {
        return data;
    }

    LINQish<T> filter(const predicate_t<T> &predicate)
    {
        std::list<T> result;
        for (const auto &item : data)
        {
            if (predicate(item))
            {
                result.push_back(item);
            }
        }

        return LINQish<T>(result);
    }

    template <typename TResult>
    LINQish<TResult> map(const mapper_t<T, TResult> &mapper)
    {
        std::list<TResult> result;
        for (const auto &item : data)
        {
            result.push_back(mapper(item));
        }

        return LINQish<TResult>(result);
    }

    bool any(const predicate_t<T> &predicate)
    {
        for (const auto &item : data)
        {
            if (predicate(item))
            {
                return true;
            }
        }

        return false;
    }

    bool all(const predicate_t<T> &predicate)
    {
        for (const auto &item : data)
        {
            if (!predicate(item))
            {
                return false;
            }
        }

        return true;
    }

    T *first(const predicate_t<T> &predicate = nullptr)
    {
        if (!predicate)
        {
            return data.empty() ? nullptr : &data.front();
        }

        for (auto &item : data)
        {
            if (predicate(item))
            {
                return &item;
            }
        }

        return nullptr;
    }

    T *last(const predicate_t<T> &predicate = nullptr)
    {
        if (!predicate)
        {
            return data.empty() ? nullptr : &data.back();
        }

        for (auto it = data.rbegin(); it != data.rend(); ++it)
        {
            if (predicate(*it))
            {
                return &(*it); // Get the address of the element
            }
        }

        return nullptr;
    }

    LINQish<T> skip(int count)
    {
        LINQish<T> result;

        auto it = data.begin();
        for (int i = 0; i < count && it != data.end(); ++i)
        {
            ++it;
        }

        while (it != data.end())
        {
            result.data.push_back(*it);
            ++it;
        }

        return result;
    }

    LINQish<T> take(int count)
    {
        LINQish<T> result;

        auto it = data.begin();
        for (int i = 0; i < count && it != data.end(); ++i)
        {
            result.data.push_back(*it);
            ++it;
        }

        return result;
    }

    T *min(const std::function<bool(const T &, const T &)> &comparer)
    {
        auto it = std::min_element(data.begin(), data.end(), comparer);
        return (it != data.end()) ? &(*it) : nullptr;
    }
};

#endif // LINQISH_H

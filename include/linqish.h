/*
 Copyright (c) 2025-present Nikolaj Andersen

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

    https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
**/

#ifndef LINQISH_H
#define LINQISH_H
#include <algorithm>
#include <functional>
#include <set>
#include <vector>

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

    std::vector<T> toVector() const
    {
        return std::vector<T>(data.begin(), data.end());
    }

    LINQish<T> &filter(const predicate_t<T> &predicate)
    {
        std::list<T> result;
        for (const auto &item : data)
        {
            if (predicate(item))
            {
                result.push_back(item);
            }
        }

        data = std::move(result);
        return *this;
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

    LINQish<T> &skip(int count)
    {
        auto it = data.begin();
        for (int i = 0; i < count && it != data.end(); ++i)
        {
            ++it;
        }

        data = std::list<T>(it, data.end());
        return *this;
    }

    LINQish<T> &take(int count)
    {
        std::list<T> result;

        auto it = data.begin();
        for (int i = 0; i < count && it != data.end(); ++i, ++it)
        {
            result.push_back(*it);
        }

        data = std::move(result);
        return *this;
    }

    LINQish<T> &takeWhile(const predicate_t<T> &predicate)
    {
        std::list<T> result;
        for (auto &item : data)
        {
            if (predicate(item))
            {
                result.push_back(item);
            }
            else
            {
                break;
            }
        }

        data = result;
        return *this;
    }

    LINQish<T> &skipWhile(const predicate_t<T> &predicate)
    {
        auto it = data.begin();

        while (it != data.end() && predicate(*it))
        {
            ++it;
        }

        std::list<T> result(it, data.end());

        data = result;
        return *this;
    }

    /**
     * @brief Finds the minimum element in the list using a custom comparison function.
     *
     * This function uses `std::min_element` to determine the smallest element
     * based on the given `comparer` function. It returns a pointer to the found
     * element or `nullptr` if the list is empty.
     *
     * @tparam T The type of elements in the list.
     * @param comparer A comparison function that determines ordering of elements.
     *                 Should return `true` if `a` argument is considered
     *                 smaller than `b`.
     * @return T* Pointer to the minimum element, or `nullptr` if the list is empty.
     *
     * @note The comparison function should define a **strict weak ordering**
     *       between elements for correct behavior.
     */
    T *min(const std::function<bool(const T &, const T &)> &comparer)
    {
        auto it = std::min_element(data.begin(), data.end(), comparer);
        return (it != data.end()) ? &(*it) : nullptr;
    }

    /**
     * @brief Finds the maximum element in the list using a custom comparison function.
     *
     * This function uses `std::max_element` to determine the largest element
     * based on the given `comparer` function. It returns a pointer to the found
     * element or `nullptr` if the list is empty.
     *
     * @tparam T The type of elements in the list.
     * @param comparer A comparison function that determines ordering of elements.
     *                 Should return `true` if `b` argument is considered
     *                 greater than `a`.
     * @return T* Pointer to the maximum element, or `nullptr` if the list is empty.
     *
     * @note The comparison function should define a **strict weak ordering**
     *       between elements for correct behavior.
     */
    T *max(const std::function<bool(const T &, const T &)> &comparer)
    {
        auto it = std::max_element(data.begin(), data.end(), comparer);
        return (it != data.end()) ? &(*it) : nullptr;
    }

    /**
     * @brief Finds the element with the minimum value based on a key selector function.
     *
     * This function applies `selector` to each element, then finds the element
     * that produces the lowest value.
     *
     * @tparam TResult The type of the derived value used for comparison.
     * @param selector Function that extracts the key for comparison.
     * @return T* Pointer to the element with the minimum derived value, or nullptr if empty.
     */
    template <typename TResult>
    T *minBy(const std::function<TResult(const T &)> &selector)
    {
        if (data.empty())
            return nullptr;

        return &(*std::min_element(data.begin(), data.end(),
                                   [&](const T &a, const T &b)
                                   { return selector(a) < selector(b); }));
    }

    /**
     * @brief Finds the element with the maximum value based on a key selector function.
     *
     * This function applies `selector` to each element, then finds the element
     * that produces the highest value.
     *
     * @tparam TResult The type of the derived value used for comparison.
     * @param selector Function that extracts the key for comparison.
     * @return T* Pointer to the element with the maximum derived value, or nullptr if empty.
     */
    template <typename TResult>
    T *maxBy(const std::function<TResult(const T &)> &selector)
    {
        if (data.empty())
            return nullptr;

        return &(*std::max_element(data.begin(), data.end(),
                                   [&](const T &a, const T &b)
                                   { return selector(a) < selector(b); }));
    }

    bool contains(const T &value) const
    {
        return std::find(data.begin(), data.end(), value) != data.end();
    }

    bool contains(const predicate_t<T> &predicate) const
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

    template <typename Container>
    LINQish<T> &concat(const Container &values)
    {
        data.insert(data.end(), values.begin(), values.end());
        return *this;
    }

    LINQish<T> &concat(std::initializer_list<T> values)
    {
        data.insert(data.end(), values.begin(), values.end());
        return *this;
    }

    LINQish<T> &distinct()
    {
        std::list<T> result;
        std::set<T> seen;

        for (const auto &item : data)
        {
            if (seen.insert(item).second)
            {
                result.push_back(item);
            }
        }

        data = std::move(result);
        return *this;
    }
};

#endif // LINQISH_H

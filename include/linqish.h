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
#include <list>

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
    /**
     * @brief Constructs an empty LINQish collection.
     *
     * Initializes the internal container with no elements.
     */
    LINQish() {}
    /**
     * @brief Constructs a LINQish collection from an initializer list.
     *
     * Allows convenient creation using brace-enclosed values, e.g. LINQish<int>{1, 2, 3}.
     *
     * @param values The values to initialize the collection with.
     */
    LINQish(std::initializer_list<T> values) : data(values) {}
    /**
     * @brief Constructs a LINQish collection from a std::list.
     *
     * Takes ownership of the provided list of elements.
     *
     * @param values A std::list containing the initial elements.
     */
    LINQish(std::list<T> values) : data(values) {}
    /**
     * @brief Copy-constructs a LINQish collection from another instance.
     *
     * Creates a deep copy of the internal container from the provided LINQish object.
     *
     * @param other The LINQish object to copy from.
     */
    LINQish(const LINQish<T> &other) : data(other.data) {}

    /**
     * @brief Converts the collection into a std::list of elements.
     *
     * @return std::list<T> A list containing all elements from the collection.
     */
    std::list<T> toList()
    {
        return data;
    }

    /**
     * @brief Converts the collection into a std::vector of elements.
     *
     * @return std::vector<T> A vector containing all elements from the collection.
     */
    std::vector<T> toVector() const
    {
        return std::vector<T>(data.begin(), data.end());
    }

    /**
     * @brief Returns the number of elements in the collection.
     *
     * @return int The size of the collection.
     */
    int size()
    {
        return data.size();
    }

    /**
     * @brief Filters the collection by applying the given predicate to each element.
     *
     * Removes elements that do not satisfy the predicate, modifying the current collection in-place.
     *
     * @param predicate A function that takes an element of type T and returns true if the element should be retained.
     * @return LINQish<T>& Reference to the current collection after filtering.
     */
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

    /**
     * @brief Projects each element of the collection into a new form using the mapper function.
     *
     * Creates a new collection containing the results of applying the mapper to each element.
     *
     * @tparam TResult The type of the resulting elements.
     * @param mapper A function that transforms an element of type T into type TResult.
     * @return LINQish<TResult> A new collection containing the mapped results.
     */
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

    /**
     * @brief Determines whether any element in the collection satisfies the given predicate.
     *
     * @param predicate A function that takes an element of type T and returns true if the element matches the desired condition.
     * @return true If at least one element satisfies the predicate.
     * @return false If no elements satisfy the predicate.
     */
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

    /**
     * @brief Determines whether all elements in the collection satisfy the given predicate.
     *
     * @param predicate A function that takes an element of type T and returns true if the element matches the desired condition.
     * @return true If every element satisfies the predicate.
     * @return false If at least one element does not satisfy the predicate.
     */
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

    /**
     * @brief Returns a pointer to the first element that satisfies the given predicate.
     *
     * If no predicate is provided, returns a pointer to the first element in the collection,
     * or nullptr if the collection is empty.
     *
     * @param predicate A function that takes an element of type T and returns true if the element matches the desired condition.
     * @return T* Pointer to the first matching element, or nullptr if none is found.
     */
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

    /**
     * @brief Returns a pointer to the last element that satisfies the given predicate.
     *
     * If no predicate is provided, returns a pointer to the last element in the collection,
     * or nullptr if the collection is empty.
     *
     * @param predicate A function that takes an element of type T and returns true if the element matches the desired condition.
     * @return T* Pointer to the last matching element, or nullptr if none is found.
     */
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

    /**
     * @brief Skips the specified number of elements from the beginning of the collection.
     *
     * Removes the first `count` elements, if available, modifying the collection in-place.
     *
     * @param count The number of elements to skip.
     * @return LINQish<T>& Reference to the modified collection.
     */
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

    /**
     * @brief Retains the specified number of elements from the beginning of the collection.
     *
     * Truncates the collection to the first `count` elements, modifying it in-place.
     *
     * @param count The number of elements to take.
     * @return LINQish<T>& Reference to the modified collection.
     */
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

    /**
     * @brief Retains elements from the beginning of the collection while the predicate is true.
     *
     * Iterates until the predicate fails, keeping only the matching initial segment.
     *
     * @param predicate A function that returns true while elements should be retained.
     * @return LINQish<T>& Reference to the modified collection.
     */
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

    /**
     * @brief Skips elements from the beginning of the collection while the predicate is true.
     *
     * Iterates until the predicate fails, discarding the matching initial segment.
     *
     * @param predicate A function that returns true while elements should be skipped.
     * @return LINQish<T>& Reference to the modified collection.
     */
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

    /**
     * @brief Computes the sum of values projected from each element using the provided selector.
     *
     * Applies the selector to each element and accumulates the result as a float.
     *
     * @param selector A function that extracts a float value from each element.
     * @return float The total sum of projected values.
     */
    float sum(const std::function<float(const T &)> &selector) const
    {
        float total = 0;
        for (const auto &item : data)
        {
            total += selector(item);
        }
        return total;
    }

    /**
     * @brief Computes the average of values projected from each element using the provided selector.
     *
     * Applies the selector to each element, sums the results, and divides by the number of elements.
     * If the collection is empty, this will result in a divide-by-zero error.
     *
     * @param selector A function that extracts a float value from each element.
     * @return float The average of projected values.
     */
    float average(const std::function<float(const T &)> &selector) const
    {
        float total = this->sum(selector);

        return total / data.size();
    }

    /**
     * @brief Checks whether the collection contains the specified value.
     *
     * Performs a linear search to determine if any element in the collection
     * matches the given value using the equality operator.
     *
     * @param value The value to look for in the collection.
     * @return true If the value exists in the collection.
     * @return false Otherwise.
     */
    bool contains(const T &value) const
    {
        return std::find(data.begin(), data.end(), value) != data.end();
    }

    /**
     * @brief Checks whether any element in the collection satisfies the predicate.
     *
     * Iterates through the collection and evaluates the predicate on each element.
     * Returns true if the predicate returns true for any element.
     *
     * @param predicate A function that takes an element and returns a boolean.
     * @return true If at least one element satisfies the predicate.
     * @return false Otherwise.
     */
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

    /**
     * @brief Appends elements from another container to the current collection.
     *
     * Inserts all elements from the provided container at the end of the current collection.
     *
     * @tparam Container A container type with compatible value_type and iterators.
     * @param values The container whose elements will be concatenated.
     * @return LINQish<T>& Reference to the modified LINQish object.
     */
    template <typename Container>
    LINQish<T> &concat(const Container &values)
    {
        data.insert(data.end(), values.begin(), values.end());
        return *this;
    }

    /**
     * @brief Appends elements from an initializer list to the current collection.
     *
     * Inserts all elements from the initializer list at the end of the current collection.
     *
     * @param values The initializer list to concatenate.
     * @return LINQish<T>& Reference to the modified LINQish object.
     */
    LINQish<T> &concat(std::initializer_list<T> values)
    {
        data.insert(data.end(), values.begin(), values.end());
        return *this;
    }

    /**
     * @brief Removes duplicate elements from the collection.
     *
     * Preserves the original order while eliminating any repeated values.
     * Elements are compared using their equality and ordering semantics via std::set.
     *
     * @return LINQish<T>& Reference to the modified LINQish object.
     */
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

    /**
     * @brief Reverses the order of elements in the collection.
     *
     * All elements are reordered in-place to reflect the opposite sequence.
     *
     * @return LINQish<T>& Reference to the modified LINQish object.
     */
    LINQish<T> &reverse()
    {
        data.reverse();
        return *this;
    }
};

#endif // LINQISH_H

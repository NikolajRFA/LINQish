# LINQish - Fluent Query Utilities for C++

LINQish is a **modern, expressive library** that brings LINQ-style operations to C++ lists, allowing developers to write cleaner, more functional-style queries.

## ✨ Features
- 🔍 **Fluent-style chaining** for operations like `filter`, `map`, and `any`
- 📜 **Intuitive, readable syntax** inspired by C# LINQ
- 🚀 **Efficient list transformations** using the power of C++
- 💡 **Supports functional programming concepts** with lambdas
- ✅ **Seamless list manipulation** for cleaner, more expressive code

## 🔗 Example Usage

```cpp
#include "linqish.h"

std::list<int> filterAndMapNumbers()
{
    LINQish<int> numbers = {1, 2, 3, 4, 5};

    return numbers.filter([](int x) { return x % 2 == 0; })
                         .map<int>([](int x) { return x * 10; })
                         .toList();
}
```
## 📦 Installation
Simply include `linqish.h`in your project:
```bash
git clone https://github.com/NikolajRFA/LINQish.git
```
Then include the header file:
```cpp
#include "linqish.h"
```
## 📜 Available Methods
| Method  | Description |
|---------|-------------|
| `filter(predicate)` | Returns a filtered list based on the given condition |
| `map(transformer)` | Applies a function to each element and returns a transformed list |
| `any(predicate)` | Checks if any element matches a condition |
| `all(predicate)` | Checks if all elements satisfy a condition |
| `first(predicate)` | Gets the first matching element |
| `last(predicate)` | Gets the last matching element |

Feel free to open issues for bug reports, feature requests, or general improvements!

## 📜 License

This project is licensed under the **Apache License 2.0**. You are free to use, modify, and distribute this software, provided that you comply with the terms of the license, including providing proper attribution and including a copy of the license in any distribution.

See the full license text in the [`LICENSE`](LICENSE) file.

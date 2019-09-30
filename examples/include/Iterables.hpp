#ifndef ITERABLES_HPP
#define ITERABLES_HPP

#include <algorithm>
#include <list>

namespace Iterables {
    template<typename T>
    static bool contains(std::list<T> &, const T &);
};

template<typename T>
bool Iterables::contains(std::list<T> &listOfElements, const T &element) {
    return std::find(listOfElements.begin(), listOfElements.end(), element) != listOfElements.end();
}

#endif

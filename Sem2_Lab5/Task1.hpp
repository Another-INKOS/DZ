#ifndef CONTAINS_HPP
#define CONTAINS_HPP

template<typename T>
bool contains(const T& elem, const T* arr, size_t size) {
    for (size_t i = 0; i < size; ++i)
        if (arr[i] == elem)
            return true;
    return false;
}

#endif

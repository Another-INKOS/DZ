#ifndef CHANGE_HPP
#define CHANGE_HPP

#include "contains.hpp"
#include <iostream>

template<typename T>
bool change(const T& elem1, const T& elem2, T* arr, size_t size) {
    if (!contains(elem1, arr, size) || !contains(elem2, arr, size)) {
        std::cout << "Ошибка: один или оба элемента не найдены в массиве.\n";
        return false;
    }
    size_t idx1 = 0, idx2 = 0;
    bool found1 = false, found2 = false;
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] == elem1 && !found1) { idx1 = i; found1 = true; }
        if (arr[i] == elem2 && !found2) { idx2 = i; found2 = true; }
        if (found1 && found2) break;
    }
    if (idx1 != idx2) {
        T temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;
        std::cout << "Обмен успешно выполнен.\n";
    }
    else {
        std::cout << "Элементы совпадают, обмен не требуется.\n";
    }
    return true;
}

#endif

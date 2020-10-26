//
// Created by Andrew Kireev on 26.10.2020.
//

//Даны неотрицательные целые числа n,k и массив целых чисел из [0..10^9] размера n.
//Требуется найти k-ю порядковую статистику.
//т.е. напечатать число, которое бы стояло на позиции с индексом k (0..n-1) в отсортированном массиве.
//6_1. Реализуйте стратегию выбора опорного элемента “медиана трёх”.
//Функцию Partition реализуйте методом прохода двумя итераторами от начала массива к концу.

#include <iostream>
#include <algorithm>


template <typename T>
class DefaultComparator{
public:
    bool operator()(const T &lhs, const T &rhs) const {
        return lhs < rhs;
    }
};

template <typename T, typename Comparator = DefaultComparator<T>>
int find_pivot(T* mas, int first, int second, int third, Comparator comp) {
    if (comp(mas[first], mas[third]))
        std::swap(mas[first], mas[second]);
    if (comp(mas[second], mas[first]))
        std::swap(mas[second], mas[first]);
    if (comp(mas[third], mas[second]))
        std::swap(mas[third], mas[second]);
    return second;
}

template <typename T, typename Comparator = DefaultComparator<T>>
int partition(T* mas, int left, int right, Comparator comp) {
    int mid = left + (right - left) / 2;
    int index_pivot = find_pivot(mas, left, mid, right - 1, comp);
    std::swap(mas[index_pivot], mas[right - 1]);
    int i = left;
    int j = left;
    while (j < right - 1) {
        if (comp(mas[j], mas[right - 1]))
            std::swap(mas[i++], mas[j]);
        ++j;
    }
    std::swap(mas[i], mas[right - 1]);
    return i;
}

template <typename T, typename Comparator = DefaultComparator<T>>
int ordinal_statistic(T *mas, int size, int k_index, Comparator comp) {
    int left = 0;
    int right = size;

    while (true) {
        int m = partition(mas, left, right, comp);

        if (m == k_index)
            return k_index;
        else if (m < k_index)
            left = m + 1;
        else
            right = m;
    }
}


int main(int argc, char **argv) {
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    int mas[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> mas[i];
    }

    DefaultComparator<int> comp;

    int k_index = ordinal_statistic(mas, n, k, comp);
    std::cout << mas[k_index];
    return 0;
}
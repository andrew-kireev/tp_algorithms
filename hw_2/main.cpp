//
// Created by Andrew Kireev on 08.10.2020.
//

//Дан отсортированный массив различных целых чисел A[0..n-1] и массив целых чисел B[0..m-1].
//Для каждого элемента массива B[i] найдите минимальный индекс элемента массива A[k], ближайшего по значению к B[i].
//Требования: Время работы поиска для каждого элемента B[i]: O(log(k)).
//Внимание! В этой задаче для каждого B[i] сначала нужно определить диапазон для
//бинарного поиска размером порядка k, а потом уже в нем делать бинарный поиск.


#include <iostream>

int binary_search(int* vec, int left, int right, int key, int size) {
    int mid;
    if (size <= right)
        right = size - 1;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (vec[mid] <= key)
            return mid;

        if (vec[mid] <= key)
        {
            left = mid + 1;
        }
        else
            right = mid;
    }
    if (abs(vec[left] - key) < abs(vec[left - 1] - key))
        return left;
    return left - 1;

}

int exponential_search(int *mas, int size, int key)
{
    if (mas[0] == key || size == 0) {
        return 0;
    }

    int pos = 1;
    while (pos < size && mas[pos] < key) {
        pos *= 2;
    }

    return binary_search(mas, pos / 2,
                         (pos + 1 < size ? pos + 1 : size), key, size);
}

int main(int argc, char **argv) {
    int n;
    std::cin >> n;
    int *mas1 = new int[n];
    for (int i = 0; i != n; ++i)
        std::cin >> mas1[i];
    std::cin >> n;
    int *mas2 = new int[n];
    for (int i = 0; i != n; ++i)
        std::cin >> mas2[i];

    for (int i = 0; i != n; ++i) {
        if (i != 0)
            std::cout << " ";
        std::cout << exponential_search(mas1, n, mas2[i]);
    }
}

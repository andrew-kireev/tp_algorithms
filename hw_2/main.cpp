//
// Created by Andrew Kireev on 08.10.2020.
//

//Дан отсортированный массив различных целых чисел A[0..n-1] и массив целых чисел B[0..m-1].
//Для каждого элемента массива B[i] найдите минимальный индекс элемента массива A[k], ближайшего по значению к B[i].
//Требования: Время работы поиска для каждого элемента B[i]: O(log(k)).
//Внимание! В этой задаче для каждого B[i] сначала нужно определить диапазон для
//бинарного поиска размером порядка k, а потом уже в нем делать бинарный поиск.


#include <iostream>
#include <vector>
#include "tests.h"

int binary_search(int vec[], int left, int right, int key, int size)
{
    if (key == vec[left])
        return left;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (vec[mid] < key) {
            left = mid + 1;
        }
        else if (vec[mid] > key) {
            right = mid - 1;
        }
        else {
            left = mid;
            break;
        }
    }
    if (left >= size)
        return size - 1;
        if (left <= 0)
            return left;
        if (abs(vec[left] - key) < abs(vec[left - 1] - key))
            return left;
        return left - 1;
}

int exponential_search(int *mas, int size, int key) {
    int pos = 1;
    while (pos < size && mas[pos] < key) {
        pos *= 2;
    }

    return binary_search(mas, (pos) / 2,
                         (pos + 1 < size ? pos + 1 : size), key, size);         /// (pos - 1) / 2
}

int main(int argc, char **argv) {

    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();
    test13();
    test14();


    int n;
    std::cin >> n;
    int *mas1 = new int[n];
    for (int i = 0; i != n; ++i)
        std::cin >> mas1[i];
    int n2;
    std::cin >> n2;
    int *mas2 = new int[n2];
    for (int i = 0; i != n2; ++i)
        std::cin >> mas2[i];

    for (int i = 0; i != n2; ++i) {
        std::cout << exponential_search(mas1, n, mas2[i]) << ' ';
    }
}
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
    int ans = 0;
    bool equal = false;

    while (left <= right) {
        int mid = left + (right - left + 1) / 2;

        if (vec[mid] < key) {
            left = mid + 1;
        }
        else if (vec[mid] > key) {
            right = mid - 1;
        }
        else  {
            left = mid + 1;
            equal = true;
        }
    }
    if (left >= size)
        left = size - 1;
    while (left >= 1 && abs(vec[left] - key) >= abs(vec[left - 1] - key))
        left--;
//    if (!equal) {
        if (left >= size - 1)
            left = size - 1;
        if (left <= 0)
            return left;
        if (abs(vec[left] - key) < abs(vec[left - 1] - key))
            return left;
        return left - 1;
//    }
    return left;
}


int exponential_search(int *mas, int size, int key) {
    if (mas[0] >= key || size == 0) {
        return 0;
    }
//    if (mas[size - 1] < key)
//        return size - 1;

    int pos = 1;
    int equal_elems = 0;
    while (pos < size && mas[pos] < key) {
        pos *= 2;
//        if (mas[pos - 1] == mas[pos])
//            equal_elems++;
    }
//    int left = (pos - 1) / 2 - equal_elems;

    return binary_search(mas, (pos) / 2,
                         (pos + 1 < size ? pos + 1 : size), key, size);         /// (pos - 1) / 2
}

int main(int argc, char **argv) {
//    int n;
//    std::cin >> n;
//    int *mas1 = new int[n];
//    for (int i = 0; i != n; ++i)
//        std::cin >> mas1[i];
//    int n2;
//    std::cin >> n2;
//    int *mas2 = new int[n];
//    for (int i = 0; i != n2; ++i)
//        std::cin >> mas2[i];
//
//    for (int i = 0; i != n2; ++i) {
//        if (i != 0)
//            std::cout << " ";
//        std::cout << exponential_search(mas1, n, mas2[i]);
//    }

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
    test12();
    test13();
    test14();
}


//
//10 20 30
//9 15 35
//0 0 2
//TEST 1 - OK
//
//10 20 30
//8 9 10 32
//0 0 0 2
//TEST 2 - OK
//
//13 15 27 34 54
//2 72 27 30 90 53
//0 4 2 2 4 4
//TEST 3 - OK
//
//1 15 26 33 54 78
//2 72 27 30 90 53 5
//0 5 2 3 5 4 0
//TEST 4 - OK
//
//1 15 26 53 54 89 91
//0 -10 27 30 90 53
//0 0 2 2 5 3
//TEST 5 - OK
//
//1 15 26 53 54 89 91
//-5 -10 -20 -30 40 50
//0 0 0 0 3 3
//TEST 6 - OK
//
//15 15 15 15 15 15 15
//-5 -10 -20 -30 40 50
//0 0 0 0 0 0
//TEST 7 - OK
//
//-50 -50 -50 -50 -50 -2 50 300
//-5 -10 -20 -30 40 50
//5 5 5 0 6 6
//TEST 8 - OK
//
//-50 -50 -50 -50 -50 -50 -50
//-5 -10 -20 -30 40 50
//0 0 0 0 0 0
//TEST 9 - OK
//
//-1 0 0 0 0 0 0
//-5 -10 -20 -30 40 50
//0 0 0 0 1 1
//TEST 10 - OK
//
//5 5 5 5 10 10 10
//9 8 6 5 10 10
//4 4 0 0 4 4
//TEST 11 - OK
//
//-50 -50 -50 -50 -50 0 5
//-5 -10 -20 -30 40 50
//5 5 5 0 6 6
//TEST 12 - OK
//
//0 1 25 75 126 200 300
//-5 -10 -20 -30 40 100
//0 0 0 0 2 3
//TEST 13 - OK
//
//33 39 57 60 67 77 78 79 88
//79 33 57 88 99 67 60 20 77 79
//7 0 2 8 8 4 3 0 5 7
//TEST 14 - OK
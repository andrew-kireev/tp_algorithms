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
//    if (size <= right)
//        right = size - 1;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (vec[mid] == key)
            return mid;

        if (vec[mid] <= key)
        {
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    if (left <= 0)
        return left;
    if (left > size - 1)
        return size - 1;
    if (abs(vec[left] - key) < abs(vec[left - 1] - key))
        return left;
    return left - 1;

}

int exponential_search(int *mas, int size, int key) {
    if (mas[0] == key || size == 0) {
        return 0;
    }

    int pos = 1;
    while (pos < size && mas[pos] < key) {
        pos *= 2;
    }

    return binary_search(mas, (pos - 1) / 2,
                         (pos + 1 < size ? pos + 1 : size), key, size);
}



    void test1() {
    int mas1[] = {10, 20, 30};
    int mas2[] = {9, 15, 35};

    int n = 3;

    for (int i = 0; i != n; ++i)
        std::cout << mas1[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != 3; ++i)
        std::cout << mas2[i] << " ";
    std::cout << std::endl;

    for (int i = 0; i != n; ++i) {
        if (i != 0)
            std::cout << " ";
        std::cout << exponential_search(mas1, n, mas2[i]);
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void test2() {
    int mas1[] = {10, 20, 30};
    int mas2[] = {8, 9, 10, 32};

    int n = 3;

    for (int i = 0; i != n; ++i)
        std::cout << mas1[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != 3; ++i)
        std::cout << mas2[i] << " ";
    std::cout << std::endl;

    for (int i = 0; i != 4; ++i) {
        if (i != 0)
            std::cout << " ";
        std::cout << exponential_search(mas1, n, mas2[i]);
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void test3() {
    int mas1[] = {13, 15, 27, 34, 54};
    int mas2[] = {2, 72, 27, 30, 90, 53};

    int n = 5;

    for (int i = 0; i != n; ++i)
        std::cout << mas1[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != 6; ++i)
        std::cout << mas2[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != 6; ++i) {
        if (i != 0)
            std::cout << " ";
        std::cout << exponential_search(mas1, n, mas2[i]);
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void test4() {
    int mas1[] = {1, 15, 26, 33, 54, 78};
    int mas2[] = {2, 72, 27, 30, 90, 53, };

    int n = 5;

    for (int i = 0; i != n; ++i)
        std::cout << mas1[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != 6; ++i)
        std::cout << mas2[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != 6; ++i) {
        if (i != 0)
            std::cout << " ";
        std::cout << exponential_search(mas1, n, mas2[i]);
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void test5() {
    int mas1[] = {1, 15, 26, 53, 54, 89, 91};
    int mas2[] = {0, -10, 27, 30, 90, 53};

    int n = 7;

    for (int i = 0; i != n; ++i)
        std::cout << mas1[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != 6; ++i)
        std::cout << mas2[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != 6; ++i) {
        if (i != 0)
            std::cout << " ";
        std::cout << exponential_search(mas1, n, mas2[i]);
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void test6() {
    int mas1[] = {1, 15, 26, 53, 54, 89, 91};
    int mas2[] = {-5, -10, -20, -30, 40, 50};

    int n = 7;
    int n2 = 6;

    for (int i = 0; i != n; ++i)
        std::cout << mas1[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != n2; ++i)
        std::cout << mas2[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != n2; ++i) {
        if (i != 0)
            std::cout << " ";
        std::cout << exponential_search(mas1, n, mas2[i]);
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void test7() {
    int mas1[] = {15, 15, 15, 15, 15, 15, 15};
    int mas2[] = {-5, -10, -20, -30, 40, 50};

    int n = 7;
    int n2 = 6;

    for (int i = 0; i != n; ++i)
        std::cout << mas1[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != n2; ++i)
        std::cout << mas2[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != n2; ++i) {
        if (i != 0)
            std::cout << " ";
        std::cout << exponential_search(mas1, n, mas2[i]);
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void test8() {
    int mas1[] = {-50, -50, -2, -50, -50, 50, -300};
    int mas2[] = {-5, -10, -20, -30, 40, 50};

    int n = 7;
    int n2 = 6;

    for (int i = 0; i != n; ++i)
        std::cout << mas1[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != n2; ++i)
        std::cout << mas2[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != n2; ++i) {
        if (i != 0)
            std::cout << " ";
        std::cout << exponential_search(mas1, n, mas2[i]);
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

int main(int argc, char **argv) {
    int n;
    std::cin >> n;
    int *mas1 = new int[n];
    for (int i = 0; i != n; ++i)
        std::cin >> mas1[i];
    int n2;
    std::cin >> n2;
    int *mas2 = new int[n];
    for (int i = 0; i != n2; ++i)
        std::cin >> mas2[i];

    for (int i = 0; i != n2; ++i) {
        if (i != 0)
            std::cout << " ";
        std::cout << exponential_search(mas1, n, mas2[i]);
    }
//    std::cout << std::endl;

//    test1();
//    test2();
//    test3();
//    test4();
//    test5();
//    test6();
//    test8();
}


//1 15 26 53 54 89 91
//-5 -10 -20 -30 40 50
//0 0 0 0 3 3
//
//-50 -50 -2 -50 -50 50 -300
//-5 -10 -20 -30 40 50
//2 2 2 1 5 5

//10 20 30
//9 15 35
//0 0 2
//
//10 20 30
//8 9 10
//0 0 0 2
//
//13 15 27 34 54
//2 72 27 30 90 53
//0 4 2 2 4 4
//
//1 15 26 33 54
//2 72 27 30 90 53
//0 4 2 3 4 4
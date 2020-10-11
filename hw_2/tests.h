//
// Created by Andrew Kireev on 11.10.2020.
//

#ifndef TP_ALGORITHMS_TESTS_H
#define TP_ALGORITHMS_TESTS_H

#include <iostream>
#include <vector>


int exponential_search(int *mas, int size, int key);
int binary_search(int vec[], int left, int right, int key, int size);

void test1() {
    int mas1[] = {10, 20, 30};
    int mas2[] = {9, 15, 35};
    std::vector<int> answers = {0, 0, 2};

    int n = 3;
    int n2 = 3;
    for (int i = 0; i != n; ++i)
        std::cout << mas1[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != 3; ++i)
        std::cout << mas2[i] << " ";
    std::cout << std::endl;

    std::vector<int> vec;

    for (int i = 0; i != n; ++i) {
        vec.push_back(exponential_search(mas1, n, mas2[i]));
    }

    bool is_right = true;
    for (int i = 0; i != n; ++i) {
        if (answers[i] != vec[i]) {
            is_right = false;
            break;
        }
    }
    for (int i = 0; i != n2; ++i) {
        if (i != 0)
            std::cout << " ";
        std::cout << vec[i];
    }
    if (is_right)
        std::cout << "\nTEST 1 - OK\n" << std::endl;
    else
        std::cout << "\nTEST 1 - ERROR\n" << std::endl;
}

void test2() {
    int mas1[] = {10, 20, 30};
    int mas2[] = {8, 9, 10, 32};
    std::vector<int> answers = {0, 0, 0, 2};

    int n = 3;
    int n2 = 4;
    for (int i = 0; i != n; ++i)
        std::cout << mas1[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != n2; ++i)
        std::cout << mas2[i] << " ";
    std::cout << std::endl;

    std::vector<int> vec;

    for (int i = 0; i != n2; ++i) {
        vec.push_back(exponential_search(mas1, n, mas2[i]));
    }

    bool is_right = true;
    for (int i = 0; i != n2; ++i) {
        if (answers[i] != vec[i]) {
            is_right = false;
            break;
        }
    }
    for (int i = 0; i != n2; ++i) {
        if (i != 0)
            std::cout << " ";
        std::cout << vec[i];
    }
    if (is_right)
        std::cout << "\nTEST 2 - OK\n" << std::endl;
    else
        std::cout << "\nTEST 2 - ERROR\n" << std::endl;
}

void test3() {
    int mas1[] = {13, 15, 27, 34, 54};
    int mas2[] = {2, 72, 27, 30, 90, 53};
    std::vector<int> answers = {0, 4, 2, 2, 4, 4};

    int n = 5;
    int n2 = 6;
    for (int i = 0; i != n; ++i)
        std::cout << mas1[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != n2; ++i)
        std::cout << mas2[i] << " ";
    std::cout << std::endl;

    std::vector<int> vec;

    for (int i = 0; i != n2; ++i) {
        vec.push_back(exponential_search(mas1, n, mas2[i]));
    }

    bool is_right = true;
    for (int i = 0; i != n2; ++i) {
        if (answers[i] != vec[i]) {
            is_right = false;
            break;
        }
    }
    for (int i = 0; i != n2; ++i) {
        if (i != 0)
            std::cout << " ";
        std::cout << vec[i];
    }
    if (is_right)
        std::cout << "\nTEST 3 - OK\n" << std::endl;
    else
        std::cout << "\nTEST 3 - ERROR\n" << std::endl;
}

void test4() {
    int mas1[] = {1, 15, 26, 33, 54, 78};
    int mas2[] = {2, 72, 27, 30, 90, 53, 5};
    std::vector<int> answers = {0, 5, 2, 3, 5, 4, 0};

    int n = 6;
    int n2 = 7;
    for (int i = 0; i != n; ++i)
        std::cout << mas1[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != n2; ++i)
        std::cout << mas2[i] << " ";
    std::cout << std::endl;

    std::vector<int> vec;

    for (int i = 0; i != n2; ++i) {
        vec.push_back(exponential_search(mas1, n, mas2[i]));
    }

    bool is_right = true;
    for (int i = 0; i != n2; ++i) {
        if (answers[i] != vec[i]) {
            is_right = false;
            break;
        }
    }
    for (int i = 0; i != n2; ++i) {
        if (i != 0)
            std::cout << " ";
        std::cout << vec[i];
    }
    if (is_right)
        std::cout << "\nTEST 4 - OK\n" << std::endl;
    else
        std::cout << "\nTEST 4 - ERROR\n" << std::endl;
}

void test5() {
    int mas1[] = {1, 15, 26, 53, 54, 89, 91};
    int mas2[] = {0, -10, 27, 30, 90, 53};
    std::vector<int> answers = {0, 0, 2, 2, 5, 3};

    int n = 7;
    int n2 = 6;
    for (int i = 0; i != n; ++i)
        std::cout << mas1[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != n2; ++i)
        std::cout << mas2[i] << " ";
    std::cout << std::endl;

    std::vector<int> vec;

    for (int i = 0; i != n2; ++i) {
        vec.push_back(exponential_search(mas1, n, mas2[i]));
    }

    bool is_right = true;
    for (int i = 0; i != n2; ++i) {
        if (answers[i] != vec[i]) {
            is_right = false;
            break;
        }
    }
    for (int i = 0; i != n2; ++i) {
        if (i != 0)
            std::cout << " ";
        std::cout << vec[i];
    }
    if (is_right)
        std::cout << "\nTEST 5 - OK\n" << std::endl;
    else
        std::cout << "\nTEST 5 - ERROR\n" << std::endl;
}

void test6() {
    int mas1[] = {1, 15, 26, 53, 54, 89, 91};
    int mas2[] = {-5, -10, -20, -30, 40, 50};
    std::vector<int> answers = {0, 0, 0, 0, 3, 3};

    int n = 7;
    int n2 = 6;
    for (int i = 0; i != n; ++i)
        std::cout << mas1[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != n2; ++i)
        std::cout << mas2[i] << " ";
    std::cout << std::endl;

    std::vector<int> vec;

    for (int i = 0; i != n2; ++i) {
        vec.push_back(exponential_search(mas1, n, mas2[i]));
    }

    bool is_right = true;
    for (int i = 0; i != n2; ++i) {
        if (answers[i] != vec[i]) {
            is_right = false;
            break;
        }
    }
    for (int i = 0; i != n2; ++i) {
        if (i != 0)
            std::cout << " ";
        std::cout << vec[i];
    }
    if (is_right)
        std::cout << "\nTEST 6 - OK\n" << std::endl;
    else
        std::cout << "\nTEST 6 - ERROR\n" << std::endl;
}

void test7() {
    int mas1[] = {15, 15, 15, 15, 15, 15, 15};
    int mas2[] = {-5, -10, -20, -30, 40, 50};

    std::vector<int> answers = {0, 0, 0, 0, 0, 0};

    int n = 7;
    int n2 = 6;
    for (int i = 0; i != n; ++i)
        std::cout << mas1[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != n2; ++i)
        std::cout << mas2[i] << " ";
    std::cout << std::endl;

    std::vector<int> vec;

    for (int i = 0; i != n2; ++i) {
        vec.push_back(exponential_search(mas1, n, mas2[i]));
    }

    bool is_right = true;
    for (int i = 0; i != n2; ++i) {
        if (answers[i] != vec[i]) {
            is_right = false;
            break;
        }
    }
    for (int i = 0; i != n2; ++i) {
        if (i != 0)
            std::cout << " ";
        std::cout << vec[i];
    }
    if (is_right)
        std::cout << "\nTEST 7 - OK\n" << std::endl;
    else
        std::cout << "\nTEST 7 - ERROR\n" << std::endl;
}

void test8() {
    int mas1[] = {-50, -50, -50, -50, -50, -2, 50, 300};
    int mas2[] = {-5, -10, -20, -30, 40, 50};

    std::vector<int> answers = {5, 5, 5, 0, 6, 6};

    int n = 8;
    int n2 = 6;
    for (int i = 0; i != n; ++i)
        std::cout << mas1[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != n2; ++i)
        std::cout << mas2[i] << " ";
    std::cout << std::endl;

    std::vector<int> vec;

    for (int i = 0; i != n2; ++i) {
        vec.push_back(exponential_search(mas1, n, mas2[i]));
    }

    bool is_right = true;
    for (int i = 0; i != n2; ++i) {
        if (answers[i] != vec[i]) {
            is_right = false;
            break;
        }
    }
    for (int i = 0; i != n2; ++i) {
        if (i != 0)
            std::cout << " ";
        std::cout << vec[i];
    }
    if (is_right)
        std::cout << "\nTEST 8 - OK\n" << std::endl;
    else
        std::cout << "\nTEST 8 - ERROR\n" << std::endl;
}

void test9() {
    int mas1[] = {-50, -50, -50, -50, -50, -50, -50};
    int mas2[] = {-5, -10, -20, -30, 40, 50};

    std::vector<int> answers = {0, 0, 0, 0, 0, 0};

    int n = 7;
    int n2 = 6;
    for (int i = 0; i != n; ++i)
        std::cout << mas1[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != n2; ++i)
        std::cout << mas2[i] << " ";
    std::cout << std::endl;

    std::vector<int> vec;

    for (int i = 0; i != n2; ++i) {
        vec.push_back(exponential_search(mas1, n, mas2[i]));
    }

    bool is_right = true;
    for (int i = 0; i != n2; ++i) {
        if (answers[i] != vec[i]) {
            is_right = false;
            break;
        }
    }
    for (int i = 0; i != n2; ++i) {
        if (i != 0)
            std::cout << " ";
        std::cout << vec[i];
    }
    if (is_right)
        std::cout << "\nTEST 9 - OK\n" << std::endl;
    else
        std::cout << "\nTEST 9 - ERROR\n" << std::endl;
}

void test10() {
    int mas1[] = {-1, 0, 0, 0, 0, 0, 0};
    int mas2[] = {-5, -10, -20, -30, 40, 50};

    std::vector<int> answers = {0, 0, 0, 0, 1, 1};

    int n = 7;
    int n2 = 6;
    for (int i = 0; i != n; ++i)
        std::cout << mas1[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != n2; ++i)
        std::cout << mas2[i] << " ";
    std::cout << std::endl;

    std::vector<int> vec;

    for (int i = 0; i != n2; ++i) {
        vec.push_back(exponential_search(mas1, n, mas2[i]));
    }

    bool is_right = true;
    for (int i = 0; i != n2; ++i) {
        if (answers[i] != vec[i]) {
            is_right = false;
            break;
        }
    }
    for (int i = 0; i != n2; ++i) {
        if (i != 0)
            std::cout << " ";
        std::cout << vec[i];
    }
    if (is_right)
        std::cout << "\nTEST 10 - OK\n" << std::endl;
    else
        std::cout << "\nTEST 10 - ERROR\n" << std::endl;
}

void test11() {
    int mas1[] = {5, 5, 5, 5, 10, 10, 10};
    int mas2[] = {9, 8, 6, 5, 10, 10};

    std::vector<int> answers = {4, 4, 0, 0, 4, 4};

    int n = 7;
    int n2 = 6;
    for (int i = 0; i != n; ++i)
        std::cout << mas1[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != n2; ++i)
        std::cout << mas2[i] << " ";
    std::cout << std::endl;

    std::vector<int> vec;

    for (int i = 0; i != n2; ++i) {
        vec.push_back(exponential_search(mas1, n, mas2[i]));
    }

    bool is_right = true;
    for (int i = 0; i != n2; ++i) {
        if (answers[i] != vec[i]) {
            is_right = false;
            break;
        }
    }
    for (int i = 0; i != n2; ++i) {
        if (i != 0)
            std::cout << " ";
        std::cout << vec[i];
    }
    if (is_right)
        std::cout << "\nTEST 11 - OK\n" << std::endl;
    else
        std::cout << "\nTEST 11 - ERROR\n" << std::endl;
}

void test12() {
    int mas1[] = {-50, -50, -50, -50, -50, 0, 5};
    int mas2[] = {-5, -10, -20, -30, 40, 50};

    std::vector<int> answers = {5, 5, 5, 0, 6, 6};

    int n = 7;
    int n2 = 6;
    for (int i = 0; i != n; ++i)
        std::cout << mas1[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != n2; ++i)
        std::cout << mas2[i] << " ";
    std::cout << std::endl;

    std::vector<int> vec;

    for (int i = 0; i != n2; ++i) {
        vec.push_back(exponential_search(mas1, n, mas2[i]));
    }

    bool is_right = true;
    for (int i = 0; i != n2; ++i) {
        if (answers[i] != vec[i]) {
            is_right = false;
            break;
        }
    }
    for (int i = 0; i != n2; ++i) {
        if (i != 0)
            std::cout << " ";
        std::cout << vec[i];
    }
    if (is_right)
        std::cout << "\nTEST 12 - OK\n" << std::endl;
    else
        std::cout << "\nTEST 12 - ERROR\n" << std::endl;
}

void test13() {
    int mas1[] = {0, 1, 25, 75, 126, 200, 300};
    int mas2[] = {-5, -10, -20, -30, 40, 100};

    std::vector<int> answers = {0, 0, 0, 0, 2, 3};

    int n = 7;
    int n2 = 6;
    for (int i = 0; i != n; ++i)
        std::cout << mas1[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != n2; ++i)
        std::cout << mas2[i] << " ";
    std::cout << std::endl;

    std::vector<int> vec;

    for (int i = 0; i != n2; ++i) {
        vec.push_back(exponential_search(mas1, n, mas2[i]));
    }

    bool is_right = true;
    for (int i = 0; i != n2; ++i) {
        if (answers[i] != vec[i]) {
            is_right = false;
            break;
        }
    }
    for (int i = 0; i != n2; ++i) {
        if (i != 0)
            std::cout << " ";
        std::cout << vec[i];
    }
    if (is_right)
        std::cout << "\nTEST 13 - OK\n" << std::endl;
    else
        std::cout << "\nTEST 13 - ERROR\n" << std::endl;
}

void test14() {
    int mas1[] = {33, 39, 57, 60, 67, 77, 78, 79, 88};
    int mas2[] = {79, 33, 57, 88, 99, 67, 60, 20, 77, 79};

    std::vector<int> answers = {7, 0, 2, 8, 8, 4, 3, 0, 5, 7};

    int n = 9;
    int n2 = 10;
    for (int i = 0; i != n; ++i)
        std::cout << mas1[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i != n2; ++i)
        std::cout << mas2[i] << " ";
    std::cout << std::endl;

    std::vector<int> vec;

    for (int i = 0; i != n2; ++i) {
        vec.push_back(exponential_search(mas1, n, mas2[i]));
    }

    bool is_right = true;
    for (int i = 0; i != n2; ++i) {
        if (answers[i] != vec[i]) {
            is_right = false;
            break;
        }
    }
    for (int i = 0; i != n2; ++i) {
        if (i != 0)
            std::cout << " ";
        std::cout << vec[i];
    }
    if (is_right)
        std::cout << "\nTEST 14 - OK\n" << std::endl;
    else
        std::cout << "\nTEST 14 - ERROR\n" << std::endl;
}


#endif //TP_ALGORITHMS_TESTS_H

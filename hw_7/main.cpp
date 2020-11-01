//
// Created by Andrew Kireev on 01.11.2020.
//

//7_2. LSD для long long.
//Дан массив неотрицательных целых 64-битных чисел. Количество чисел не больше 106.
//Отсортировать массив методом поразрядной сортировки LSD по байтам.

#include <iostream>
#include <vector>


const int LONG_LONG_SIZE = 64;

template <typename T>
class Vector {
public:
    Vector() {
        size_ = capacity_ = 0;
        buf_ = nullptr;
    }

    Vector(size_t size) : size_(size), capacity_(size) {
        buf_ = new T[size];
    }

    ~Vector() {
        delete[] buf_;
    }

    size_t size() const {
        return size_;
    }

    void push_back(T value) {
        if (this->size_ == 0) {
            buf_ = new T[++capacity_];
        } else if (size_ == capacity_){
            T* old_data = buf_;
            capacity_ *= 2;
            buf_ = new T[capacity_];

            for (size_t i = 0; i < size_; ++i) {
                buf_[i] = old_data[i];
            }

            delete[] old_data;
        }
        buf_[size_++] = value;

    }

    void pop() {
        --size_;
    }

    const T& operator[](size_t index) const {
        return buf_[index];
    }

    T& operator[](size_t index) {
        return buf_[index];
    }

    T * begin() const {
        return buf_;
    }

    T * end() const {
        return buf_ + size_;
    }

    bool is_empty() const {
        return size_ == 0;
    }

private:
    T *buf_;
    size_t size_;
    size_t capacity_;
};

void countind_sort(Vector<long long>& vec, size_t digit_num) {
    Vector<long long> occurances(256);

    for (size_t i = 0; i != 256; ++i) {
        occurances[i] = 0;
    }

    for (size_t i = 0; i != vec.size(); ++i) {
        ++occurances[(vec[i] >> (8 * digit_num)) & 255];
    }

    for (size_t i = 1; i != 256; ++i) {
        occurances[i] += occurances[i - 1];
    }

    Vector<long long> tmp(vec.size());

    for (int i = vec.size() - 1; i >= 0; --i) {
        long long value = (vec[i] >> (8 * digit_num)) & 255;
        tmp[--occurances[value]] = vec[i];
    }

    for (size_t i = 0; i != vec.size(); ++i)
        vec[i] = tmp[i];
}


void lsd_sort(Vector<long long>& vec) {

    for (size_t i = 0; i != LONG_LONG_SIZE; ++i)
        countind_sort(vec, i);
}


int main(int argc, char **argv) {
    int n;
    std::cin >> n;
    Vector<long long> vec(n);

    for (size_t i = 0; i != n; ++i) {
        std::cin >> vec[i];
    }

    lsd_sort(vec);

    for (size_t i = 0; i != n; ++i) {
        std::cout << vec[i] << ' ';
    }

    return 0;
}
//
// Created by Andrew Kireev on 28.10.2020.
//

#include <iostream>
#include <string>
#include <vector>


int binary_search(int vec[], int left, int right, int key, int size)
{   int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;

        if (vec[mid] == key)
            return mid;

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
    return mid;
}


template<typename T>
class Stack {
public:
    Stack() : capacity_(0), size_(0), top_(nullptr) {
    }

    ~Stack() {
        delete [] top_;
    }

    void push(float value) {
        if (capacity_ == 0) {
            top_ = new T[5];
            capacity_ = 5;
        }
        if (size_ == capacity_) {
            resize();
        }
        top_[size_] = value;
        ++size_;
    }

    void resize() {
        T *old_top = top_;
        capacity_ *= 2;
        top_ = new T[capacity_];
        for (int i = 0; i != size_; ++i) {
            top_[i] = old_top[i];
        }
        delete[] old_top;
    }

    void print_stack() const {
        for (int i = 0; i != size_; ++i)
            std::cout << top_[i] << " ";
        std::cout << std::endl;
    }

    float pop() {
        if (size_ > 0) {
            --size_;
            return top_[size_];
        }
        return -1;
    }

    float top() const{
        return top_[size_ - 1];
    }

    bool is_clear() const {
        return (size_ == 0);
    }

    size_t size() const {
        return size_;
    }

private:
    T *top_;
    size_t size_;
    size_t capacity_;
};


void stack_anagram(std::string string1, std::string string2) {
    std::string new_str;

    Stack<char> stack;
    std::vector<char> vec;
    int i = 0;

    for (auto symbol : string1) {
        stack.push(symbol);
        if (stack.top() == string2[i]) {
             vec.push_back(stack.pop());
            ++i;
        }
    }

    while (stack.size() != 0) {
        if (stack.top() == string2[i]) {
             vec.push_back(stack.pop());
            ++i;
        }
        else {
            std::cout << "NO";
            return ;
        }
    }


    for (int j = 0; j != vec.size(); ++j) {
        if (vec[j] != string2[j]) {
            std::cout << "NO";
            break;
        }
    }
    std::cout << "YES";
}


int main(int argc, char **argv) {
    std::string first, second;

    std::cin >> first;
    std::cin >> second;
    if (first.size() != second.size()) {
        std::cout << "NO";
        return 0;
    }
    stack_anagram(first, second);


    return 0;
}

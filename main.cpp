#include <iostream>

template <typename T>
class Stack {
public:
    Stack() : top_(nullptr), size_(0) {}

    ~Stack() {
        delete [] top_;
    }

    void push(T value) {
        if (size_ == 0) {
            top_ = new T;
            top_[0] = value;
            ++size_;
        } else {
            T *old_top = top_;
            top_ = new T[++size_];
            for (int i = 0; i != size_ - 1; ++i) {
                top_[i] = old_top[i];
            }
            top_[size_ - 1] = value;
            delete[] old_top;
        }
    }

    void print_stack() const {
        for (int i = 0; i != size_; ++i)
            std::cout << top_[i] << " ";
        std::cout << std::endl;
    }

    void pop() {
        if (size_ > 0)
            --size_;
    }

    T top() const{
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
};



int main() {
    Stack<int> stack;

    for (int i = 1; i != 10; ++i)
        stack.push(i);
    stack.print_stack();
    std::cout << "size = " << stack.size() << std::endl;

    for (int i = 1; i != 9; ++i) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << std::endl;

    for (int i = 1; i != 9; ++i)
        stack.pop();
    stack.print_stack();
    return 0;
}

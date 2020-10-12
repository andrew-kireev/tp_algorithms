//В первой строке количество команд n. n ≤ 1000000.
//Каждая команда задаётся как 2 целых числа: a b.
//a = 1 - push front
//        a = 2 - pop front
//        a = 3 - push back
//        a = 4 - pop back
//        Команды добавления элемента 1 и 3 заданы с неотрицательным параметром b.
//Для очереди используются команды 2 и 3. Для дека используются все четыре команды.
//Если дана команда pop*, то число b - ожидаемое значение. Если команда pop вызвана для пустой структуры данных, то ожидается “-1”.
//Формат выходных данных.
//Требуется напечатать YES - если все ожидаемые значения совпали. Иначе, если хотя бы одно ожидание не оправдалось, то напечатать NO.

//3_3. Реализовать очередь с помощью двух стеков. Использовать стек, реализованный с помощью динамического буфера.
//Требования: Очередь должна быть реализована в виде класса. Стек тоже должен быть реализован в виде класса.


#include <iostream>

class Stack {
public:
    Stack() : capacity_(0), size_(0), top_(nullptr) {
    }

    ~Stack() {
        delete [] top_;
    }

    void push(float value) {
        if (capacity_ == 0) {
            top_ = new float[5];
            capacity_ = 5;
        }
        if (size_ == capacity_) {
            resize();
        }
        top_[size_] = value;
        ++size_;
    }

    void resize() {
        float *old_top = top_;
        capacity_ *= 2;
        top_ = new float[capacity_];
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
    float *top_;
    size_t size_;
    size_t capacity_;
};


class Queue {
public:
    Queue() {}

    void push(float value) {
        in_.push(value);
    }

    void move_elements() {
        while (!in_.is_clear()) {
            out_.push(in_.pop());
        }
    }

    int pop() {
        if (out_.size() != 0 || in_.size() != 0) {
            if (out_.size() != 0)
                return out_.pop();
            else {
                move_elements();
                return out_.pop();
            }
        }
        return -1;
    }

    float top() {
        if (out_.size() != 0 || in_.size() != 0) {
            if (out_.size() != 0)
                return out_.top();
            else {
                move_elements();
                return out_.top();
            }
        }
        return -1;
    }

    bool is_clear() const {
        return (in_.is_clear() && out_.is_clear());
    }

private:
    Stack in_;
    Stack out_;
};

int main() {
    Queue queue;

    int n = 0;
    int first, second;
    bool all_right = true;

    std::cin >> n;
    for (int i = 0; i != n; ++i) {
        std::cin >> first >> second;
        if (first == 3)
            queue.push(second);
        else if (first == 2) {
            if (queue.pop() != second) {
                all_right = false;
                break;
            }
        }
    }
    if (all_right)
        std::cout << "YES";
    else
        std::cout << "NO";
    return 0;
}
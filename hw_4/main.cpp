#include <iostream>

template <typename T>
class Vector {
public:
    Vector() {
        size_ = capacity_ = 0;
        buf_ = nullptr;
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


template <typename T>
class DefaultComparator{
public:
    bool operator()(const T &lhs, const T &rhs) const {
        return lhs < rhs;
    }
};


template <typename T>
class DefaultComparatorLessEqual{
public:
    bool operator()(const T &lhs, const T &rhs) const {
        return lhs <= rhs;
    }
};

struct Time {
    size_t arraving;
    size_t departure;
    bool operator<(const Time &other) const {
        return this->departure < other.departure;
    }

    bool operator>(const Time &other) const {
        return this->departure > other.departure;
    }

    bool operator==(const Time &other) const {
        return this->departure == other.departure;
    }

    bool operator>=(const Time &other) const {
        return this->departure >= other.departure;
    }

    bool operator<=(const Time &other) const {
        return this->departure <= other.departure;
    }

    friend std::ostream& operator<< (std::ostream &out, const Time& time);
};

std::ostream& operator<< (std::ostream &out, const Time& time) {
    out << time.departure;
    return out;
}


template<class T, class Comparator = DefaultComparator<T>,
        class ComparatorLessEqual = DefaultComparatorLessEqual<T>>
class Heap {
public:

    Heap() = default;

    Heap(DefaultComparator<T> comp, DefaultComparatorLessEqual<T> comp_less) : comp_(comp),
                                comp_less_eq_(comp_less), max_size_(0) {}

    void push_back(T value) {
        data_.push_back(value);
        sift_up(data_.size() - 1);
        if (data_.size() > max_size_)
            max_size_ = data_.size();
    }

    T pop() {
        T elem = data_[0];

        data_[0] = data_[data_.size() - 1];
        data_.pop();
        if (!data_.is_empty())
            sift_down(0);
        return elem;
    }

    void build_heap() {
        for (int i = data_.size() / 2 - 1; i >= 0; --i)
            sift_down(i);
    }

    const T& top() const {
        if (data_.size())
            return data_[0];
    }

    size_t size() const {
        return data_.size();
    }

    bool is_empty() const {
        return data_.is_empty();
    }

    void print_heap() const {
        for (auto item : data_) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }

    int max_size() const {
        return max_size_;
    }

private:
    Vector<T> data_;
    Comparator comp_ = DefaultComparator<T>();
    ComparatorLessEqual comp_less_eq_ = DefaultComparatorLessEqual<T>();

    int max_size_ = 0;


    void sift_up(size_t index) {
        while (index > 0) {
            size_t parent_index = (index - 1) / 2;
            if (comp_less_eq_(data_[parent_index], data_[index]))
                return;
            std::swap(data_[parent_index], data_[index]);
            index = parent_index;
        }
    }

    void sift_down(size_t index) {
        size_t left_son = 2 * index + 1;
        size_t right_son = 2 * index + 2;
        size_t largest = index;

        if (left_son < data_.size() && comp_(data_[left_son], data_[index]))
            largest = left_son;

        if (right_son < data_.size() && comp_(data_[right_son], data_[largest]))
            largest = right_son;
        if (largest != index) {
            std::swap(data_[largest], data_[index]);
            sift_down(largest);
        }
    }
};


int main(int argc, char **argv) {
    Heap<Time> hp;

    int n;

    std::cin >> n;
    size_t arriving, derapture;

    for (size_t i = 0; i != n; ++i) {
        std::cin >> arriving >> derapture;
        if (!hp.is_empty() && arriving > hp.top().departure) {
            hp.pop();
            hp.push_back({arriving, derapture});
        } else
            hp.push_back({arriving, derapture});
    }
    std::cout << hp.max_size();

    return 0;
}

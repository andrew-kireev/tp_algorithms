//
// Created by Andrew Kireev on 17.10.2020.
//

#include <iostream>


template <typename T>
class Vector {
public:
    Vector() {
        size_ = capacity_ = 0;
        buf_ = nullptr;
    }

    Vector(size_t size) {
        buf_ = new T[size];
        size_ = size;
        capacity_ = size;
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


struct Date {
    size_t day;
    size_t month;
    size_t year;

    bool born;

    bool operator<(const Date &other) {
        if (this->year < other.year)
            return true;
        else if (this->year == other.year && this->month < other.month)
            return true;
        else if (this->year == other.year && this->month == other.month &&
        this->day < other.day)
            return true;
        return false;
    }
    friend std::ostream& operator<< (std::ostream &out, const Date& date);
    friend std::istream& operator>> (std::istream &in, Date &date);
};

std::ostream& operator<< (std::ostream &out, const Date& date) {
    out << date.day << ' ' << date.month << ' ' << date.year << std::endl;
    return out;
}

std::istream& operator>> (std::istream &in, Date& date) {
    in >> date.day;
    in >> date.month;
    in >> date.year;
    return in;
}

struct Years_of_life {
    Date birth_date;
    Date death_date;
};


template <typename T>
void merge(T *vec, size_t left, size_t mid, size_t right) {
    int pos_fist = left;
    int pos_second = mid + 1;
    int  pos_tmp = 0;

//    Vector<T> tmp(right - left + 1);
    T *tmp = new T[right - left + 1];


    while (pos_fist <= mid && pos_second <= right) {
        if (vec[pos_fist] < vec[pos_second])
            tmp[pos_tmp++] = vec[pos_fist++];
        else
            tmp[pos_tmp++] = vec[pos_second++];
    }

    while (pos_second <= right)   // пока вторая последовательность непуста
        tmp[pos_tmp++] = vec[pos_second++];
    while (pos_fist <= mid)  // пока первая последовательность непуста
        tmp[pos_tmp++] = vec[pos_fist++];

    // скопировать буфер temp в a[lb]...a[ub]
    for (pos_tmp = 0; pos_tmp < right - left + 1; pos_tmp++)
        vec[left + pos_tmp] = tmp[pos_tmp];

}


template <typename T>
void merge_sort(T *vec, size_t left, size_t right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(vec, left, mid);
        merge_sort(vec, mid + 1, right);

        merge(vec, left, mid, right);
    }
}


int count_contemporaries(const Vector<Date>& vec) {
    int count = 0;
    int max_count = 0;

    for (auto date : vec) {
        if (date.born)
            ++count;
        else
            --count;
        if (count > max_count)
            max_count = count;
    }
    return max_count;
}


int main(int argc, char **argv) {

//    Vector<Date> dates;

    Date *dates = new Date[6];

    size_t n;
    std::cin >> n;
    int j = 0;
    for (int i = 0; i != n; ++i) {
        Date date1, date2;
        std::cin >> date1 >> date2;
        date1.born = true;
        date2.born = false;
        dates[j] = date1;
        ++j;
        dates[j] = date2;
        ++j;
//        dates.push_back(date1);
//        dates.push_back(date2);
    }


//    for (auto date : dates)
//        std::cout << date;

    merge_sort(dates, 0, 6);

    for (int i = 0; i != 6; ++i) {
        std::cout << dates[i];
    }

//    for (auto date : dates)
//        std::cout << date;
//
//    std::cout << date[];

//    std::cout << count_contemporaries(dates);


    return 0;
}
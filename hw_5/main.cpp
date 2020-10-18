//
// Created by Andrew Kireev on 17.10.2020.
//

#include <iostream>
#include <algorithm>
#include <vector>


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

    bool operator<=(const Date &other) {
        if (this->year <= other.year)
            return true;
        else if (this->year == other.year && this->month <= other.month)
            return true;
        else if (this->year == other.year && this->month == other.month &&
                 this->day <= other.day)
            return true;
        return false;
    }

    friend std::ostream& operator<< (std::ostream &out, const Date& date);
    friend std::istream& operator>> (std::istream &in, Date &date);
};

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.year < rhs.year)
        return true;
    else if (lhs.year == rhs.year && lhs.month < rhs.month)
        return true;
    else if (lhs.year == rhs.year && lhs.month == rhs.month &&
             lhs.day < rhs.day)
        return true;
    return false;
}

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


//template <typename T>
//void merge(std::vector<T>& vec, size_t left, size_t mid, size_t right) {
//    int pos_fist = left;
//    int pos_second = mid + 1;
//    int  pos_tmp = 0;
//
//    std::vector<T> tmp(right - left + 1);
////    T *tmp = new T[right - left + 1];
//
//
//    while (pos_fist <= pos_second && pos_second <= right) {
//        if (vec[pos_fist] < vec[pos_second])
//            tmp[pos_tmp++] = vec[pos_fist++];
//        else
//            tmp[pos_tmp++] = vec[pos_second++];
//    }
//
//    while (pos_second <= right)   // пока вторая последовательность непуста
//        tmp[pos_tmp++] = vec[pos_second++];
//    while (pos_fist <= mid)  // пока первая последовательность непуста
//        tmp[pos_tmp++] = vec[pos_fist++];
//
//    // скопировать буфер temp в a[lb]...a[ub]
//    for (pos_tmp = 0; pos_tmp < right - left + 1; pos_tmp++)
//        vec[left + pos_tmp] = tmp[pos_tmp];
//
//}

template <typename T>
void merge(T vec[], int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    T L[n1];
    T M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = vec[left + i];
    for (int j = 0; j < n2; j++)
        M[j] = vec[mid + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = left;


    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = M[j];
            j++;
        }
        k++;
    }


    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vec[k] = M[j];
        j++;
        k++;
    }
}


template <typename T>
void merge_sort(T arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int count_contemporaries(Date dates[], int size) {
    int count = 0;
    int max_count = 0;

    for (int i = 0; i != size; ++i) {
        if (dates[i].born)
            ++count;
        else
            --count;
        if (count > max_count)
            max_count = count;
    }
    return max_count;
}


int main(int argc, char **argv) {


    size_t n;
    std::cin >> n;

    Date dates[n * 2];

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
    }

    for (int i = 0; i != n * 2; ++i)
        std::cout << dates[i];

    std::cout << std::endl;


    merge_sort(dates, 0, n * 2);

    for (int i = 0; i != n * 2; ++i)
        std::cout << dates[i];

    std::cout << std::endl;

    std::cout << count_contemporaries(dates, n * 2);


    return 0;
}
////
//// Created by Andrew Kireev on 17.10.2020.
////

////Группа людей называется современниками если был такой момент, когда они могли собраться вместе.
////Для этого в этот момент каждому из них должно было  уже исполниться 18 лет, но ещё не исполниться 80 лет.
////Дан список Жизни Великих Людей. Необходимо получить максимальное количество современников.
////В день 18летия человек уже может принимать участие в собраниях, а в день 80летия и в день смерти уже не может.
////Замечание. Человек мог не дожить до 18-летия, либо умереть в день 18-летия.
////В этих случаях принимать участие в собраниях он не мог.

#include <iostream>

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

    bool operator<=(const Date &other) const {
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


template <typename T>
class DefaultComparator{
public:
    bool operator()(const T &lhs, const T &rhs) const {
        return lhs <= rhs;
    }
};


template <typename T, typename Comparator = DefaultComparator<T>>
void merge(T vec[], int left, int mid, int right,
           Comparator comp = DefaultComparator<T>()) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    T* tmp_left = new T[n1];
    T* tmp_right = new T[n2];

    for (int i = 0; i < n1; ++i)
        tmp_left[i] = vec[left + i];
    for (int i = 0; i < n2; i++)
        tmp_right[i] = vec[mid + 1 + i];

    int pos_first = 0, pos_second = 0;
    while (pos_first < n1 && pos_second < n2)
        if (comp(tmp_left[pos_first], tmp_right[pos_second]))
            vec[left++] = tmp_left[pos_first++];
        else
            vec[left++] = tmp_right[pos_second++];


    while (pos_first < n1)
        vec[left++] = tmp_left[pos_first++];

    while (pos_second < n2)
        vec[left++] = tmp_right[pos_second++];
}


template <typename T, typename Comparator = DefaultComparator<T>>
void merge_sort(T arr[], int left, int right,
        Comparator comp = DefaultComparator<T>()) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


// Корректируем дату рождения, смерти так, чтобы получить промежутов, в котором человек
// мог быть современником
void check_dates(Date& birthday, Date& deth) {
    Date new_deth = birthday;
    new_deth.year += 80;
    new_deth.born = false;
    Date new_birthday = birthday;
    new_birthday.born = true;
    new_birthday.year += 18;
    birthday = new_birthday;
    if (new_birthday < deth)
        birthday = new_birthday;
    if (new_deth < deth)
        deth = new_deth;
    deth.day--;
    if (deth < birthday) {
        birthday.year = 0;
        deth.year = 0;
    }
}

// Считаем современников
int count_contemporaries(Date dates[], int size) {
    int count = 0;
    int max_count = 0;

    for (int i = 0; i != size; ++i) {
        if (dates[i].year == 0)
            continue;
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
        check_dates(date1, date2);
        dates[j] = date1;
        ++j;
        dates[j] = date2;
        ++j;
    }

    merge_sort(dates, 0, n * 2);

    std::cout << count_contemporaries(dates, n * 2);
    return 0;
}
//
// Created by Andrew Kireev on 17.11.2020.
//

//Реализуйте структуру данных типа “множество строк” на основе динамической хеш-таблицы с открытой адресацией.
// Хранимые строки непустые и состоят из строчных латинских букв.
//Хеш-функция строки должна быть реализована с помощью вычисления значения многочлена методом Горнера.
//Начальный размер таблицы должен быть равным 8-ми.
// Перехеширование выполняйте при добавлении элементов в случае, когда коэффициент заполнения таблицы достигает 3/4.
//Структура данных должна поддерживать операции добавления строки в множество,
// удаления строки из множества и проверки принадлежности данной строки множеству.
//1_2. Для разрешения коллизий используйте двойное хеширование.



#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>



int hash_1(const std::string& string, int table_size) {
    int hash = 0;
    int hasher = 11;

    std::accumulate(string.begin(), string.end(), 0,
            [&hash, hasher, table_size](int init, char c) {
        return hash += (hash * hasher + c) % table_size;
    });
    return hash % table_size;
}

int hash_2(const std::string& string, int table_size) {
    int hash = 0;
    int hasher = 17;

    std::accumulate(string.begin(), string.end(), 0,
                    [&hash, hasher, table_size](int init, char c) {
                        return hash += (hash * hasher + c) % table_size;
                    });
    return (2 * hash + 1) % table_size;
}

template<class T>
struct Hash1;

template<> struct Hash1<std::string> {
    size_t operator() (const std::string& key, int table_size) const {
        return hash_1(key, table_size);
    }
};

template<class T>
struct Hash2;

template<> struct Hash2<std::string> {
    size_t operator() (const std::string& key, int table_size) const {
        return hash_2(key, table_size);
    }
};

template <typename Value, typename Hash_1 = Hash1<std::string>,
        typename Hash_2 = Hash2<std::string>>
class HashTable {

    struct TableNode {
        TableNode() : is_deleted_(true) {}

        explicit TableNode(Value& value) : value_(value) {}
        Value value_;
        bool is_deleted_ = false;
    };

public:
    HashTable() {
        data_.resize(8);
    }


    HashTable(int capacity) {
        data_.resize(capacity);
    }

    bool insert(const std::string& string) {
        if (size_ + 1 >= (data_.capacity() * 0.75))
            re_hash();
        int string_hash_1 = hash_1_(string, data_.capacity());
        int string_hash_2 = hash_2_(string, data_.capacity());

        if (at(string) == true)
            return false;
        for (size_t i = 0; i != data_.capacity(); ++i) {
            int current_hash = (string_hash_1 + i * string_hash_2) % data_.capacity();
            if (data_[current_hash].is_deleted_ == true) {
                data_[current_hash].value_ = string;
                data_[current_hash].is_deleted_ = false;
                ++size_;
                return true;
            }
        }
        return false;
    }

    bool at(const std::string& string) const {
        int string_hash_1 = hash_1_(string, data_.capacity());
        int string_hash_2 = hash_2_(string, data_.capacity());


        for (size_t i = 0; i != data_.capacity(); ++i) {
            int current_hash = (string_hash_1 + i * string_hash_2) % data_.capacity();
            if (data_[current_hash].value_ == string && data_[current_hash].is_deleted_ == false)
                return true;
            else if(data_[current_hash].value_.size() == 0
                    && data_[current_hash].is_deleted_ == true)
                return false;
        }

        return false;
    }

    bool erase(const std::string& string) {
        if (at(string)) {
            int string_hash_1 = hash_1_(string, data_.capacity());
            int string_hash_2 = hash_2_(string, data_.capacity());

            for (size_t i = 0; i != data_.capacity(); ++i) {
                int current_hash = (string_hash_1 + i * string_hash_2) % data_.capacity();
                if (data_[current_hash].value_ == string && data_[current_hash].is_deleted_ == false) {
                    data_[current_hash].is_deleted_ = true;
                    --size_;
                    return true;
                }
            };
        }
        return false;
    }

    void print_table() const {
        for (const auto& it : data_) {
            if (it.is_deleted_ == false)
                std::cout << it.value_ << std::endl;
        }
    }

private:
    std::vector<TableNode> data_;
    size_t size_ = 0;
    Hash_1 hash_1_;
    Hash_2 hash_2_;

    void re_hash() {
        std::vector<TableNode> tmp_data = std::move(data_);
        data_.resize(tmp_data.capacity() * 2);
        size_ = 0;

        for (auto it : tmp_data) {
            if (it.is_deleted_  == false)
                insert(it.value_);
        }
    }
};



void test() {
    HashTable<std::string> hash_table;

    std::vector<char> signs =
            {'+', '-', '+', '?', '+', '+',
             '-', '-', '+', '?', '+'};

    std::vector<std::string> strings =
            {"privet", "kak", "tut", "ura", "op",
             "1234", "qwerty", "kak", "op", "ura", "kak"};

    std::vector<std::string> expected =
            {"OK", "FAIL", "OK", "FAIL", "OK",
             "OK", "FAIL", "FAIL", "FAIL", "FAIL", "OK"};

    bool res = false;
    std::string status;

    for (int i = 0; i != expected.size(); ++i) {
        switch (signs[i]) {
            case '+':
                res = hash_table.insert(strings[i]);
                break;
            case '-':
                res = hash_table.erase(strings[i]);
                break;
            case '?':
                res = hash_table.at(strings[i]);
                break;
        }
        if (res) {
            status = "OK";
        } else {
            status = "FAIL";
        }
        if (status == expected[i])
            std::cout << strings[i] << ": ВСЕ ОК!" << std::endl;
        else
            std::cout << strings[i] << ": ОШИБКА!" << std::endl;
    }
}


int main(int argc, char **argv) {
    std::string key;
    char operation = '\0';

    HashTable<std::string> hash_table;
    while (std::cin >> operation >> key) {
        bool res = false;
        switch (operation) {
            case '+':
                res = hash_table.insert(key);
                break;
            case '-':
                res = hash_table.erase(key);
                break;
            case '?':
                res = hash_table.at(key);
                break;
            default:
                return 1;
        }
        if (res) {
            std::cout << "OK" << std::endl;
        } else {
            std::cout << "FAIL" << std::endl;
        }
    }
//    test();
    return 0;
}
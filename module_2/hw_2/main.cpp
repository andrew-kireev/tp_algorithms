//
// Created by Andrew Kireev on 20.11.2020.
//
//Дано число N < 106 и последовательность целых чисел из [-231..231] длиной N.
//Требуется построить бинарное дерево, заданное наивным порядком вставки.
//Т.е., при добавлении очередного числа K в дерево с корнем root, если root→Key ≤ K,
// то узел K добавляется в правое поддерево root; иначе в левое поддерево root.
//Требования: Рекурсия запрещена. Решение должно поддерживать передачу функции сравнения снаружи.
//
//2_3. Выведите элементы в порядке post-order (снизу вверх).


#include <stack>
#include <iostream>
#include <memory>

template <typename T>
class DefaultComparator{
public:
    bool operator()(const T &lhs, const T &rhs) const {
        return lhs < rhs;
    }
};

template <typename Value, typename Comparator = DefaultComparator<Value>>
class BinaryTree {
    struct Node {
        Node() = default;
        explicit Node(Value value) : value_(value) {}
        
        std::shared_ptr<Node> left_ = nullptr;
        std::shared_ptr<Node> right_ = nullptr;
        Value value_;
    };

public:
    BinaryTree() = default;

    void insert(Value value) {
        if (root_ == nullptr) {
            root_ = std::make_shared<Node>(value);
            return;
        }

        std::shared_ptr<Node> cur_node = root_;
        std::shared_ptr<Node> parent;
        bool right_or_left = false;
        while (cur_node != nullptr) {
            if (comp_(value, cur_node->value_)) {
                parent = cur_node;
                cur_node = cur_node->left_;
                right_or_left = false;
                continue;
            }

            if (!comp_(value, cur_node->value_)) {
                parent = cur_node;
                cur_node = cur_node->right_;
                right_or_left = true;
                continue;
            }
            break;
        }
        cur_node = std::make_shared<Node>(value);
        if (right_or_left)
            parent->right_ = cur_node;
        else
            parent->left_ = cur_node;
    }


    void post_oder(std::function<void(Value&)> func) {
        if (root_ == nullptr)
            return;

        std::stack<std::shared_ptr<Node>> stack1, stack2;

        stack1.push(root_);
        std::shared_ptr<Node> node;

        while (!stack1.empty()) {
            node = stack1.top();
            stack1.pop();
            stack2.push(node);

            if (node->left_)
                stack1.push(node->left_);

            if (node->right_)
                stack1.push(node->right_);
        }

        while (!stack2.empty()) {
            node = stack2.top();
            stack2.pop();
            func(node->value_);
        }
    }
private:
    std::shared_ptr<Node> root_;
    Comparator comp_;
};


int main(int argc, char **argv) {
    BinaryTree<int> tree;

    int n, number;
    std::cin >> n;
    for (int i = 0; i != n; ++i) {
        std::cin >> number;
        tree.insert(number);
    }

    tree.post_oder([](int& value){
        std::cout << value << " ";
    });

    return 0;
}

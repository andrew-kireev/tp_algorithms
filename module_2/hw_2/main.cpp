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

        ~Node() = default;
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



    int min(int left, int right) {
    	if (left < right)
    		return left;
    	return right;
    }


	int min_depth()
	{
		if (root_ == nullptr)
			return 0;
		return min_depth(root_);
	}

	int min_depth(std::shared_ptr<Node> node)
	{
		if (node == nullptr)
			return 0;
		return std::min(min_depth(node->left_), min_depth(node->right_)) + 1;
	}

    ~BinaryTree() {
        if (root_ == nullptr)
            return;

        std::stack<std::shared_ptr<Node>> queue;

        queue.push(root_);
        std::shared_ptr<Node> node;

        while (!queue.empty()) {
            node = queue.top();
            queue.pop();

            if (node->left_) {
                queue.push(node->left_);
                node->left_ = nullptr;
            }

            if (node->right_) {
                queue.push(node->right_);
                node->right_ = nullptr;
            }
        }
        if (node->left_ == nullptr && node->right_ == nullptr)
            node.reset();
        else
            queue.push(node);
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

//    tree.post_oder([](int& value){
//        std::cout << value << " ";
//    });

	std::cout << tree.min_depth() << std::endl;

    return 0;
}

//
// Created by Andrew Kireev on 21.11.2020.
//

#include <iostream>
#include <memory>
#include <queue>
#include <stack>



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

    size_t max_width() const {
        size_t max_width = 0;
        std::queue<std::shared_ptr<Node>> layer;

        layer.push(root_);
        while (!layer.empty()) {
            size_t cur_width = layer.size();
            if (cur_width > max_width)
                max_width = cur_width;

            for (size_t i = 0; i != cur_width; ++i) {
                std::shared_ptr<Node> tmp_node = layer.front();
                layer.pop();
                if (tmp_node->left_)
                    layer.push(tmp_node->left_);
                if (tmp_node->right_)
                    layer.push(tmp_node->right_);
            }
        }
        return max_width;
    }

private:
    std::shared_ptr<Node> root_;
    Comparator comp_;
};

template <typename Value>
class Treap {
    struct TreapNode {

        TreapNode() = default;

        TreapNode(Value& value, size_t priority) : value_(value),
        priority_(priority) {}

        Value value_;
        size_t priority_;
        std::shared_ptr<TreapNode> left_;
        std::shared_ptr<TreapNode> right_;
    };
public:

    void insert(Value& value, size_t priority) {
        auto node = std::make_shared<TreapNode>(TreapNode(value, priority));

        if (root_ == nullptr) {
            root_ = node;
            return;
        }
        std::shared_ptr<TreapNode> cur_node = root_, prev_node = root_;

        while (cur_node != nullptr && priority <= cur_node->priority_) {
            prev_node = cur_node;
            if (value <= cur_node->value_)
                cur_node = cur_node->left_;
            else
                cur_node = cur_node->right_;
        }

        split(cur_node, value, node->left_, node->right_);
        if (cur_node == root_)
            root_ = node;
        else if (value <= prev_node->value_)
            prev_node->left_ = node;
        else
            prev_node->right_ = node;
    }

    int max_width() const {
        size_t max_width = 0;
        std::queue<std::shared_ptr<TreapNode>> layer;

        layer.push(root_);
        while (!layer.empty()) {
            size_t cur_width = layer.size();
            if (cur_width > max_width)
                max_width = cur_width;

            for (size_t i = 0; i != cur_width; ++i) {
                std::shared_ptr<TreapNode> tmp_node = layer.front();
                layer.pop();
                if (tmp_node->left_)
                    layer.push(tmp_node->left_);
                if (tmp_node->right_)
                    layer.push(tmp_node->right_);

            }
        }
        return max_width;
    }

    void print() {
        print(root_);
    }

    void print(std::shared_ptr<TreapNode> node) {
        if (node != nullptr) {
            std::cout << node->value_ << " " << node->priority_ << std::endl;
            print(node->left_);
            print(node->right_);
        }
    }


private:
    std::shared_ptr<TreapNode> root_;

    void split(std::shared_ptr<TreapNode>& cur_node, int key,
               std::shared_ptr<TreapNode>& left, std::shared_ptr<TreapNode>& right) {

        if (cur_node == nullptr) {
            left = nullptr;
            right = nullptr;
        } else if (cur_node->value_ <= key) {
            split(cur_node->right_, key, cur_node->right_, right);
            left = cur_node;
        } else {
            split(cur_node->left_, key, left, cur_node->left_);
            right = cur_node;
        }
    }

    std::shared_ptr<TreapNode> merge(std::shared_ptr<TreapNode>& left, std::shared_ptr<TreapNode>& right) {
        if (left == nullptr || right == nullptr)
            return left == nullptr ? right : left;

        if (left->priority_ > right->priority_) {
            left->right_ = merge(left->right_, right);
            return left;
        } else {
            right->left_ = merge(left, right->left_);
            return right;
        }
    }
};


int main(int argc, char **argv) {
    Treap<int> treap;
    BinaryTree<int> binary_tree;
    size_t n, priority;
    int number;

    std::cin >> n;
    for (size_t i = 0; i != n; ++i) {
        std::cin >> number >> priority;
        treap.insert(number, priority);
        binary_tree.insert(number);
    }

    treap.print();
//    std::cout << treap.max_width() - binary_tree.max_width();
    return 0;
}
//
// Created by Andrew Kireev on 06.12.2020.
//

//4_1. Солдаты. В одной военной части решили построить в одну шеренгу по росту.
//Т.к. часть была далеко не образцовая, то солдаты часто приходили не вовремя,
//а то их и вовсе приходилось выгонять из шеренги за плохо начищенные сапоги.
//Однако солдаты в процессе прихода и ухода должны были всегда быть выстроены
//по росту – сначала самые высокие, а в конце – самые низкие. За расстановку
//солдат отвечал прапорщик, который заметил интересную особенность – все солдаты
//в части разного роста. Ваша задача состоит в том, чтобы помочь прапорщику правильно
//расставлять солдат, а именно для каждого приходящего солдата указывать, перед каким
//солдатом в строе он должен становится.
//Требования: скорость выполнения команды - O(log n).


#include <iostream>
#include <vector>
#include <memory>
#include <stack>



template <class T>
struct DefaultComparator {
public:
	bool operator()(const T& lhs, const T& rhs) const {
		return lhs < rhs;
	}
};

template <class Key, class Value,
		class Comparator = DefaultComparator<Key>>
class AvlTree {
	struct Node {

		explicit Node(Key _key) : key_(_key), position_(1), height(1) {}
		std::shared_ptr<Node> left;
		std::shared_ptr<Node> right;

		Key key_;
		Value position_;

		uint8_t height;

		Node(const Key& k, const Value& v) :
				left(nullptr), right(nullptr),
				key_(k), position_(v), height(1) {
		}
	};
public:
	explicit AvlTree(Comparator comp_ = Comparator()) :
			root_(nullptr), nodes_amount_(0), comp_(comp_) {}

	~AvlTree() {
		root_.reset();
	}

	void insert(const Key& key, Value& value) {
		root_ = insert(key, value, root_);
	}

	void erase(const Key& key) {
		root_ = erase(root_, key);
	}
private:
	std::shared_ptr<Node> root_;
	size_t nodes_amount_;

	Comparator comp_;

	std::shared_ptr<Node> insert(const Key& key, Value& value, std::shared_ptr<Node> node) {
		if (!node) {
			nodes_amount_++;
			return std::make_shared<Node>(key);
		}

		++node->position_;

		if (comp_(key, node->key_)) {
			value += find_position(node->right) + 1;
			node->left = insert(key, value, node->left);
		} else {
			node->right = insert(key, value, node->right);
		}
		return balance(node);
	}

	int find_position(std::shared_ptr<Node> node) {
		if (node == nullptr)
			return 0;
		return node->position_;
	}

	void fix_position(std::shared_ptr<Node> p) {
		int left_h = find_position(p->left);
		int right_h = find_position(p->right);

		p->position_ = left_h + right_h + 1;
	}

	std::shared_ptr<Node> fix_positions(std::stack<std::shared_ptr<Node>>& nodes,
					   std::shared_ptr<Node> cur_node) {
		while (!nodes.empty()) {
			std::shared_ptr<Node> node = nodes.top();
			--node->position_;

			if (node->key_ > cur_node->key_)
				node->left = cur_node;
			else
				node->right = cur_node;

			cur_node = balance(node);
			nodes.pop();
		}
		return cur_node;
	}

	std::shared_ptr<Node> erase(std::shared_ptr<Node> cur_node, int position) {
		if (cur_node == nullptr)
			return nullptr;
		if (position >= cur_node->position_)
			return cur_node;

		int current = 0;
		std::stack<std::shared_ptr<Node>> nodes;

		while (true) {
			int nodes_right = find_position(cur_node->right);
			if (position - current > nodes_right) {
				nodes.push(cur_node);
				cur_node = cur_node->left;
				current += nodes_right + 1;
			}
			else if (position - current < nodes_right) {
				if (cur_node->right != nullptr) {
					nodes.push(cur_node);
					cur_node = cur_node->right;
				} else
					break;
			} else {
				std::shared_ptr<Node> left = cur_node->left;
				std::shared_ptr<Node> right = cur_node->right;
				int key = cur_node->key_;

				cur_node.reset();

				if (right == nullptr) {

					if (left == nullptr) {
						if (!nodes.empty() ) {
							cur_node = nodes.top();
							nodes.pop();
							if (cur_node->key_ > key)
								cur_node->left = nullptr;
							else
								cur_node->right = nullptr;

							--cur_node->position_;
						} else
							return nullptr;
					} else
						cur_node = left;
				} else {
					std::shared_ptr<Node> min;
					std::shared_ptr<Node> tree = find_and_remove_min(right, min);
					min->left = left;
					min->right = tree;
					fix_position(min);
					cur_node = balance(min);
				}
				break;
			}
		}

		return fix_positions(nodes, cur_node);
	}

	std::shared_ptr<Node> find_and_remove_min(std::shared_ptr<Node> node, std::shared_ptr<Node>& min) {
		if (!node->left) {
			min = node;
			return node->right;
		}
		node->left = find_and_remove_min(node->left, min);
		--node->position_;
		return balance(node);
	}

	uint8_t height(std::shared_ptr<Node> node) {
		if (!node)
			return 0;

		return node->height;
	}

	void fix_height(std::shared_ptr<Node> node) {
		if (!node)
			return;

		node->height = std::max(height(node->left), height(node->right)) + 1;
	}

	int b_factor(std::shared_ptr<Node> node) {
		return height(node->right) - height(node->left);
	}

	std::shared_ptr<Node> balance(std::shared_ptr<Node> node) {
		fix_height(node);

		int bf = b_factor(node);
		if (bf == 2) {
			if (b_factor(node->right) < 0)
				node->right = rotate_right(node->right);
			return rotate_left(node);
		} else if (bf == -2) {
			if (b_factor(node->left) > 0)
				node->left = rotate_left(node->left);
			return rotate_right(node);
		}
		return node;
	}

	std::shared_ptr<Node> rotate_left(std::shared_ptr<Node> p) {
		std::shared_ptr<Node> q = p->right;
		p->right = q->left;
		q->left = p;

		fix_position(p);
		fix_position(q);

		fix_height(p);
		fix_height(q);
		return q;
	}

	std::shared_ptr<Node> rotate_right(std::shared_ptr<Node> p) {
		std::shared_ptr<Node> q = p->left;
		p->left = q->right;
		q->right = p;

		fix_position(p);
		fix_position(q);

		fix_height(p);
		fix_height(q);
		return q;
	}
};



int main()
{
	int n;
	std::cin >> n;

	AvlTree<int, int> tree;
	std::vector<int> result;
	int command, key, position;

	for(size_t i = 0; i < n; ++i) {
		std::cin >> command;

		if (command == 1) {
			position = 0;
			std::cin >> key;
			tree.insert(key, position);
			result.push_back(position);
		} else if (command == 2) {
			std::cin >> key;
			tree.erase(key);
		}
	}

	for(int i : result)
		std::cout << i << std::endl;

	return 0;
}


//10
//1 321
//1 434
//1 54
//2 434
//1 87
//1 56
//2 87
//2 95
//1 43
//2 56


//10
//1 432
//1 656
//1 432
//2 656
//1 12
//1 1000
//2 432
//1 56
//2 1000
//2 478
//0
//0
//1
//3
//0
//4
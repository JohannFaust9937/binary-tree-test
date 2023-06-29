#pragma once
#include <cstdio>

struct Node {
	bool root{ false };
	int key{ 0 }, value{ 0 };
	Node * left{ nullptr }, * right{ nullptr };

	Node() = default;
	Node(int key, int value, bool root = false) : key{ key }, value{ value }, root{ root } {}
	~Node() {}

	void insert(int key, int value) {
		if (key < this->key) {
			if (left == nullptr)
				left = new Node(key, value);
			else
				left->insert(key, value);
		}
		else {
			if (right == nullptr)
				right = new Node(key, value);
			else
				right->insert(key, value);
		}
	}

	Node* searchDescendant(int key) {
		if (key == this->key)
			return this;
		else if (this->left && key < this->key)
			this->left->searchDescendant(key);
		else if (this->right && key > this->key)
			this->right->searchDescendant(key);
		else
			return nullptr;
	}

	Node* searchAscendant(int key) {

		// Базовые случай для рекурсии
		if (this->key == key && this->root)
			return this;
		
		// Для первого уровня потомков от Root
		if (key < this->key && this->left && this->root)
			this->left->searchAscendant(key);
		else if (key > this->key && this->right && this->root)
			this->right->searchAscendant(key);

		// Для второго и остальных уровней потомков от Root
			// Случаи для варианта, когда и левый и правый потомок существуют
		if (left && right) {

		}
			// Случаи для левого потомка при его наличии
		if (left ) {

		}
			// Случаи для правого потомка при его наличии
		if (right) {

		}
	}
	
	Node* getMin() {
		if (left)
			return left->getMin();
		return this;
	}

	Node* getMax() {
		if (right)
			return right->getMax();
		return this;
	}

	int bypassWide() {
		const unsigned short max_size{ 65535 };
		Node** queue{ new Node*[max_size] } ;
		int begin{ 0 }, end{ 0 };
		
		queue[end++] = this;
		while (begin < end) {
			Node* current{ queue[begin++] };
			printf("%u ", current->key);
			if (current->left)
				queue[end++] = current->left;
			if (current->right)
				queue[end++] = current->right;
		}
		delete[] queue;
		return end;
	}
	
	void bypassLCR() {
		if (this->left)
			left->bypassLCR();
		printf("%u ", this->key);
		if (this->right)
			right->bypassLCR();
	}

	void bypassRLC() {
		if (this->left)
			left->bypassRLC();
		if (this->right)
			right->bypassRLC();
		printf("%u ", this->key);
	}

	void bypassLRC() { 
		printf("%u ", this->key);
		if (this->left)
			left->bypassLRC();
		if (this->right)
			right->bypassLRC();
	}

	void remove(int key) {
		Node* current{ searchDescendant(key) };
		if (!current->left && !current->right) {
			delete current;
			current = nullptr;
		}
	}
};
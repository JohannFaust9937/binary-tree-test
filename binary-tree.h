#pragma once
#include <cstdio>

struct Node {
	int key{ 0 }, value{ 0 };
	Node* left{ nullptr }, * right{ nullptr };

	Node() = default;
	Node(int key, int value) : key{ key }, value{ value } {}
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

	Node* search(int key) {
		if (key == this->key)
			return this;
		else if (key < this->key && left != nullptr)
			left->search(key);
		else if (key > this->key && right != nullptr)
			right->search(key);
		else
			return nullptr;
	}

	Node* getMin() {
		if (left != nullptr)
			return left->getMin();
		return this;
	}

	Node* getMax() {
		if (right != nullptr)
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
		// Looking for the case of deleting a node with two descendants
	}

	void remove_leaf(int key) {
		if (this->left && this->left->key == key) {
			delete this->left;
			this->left = nullptr;
		}
		else if (this->right && this->right->key == key) {
			delete this->right;
			this->right = nullptr;
		}
		else {
			if (key < this->key && this->left)
				this->left->remove(key);
			else if (key > this->key && this->right)
				this->right->remove(key);
		}
	}
			
};
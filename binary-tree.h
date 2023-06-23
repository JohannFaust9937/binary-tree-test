#pragma once
#include <cstdio>

struct Node {
	int key{ 0 }, value{ 0 };
	Node* left{ nullptr }, * right{ nullptr };

	Node() = default;
	Node(int key, int value) : key{ key }, value{ value } {}
	~Node() {
		printf("\nRun ~Node()");
	}

	void insert(int key, int value, int depth = 0) {
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

	void bypassWide() {
		printf("%u ", this->key);
		this->left
	}

	void bypassSymmetrical() {
		if (this->left)
			left->bypassSymmetrical();
		printf("%u ", this->key);
		if (this->right)
			right->bypassSymmetrical();
	}

	void bypassDirect() {
		if (this->left)
			left->bypassDirect();
		if (this->right)
			right->bypassDirect();
		printf("%u ", this->key);
	}

	void bypassReverse() {
		printf("%u ", this->key);
		if (this->left)
			left->bypassReverse();
		if (this->right)
			right->bypassReverse();
	}

	// ?????
	void remove(int key) {
		if (this->left)
			if (this->left->key == key)
				this->left = nullptr;

			else
				this->left->remove(key);

		if (this->right)
			if (this->right->key == key)
				this->right = nullptr;
			else
				this->right->remove(key);
	}
};
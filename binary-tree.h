#pragma once
#include <cstdio>

struct Node {
	int key{ 0 }, value{ 0 };
	Node*left{ nullptr }, *right{ nullptr };

	Node() = default;
	Node(int key, int value) : key{ key }, value{ value } {}
	~Node() {}

	void insert(int key, int value)
	{
		if (key < this->key)
		{
			if (left == nullptr)
				left = new Node(key, value);
			else
				left->insert(key, value);
		}
		else
		{
			if (right == nullptr)
				right = new Node(key, value);
			else
				right->insert(key, value);
		}
	}

	Node* search(int key)
	{
		if (key == this->key)
			return this;
		else if (key < this->key && left != nullptr)
			left->search(key);
		else if (key >= this->key && right != nullptr)
			right->search(key);
		else
			return nullptr;
	}

	Node* getMin()
	{
		if (left != nullptr)
			return left->getMin();
		return this;
	}

	Node* getMax()
	{
		if (right != nullptr)
			return right->getMax();
		return this;
	}
};
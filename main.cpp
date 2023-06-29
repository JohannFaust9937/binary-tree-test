#include "binary-tree.h"

int main(int, char*[])
{
	Node* root{ new Node(0, 0, true)};
	root->insert(1, 0);
	root->insert(12, 0);
	root->insert(12, 0);
	root->insert(7, 0);
	root->insert(8, 0);
	root->insert(3, 0);
	root->insert(4, 0);
	printf("Bypass of binary tree:\n");
	root->bypassWide();
	printf("\n================================================================\n");
	root->remove(4);
	printf("Bypass of binary tree after delete node \"4\":\n");
	printf("\n[%i]", root->bypassWide() - 1);
	printf("\n[%p]", root->searchDescendant(1)->left);
	
	delete root;
	return 0;
}


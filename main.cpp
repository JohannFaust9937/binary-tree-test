#include "binary-tree.h"

int main(int, char*[])
{
	Node* Root{ new Node(0, 0)};
	Root->insert(1, 0);
	Root->insert(12, 0);
	Root->insert(12, 0);
	Root->insert(7, 0);
	Root->insert(8, 0);
	Root->insert(3, 0);
	Root->insert(4, 0);
	printf("Bypass of binary tree:\n");
	Root->bypassReverse();
	printf("\n================================================================\n");
	Root->remove(7);
	printf("Bypass of binary tree after delete node \"7\":\n");
	Root->bypassReverse();
	delete Root;
	return 0;
}


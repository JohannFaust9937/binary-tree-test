#include "binary-tree.h"

int main(int, char*[])
{
	Node Root;
	Root.insert(1, 0);
	Root.insert(2, 0);
	Root.insert(3, 0);
	printf("%p\n", Root.search(0));
	printf("%p\n", Root.search(1));
	printf("%p\n", Root.search(2));
	printf("%p\n", Root.search(3));
	printf("%p\n", Root.search(4));
	printf("________________\n");
	printf("%i\n", Root.getMin()->key);
	printf("%i\n", Root.getMax()->key);
	return 0;
}


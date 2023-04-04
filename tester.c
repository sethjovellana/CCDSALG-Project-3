#include "bst.h"

int main(){
	printf("%d", 1);
	bst *tree = create();
	insert(tree, 4);
	printf("%d", tree->pRoot->data);
	insert(tree, 44);
	printf("%d", 1);
	insert(tree, 46);
	insert(tree, 90);
	insert(tree, 56);
	insert(tree, 75);	
	
	inorder(tree->pRoot);
	return 0;
}





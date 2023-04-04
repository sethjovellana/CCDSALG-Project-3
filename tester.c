#include "bst.h"

int main(){
	printf("%d ", 1);
	bst *tree = create();
	insert(tree, 60);
	printf("%d ", 1);
	insert(tree, 44);
	printf("%d ", 1);
	insert(tree, 46);
	printf("%d ", 1);
	insert(tree, 90);
	printf("%d ", 1);
	insert(tree, 56);
	printf("%d ", 1);
	insert(tree, 75);	
	printf("%d ", 1);
	printf("%d ", tree->pRoot->data);
	printf("%d ", tree->pRoot->pLeft->data);
	printf("%d ", tree->pRoot->pRight->data);	
	inorder(tree->pRoot);
	return 0;
}





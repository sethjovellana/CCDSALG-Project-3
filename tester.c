#include "bst.h"

int main(){
	bst *tree = create();
	insert(tree, 60);
	insert(tree, 44);
	insert(tree, 46);
	insert(tree, 90);
	insert(tree, 56);
	insert(tree, 75);	
	
	inorder(tree->pRoot);
	printf("\n");
	preorder(tree->pRoot);
	printf("\n");
	postorder(tree->pRoot);
	return 0;
}





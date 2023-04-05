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
	printf("\n");
	
	// search function test cases:
	sNode *key = search(tree, 90);
	printf("%d", key->data);
	printf("\n");
	
	sNode *key2 = search(tree, 75);
	printf("%d", key2->data);
	printf("\n");
	
	sNode *key3 = search(tree, 100);
	printf("%d", key3->data); // prints blank/null because key doesn't exist.
    printf("\n");


    printf("%d", minimum(tree->pRoot)); // is this correct?
	printf("\n");
    
    printf("%d", maximum(tree->pRoot));
	printf("\n");


	return 0;
}




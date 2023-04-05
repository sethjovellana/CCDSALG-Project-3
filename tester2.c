#include "bst2.h"

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

	printf("\n");

	// max and min function test cases:
    sNode *key4 = maximum(tree->pRoot);
    printf("Maximum: %d", key4->data);
    printf("\n");
  
    sNode *key5 = minimum(tree->pRoot);
    printf("Minimum: %d", key5->data);
    printf("\n");

	printf("\n");


	sNode *key6 = parent(tree, 44);
	printf("Parent of 44: %d", key6->data); //ans: 60
	printf("\n");

	sNode *key7 = parent(tree, 46);
	printf("Parent of 46: %d", key7->data); //ans: 44
	printf("\n");

	sNode *key8 = parent(tree, 75);
	printf("Parent of 75: %d", key8->data); //ans: 90
	printf("\n");
	printf("\n");
	

	// search function test cases:
	sNode *key = search(tree, 90);
	printf("Search case #1: %d", key->data);
	printf("\n");
	
	sNode *key2 = search(tree, 75);
	printf("Search case #2: %d", key2->data);
	printf("\n");
	
	sNode *key3 = search(tree, 100);
	printf("Search case #3: %d", key3->data); // prints blank/null because key doesn't exist.
    printf("\n");



	return 0;
}




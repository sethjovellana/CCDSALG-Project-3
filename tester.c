#include "bst.h"

int main(){
	bst *tree = create();
	insert(tree, 60);
	insert(tree, 44);
	insert(tree, 46);
	insert(tree, 90);
	insert(tree, 56);
	insert(tree, 75);	
	insert(tree, 13);
	insert (tree, 91);
	
	printf("Inorder: \n");
	inorder(tree->pRoot);
	printf("\n");
	printf("Preorder: \n");
	preorder(tree->pRoot);
	printf("\n");
	printf("Postorder: \n");
	postorder(tree->pRoot);
	printf("\n");
	
	// search function test cases:
	printf("Search 90: \n");
	sNode *key = search(tree, 90);
	printf("%d", key->data);
	printf("\n");
	
	printf("Search 75: \n");
	sNode *key2 = search(tree, 75);
	printf("%d", key2->data);
	printf("\n");
	
	sNode *max = maximum(tree->pRoot);
	printf("Maximum: %d \n", max->data);

	sNode *min = minimum(tree->pRoot);
	printf("Minimum: %d \n", min->data);

	sNode *p = parent(tree, 44);
	printf("Parent:  %d \n", p->data);

	sNode *suc = successor(tree, 44);
	printf("Successor:  %d \n", suc->data);
	
	sNode *pre = predecessor(tree, 90);
	printf("Predessesor: %d \n", pre->data);

	/*sNode *key3 = search(tree, 44);
	if((sNode*)malloc(sizeof(sNode) == NULL)){
		printf("NULL\n");
	} else {
	printf("%d", key3->data); // prints blank/null because key doesn't exist.
	} */
	return 0; 
}





/*******************************************************************
YOU ARE NOT ALLOWED TO MODIFY THE STRUCT AND THE FUNCTION PROTOTYPES
*******************************************************************/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *pLeft;
    struct Node *pRight;
};

typedef struct Node sNode;

typedef struct {
	sNode *pRoot;
} bst;

bst* create() {
	bst *t = malloc(sizeof(bst));	
	t->pRoot = NULL;
	
	return t;
}

void insert(bst *t, int x) {
	sNode *newNode = malloc(sizeof(sNode));
	newNode->data = x;
	newNode->pLeft = NULL;
	newNode->pRight = NULL;
	
	if (t->pRoot == NULL){
		t->pRoot = newNode;
	}
	
	else{
		sNode *prev = NULL;
		sNode *temp = t->pRoot;
		
		while (temp != NULL){
			if (temp->data > x){
				prev = temp;
				temp = temp->pLeft;
			}
			else if (temp->data < x){
				prev = temp;
				temp = temp->pRight;
			}
		}
		if (prev->data > x)
			prev->pLeft = newNode;
		else
			prev->pRight = newNode;
	}
}

sNode* search(bst *t, int x) {
	sNode *root = t->pRoot;
	while (root != NULL && root->data != x){
		
		if (x < root->data)
			root = root->pLeft;
		else 
			root = root->pRight;
	}
	return root;
}

void inorder(sNode *pPointer) {
	if (pPointer == NULL)
		return;
	inorder(pPointer->pLeft);
	printf("%d ", pPointer->data);
	inorder(pPointer->pRight);
}

void preorder(sNode *pPointer) {
	if (pPointer == NULL)
		return;
	printf("%d ", pPointer->data);
	preorder(pPointer->pLeft);
	preorder(pPointer->pRight);
}

void postorder(sNode *pPointer) {
	if (pPointer == NULL)
		return;
	postorder(pPointer->pLeft);
	postorder(pPointer->pRight);
	printf("%d ", pPointer->data);
}

sNode* maximum(sNode *pPointer) {
	/*
	// x is the pointer to a binary search tree
	while (right of x != NIL)
	x = right of x;
	return x;
	*/
	if (pPointer == NULL)
		return NULL;

	sNode *pTemp = NULL;
	while (pPointer->pRight != NULL){
		pTemp = pPointer->pRight;
	}

	return pTemp;
}


sNode* minimum(sNode *pPointer) {
	/*
	// x is the pointer to a binary search tree
	while (left of x != NIL)
	x = left of x;
	return x;
	*/
	if (pPointer == NULL)
		return NULL;

	sNode *pTemp = NULL;
	while (pPointer->pLeft != NULL){
		pTemp = pPointer->pLeft;
	}

	return pTemp; 
}

sNode* parent(bst *t, int x) {
	// Your code here
	// cases
	// children -> parent [put]
	// root node -> null [put]
	// null tree -> null
	// no node -> null

	/*
	y = parent of x
	while(y!= NULL  && x == right of y){
		x = y
		y = parent of y; 
	}

	return y
	*/

	sNode *tempParent = NULL;
	
	while(t != NULL) {
		if(x < t->pRoot){ //if values is less than root node
			tempParent = t; //var will be the right subtree
			t = tempParent->pLeft;

		} else if (x > t->pRoot){
			tempParent = t;
			t = tempParent->pRight;
		} else { 
			break;
		}

	}

	return tempParent;

}


/*
sNode* successor(bst *t, int x) {
	// Your code here
}

sNode* predecessor(bst *t, int x) {
	// Your code here
}
*/
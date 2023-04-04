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
/*
sNode* maximum(sNode *pPointer) {
	// Your code here
}

sNode* minimum(sNode *pPointer) {
	// Your code here
}

sNode* parent(bst *t, int x) {
	// Your code here
}

sNode* successor(bst *t, int x) {
	// Your code here
}

sNode* predecessor(bst *t, int x) {
	// Your code here
}
*/

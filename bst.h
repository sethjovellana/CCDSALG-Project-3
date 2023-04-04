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
	bst t;
	t.pRoot = NULL;
	bst *ptrT = &t;
	
	return ptrT;
}

void insert(bst *t, int x) {
	sNode *newNode;
	newNode = malloc(sizeof(sNode));
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
/*
sNode* search(bst *t, int x) {
	// Your code here
}
*/
void inorder(sNode *pPointer) {
	inorder(pPointer->pLeft);
	printf("%d", 1);
	printf("%d ", pPointer->data);
	inorder(pPointer->pRight);
}
/*
void preorder(sNode *pPointer) {
	// Your code here
}

void postorder(sNode *pPointer) {
	// Your code here
}

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

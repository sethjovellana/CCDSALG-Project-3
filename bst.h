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
	bst *t = (bst*)malloc(sizeof(bst));	
	t->pRoot = NULL;
	
	return t;
}

void insert(bst *t, int x) {
	sNode *newNode = (sNode*)malloc(sizeof(sNode));
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
	// Your code here
	if(pPointer == NULL){
        return NULL; //no value in the tree
	}
    else if(pPointer -> pRight == NULL){
        return pPointer; //no more right subtree meaning max is found
	}
    else {
        return maximum(pPointer->pRight); //iterates until max is found
	}
}

sNode* minimum(sNode *pPointer) {
	// Your code here
	if(pPointer == NULL) {
        return NULL; //no value in the tree
	}
    else if(pPointer -> pLeft == NULL) {
        return pPointer; //no more left subtree meaning min is found
	}
    else {
        return minimum(pPointer->pLeft); //iterates until min is found
	}
}

sNode* parent(bst *t, int x) {
	// Your code here


	sNode *root = t->pRoot;	
	if(root == NULL)
		return NULL;
	
	sNode *tempParent = NULL;
	
	while(root != NULL) {
		if(x < root->data){ //if value is less than node
			tempParent = root; 
			root = root->pLeft;

		} else if (x > root->data){ //if value is more than node
			tempParent = root;
			root = root->pRight;
		} else { 
			break;
		}

	}

	return tempParent;

}



sNode* successor(bst *t, int x) {

	//sNode* root = t->pRoot;
	sNode* n = search(t, x);

	// checks if the right tree is null
	if( n-> pRight != NULL)
		return minimum(n-> pRight);
	

	// looks for the parent if there is no right subtree
	sNode* p = parent(t, x);

	while(p != NULL && n == p->pRight){
		n = p;
		p = parent(t,p->data);
	}

	return p;

}


sNode* predecessor(bst *t, int x) {

	//sNode* root = t->pRoot;
	sNode* n = search(t, x);

	// checks if the right tree is null
	if( n-> pLeft != NULL)
		return maximum(n-> pLeft);
	

	// looks for the parent if there is no left subtre
	sNode* p = parent(t, x);

	while(p != NULL && n == p->pLeft){
		n = p;
		p = parent(t,p->data);
	}

	return p;

	
}


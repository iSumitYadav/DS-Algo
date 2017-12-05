#include<bits/stdc++.h>
using namespace std;

struct node{
	int d;
	node *left = NULL, *right = NULL;
};

node *newNode(int data){
	node *t = new node;
	t->d = data;
	//t->left = t->right = NULL;

	return t;
}

void inOrderTraversal(node *root){
	if(!root)
		return;

	inOrderTraversal(root->left);
	cout << root->d << " ";
	inOrderTraversal(root->right);
}

void minDepth(node *root, int *depth, int level){
	if(!root)
		return;
	cout << root->d << " ";
	// check cond. only for leaf
	if(!root->left && !root->right && *depth > level){
		*depth = level;
		return;
	}

	return minDepth(root->left, depth, level+1);
	return minDepth(root->right, depth, level+1);
}

int minDepthofTree(node *root){
	if(!root)
		return 0;

	int level = 0, depth = INT_MAX;

	minDepth(root, &depth, level);cout << endl;

	return depth;
}

int main(){
	node *r = newNode(1);
	r->left = newNode(2);
	r->right = newNode(3);
	r->left->left = newNode(4);
	r->left->right = newNode(5);
	r->right->left = newNode(6);
	r->right->right = newNode(7);
	r->left->left->left = newNode(8);
	r->left->left->right = newNode(9);
	r->left->right->left = newNode(10);
	r->left->right->right = newNode(11);
	r->right->left->left = newNode(12);
	r->right->left->right = newNode(13);
	r->right->right->left = newNode(14);
	r->right->right->right = newNode(15);

	// inOrderTraversal(r);cout << endl;

	cout << minDepthofTree(r) << endl;

	return 0;
}
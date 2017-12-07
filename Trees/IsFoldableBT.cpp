#include<bits/stdc++.h>
using namespace std;

struct node{
	int d;
	node *left = NULL, *right = NULL;
};

node *newNode(int key){
	node *t = new node;
	t->d = key;

	return t;
}

int isFoldableUtil(node *a, node *b){
	if(!a && !b)
		return 1;

	//cout << a->d << " " << b->d << endl;

	if(!a || !b)
		return 0;

	int l = isFoldableUtil(a->left, b->right);
	return l && isFoldableUtil(a->right, b->left);
}

int isFoldable(node *root){
	if(!root)
		return 1;

	return isFoldableUtil(root->left, root->right);
}

int main(){
	node *r = newNode(1);
	r->left = newNode(2);
	r->right = newNode(3);
	r->left->left = newNode(4);
	//r->left->right = newNode(5);
	r->right->left = newNode(6);

	cout << isFoldable(r);

	return 0;
}
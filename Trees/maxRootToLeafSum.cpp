#include<bits/stdc++.h>
using namespace std;

struct node{
	int d;
	node * left = NULL, *right = NULL;
};

node *newNode(int key){
	node *t = new node;
	t->d = key;

	return t;
}

int maxRootToLeafSum(node *root){
	if(!root)
		return 0;

	return max(maxRootToLeafSum(root->left), maxRootToLeafSum(root->right)) + root->d;
}

int main(){
	/*
				1
			  /	  \
			 20	   3
			/ \   / \
		   4  54 6  75
	*/
	node *r = newNode(1);
	r->left = newNode(20);
	r->right = newNode(3);
	r->left->left = newNode(4);
	r->left->right = newNode(54);
	r->right->left = newNode(6);
	r->right->right = newNode(75);

	cout << maxRootToLeafSum(r) << endl;

	return 0;
}
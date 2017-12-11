#include<bits/stdc++.h>
using namespace std;

struct node{
	int d;
	node *lt=NULL, *rt=NULL;
};

node *newNode(int key){
	node *t = new node;
	t->d = key;

	return t;
}

int lcaOfBST(node *r, int n1, int n2){
	if(!r)
		return 0;
	
	if(n1 < r->d && n2 < r->d)
		return lcaOfBST(r->lt, n1, n2);

	if(n1 > r->d && n2 > r->d)
		return lcaOfBST(r->rt, n1, n2);

	return r->d;
}

int main(){
	/*
				   5
	           /      \
	         3          7
	      /     \     /   \
	    2        4   6     9
	  /                   /
	 1                   8
	*/
	node *r = newNode(5);
	r->lt = newNode(3);
	r->rt = newNode(7);
	r->lt->lt = newNode(2);
	r->lt->rt = newNode(4);
	r->lt->lt->lt = newNode(1);
	r->rt->lt = newNode(6);
	r->rt->rt = newNode(9);
	r->rt->rt->lt = newNode(8);

	int n1 = 3, n2 = 8;
	printf("LCA of BST(%d, %d): %d\n", n1, n2, lcaOfBST(r, n1, n2));

	return 0;
}
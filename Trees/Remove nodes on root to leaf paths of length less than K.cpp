#include<bits/stdc++.h>
using namespace std;

struct node{
	int d;
	node *lt=NULL, *rt=NULL;
};

node *newNode(int key){
	/*node *t = (node *)malloc(sizeof(node));
	t->lt = NULL;
	t->rt = NULL;*/
	node *t = new node;
	t->d = key;

	return t;
}

node *removeNodesLengthLessThanK(node *r, int k, int level){
	if(!r)
		return r;

	r->lt = removeNodesLengthLessThanK(r->lt, k, level+1);
	r->rt = removeNodesLengthLessThanK(r->rt, k, level+1);

	if(level < k && !r->lt && !r->rt){
		cout << "Node removed: " << r->d << endl;
		free(r);
		return NULL;
	}

	return r;
}

void preOrder(node *r){
	if(!r)
		return;

	cout << r->d << " ";
	preOrder(r->lt);
	preOrder(r->rt);
}

int main(){
	/*
				   1
	           /      \
	         2          3
	      /     \         \
	    4         5        6
	  /                   /
	 7                   8
	*/
	node *r = newNode(1);
	r->lt = newNode(2);
	r->lt->lt = newNode(4);
	r->lt->rt = newNode(5);
	r->lt->lt->lt = newNode(7);
	r->rt = newNode(3);
	r->rt->rt = newNode(6);
	r->rt->rt->lt = newNode(8);

	cout << "Pre Order Traversal: ";
	preOrder(r);
	cout << endl;

	int k, level=1;
	cin >> k;
	r = removeNodesLengthLessThanK(r, k, level);

	cout << "Pre Order Traversal After removing Nodes: ";
	preOrder(r);

	return 0;
}
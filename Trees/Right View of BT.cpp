#include<bits/stdc++.h>
using namespace std;

struct node{
	int d;
	node *lt = NULL, *rt = NULL;
};

node *newNode(int key){
	node *t = new node;
	t->d = key;

	return t;
}

void printRightViewUtil(node *r, int *depth, int level){
	if(!r)
		return;

	if(*depth < level){
		cout << r->d << " ";
		*depth = level;
	}

	printRightViewUtil(r->rt, depth, level+1);
	printRightViewUtil(r->lt, depth, level+1);
}

void printRightView(node *r){
	if(!r)
		return;

	int depth=INT_MIN, level=0;

	return printRightViewUtil(r, &depth, level);
}

int main(){
	/*
					  20
                    /    \
                  8       22
                /   \    / \
              5      3  4   25
                    / \      
                  10    14
                  	   / \
                  	 143  144
	*/
	node *r = newNode(20);
	r->lt = newNode(8);
	r->rt = newNode(22);
	r->lt->lt = newNode(5);
	r->lt->rt = newNode(3);
	r->lt->rt->lt = newNode(10);
	r->lt->rt->rt = newNode(14);
	r->lt->rt->rt->lt = newNode(143);
	r->lt->rt->rt->rt = newNode(144);
	r->rt->rt = newNode(25);
	r->rt->lt = newNode(4);

	cout << "Right View of BT\n";
	printRightView(r);

	return 0;
}
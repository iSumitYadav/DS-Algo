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

int isFullBT(node *r){
	if(!r || (!r->lt && !r->rt))
		return 1;

	if(!r->lt || !r->rt)
		return 0;

	return isFullBT(r->lt) && isFullBT(r->rt);
}

int main(){
	node *r = newNode(1);
	r->lt = newNode(2);
	r->rt = newNode(3);
	r->lt->lt = newNode(4);
	r->lt->rt = newNode(5);

	cout << isFullBT(r);

	return 0;
}
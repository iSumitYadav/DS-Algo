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

node *lca(node *r, int n1, int n2){
	if(!r)
		return NULL;

	if(r->d == n1 || r->d == n2)
		return r;

	node *left_lca = lca(r->lt, n1, n2);
	node *right_lca = lca(r->rt, n1, n2);

	if(left_lca && right_lca)
		return r;

	if(left_lca)
		return left_lca;
	else
		return right_lca;
}

int main(){
	node *r = newNode(1);
	r->lt = newNode(2);
	r->rt = newNode(3);
	r->lt->lt = newNode(4);
	r->lt->rt = newNode(5);
	r->rt->lt = newNode(6);
	r->rt->rt = newNode(7);

	cout << "LCA(4, 5) = " << lca(r, 4, 5)->d;
    cout << "\nLCA(4, 6) = " << lca(r, 4, 6)->d;
    cout << "\nLCA(3, 4) = " << lca(r, 3, 4)->d;
    cout << "\nLCA(2, 4) = " << lca(r, 2, 4)->d;
    cout << "\nLCA(5, 6) = " << lca(r, 5, 6)->d;

	return 0;
}
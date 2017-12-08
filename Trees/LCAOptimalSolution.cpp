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

node *findLCAUtil(node *r, int n1, int n2, bool &v1, bool &v2){
	if(!r)
		return NULL;

	if(r->d == n1){
		v1 = true;
		return r;
	}

	if(r->d == n2){
		v2 = true;
		return r;
	}

	node *left_lca = findLCAUtil(r->lt, n1, n2, v1, v2);
	node *right_lca = findLCAUtil(r->rt, n1, n2, v1, v2);

	if(left_lca && right_lca)
		return r;

	if(left_lca)
		return left_lca;
	else
		return right_lca;
}

bool findNode(node *r, int key){
	if(!r)
		return false;

	if(r->d == key)
		return true;

	return findNode(r->lt, key) || findNode(r->rt, key);
}

node *findLCA(node *r, int n1, int n2){
	if(!r)
		return NULL;

	bool v1=false, v2=false;

	node *lca = findLCAUtil(r, n1, n2, v1, v2);

	if((v1 && v2) || (v1 && findNode(r, n2)) || (v2 && findNode(r, n1)))
		return lca;

	return NULL;
}

int main(){
	node *r = newNode(1);
	r->lt = newNode(2);
	r->rt = newNode(3);
	r->lt->lt = newNode(4);
	r->lt->rt = newNode(5);
	r->rt->lt = newNode(6);
	r->rt->rt = newNode(7);

	int arr_n1[] = {4, 4, 3, 2, 5};
	int arr_n2[] = {5, 6, 4, 4, 67};
	int n = sizeof(arr_n1)/sizeof(arr_n1[0]), i;
	node *lca;

	for(i=0; i<n; i++){
		cout << "LCA(" << arr_n1[i] << ", " << arr_n2[i] << ") = ";
		lca = findLCA(r, arr_n1[i], arr_n2[i]);
		(lca) ? cout << lca->d : cout << "NULL";
		cout << endl;
	}

	return 0;
}
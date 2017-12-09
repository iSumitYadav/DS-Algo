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

node *createBSTUtil(node *r, int key){
	if(!r){
		r = newNode(key);
		return r;
	}

	if(key <= r->d)
		r->lt = createBSTUtil(r->lt, key);
	else
		r->rt = createBSTUtil(r->rt, key);

	return r;
}

node *createBST(int arr[], int n){
	node *r = NULL;

	for(int i=0; i<n; i++){
		r = createBSTUtil(r, arr[i]);
	}

	return r;
}

void inorderTraversal(node *r){
	if(!r)
		return;

	inorderTraversal(r->lt);
	cout << r->d << " ";
	inorderTraversal(r->rt);
}

int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int size = sizeof(arr)/sizeof(arr[0]);

	node *r = createBST(arr, size);
	
	inorderTraversal(r);

	return 0;
}
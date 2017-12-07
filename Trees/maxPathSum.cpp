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

int main(){
	node *r = newNode(1);
	return 0;
}
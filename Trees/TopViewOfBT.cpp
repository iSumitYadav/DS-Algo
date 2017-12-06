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

void printTopView(node *root){
	if(!root)
		return;

	unordered_map <int, int> m;
	pair<node*, int> p;
	queue<pair<node*, int>> q;
	node * temp;
	int val = 0;

	q.push(make_pair(root, val));

	while(!q.empty()){
		p = q.front();
		q.pop();
		temp = p.first;
		val = p.second;

		if(m.find(val) == m.end()){
			cout << temp->d << " ";
			m[val] = temp->d;
		}

		if(temp->left){
			q.push(make_pair(temp->left, val-1));
		}

		if(temp->right){
			q.push(make_pair(temp->right, val+1));
		}
	}
}

int main(){
	node *r = newNode(1);
	r->left = newNode(2);
	r->right = newNode(3);
	r->left->left = newNode(4);
	r->left->right = newNode(5);
	r->right->left = newNode(6);
	r->right->right = newNode(7);
	r->left->left->left = newNode(8);
	r->left->left->right = newNode(9);
	r->left->left->right->right = newNode(10);
	r->left->left->right->right->right = newNode(11);
	r->left->left->right->right->right->right = newNode(12);
	r->left->left->right->right->right->right->right = newNode(13);
	r->left->left->right->right->right->right->right->right = newNode(14);

	printTopView(r);

	return 0;
}
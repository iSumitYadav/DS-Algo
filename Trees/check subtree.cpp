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

int isSubTreeUtil(node *t, node *s){
	if(!t && !s)
		return 1;

	if(!t || !s)
		return 0;

	return (t->d == s->d) && isSubTreeUtil(t->lt, s->lt) && isSubTreeUtil(t->rt, s->rt);
}

// TC: O(n) as a node is traversed single time only
int isSubTree(node *t, node *s){
	if(!t && !s)
		return 1;

	if(!t)
		return 0;

	if(!s)
		return 1;

	if(t->d == s->d)
		return isSubTreeUtil(t, s);

	return isSubTree(t->lt, s) || isSubTree(t->rt, s);
}

int main(){
	/*	tree t
			  1
            /   \
          2      3
        /    \     \
       4     5      6
      / \
     44  7

     	subtree s
		   2
        /    \
       4     5
        \
    	7
	*/
	node *t = newNode(123);
	t->lt = newNode(2);
	t->rt = newNode(3);
	t->lt->lt = newNode(4);
	t->lt->rt = newNode(5);
	t->rt->rt = newNode(6);
	// t->lt->lt->lt = newNode(44);
	t->lt->lt->rt = newNode(7);

	node *s = newNode(2);
	s->lt = newNode(4);
	s->rt = newNode(5);
	s->lt->rt = newNode(7);

	if(isSubTree(t, s))
		cout << "Yes: Tree S is SubTree of Tree T" << endl;
	else
		cout << "No: Tree S is not SUBTree of Tree T" << endl;

	return 0;
}
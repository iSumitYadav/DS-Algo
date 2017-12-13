#include<bits/stdc++.h>
using namespace std;

struct node{
	int d;
	// char d;
	node *lt=NULL, *rt=NULL;
};

node *newnode(int key){
	node *t = new node;
	t->d = key;

	return t;
}

int isSubSETTreeUtil(node *t, node *s){
	if(!s)
		return 1;

	if(!t)
		return 0;

	if(t->d != s->d)
		return 0;

	return (t->d == s->d) && isSubSETTreeUtil(t->lt, s->lt) && isSubSETTreeUtil(t->rt, s->rt);
}

int isSubSETTree(node *t, node *s){
	if(!t && !s)
		return 1;

	if(!t)
		return 0;

	if(!s)
		return 1;

	if(t->d == s->d)
		return isSubSETTreeUtil(t, s);

	if(isSubSETTree(t->lt, s) || isSubSETTree(t->rt, s))
		return 1;

	return 0;
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
	node *t = newnode(1);
	t->lt = newnode(2);
	t->rt = newnode(3);
	t->lt->lt = newnode(4);
	t->lt->rt = newnode(5);
	t->rt->rt = newnode(6);
	t->lt->lt->lt = newnode(44);
	t->lt->lt->rt = newnode(7);

	node *s = NULL;/*newnode(2);
	s->lt = newnode(4);
	s->rt = newnode(5);
	s->lt->rt = newnode(7);*/

	/*node *t = newnode('a');
    t->lt = newnode('b');
    t->rt = newnode('d');
    t->lt->lt = newnode('c');
    t->rt->rt = newnode('e');
 
    node *s = newnode('a');
    s->lt = newnode('b');
    s->lt->lt = newnode('c');
    s->rt = newnode('d');*/

	if(isSubSETTree(t, s))
		cout << "Yes: Tree S is SUB-SET Tree of Tree T" << endl;
	else
		cout << "No: Tree S is not SUB-SET Tree of Tree T" << endl;

	return 0;
}
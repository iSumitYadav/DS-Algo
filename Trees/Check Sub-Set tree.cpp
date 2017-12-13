#include<bits/stdc++.h>
using namespace std;

struct node{
	int d;
	// char d;
	node *lt=NULL, *rt=NULL;
};

node *newNode(int key){
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
	/*node *t = newNode(1);
	t->lt = newNode(2);
	t->rt = newNode(3);
	t->lt->lt = newNode(4);
	t->lt->rt = newNode(5);
	t->rt->rt = newNode(6);
	t->lt->lt->lt = newNode(44);
	t->lt->lt->rt = newNode(7);

	node *s = NULL;*//*newNode(2);
	s->lt = newNode(4);
	s->rt = newNode(5);
	s->lt->rt = newNode(7);*/

	/*node *t = newNode('a');
    t->lt = newNode('b');
    t->rt = newNode('d');
    t->lt->lt = newNode('c');
    t->rt->rt = newNode('e');
 
    node *s = newNode('a');
    s->lt = newNode('b');
    s->lt->lt = newNode('c');
    s->rt = newNode('d');*/

    // tREE 1
    /* Construct the following tree
              26
            /   \
          10     3
        /    \     \
      4      6      3
       \	  \
        30	   45
    */
    struct node *t        = newNode(26);
    t->rt              = newNode(3);
    t->rt->rt       = newNode(3);
    t->lt               = newNode(10);
    t->lt->lt         = newNode(4);
    t->lt->lt->rt  = newNode(30);
    t->lt->rt        = newNode(6);
    t->lt->rt->rt        = newNode(45);
 
    // tREE 2
    /* Construct the following tree
          10
        /    \
      4      6
       \
        30
    */
    struct node *s    = newNode(10);
    s->rt          = newNode(6);
    s->lt           = newNode(4);
    s->lt->rt    = newNode(30);

	if(isSubSETTree(t, s))
		cout << "Yes: Tree S is SUB-SET Tree of Tree T" << endl;
	else
		cout << "No: Tree S is not SUB-SET Tree of Tree T" << endl;

	return 0;
}
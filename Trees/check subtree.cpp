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

int issubtreeUtil(node *t, node *s){
	if(!t && !s)
		return 1;

	if(!t || !s)
		return 0;

	return (t->d == s->d) && issubtreeUtil(t->lt, s->lt) && issubtreeUtil(t->rt, s->rt);
}

// tC: O(n) as a node is traversed single time only
int issubtree(node *t, node *s){
	if(!t && !s)
		return 1;

	if(!t)
		return 0;

	if(!s)
		return 1;

	if(t->d == s->d)
		return issubtreeUtil(t, s);

	return issubtree(t->lt, s) || issubtree(t->rt, s);
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
	/*node *t = newNode(123);
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
	s->lt->rt = newNode(7);*/

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

	if(issubtree(t, s))
		cout << "Yes: tree s is subtree of tree t" << endl;
	else
		cout << "No: tree s is not sUBtree of tree t" << endl;

	return 0;
}
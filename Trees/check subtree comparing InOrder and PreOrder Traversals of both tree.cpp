#include<bits/stdc++.h>
using namespace std;

struct node{
	char d;
	node *lt=NULL, *rt=NULL;
};

node *newNode(char key){
	node *t = new node;
	t->d = key;

	return t;
}

void inOrder(node *r, string &str, int i){
	if(!r){
		str.append("#");
		return;
	}

	inOrder(r->lt, str, i+1);
	str.push_back(r->d);
	inOrder(r->rt, str, i+1);
}

void preOrder(node *r, string &str, int i){
	if(!r){
		str.append("#");
		return;
	}

	str.push_back(r->d);
	preOrder(r->lt, str, i+1);
	preOrder(r->rt, str, i+1);
}

int isSubtree(node *t, node *s){
	if(!t)
		return 0;

	if(!s)
		return 1;

	string inT="", inS="";
	int m=0, n=0;
	inOrder(t, inT, m);
	inOrder(s, inS, n);
// cout <<inT << endl << inS << endl;
	if(inT.find(inS) == -1)
		return 0;

	m=0, n=0;
	string preT="", preS="";
	preOrder(t, preT, m);
	preOrder(s, preS, n);
// cout << preT << endl << preS << endl;
	if(preT.find(preS) == -1)
		return 0;

	return 1;
}

int main(){
	node *t = newNode('a');
    t->lt = newNode('b');
    t->rt = newNode('d');
    t->lt->lt = newNode('c');
    t->rt->rt = newNode('e');
 
    node *s = newNode('a');
    s->lt = newNode('b');
    s->lt->lt = newNode('c');
    s->rt = newNode('d');
    // s->rt->rt = newNode('e');
 
    if (isSubtree(t, s))
        cout << "Yes: s is a subtree of t";
    else
        cout << "No: s is NOt a subtree of t";

	return 0;
}
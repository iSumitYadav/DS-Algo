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

void printBottomViewUtil(node *r, map<int, pair<int, node *>> &m, int hori_pos, int level){
	if(!r)
		return;

	// ">"" if first node at that level OR ">=" if later node in traversal
	if(level >= m[hori_pos].first)
		m[hori_pos] = make_pair(level, r);

	printBottomViewUtil(r->lt, m, hori_pos-1, level+1);
	printBottomViewUtil(r->rt, m, hori_pos+1, level+1);
}

void printBottomView(node *r){
	if(!r){
		cout << "NULL";
		return;
	}

	// horizontal position and level of current node
	int hori_pos = 0, level=0;
	map<int, pair<int, node *>> m;

	printBottomViewUtil(r, m, hori_pos, level);

	map<int, pair<int, node *>>::iterator it;

	for(it=m.begin(); it!=m.end(); it++)
		cout << (*it).second.second->d << " ";
}

int main(){
	/*
					  20
                    /    \
                  8       22
                /   \      \
              5      3      25
                    / \      
                  10    14
                  		 \
                  		  144
	*/
	node *r = newNode(20);
	r->lt = newNode(8);
	r->rt = newNode(22);
	r->lt->lt = newNode(5);
	r->lt->rt = newNode(3);
	r->lt->rt->lt = newNode(10);
	r->lt->rt->rt = newNode(14);
	r->lt->rt->rt->rt = newNode(144);
	r->rt->rt = newNode(25);
	r->rt->lt = newNode(4);

	printBottomView(r);

	return 0;
}
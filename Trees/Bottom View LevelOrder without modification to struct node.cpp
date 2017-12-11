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

void printBottomView(node *r){
	if(!r){
		cout << "NULL" << endl;
		return;
	}

	queue<pair<int, node *>> q;
	map<int, node *> m;
	int hd = 0;

	q.push(make_pair(hd, r));

	while(!q.empty()){
		pair<int, node *> t = q.front();
		q.pop();

		m[t.first] = t.second;

		if(t.second->lt){
			q.push(make_pair(t.first-1, t.second->lt));
		}

		if(t.second->rt){
			q.push(make_pair(t.first+1, t.second->rt));
		}
	}

	map<int, node *>::iterator it;
	for(it=m.begin(); it!=m.end(); it++){
		cout << (*it).second->d << " ";
	}cout << endl;
}

int main(){
	/*
					  20
                    /    \
                  8       22
                /   \    / \
              5      3  4   25
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
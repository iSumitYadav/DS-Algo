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

void reverseAltLevelUsingInOrder(node *r, int level, vector<int> &v, int rev=0){
	if(!r)
		return;

	reverseAltLevelUsingInOrder(r->lt, level+1, v, rev);
	if(level%2 == 0){
			if(rev && !v.empty()){
			r->d = v.front();
			v.erase(v.begin());
		}
		else
			v.push_back(r->d);
	}
	//cout << r->d << " ";
	reverseAltLevelUsingInOrder(r->rt, level+1, v, rev);
}

void levelwiseLevelOrder(node *r){
	if(!r)
		return;

	queue<node *> q1;
	queue<node *> q2;
	node *t1, *t2;

	q1.push(r);

	while(!q1.empty() || !q2.empty()){
		while(!q1.empty()){
			t1 = q1.front();
			q1.pop();

			cout << t1->d << " ";

			if(t1->lt){
				q2.push(t1->lt);
			}

			if(t1->rt){
				q2.push(t1->rt);
			}
		}cout << endl;

		while(!q2.empty()){
			t2 = q2.front();
			q2.pop();

			cout << t2->d << " ";

			if(t2->lt)
				q1.push(t2->lt);

			if(t2->rt)
				q1.push(t2->rt);
		}cout << endl;
	}cout << endl;
}

int main(){
	node *r = newNode(1);
	r->lt = newNode(2);
	r->rt = newNode(3);
	r->lt->lt = newNode(4);
	r->lt->rt = newNode(5);
	r->rt->lt = newNode(6);
	r->rt->rt = newNode(7);
	r->lt->lt->lt = newNode(8);
	r->lt->lt->rt = newNode(9);
	r->lt->rt->lt = newNode(10);
	r->lt->rt->rt = newNode(11);
	r->rt->lt->lt = newNode(12);
	r->rt->lt->rt = newNode(13);
	r->rt->rt->lt = newNode(14);
	r->rt->rt->rt = newNode(15);

	vector<int> v;
	int level = 1;
	levelwiseLevelOrder(r);
	reverseAltLevelUsingInOrder(r, level, v);
	cout << endl << endl;

	/*vector<int>::iterator it;
	for(it=v.begin(); it!=v.end(); it++)
		cout << *it << " ";
	cout << endl;*/

	reverse(v.begin(), v.end());

	/*for(it=v.begin(); it!=v.end(); it++)
		cout << *it << " ";
	cout << endl;*/

	int rev = 1;
	reverseAltLevelUsingInOrder(r, level, v, rev);
	cout << endl;
	levelwiseLevelOrder(r);

	return 0;
}
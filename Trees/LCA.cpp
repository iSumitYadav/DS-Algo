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

bool lcaUtil(node *r, int n, vector<int> &path){
	if(!r)
		return false;

	path.push_back(r->d);

	if(r->d == n)
		return true;

	bool res = lcaUtil(r->lt, n, path) || lcaUtil(r->rt, n, path);

	if(res == true)
		return true;

	path.pop_back();

	return false;
}

int lca(node *r, int n1, int n2){
	int res = INT_MIN;
	if(!r)
		return res;

	vector<int> path1, path2;

	if(!lcaUtil(r, n1, path1) || !lcaUtil(r, n2, path2))
		return res;

	vector<int>::iterator i, j;

	for(i=path1.begin(), j=path2.begin(); i!=path1.end() && j!=path2.end(); i++, j++){
		if(*i != *j){
			break;
		}
	}

	return *(i-1);
}

int main(){
	node *r = newNode(1);
	r->lt = newNode(2);
	r->rt = newNode(3);
	r->lt->lt = newNode(4);
	r->lt->rt = newNode(5);
	r->rt->lt = newNode(6);
	r->rt->rt = newNode(7);

	cout << "LCA(4, 5) = " << lca(r, 4, 5);
    cout << "\nLCA(4, 6) = " << lca(r, 4, 6);
    cout << "\nLCA(3, 4) = " << lca(r, 3, 4);
    cout << "\nLCA(2, 4) = " << lca(r, 2, 4);
    cout << "\nLCA(5, 6) = " << lca(r, 5, 6);

	return 0;
}
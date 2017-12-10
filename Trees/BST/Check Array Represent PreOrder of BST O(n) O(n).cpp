// http://www.geeksforgeeks.org/check-if-a-given-array-can-represent-preorder-traversal-of-binary-search-tree/
#include<bits/stdc++.h>
using namespace std;

bool isPreOrderOfBST(int pre[], int n){
	stack<int> s;

	int root = INT_MIN;

	for(int i=0; i<n; i++){
		if(pre[i] < root)
			return false;

		while(!s.empty() && pre[i] > s.top()){
			root = s.top();
			s.pop();
		}

		s.push(pre[i]);
	}

	return true;
}

int main(){
	int arr[] = {40, 30, 35, 20, 80, 100};
	int size = sizeof(arr)/sizeof(arr[0]);

	isPreOrderOfBST(arr, size) ? cout << "TRUE" : cout << "FALSE";

	return 0;
}
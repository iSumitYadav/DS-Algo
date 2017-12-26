#include<bits/stdc++.h>
using namespace std;

void findFrequency(string str){
	// O(1), if map was used that'll be O(log n)
	unordered_map<string, int> u_map;

	stringstream ss(str);
	string word;

	while(ss >> word){
		u_map[word]++;
	}

	unordered_map<string, int>::iterator it;
	for(it=u_map.begin(); it!=u_map.end(); it++)
		cout << it->first << " " << it->second << endl;
}

int main(){
	string str;
	getline(cin, str);

	findFrequency(str);

	return 0;
}
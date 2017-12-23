// https://www.geeksforgeeks.org/boggle-find-possible-words-board-characters/
#include<bits/stdc++.h>
using namespace std;

#define M 3
#define N 3

string dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO", "SEEK"};
int dict_size = sizeof(dictionary)/sizeof(dictionary[0]);

int isDictWord(string str){
	for(int i=0; i<dict_size; i++){
		if(str.compare(dictionary[i]) == 0){
			return 1;
		}
	}

	return 0;
}

void findWordsUtil(char boggle[M][N], int row, int col, int visited[M][N], string &str, set<string> &s){
	visited[row][col] = 1;
	str.push_back(boggle[row][col]);

	if(isDictWord(str)){
		s.insert(str);
	}

	for(int i=row-1; i<=row+1 && i<M; i++){
		for(int j=col-1; j<=col+1 && j<N; j++){
			if(i >= 0 && j >= 0 && !visited[i][j])
				findWordsUtil(boggle, i, j, visited, str, s);
		}
	}

	visited[row][col] = 0;
	str.pop_back();
}

void findWords(char boggle[M][N]){
	string str;
	set<string> s;

	int visited[M][N] = {0};

	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			findWordsUtil(boggle, i, j, visited, str, s);
		}
	}

	set<string>::iterator it;
	for(it=s.begin(); it!=s.end(); it++){
		cout << *it << endl;
	}
}

int main(){
	char boggle[M][N] = {{'G','I','Z'},
                         {'U','E','K'},
                         {'Q','S','E'}};
 
    printf("Following words of dictionary are present:\n");

    findWords(boggle);

	return 0;
}
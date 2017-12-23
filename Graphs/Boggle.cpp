#include<bits/stdc++.h>
using namespace std;

#define M 3
#define N 3

string dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO", "SEEK"};
int dict_size = sizeof(dictionary)/sizeof(dictionary[0]);

void findWords(char boggle[M][N]){
	;
}

int main(){
	char boggle[M][N] = {{'G','I','Z'},
                         {'U','E','K'},
                         {'Q','S','E'}};
 
    printf("Following words of dictionary are present:\n");

    findWords(boggle);

	return 0;
}
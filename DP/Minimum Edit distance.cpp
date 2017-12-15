#include<bits/stdc++.h>
using namespace std;

int minEditDistance(char x[], char y[], int l1, int l2){
	int dp[l1+1][l2+1], i, j;

	for(i=0; i<=l1; i++){
		for(j=0; j<=l2; j++){
			// cost to change(DELETE) all J characters of string2 to NULL string1(i==0) is j
			if(i == 0)
				dp[i][j] = j;

			// cost to change(INSERT) all I characters of string1 to NULL string2(j==0) is i
			else if(j == 0)
				dp[i][j] = i;

			// No cost incured if the character is same in both strings
			// OR
			// the cost is same as for a string of 1 character less
			else if(x[i-1] == y[j-1])
				dp[i][j] = dp[i-1][j-1];

			else{
				dp[i][j] = 1 + min(min(dp[i-1][j], 		// Insert
							dp[i][j-1]), 		// Delete
							dp[i-1][j-1]); 		// Replace
			}
		}
	}

	return dp[l1][l2];
}

int main(){
	char x[] = "abcdef";
	char y[] = "azced";
	int l1 = strlen(x);
	int l2 = strlen(y);

	cout << minEditDistance(x, y, l1, l2);

	return 0;
}
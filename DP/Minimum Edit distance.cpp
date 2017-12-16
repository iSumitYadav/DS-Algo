#include<bits/stdc++.h>
using namespace std;

int minEditDistance(char x[], char y[], int l1, int l2){
	int dp[l2+1][l1+1], i, j;

	for(i=0; i<=l2; i++){
		for(j=0; j<=l1; j++){
			// cost to change(DELETE) all J characters of string2 to NULL string1(i==0) is j
			if(i == 0)
				dp[i][j] = j;

			// cost to change(INSERT) all I characters of string1 to NULL string2(j==0) is i
			else if(j == 0)
				dp[i][j] = i;

			// No cost incured if the character is same in both strings
			// OR
			// the cost is same as for a string of 1 character less
			else if(x[j-1] == y[i-1])
				dp[i][j] = dp[i-1][j-1];

			else{
				dp[i][j] = 1 + min(min(dp[i-1][j], 		// Insert
							dp[i][j-1]), 				// Delete
							dp[i-1][j-1]); 				// Replace
			}
		}
	}

	cout << x << endl << y << "\n\n";

	/*for(i=1;i<=l2;i++){
		for(j=1;j<=l1;j++){
			cout << dp[i][j] << " ";
		}cout << endl;
	}cout << endl;*/

	i = l2, j = l1;
	while(i && j){
		if(x[j-1] == y[i-1]){
			i--;
			j--;
		}else if(dp[i][j] == 1 + dp[i-1][j]){
			// Insert
			cout << y[i-1] << " Inserted\n";
			i--;
		}else if(dp[i][j] == 1 + dp[i][j-1]){
			// Delete
			cout << x[j-1] << " Deleted\n";
			j--;
		}else if(dp[i][j] == 1 + dp[i-1][j-1]){
			// Replace
			cout << x[j-1] << " Replaced with " << y[i-1] << endl;
			i--;
			j--;
		}
	}cout << endl;

	return dp[l2][l1];
}

int main(){
	char x[] = "adc";
	char y[] = "ab";
	int l1 = strlen(x);
	int l2 = strlen(y);

	cout << "Min. edit distance is : " << minEditDistance(x, y, l1, l2);

	return 0;
}
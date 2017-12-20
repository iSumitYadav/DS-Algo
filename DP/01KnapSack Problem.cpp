#include<bits/stdc++.h>
using namespace std;

int knapSack(int val[], int wt[], int n, int wtAllowed){
	int dp[n+1][wtAllowed+1];

	for(int i=0; i<=n; i++){
		for(int j=0; j<=wtAllowed; j++){
			if(i == 0 || j == 0)
				dp[i][j] = 0;
			else if(j < wt[i-1])
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j - wt[i-1]]);
		}
	}

	/*for(int i=0; i<=n; i++){
		for(int j=0; j<=wtAllowed; j++){
			printf("%2d ", dp[i][j]);
		}printf("\n");
	}printf("\n");*/

	return dp[n][wtAllowed];
}

int main(){
	int wt[] = {1, 3, 4, 5};
	int val[] = {1, 4, 5, 7};
	int n = sizeof(val)/sizeof(val[0]);

	int wtAllowed;

	while(scanf("%d", &wtAllowed) && wtAllowed > 0)
		printf("Max Val allowed for %d wt: %d\n\n", wtAllowed, knapSack(val, wt, n, wtAllowed));

	return 0;
}
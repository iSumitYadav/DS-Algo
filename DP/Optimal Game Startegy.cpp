#include<bits/stdc++.h>
using namespace std;

struct game{
	int first;
	int second;
};

game optimalGameStrategy(int *arr, int n){
	game dp[n][n];
	memset(dp, 0, sizeof(dp));
	int len, strt, end, i, j;

	for(len=1; len<=n; len++){
		// printf("len=%d\n", len);
		for(strt=0; strt+len-1 < n; strt++){ // strt + len -1 should be less than n
			end = strt + len - 1;
			// printf("%d %d\n\n", strt, end);

			// If only one value to choose, first player we take it and left 2nd player with zero value
			if(strt == end){
				dp[strt][end].first = arr[strt];
				dp[strt][end].second = 0;
			}else{
				// 1st player will choose maximum of the left-most value + what is left after(second value) 2nd player played his move on (strt+1 to end) OR the right-most value + what is left after(second value) 2nd player played his move on (strt to end-1)
				dp[strt][end].first = max((arr[strt] + dp[strt+1][end].second), (arr[end] + dp[strt][end-1].second));

				// 2nd player will get minimum of the first(as maximum of first is for 1st player) after 1st player made his move (either strt+1 to end if 1st chose strt element OR strt to end-1 if 1st player chose end element)
				dp[strt][end].second = min(dp[strt+1][end].first, dp[strt][end-1].first);
			}
		}
	}

	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(dp[i][j].first)
				printf("(%2d, %2d) ", dp[i][j].first, dp[i][j].second);
			else
				printf("(__, __) ");
		}printf("\n");
	}

	return dp[0][n-1];
}

int main(){
	int arr[] = {20, 30, 2, 2, 2, 10};
	int n = sizeof(arr)/sizeof(arr[0]);

	game g = optimalGameStrategy(arr, n);
	printf("\nFirst Player: %d\nSecond Player: %d\n", g.first, g.second);

	return 0;
}
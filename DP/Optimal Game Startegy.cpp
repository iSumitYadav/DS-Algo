#include<bits/stdc++.h>
using namespace std;

struct game{
	int first;
	int second;
};

game optimalGameStrategy(int *arr, int n, int printDP){
	game dp[n][n];
	//memset(dp, 0, sizeof(dp));
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

	if(printDP){
			for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				if(i <= j)
					printf("(%2d, %2d) ", dp[i][j].first, dp[i][j].second);
				else
					printf("(__, __) ");
			}printf("\n");
		}printf("\n");
	}

	return dp[0][n-1];
}

game optimalGameStrategyMethod2(int arr[], int n, int printDP){
	game dp[n][n];
	int len, strt, end, i, j;

	for(len=1; len<=n; len++){
		// for(strt=0; strt + len -1 < n; strt++){
		strt = 0;
		end = strt + len - 1;
		while(end < n){
			if(strt == end){
				dp[strt][end].first  = arr[strt];
				dp[strt][end].second = 0;
			}else if(arr[strt] + dp[strt+1][end].second > dp[strt][end-1].second + arr[end]){
				dp[strt][end].first  = arr[strt] + dp[strt+1][end].second;
				dp[strt][end].second = dp[strt+1][end].first;
			}else{
				dp[strt][end].first  = dp[strt][end-1].second + arr[end];
				dp[strt][end].second = dp[strt][end-1].first;
			}
			strt++;
			end = strt + len - 1;
		}
	}

	if(printDP){
			for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				if(i <= j)
					printf("(%2d, %2d) ", dp[i][j].first, dp[i][j].second);
				else
					printf("(__, __) ");
			}printf("\n");
		}printf("\n");
	}

	return dp[0][n-1];
}

int main(){
	int arr[] = {20, 30, 2, 2, 2, 10};
	int n = sizeof(arr)/sizeof(arr[0]);
	int printDP = 0;

	game g = optimalGameStrategy(arr, n, printDP);
	printf("First Player:  %d\nSecond Player: %d\n\n", g.first, g.second);

	g = optimalGameStrategyMethod2(arr, n, printDP);
	printf("First Player:  %d\nSecond Player: %d\n", g.first, g.second);

	return 0;
}
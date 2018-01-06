// https://www.geeksforgeeks.org/greedy-algorithms-set-1-activity-selection-problem/
#include<bits/stdc++.h>
using namespace std;

struct activity{
	int start, finish;
};

bool compare(activity one, activity two){
	if(one.finish != two.finish)
		return one.finish < two.finish;
	else
		return one.start < two.start;
}

void activitySelection(activity *arr, int n){
	sort(arr, arr+n, compare);

	// for(int i=0; i<n; i++){
	// 	printf("%d\t%d\n", arr[i].start, arr[i].finish);
	// }

	printf("Start\tFinish\n");
	printf("%d\t%d\n", arr[0].start, arr[0].finish);
	int prev = 0;
	for(int i=1; i<n; i++){
		if(arr[prev].finish <= arr[i].start){
			printf("%d\t%d\n", arr[i].start, arr[i].finish);
			prev = i;
		}
	}
}

int main(){
	while(1){
		int n;
		printf("Enter No. of Activities: ");
		scanf("%d", &n);

		if(n < 1)
			break;

		activity *arr = new activity[n];
		printf("Start\tFinish\n");
		for(int i=0; i<n; i++){
			scanf("%d %d", &(arr[i].start), &(arr[i].finish));
		}

		printf("\nSelected Activities are:\n");
		activitySelection(arr, n);
		printf("\n");
	}
	return 0;
}
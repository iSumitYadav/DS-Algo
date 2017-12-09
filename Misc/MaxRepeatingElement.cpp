#include<bits/stdc++.h>
using namespace std;

void maxHeapify(int arr[], int heap_size, int i){
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;

	if(left < heap_size && arr[left] > arr[largest])
		largest = left;
	if(right < heap_size && arr[right] > arr[largest])
		largest = right;

	if(largest != i){
		swap(arr[i], arr[largest]);
		maxHeapify(arr, heap_size, largest);
	}
}

void buildHeap(int arr[], int n){
	for(int i=(n/2)-1; i>=0; i--){
		maxHeapify(arr, n, i);
	}
}

void heapSort(int arr[], int n){
	buildHeap(arr, n);

	for(int i=n-1; i>=0; i--){
		swap(arr[0], arr[i]);
		maxHeapify(arr, i, 0);
	}
}

int *maxRepeatingElement(int arr[], int n){
	heapSort(arr, n);

	for(int i=0; i<n; i++)
		cout << arr[i] << " ";

	int i=0, j=1, cnt=1, maxCnt=1, maxRepElem=arr[0];

	while(j < n){
		if(arr[i] == arr[j]){
			cnt++;
		}else{
			cnt=1;
		}

		if(cnt > maxCnt){
			maxCnt = cnt;
			maxRepElem = arr[i];
		}

		i++;
		j++;
	}

	static int ans[2];
	ans[0] = maxRepElem;
	ans[1] = maxCnt;

	return ans;
}

int main(){
	int arr[] = {3,3,3,8,3,8,3,1,4,8,6,8,8,7,2,6,5,9};
	int n = sizeof(arr)/sizeof(arr[0]);

	int *ans = maxRepeatingElement(arr, n);
	cout << endl << ans[0] << " repeated " << ans[1] << " times!";

	return 0;
}
#include<bits/stdc++.h>
using namespace std;

class MinHeap{
	int *harr;
	int capacity;
	int heap_size;

public:
	MinHeap(int arr[], int size); // Constructor
	void MinHeapify(int i);
	int extractMin();

	int getParent(int child){
		return (child-1)/2;
	}

	int getLeftChild(int parent){
		return 2*parent + 1;
	}

	int getRightChild(int parent){
		return 2*parent + 2;
	}

	int getMin(){
		return harr[0];
	}
};

MinHeap::MinHeap(int arr[], int size){
	heap_size = size;
	harr = arr;

	int i = (heap_size - 1)/2;

	while(i >= 0){
		MinHeapify(i);
		i--;
	}
}

void MinHeap::MinHeapify(int i){
	int smallest = i;
	int left = getLeftChild(i);
	int right = getRightChild(i);

	if(left < heap_size && harr[left] < harr[smallest])
		smallest = left;

	if(right < heap_size && harr[right] < harr[smallest])
		smallest = right;

	if(smallest != i){
		swap(harr[i], harr[smallest]);
		MinHeapify(smallest);
	}
}

int MinHeap::extractMin(){
	if(heap_size == 0)
		return INT_MAX;

	int root = harr[0];

	if(heap_size > 1){
		harr[0] = harr[heap_size-1];
		MinHeapify(0);
	}
	heap_size--;

	return root;
}

int kthSmallestElement(int arr[], int n, int k){
	int arr2[n];
	for(int i=0;i<n;i++)
		arr2[i] = arr[i];

	MinHeap mh(arr2, n);

	for(int i=1; i<k; i++)
		mh.extractMin();

	return mh.getMin();
}

int main(){
	int arr[] = {9,6,8,99,6,3,2,4,5,10};
	int size = sizeof(arr)/sizeof(arr[0]);

	//int k;
	//cin >> k;

	for(int i=1; i<=size; i++)
		cout << i << " Smallest Element: " << kthSmallestElement(arr, size, i) << endl;

	return 0;
}
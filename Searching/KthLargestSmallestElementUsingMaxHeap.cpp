#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
	int *harr;
	int heap_size;
	int count;
public:
	MaxHeap(int *arr, int n);
	void MaxHeapify(int i);
	int extractMax();

	int getParent(int child){
		return (child - 1)/2;
	}

	int getLeftChild(int parent){
		return 2*parent + 1;
	}

	int getRightChild(int parent){
		return 2*parent + 2;
	}

	int getMax(){
		return harr[0];
	}
};

MaxHeap::MaxHeap(int *arr, int n){
	harr = arr;
	heap_size = n;

	for(int i=(heap_size-1)/2; i>=0; i--)
		MaxHeapify(i);
}

void MaxHeap::MaxHeapify(int i){
	int smallest = i;
	int l = getLeftChild(i);
	int r = getRightChild(i);

	if(l < heap_size && harr[l] > harr[smallest])
		smallest = l;
	if(r < heap_size && harr[r] > harr[smallest])
		smallest = r;

	if(smallest != i){
		swap(harr[smallest], harr[i]);
		MaxHeapify(smallest);
	}
}

int MaxHeap::extractMax(){
	if(heap_size == 0)
		return INT_MAX;

	int root = harr[0];

	if(heap_size > 1){
		harr[0] = harr[heap_size-1];
		MaxHeapify(0);
	}
	heap_size--;

	return root;
}

int kthSmallestElement(int *arr, int n, int k){
	int arr2[n];
	for(int i=0;i<n;i++)
		arr2[i] = arr[i];

	MaxHeap mh(arr2, k);

	for(int i=k; i<n; i++){
		if(arr2[0] > arr2[i]){
			arr2[0] = arr2[i];
			mh.MaxHeapify(0);
		}
	}

	return mh.getMax();
}

int main(){
	int arr[] = {4,2,1,5,3,6,70,9,8,11};
	int n = sizeof(arr)/sizeof(arr[0]);

	int k = 2;
	for(k=1;k<=n; k++)
		cout << k << " Smallest Element: " << kthSmallestElement(arr, n, k) << endl;

	return 0;
}
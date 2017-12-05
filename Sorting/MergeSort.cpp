#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int h){
    int n1 = m - l + 1;// think of l=0 and h=1, 2 element-case, so m should be 0 as well which gives n1 = 1 (l,m = 0)
    int n2 = h - m;// h = 1 and m = 0, gives n2 = 1(1-0)
    
    int left[n1], right[n2];
    
    for(int i=0; i<n1; i++)
        left[i] = arr[i + l];//indexing for left part arr will start from (l+ith) index
    for(int j=0; j<n2; j++)
        right[j] = arr[j + m + 1];//indexing for right part arr will start from (m+1 + jth) index
    
    int i=0, j=0, k=l;
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            arr[k++] = left[i++];
        }else{
            arr[k++] = right[j++];
        }
    }
    
    while(i < n1)
        arr[k++] = left[i++];
    while(j < n2)
        arr[k++] = right[j++];
    
    return;
}

void mergeSort(int arr[], int l, int h){
    if(l < h){
        int mid = l + (h - l)/2;
        
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, h);
        
        merge(arr, l, mid, h);
    }
    return;
}

int main() {
	int n, i;
	cin >> n;
	
	int *arr = new int[n];
	for(i=0; i<n; i++){
	    cin >> arr[i];
	    cout << arr[i] << " ";
	}cout << endl;
	
	mergeSort(arr, 0, n-1);
	
	for(i=0; i<n; i++)
	    cout << arr[i] << " ";
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

void merge(int* arr, int start, int mid, int end){
	vector<int>ans(end-start+1);
	int i = start, j = mid + 1, k = 0;

	while(i<=mid and j<=end){
		if(arr[i]<=arr[j]) ans[k++] = arr[i++];
		else ans[k++] = arr[j++];
	}

	while(i<=mid){
		ans[k++] = arr[i++];
	}

	while(j<=end){
		ans[k++] = arr[j++];
	}

	for(int m = start; m<=end; m++){
		arr[m] = ans[m-start];
	}
}

void merge_sort(int* arr, int start, int end){
	if(start == end){
		return;
	}
	int mid = start + (end-start)/2;
	merge_sort(arr, start, mid);
	merge_sort(arr, mid+1, end);
	merge(arr, start, mid, end);
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}

	merge_sort(arr, 0, n-1);

	for(int i = 0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}
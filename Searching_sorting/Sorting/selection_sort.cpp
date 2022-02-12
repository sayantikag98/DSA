#include<bits/stdc++.h>
using namespace std;

int min_index(int* arr, int ind, int n){
	int min = ind;
	for(int i = ind + 1; i<n; i++){
		if(arr[min]>arr[i]) min = i;
	}
	return min;
}

void selection_sort(int* arr, int n){
	for(int i = 0; i<n-1; i++){ 
		int min = min_index(arr, i, n);
		if(min!=i) swap(arr[i], arr[min]);
	}
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}

	selection_sort(arr, n);

	for(int i = 0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
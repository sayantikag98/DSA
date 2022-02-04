#include<bits/stdc++.h>
using namespace std;

void swap(int* arr, int i, int k){
	int temp = arr[i];
	arr[i] = arr[k];
	arr[k] = temp;
}

void print(int* arr, int n){
	for(int j = 0; j<n; j++){
		cout<<arr[j]<<" ";
	}
	cout<<endl;
}

void permutation(int* arr, int i, int n){
	if(i == n-1){
		print(arr, n);
		bool isSorted = true;
		for(int j = 0; j<n-1; j++){
			if(arr[j]>arr[j+1]){
				isSorted = false;
				break;
			}
		}
		if(isSorted){
			cout<<"_________Sorted Array____________\n";
			print(arr, n);
		}
	}
	for(int k = i; k<n; k++){
		swap(arr, i, k);
		permutation(arr, i+1, n);
		swap(arr, i, k); // backtracking
	}
}

// backtracking is needed because we are changing the original array

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}
	permutation(arr, 0, n);
}

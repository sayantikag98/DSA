#include<iostream>
using namespace std;


void insertionSort(int* arr, int n){
	for(int i = 1; i<n; i++){
		int temp = arr[i], j = i-1;
		for(; j>=0; j--){
			if(arr[j]>temp){
				arr[j+1] = arr[j]; 
			}
			else break;
		}
		arr[j+1] = temp;
	}
}

// 1 4 5 2
// i = 3, temp = 2, j = 2
// 1 2 4 5



int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}
	insertionSort(arr, n);
	for(int i = 0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
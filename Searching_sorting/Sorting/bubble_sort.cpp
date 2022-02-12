#include<iostream>
using namespace std;

int count = 0;

void bubbleSort(int* arr, int n){
	for(int i = n-1; i>0; i--){
		int swaps = 0;
		for(int j = 0; j<i; j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j], arr[j+1]);
				swaps++;
				count++;
			}
		}
		if(!swaps) return;
	}
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}
	bubbleSort(arr, n);
	for(int i = 0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	cout<<count<<endl;
}
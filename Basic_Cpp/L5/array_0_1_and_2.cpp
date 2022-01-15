#include<iostream>
#include<cmath>
using namespace std;

// Array can be passed in function as int* arr or int arr[]
void func(int arr[], int n){
	int left = 0, mid = 0, right = n-1;
	while(mid<=right){
		if(arr[mid] == 1) mid++;
		else if(arr[mid] == 0){
			swap(arr[left], arr[mid]);
			left++;
			mid++; // can increase mid here because mid already has traversed that region as mid is traversing from left to right
		}
		else{
			swap(arr[mid], arr[right]);
			right--; // cannot increase mid here because mid does not know what values will be at arr[right]
		}
	}
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}
	func(arr, n);
	// arrays are passed by reference so if the original array is being modified 
	// then can print the array in the main function
	for(int i = 0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<pow(2,5)<<endl;
}
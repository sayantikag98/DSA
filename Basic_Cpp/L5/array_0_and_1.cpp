#include<iostream>
using namespace std;

// if the left pointer point towards zero then shift it right 
// and if its one then swap it if the right one is zero then move both 
// the left and the right pointer and if the right one is one then shift
// the right pointer only and not the left one 

void func_sanket(int* arr, int n){
	int left = 0, right = n - 1;
	while(left<=right){
		if(!arr[left]) left++; // if arr[left] == 0
		else{
			if(!arr[right]){ // if(arr[left] == 1 and arr[right] == 0)
				swap(arr[left], arr[right]);
				left++;
			}
			right--;
		}
	}
	for(int i = 0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

void func(int* arr, int n){
	int left = 0, right = n - 1;
	while(left<=right){
		if(arr[left] == 0 and arr[right] == 1){
			left++;
			right--;
		}
		else if(arr[left] == 0 and arr[right] == 0){
			left++;
		}
		else if(arr[left] == 1 and arr[right] == 1){
			right--;
		}
		else if(arr[left] == 1 and arr[right] == 0){
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}
	for(int i = 0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}
	func(arr, n);
	func_sanket(arr, n);
	
}
#include<iostream>
using namespace std;

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
			arr[left] = 0;
			arr[right] = 1;
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
	
}
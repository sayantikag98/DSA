// find all pairs in a sorted array whose sum is equal to s
#include<iostream>
#include<algorithm>
using namespace std;

void func(int arr[], int n, int s){
	int low = 0, high = n-1;
	while(low!=high){
		if(arr[low] + arr[high] == s){
			cout<<"("<<arr[low]<<","<<arr[high]<<")"<<endl;
			low++;
		}
		else if(arr[low] + arr[high] > s){
			high--;
		}
		else low++;
	}
}

int main(){
	int n, s;
	cin>>n;
	int arr[n];
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}
	sort(arr, arr+n);
	cin>>s;
	func(arr, n, s);
}
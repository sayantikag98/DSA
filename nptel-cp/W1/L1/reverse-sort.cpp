#include<iostream>
using namespace std;

int reverse_sort(int* arr, int n){
	int cost = 0;
	for(int i = 0; i<n-1; i++){
		int min = i;
		for(int j = i+1; j<n; j++){
			if(arr[min]>arr[j]) min=j;
		}
		for(int k = i; k<=i+(min-i)/2; k++){
			int temp = arr[k];
			arr[k] = arr[min-k+i];
			arr[min-k+i] = temp;
		}
		cost += (min-i+1);
	}
	return cost;
}

int main(){
	int test;
	cin>>test;
	for(int t = 1; t<=test; t++){
		int n;
		cin>>n;
		int arr[n];
		for(int i = 0; i<n; i++){
			cin>>arr[i];
		}
		cout<<"Case #"<<t<<": "<<reverse_sort(arr, n)<<"\n";	
	}
}





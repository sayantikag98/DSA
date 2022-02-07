#include<bits/stdc++.h>
using namespace std;

int reverse_sort_nptel(vector<int> arr, int n){
	int cost = 0;
	for(int i = 0; i<n-1; i++){
		// min_element => Returns an iterator pointing to the element with the smallest value in the range [first,last)
		int minElement = *min_element(arr.begin()+i, arr.end());
		// find() => Returns an iterator to the first element in the range [first,last) that compares equal to val. If no such element is found, the function returns last.
		auto j = find(arr.begin()+i, arr.end(), minElement);
		// reverse() => Reverses the order of the elements in the range [first,last).
		reverse(arr.begin()+i, j+1);
		// distance => Calculates the number of elements between first and last.
		cost += distance(arr.begin(), j+1) - i;
	}
	return cost;
}

int reverse_sort(vector<int> arr, int n){
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
		vector<int> arr(n);
		for(int i = 0; i<n; i++){
			cin>>arr[i];
		}
		// cout<<"Case #"<<t<<": "<<reverse_sort(arr, n)<<"\n";
		cout<<"Case #"<<t<<": "<<reverse_sort_nptel(arr, n)<<"\n";
	}
}





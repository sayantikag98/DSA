#include<iostream>
using namespace std;

void bubble_sort_recursive(int* arr, int p, int i, int n, int swaps){

	if(p==0) return; // for reaching the end of all the passes through the array => array has been completely sorted

	if(i == p){ // for each pass the comparison has reached its end
		if(!swaps) return; // when there is no swaps for a complete pass then the array is completely sorted
		bubble_sort_recursive(arr, p-1, 0, n, 0);  // for going to the next pass
		return;
	}

	if(arr[i]>arr[i+1]){  // comparing current element with its next element
		swap(arr[i], arr[i+1]); // swap when the current element is greater than the next element
		swaps++;  // count the number of swaps => required for ending the bubble sort just at the time when the array is completely sorted
	}
	bubble_sort_recursive(arr, p, i+1, n, swaps); // for going to the next element in a pass

}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}

	bubble_sort_recursive(arr, n-1, 0, n, 0);

	for(int i = 0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
#include<iostream>
#define int long long int
using namespace std;


// Approach 1 => TC - O(n) and SC - O(n)

int func1(int* arr, int n){
	int suffix[n];
	suffix[n-1] = arr[n-1];
	for(int i = n-2; i>=0; i--){
		suffix[i] = arr[i] + suffix[i+1];
	}
	int ans = 0;
	for(int i = 0; i<n-1; i++){
		ans += (arr[i] * suffix[i+1]);
	}
	return ans;
}

// Sanket's Approach => TC - O(n) and SC - O(1)

int func2(int* arr, int n){
	int sum = 0, sumSquares = 0;
	for(int i = 0; i<n; i++){
		sum += arr[i];
		sumSquares += (arr[i] * arr[i]);
	}
	int ans = (sum * sum - sumSquares)/2;
	return ans;
}

int func3(int* arr, int n){
	int ans = 0;
	for(int i = 0; i<n-1; i++){
		for(int j = i+1; j<n; j++){
			ans+= (arr[i] * arr[j]);
		}
	}
	return ans;
}


int32_t main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}

	int ans = func1(arr, n);
	int ans1 = func2(arr, n);
	int ans2 = func3(arr, n);

	
	cout<<ans<<" "<<ans1<<" "<<ans2<<endl;
}

/*

array => 1,2,3
ans:= 1*2 + 1*3 + 2*3
=>    1*[2+3] + 2*3

suffix sum array


*/
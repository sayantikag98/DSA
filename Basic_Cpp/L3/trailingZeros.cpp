#include<iostream>
#include<cmath>
#define int long long int
using namespace std;

// Approach 1: TC => O(n) + O(no of trailing zeros in n!)

int func1(int n){
	if(n == 0 or n == 1){
		cout<<"No trailing zeros\n";
		return 0;
	}
	int fact = 1;
	for(int i = 2; i<=n; i++){
		fact*=i;
	}
	int count = 0;
	while(!(fact%5)){
		count++;
		fact/=5;
	}
	return count;
}

// Sanket's Approach: TC => 

int func2(int n){
	int div = 5, count = 0;
	while(n/div){
		count += floor(n/div);
		div*=5;
	}
	return count;
}

int32_t main(){
	int n;
	cin>>n;
	cout<<" "<<func2(n)<<endl;
}


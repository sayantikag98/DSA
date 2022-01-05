#include<iostream>
#include<cmath>
#define int long long int
using namespace std;

int32_t main(){
	int n = 75625450005080000;
	int ans = 0;

	while(n){
		int digit = n % 10;
		ans = ans * 10 + digit;
		n/=10;
	}

	cout<<ans<<endl;
}

//O(n) n is the total number of digits
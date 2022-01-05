#include<iostream>
#define int long long int
using namespace std;

int sumOfFactors(int num, int n){
	int largestNumberDivisibleByNum, firstNumberDivisibleByNum = (n > num) ? num : 0;
	if(n%num == 0) largestNumberDivisibleByNum = n - num;
	else largestNumberDivisibleByNum = n - n%num;
	int sumOfFactorsDivisibleByNum = (largestNumberDivisibleByNum * (largestNumberDivisibleByNum + firstNumberDivisibleByNum))/(num * 2);
	return sumOfFactorsDivisibleByNum;
}




int32_t main(){
	int test, n; 
	cin>>test;
	while(test--){
		cin>>n;
		cout<<sumOfFactors(3, n) + sumOfFactors(5, n) - sumOfFactors(15, n)<<"\n";
	}
}
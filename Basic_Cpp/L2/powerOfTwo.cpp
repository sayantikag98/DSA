#include<iostream>
#define int long long int
using namespace std;


// TC -> O(log b base 2) SC -> O(1) for both the iterative and recursive approach

int funcIter(int a, int b){  
	int ans = 1;
	while(b){
		if(b&1) ans*=a;
		b/=2;
		a*=a;
	}
	return ans;
}


int funcRec(int a, int b){
	if(b == 0) return 1;
	if(b == 1) return a;
	int ans = funcRec(a, b/2);
	if(b&1) return a * ans * ans;
	else return ans * ans;

}


int32_t main(){
	int test, a, b;
	cin>>test;
	while(test--){
		cin>>a>>b;
		cout<<funcRec(a, b)<<endl;
		cout<<funcIter(a, b)<<endl;	
	}
}




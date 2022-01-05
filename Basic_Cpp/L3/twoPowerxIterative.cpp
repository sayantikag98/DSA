#include<iostream>
using namespace std;

int func(int a, int b){
	int ans = 1;
	while(b){
		if(b&1){
			ans*=a;
		}
		b/=2;
		a*=a;
	}
	return ans;
}

int main(){
	int a, b;
	cin>>a>>b;
	cout<<func(a,b)<<endl;
}
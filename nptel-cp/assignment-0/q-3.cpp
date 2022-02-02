#include<iostream>
using namespace std;

int func(int n){
	if(n==1) return 2;
	if(n==2) return 3;
	return func(n-1)+func(n-2);


}

int main(){
	int n;
	cin>>n;
	cout<<func(n)<<endl;
}
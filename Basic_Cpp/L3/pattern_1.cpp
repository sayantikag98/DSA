#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int nsp = 2*n-2, nst = 1, row = 1;
	while(row<=n){
		for(int i = 1; i<=nsp; i++)
			cout<<" ";
		for(int i = 1; i<=nst; i++)
			cout<<"* ";
		row++;
		cout<<endl;
		nsp-=2;
		nst+=2;
	}
}
#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int nsp = 2*n-2, val = 1, nst = 1, row = 1;
	while(row<=n){
		for(int i = 1; i<=nsp; i++){
			cout<<" ";
		}
		for(int i = 1; i<=nst; i++){
			cout<<val<<" ";
			if(i<(nst+1)/2) val++;
			else if(i!=nst and i>=(nst+1)/2) val--;
		}
		row++;
		cout<<endl;
		nsp-=2;
		nst+=2;
	}

}
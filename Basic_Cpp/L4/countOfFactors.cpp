#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int count = 0;
	for(int i = 1; i<=n; i++){
		if(!(n%i)) {
			count++;
			cout<<i<<" ";
		}
	}
	cout<<"\n";
	cout<<count<<endl;
}
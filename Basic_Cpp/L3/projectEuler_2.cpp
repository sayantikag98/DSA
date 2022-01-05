#include<iostream>
#define int long long int
using namespace std;

int sum = 0;

int funcRec(int n){
	if(n == 0) return 2;
	if(n == 1) return 8;
	int lastEvenFib = funcRec(n-1), secondLastEvenFib = funcRec(n-2);
	int nthEvenFib = 4 * lastEvenFib + secondLastEvenFib;
	cout<<nthEvenFib<<" ";
	if(nthEvenFib<=n){
		sum+=nthEvenFib;
	}
	return nthEvenFib;
}


int funcIter(int n){
	int a = 0, b = 2, sum = 0;
	while(a<=n){
		cout<<a<<" ";
		sum += a;
		int c = a + 4 * b;
		a = b;
		b = c;
	}
	cout<<"\n";
	return sum;
}

int32_t main(){
	int test, n;
	cin>>test;
	while(test--){
		cin>>n;
		// cout<<funcIter(n)<<"\n";
		cout<<"\n"<<funcRec(n)<<"\n";
		cout<<sum<<endl;
	}
}
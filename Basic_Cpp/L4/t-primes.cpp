#include<bits/stdc++.h>
 
#define int long long int
using namespace std;
 
vector<int> primes(1000002, 1);
unordered_set<int>s;
 
 
void allPrimes (int n){
	primes[0] = 0;
	primes[1] = 0;
	for(int i = 2; i*i <=n; i++){
		if(primes[i]){
			for(int j = i; i*j<=n; j++){
				primes[i*j]= 0;
			}
		}	
	}
	for(int i = 0; i<=n; i++){
		if(primes[i]){
			s.insert(i*i);
		}
	}
 
}
 
 
int32_t main(){
	int test, n;
	allPrimes(1000001);
	cin>>test;
 
	while(test--){
		cin>>n;
		if(s.find(n) == s.end()) cout<<"NO\n";
		else cout<<"YES\n";
	}
}	
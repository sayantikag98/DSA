#include<iostream>
#include<vector>
#define int long long int

using namespace std;

vector<bool> primes (1000005, 1);



// finding square root using binary search TC => O(log n)
int findSquareRoot(int x){
	int low = 1, high = 1e7;
	while(low<=high){
		int mid = low + (high - low)/2;
		if(mid * mid == x) return mid;
		else if(mid * mid > x) high = mid - 1;
		else low = mid + 1;
	}
	return high;
}

//finding whether square root is prime or not using sieve of eratosthenes TC => O(n * log(log n))
void allPrimesUsingSieve(){
	primes[0] = 0;
	primes[1] = 0;
	for(int i = 2; i*i<=1000004; i++){
		if(primes[i]){
			for(int j = i; i*j<=1000004; j++){
				primes[i*j] = 0;
			}
		}
	}
}

int32_t main(){
	int n, x;
	cin>>n;
	allPrimesUsingSieve();
	while(n--){
		cin>>x;
		int sq = findSquareRoot(x);
		if(primes[sq] and (sq*sq == x)) cout<<"YES\n";
		else cout<<"NO\n";
	}
}

// Highest bounds of n = 10^12
// Total TC => O((n^0.5) * log(log n^0.5)) + (10^5 * (log(n) + 1))
// n being 10^12 TC => O((10^6) * log(log (10^6))) + (10^5 * (log(10^12) + 1))


#include<iostream>
using namespace std;

int main(){
	int num, n, ans = 0;
	cin>>num;
	while(num--){
		cin>>n;
		ans ^= n;
	}
	cout<<ans<<endl;
}

// TC => O(n) and SC => O(1)
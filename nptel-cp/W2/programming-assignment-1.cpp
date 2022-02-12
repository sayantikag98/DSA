#include<bits/stdc++.h>
#define int long long int

using namespace std;

int func(set<int> &s, int n){
	int ans = 0, max_ele = *max_element(s.begin(), s.end());
	for(auto &ele: s){
		ans = max(ans, max_ele-ele);
	}
	return ans;
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		set<int> s;
		for(int i = 0; i<n; i++){
			int ele;
			cin>>ele;
			s.insert(ele);
		}
		cout<<func(s, n)<<endl;
	}


}

		
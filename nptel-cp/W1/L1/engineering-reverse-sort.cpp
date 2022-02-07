#include<bits/stdc++.h>

using namespace std;

// Google Code Jam 2021 Qualification Round

list<int> engineeringReverseSort(int n, int c){
	list<int> ans;
	vector<int> cost(n);
	for(int i = 0; i<cost.size(); i++){
		cost[i] = i;
	}

	// cost (c) should lie within the range n-1 <= c <= (n*n + n - 2)/2
	// if outside the range then print impossible
	if(c<n-1 or c>(n*n+n-2)/2) {
		ans.push_back(-1);
		return ans;
	}

	// the cost vector holds the cost of the sublist for that particular element
	// cost vector => [c1, c2, c3, c4, c5, .......] 
	// c1 is the cost of the sublist of size 1, c2 is the cost of the sublist of size 2
	int start = 2;
	while(cost[cost.size()-1]!=c){
		if((start*start + start - 2)/2 == cost[start-1]){
			start++;
		}
		for(int i = start-1; i<n; i++){
			if(cost[cost.size()-1] == c) break;
			else cost[i]++;
		}	
	}
	
	for(int i = cost.size()-1; i>=1; i--){
		cost[i] -= cost[i-1];
	}

	// this is the formation of the actual list iteratively following the cost
	// if there is a list of n-1 elements which has a cost of D eg: [x1, x2, x3, x4, x5]
	// then to make a list of n elements of cost D+3 we insert a new element 1 in the list such that
	// [x2, x1, 1, x3, x4, x5]
	
	for(int i = n; i>=1; i--){
		auto it = ans.begin();
		int eleCost = cost.at(n-i);
		if(!eleCost) ans.insert(ans.begin(), i);
		else {
		advance(it, eleCost - 1);
		ans.insert(it, i);
		}
		it = ans.begin();
		advance(it, eleCost - 1);
		reverse(ans.begin(), it);
	}	
	return ans;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int test;
	cin>>test;
	for(int t = 1; t<=test; t++){
		int n, c;
		cin>>n>>c;
		cout<<"Case #"<<t<<": ";
		list<int> ans = engineeringReverseSort(n, c);
		for(auto &ele: ans){
			if(ele == -1) cout<<"IMPOSSIBLE";
			else cout<<ele<<" ";
		}
		cout<<endl;
	}


}

		
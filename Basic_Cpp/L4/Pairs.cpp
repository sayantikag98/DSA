#include<bits/stdc++.h>
using namespace std;

// unordered_map -> random ordering of elements
// map -> ordered arrangement of elements

int main(){
	set<pair<int, int>> set_pair;
	unordered_map<int, pair<int, int>> map_pair;
	vector<int> v = {1,2,3,4,5};
	int count = 1;

	for(int &i:v){ // reference should be the iterable variable
		cout<<i<<" ";
	}
	cout<<endl;

	for(int i = 1; i<=5; i++){
		for(int j = i; j<=5; j++){
			pair<int, int> p = make_pair(i,j);
			set_pair.insert(p);
			map_pair[count++] = p;
		}
	}

	for(auto const &p: set_pair){
		cout<<p.first<<" "<<p.second<<"\n";
	}
	cout<<endl;

	set<pair<int, int>>::iterator it;

	for(it = set_pair.begin(); it!=set_pair.end(); it++){
		cout<<(*it).first<<" "<<(*it).second<<"\n";
		cout<<it->first<<" "<<it->second<<"\n";
		cout<<"___________________________________\n";
	}

	for(auto const &p: map_pair){
		cout<<p.first<<"->"<<" "<<p.second.first<<" "<<p.second.second<<"\n";
	}
	cout<<endl;
}
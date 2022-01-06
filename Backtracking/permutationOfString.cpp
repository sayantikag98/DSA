#include<iostream>
#include<string>
#include<vector>

using namespace std;

// all permutations of a string => swapping + backtracking

void swap(string &s, int i, int j){
	if(i!=j){
		char temp = s.at(i);
		s.at(i) = s.at(j);
		s.at(j) = temp;
	}
}


// this is for strings with distinct characters 

void permutationWithBacktracking(int i, string &str, vector<string> &v){
	if(i == str.length() - 1){  // when i reaches the last character of the string
		v.push_back(str);
	}

	// loop is for the branches and the recursion is for the levels 
	// backtract is for undowing the swapping of the string because in swapping we are modifying the original string
	for(int j = i; j<str.length(); j++){
		swap(str, i, j);
		permutationWithBacktracking(i+1, str, v);
		swap(str, i, j); // Backtracking => the string goes back to its unswapped state
	}

}

vector<string> permutationWithoutBacktracking(string str){
	// base case => a string having only one character will have itself as its only permutation
	if(str.length() == 1){
		vector<string> ans;
		ans.push_back(str);
		return ans;
	}
	// recursive work 
	vector<string> arr = permutationWithoutBacktracking(str.substr(1));
	vector<string> ans;
	int k = arr[0].length();
	for(int j = 0; j<=k; j++){ // to iterate over each of the places of each permutation
		for(int i = 0; i<arr.size(); i++){  // to iterate over all the permutations of str of length n-1
			string temp = "";
			temp += arr[i].substr(0,j);
			temp += str.at(0);
			temp += arr[i].substr(j);
			ans.push_back(temp);
		}
	}
	return ans;
}

void print (vector <string> &ans){
	cout<<ans.size()<<endl;
	for(auto ele: ans){
		cout<<ele<<" ";
	}
	cout<<"\n";
}

int main(){
	string str;
	cin>>str;
	vector<string> ans = permutationWithoutBacktracking(str);
	print(ans);
	ans.clear();
	permutationWithBacktracking(0, str, ans);
	print(ans);
}
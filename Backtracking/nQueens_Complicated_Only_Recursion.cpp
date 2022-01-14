#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<vector<int>> &arr, int n, int row, int col){
	// horizontally left 
	int c = col;
	int r = row;
	while(c >= 0){
		if(arr[r][c] == 1) return false;
		c--;
	}
	// diagonally up
	c = col;
	while(r >= 0 and c >= 0){
		if(arr[r][c] == 1) return false;
		r--;
		c--;
	}
	//diagonally down
	r = row;
	c = col;
	while(c >= 0 and r < n){
		if(arr[r][c] == 1) return false;
		r++;
		c--;
	}
	return true;
}

void print(vector<vector<int>> &arr, int n){
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"____________________________________________\n";
}

int count = 0;


/* 
	Keeping noOfQueenPlaced is important as a parameter in the recursive function 
	because it will be used in the base case
*/
void nQueen(vector<vector<int>> &arr, int n, int row, int col, int noOfQueenPlaced){

	// Base case 1: When the number of queen currently placed (noOfQueenPlaced) is equal to the total no of queens (n)
	if(noOfQueenPlaced == n){
		count+=1;
		// printing the state of the board when all the n queens are placed in the board
		print(arr, n);
		return;
	}

	// Base case 2: when the current location reaches out of the board
	if(row == n or col == n){
		return;
	}

	/* 
	This is for checking whether we can place a queen in the current location or not.
	If so, then place the queen at that location, increase the number of queen placed
	then move to the next column at the zeroth row recursively.
	*/

	if(isValid(arr, n, row, col)){
		arr[row][col] = 1;
		noOfQueenPlaced += 1;
		nQueen(arr, n, 0, col + 1, noOfQueenPlaced);
	}

	// if the current location is not valid then check for the next row in the same column recursively
	else nQueen(arr, n, row + 1, col, noOfQueenPlaced);

	// Backtracking
	/*
	If the queen cannot be placed anywhere in the current column then backtract to
	the previous location where the queen is placed, remove the queen from there,
	decrease the number of queen placed and then start checking for the next row in the 
	same column recursively.

	This backtracking step is continued and all the queen are eventually removed from 
	the board in order to get all the configuration where n queens can be placed in nxn board.
	If we stop after getting noOfQueenPlaced == n then we will get only one possible configuration.

	*/
	if(arr[row][col]){
		arr[row][col] = 0;
		noOfQueenPlaced -= 1;
		nQueen(arr, n, row+1, col, noOfQueenPlaced);
	}
}




int main(){
	int n;
	cin>>n;
	vector<vector<int>> arr(n);
	for(int i = 0; i<n; i++){
		arr[i] = vector<int>(n);
	}
	print(arr, n);
	nQueen(arr, n, 0, 0, 0);
	cout<<count<<endl;
}
#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<int>> &board, int n){
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}

bool isValid(vector<vector<int>> &board, int n, int row, int col){
	// top
	int r = row, c = col;
	while(r>=0){
		if(board[r][col]) return false;
		r--;
	}
	r = row;
	// diagonally left
	while(r>=0 and c>=0){ // this should be logical and
		if(board[r][c]) return false;
		r--;
		c--;
	}
	r = row, c = col;
	//diagonally right
	while(r>=0 and c<n){ // this should be logical and
		if(board[r][c]) return false;
		r--;
		c++;
	}
	return true;
}

bool nQueen(vector<vector<int>> &board, int n, int row, int noQueenPlaced){
	// base case when the no of queen currently placed becomes equal to n then print the board
	// here printing all the possible solved board configuration
	if(noQueenPlaced == n){
		print(board,n);
		return true;
	}
	/* 
	1. go to each column in a particular row and see if its valid to place a queen there or not
	2. if its possible then place the queen there and recursively move to the next row and start
		checking from column 0
	3. if after checking all the columns of a row there exist no valid position to place a queen 
		then return false and backtract to the previous row where the queen was placed, remove the
		queen from there and start checking recursively from the next column in the same row whether
		its possible to place the queen there and the process starts all over again till base case is 
		hit.
	4. No need to check for row in the base case because in the outer for loop it is already checked

	*/
	for(int i = row; i<n; i++){  // for rows starting from i = row because after the queen is placed it needs to move to the next row recursively
		for(int j = 0; j<n; j++){ // for column should start from 0
			if(isValid(board, n, i, j)){ // if its valid to place the queen there or not defined above
				board[i][j] = 1; // if possible to place the queen then place it
				nQueen(board, n, row+1, noQueenPlaced+1); // recursively call for the next row and increase the no of queen currently placed
				board[i][j] = 0; // for backtracking when the current queen cannot be placed anywhere then the previous queen needs to be removed from its place and checked for if it can be placed anywhere in the column next to where it was currently placed
			}
		}
		return false; // backtracking when the current queen cannot be placed anywhere in the column for a particular row
	}
	return false; // does not matter whether it returns true or false or does not return anything (warning thrown if it does not return anything)
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>> board(n);
	for(int i = 0; i<n; i++){
		board[i] = vector<int>(n);
	}
	nQueen(board, n, 0, 0);
}
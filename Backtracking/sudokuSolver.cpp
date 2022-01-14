#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

void print(vector<vector<int>> &board, int n){
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"________________________________________\n";
}

// TC => O(n)
bool isValid(vector<vector<int>> &board, int n, int row, int col, int val){
	int sqrtVal = sqrt(n);
	int r = row - row%sqrtVal;
	int c = col - col%sqrtVal;

	for(int i = 0; i<n; i++){
		// row or column
		if(board[row][i] == val or board[i][col] == val) return false;
		// 3x3 grid
		if(board[r + i/sqrtVal][c + i%sqrtVal] == val) return false;
	}
	
	return true;
}

bool sudokuSolver(vector<vector<int>> &board, int n){
	int row = -1, col = -1;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(!board[i][j]){
				row = i;
				col = j;
				break;
			}
		}
		if(row != -1 and col != -1) break;
	}

	if(row == -1 and col == -1) return true;

	for(int val = 1; val<=n; val++){
		if(isValid(board, n, row, col, val)){
			board[row][col] = val;
			if(sudokuSolver(board, n)) return true;
			board[row][col] = 0;
		}
	}
	return false;
	
}


int main(){
	int n;
	cin>>n;
	vector<vector<int>> board(n);
	for(int i = 0; i<n; i++){
		board[i] = vector<int>(n);
	}
	if(sudokuSolver(board, n)) print(board, n);
}
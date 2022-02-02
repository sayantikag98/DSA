#include<iostream>
using namespace std;

bool isValid(int** arr, int n, int row, int col){
	for(int i = row; i>=0; i--){
		if(arr[i][col]) return false;
	}
	for(int i = row, j = col; i>=0 and j>=0; i--,j--){
		if(arr[i][j]) return false;
	}

	for(int i = row, j = col; i>=0 and j<n; i--, j++){
		if(arr[i][j]) return false;
	}
	return true;
}

bool nQueen(int** arr, int n, int row, int queenPlaced){
	if(queenPlaced == n){
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<"\n";
		}
		cout<<"_______________________________________________\n";
		return true;
	}

	for(int i = row; i<n; i++){
		for(int j = 0; j<n; j++){
			if(isValid(arr, n, i, j)){
				arr[i][j] = 1;
				nQueen(arr, n, row+1, queenPlaced+1);
				arr[i][j] = 0;
			}
		}
		return false;
	}
	return false;
}

int main(){
	int n;
	cin>>n;
	
	int** arr = new int*[n];

	for(int i = 0; i<n; i++){
		arr[i] = new int[n];
		for(int j = 0; j<n; j++){
			arr[i][j] = 0;
		}
	}

	nQueen(arr, n, 0, 0);
}
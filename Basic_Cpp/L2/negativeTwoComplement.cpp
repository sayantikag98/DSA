#include<iostream>
#include<bitset>

using namespace std;

int main(){
	int x = 10;
	cout<<bitset<8>(x)<<" "<<bitset<8>(-x)<<endl;
}


// to get the binary of the decimal number num in x bits use "bitset<x>(num)"
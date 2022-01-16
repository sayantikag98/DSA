#include<iostream>
using namespace std;

int main(){
	int x = 100;
	int &y = x; // reference demo 
	cout<<x<<" "<<y<<endl;
	y = 1000;
	cout<<x<<" "<<y<<endl;
}
#include<iostream>
using namespace std;

int main(){
	int a, b, c;
	cin>>a>>b>>c;
	if((a+b>c or b+c>a or a+c>b) and (((a*a)+(b*b) == (c*c)) or ((c*c)+(b*b) == (a*a)) or ((a*a)+(c*c) == (b*b)))) cout<<"Right Angled Triangle\n";
	else cout<<"Not a Right Angled Triangle\n";
}
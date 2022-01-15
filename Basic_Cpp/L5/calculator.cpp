#include<iostream>
using namespace std;

int main(){
	bool shouldContinue;
	do{
		int num1, num2;
		cin>>num1>>num2;
		char op;
		cin>>op;
		switch(op){
			case '+':
				cout<<num1+num2<<endl;
				break;
			case '-':
				cout<<num1-num2<<endl;
				break;
			case '*':
				cout<<num1*num2<<endl;
				break;
			case '/':
				cout<<num1/num2<<endl;
				break;
			case '%':
				cout<<num1%num2<<endl;
				break;
			default: 
				cout<<"Enter a valid operator\n";
		}
		cout<<"Should you continue\n";
		cin>>shouldContinue;

	}while(shouldContinue);
}
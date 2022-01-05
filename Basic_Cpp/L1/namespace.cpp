#include<iostream>
using namespace std;


namespace foo{
	int a = 20, b = 30;
}

namespace goo{
	int c = 30, d = 40;
}

using namespace foo;
using namespace goo;

int main(){
	cout<<a<<" "<<b<<endl;
	cout<<c<<" "<<d<<endl;
}
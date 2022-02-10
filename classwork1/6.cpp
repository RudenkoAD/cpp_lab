#include <iostream>
#include <cmath>

int NOD(int a, b){
	if b==0{
		return a;
	} else {
	return NOD(b, a%b);
	}
}

int NOK(int a, b){
	return a*b/NOD(a, b);
}

int main(){
	int a, b;
	cin>>a>>b;
	cout<<NOK(a, b);
	return 0;
}

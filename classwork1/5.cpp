#include <iostream>
#include <cmath>

int NOD(int a, b){
	if b==0{
		return a;
	} else {
	return NOD(b, a%b);
	}
}

int main(){
	int a, b;
	cin>>a>>b;
	cout<<NOD(a, b);
	return 0;
}

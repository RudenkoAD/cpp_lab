#include <iostream>
#include <cmath>

using namespace std;

int NOD(int a, int b){
	if (b==0){
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

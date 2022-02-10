#include <iostream>
#include <cmath>

using namespace std;


double hypot(double a, double b){
	return sqrt(pow(a, 2) + pow(b, 2));
}


int main(){
	double a, b;
	cin>>a>>b;
	return hypot(a, b);
}

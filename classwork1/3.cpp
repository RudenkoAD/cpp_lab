#include <iostream>
#include <cmath>

using namespace std;

double solve_lin(double b, c){
	if (b==0){
		if (c==0){
			cout<<"help i shouldn't have ended here. fuck my existence";
		} else cout<<(-c)/b;
}


double solve_quad(double a, b, c){
	discr=sqrt(b*b-4*a*c);
	if discr>0{
		cout<<(b-discr)/2/a<<' '<<(b+discr)/2/a;
		return 0;	
	}
	cout<<b/2/a;
	return 0;
}


double solve(double a, b, c){
	if (a==0){
		solve_lin(b, c);
	return 0;
	}
	solve_quad(a, b, c);
	return 0;
}

int main(){
	double a, b, c;
	cin>>a>>b>>c;
	solve(a, b, c);
	return 0;
}

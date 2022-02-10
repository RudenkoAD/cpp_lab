#include <iostream>
#include <cmath>

using namespace std;

long long int fc(long long int a, int b){
    if (b==1)
        return a;
    return fc(a*b, b-1);
    }


int main()
{
    long long int a=1;
    int b;
    cin>>b;
    cout<<fc(a, b);
	return 0;
}

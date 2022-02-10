#include <iostream>

using namespace std;

double riad(double n){
    if (n==1){
        return 1;
    }
    return (riad(n-1)+(1/n/n));
}

int main()
{
    int n;
    cin>>n;
    cout<<riad(n);
}

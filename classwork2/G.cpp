#include <iostream>
#include <cmath>
using namespace std;


void del(int n){
    for (int i = n-1; i>=2; i--){
        if (!(n%i)){
            cout<<i<<' ';
        }
    }
}


int main()
{
    int n;
    cin>>n;
    del(n);
}

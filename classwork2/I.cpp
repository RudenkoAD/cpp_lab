#include <iostream>
#include <cmath>
using namespace std;


void del(int n){
    for (int i=2; i<=n; i++){
        if (!(n%i)){
            cout<<i<<' ';
            del(n/i);
            break;
        }
    }
}


int main()
{
    int n;
    cin>>n;
    del(n);
}

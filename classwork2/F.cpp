#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool erat(int n){
    for (int i = 2; i<=floor(sqrt(n)); i++){
        if (!(n%i)){
            return false;
        }
    }
    return true;
}


int main()
{
    int n;
    cin>>n;
    if (erat(n)){
        cout<<"YES";
    } else {
        cout<<"NO";
    }
}

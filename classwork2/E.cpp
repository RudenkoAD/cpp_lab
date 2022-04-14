#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int maxi=-2147483648;
    int counter=1;
    int b=1;
    while(cin>>b){
        if (b==maxi){
            counter++;
        }
        if (b>maxi){
            maxi=b;
            counter=1;
        }
    }
    cout<<counter;
}

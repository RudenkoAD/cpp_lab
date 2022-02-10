#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int maxi=-1000000001;
    int counter=1;
    while(b!=0){
        cin>>b;
        if (i==maxi){
            counter++;
        }
        if (i>maxi){
            maxi=i;
            counter=1;
        }
    }
    cout<<counter;
}

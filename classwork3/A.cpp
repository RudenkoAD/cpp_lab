#include <iostream>
using namespace std;
const int N=4;


void gnomesort(int a[N]){
    int i = 0;
    int j = 1;
    while (i < N){
        if (a[i - 1] > a[i]){
            i = j;
            j = j + 1;
        }
        else{
            int t=a[i];
            a[i]=a[i-1];
            a[i-1]=t;
            i = i - 1;
            if (i == 0){
                i = j;
                j = j + 1;
            }
        }
    }
}


int main() {
    int a[N];
    for (int i=0; i<N; i++){
        cin>>a[i];
    }
    gnomesort(a);
    for (int i=0; i<N; i++){
        cout<<a[i]<<' ';
    }
}

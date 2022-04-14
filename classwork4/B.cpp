#include <iostream>
using namespace std;

int main(){
    int a;
    cin>>a;
    int *arr = new int[a];

    for (int i=0; i<a; i++){
        cin>>arr[i];
    }
    for (int i=0; i<a-1; i++){
        cout<<arr[i]<<' ';
    }
    cout<<arr[a-1]<<'\n';
    for (int i=a-1; i>0; i--){
        cout<<arr[i]<<' ';
    }
    cout<<arr[0];
    delete[] arr;
    return 0;
}

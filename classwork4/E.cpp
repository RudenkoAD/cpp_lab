#include <iostream>
using namespace std;

void initiate_tree(int *arr, int a){
    for (int i=0; i<a; i++){
        int j=i;
        while (arr[j]>arr[(j-1)/2]){
            int temp = arr[j];
            arr[j]= arr[(j-1)/2];
            arr[(j-1)/2]=temp;
            j = (j-1)/2;
        }
    }
    return;
}

void fix_tree(int *arr, int a){
    if (a==1) return;
    for (int i=0; 2*i+2<a; ){
        if (arr[i]>=max(arr[2*i+1], arr[2*i+2])) return;
        if (arr[2*i+1]>arr[2*i+2]){
            int temp = arr[i];
            arr[i]=arr[2*i+1];
            arr[2*i+1] = temp;
            i = 2*i+1;
        } else{
            int temp = arr[i];
            arr[i]=arr[2*i+2];
            arr[2*i+2] = temp;
            i = 2*i+2;
        }
    }
    int i=(a-2)/2;
    if (arr[i]>=arr[2*i+1]) return;
    int temp = arr[i];
    arr[i]=arr[2*i+1];
    arr[2*i+1] = temp;
    return;
}

void step(int *arr, int a){
    if (a==1) return;
    int temp = arr[0];
    arr[0] = arr[a-1];
    arr[a-1] = temp;
    fix_tree(arr, a-1);
    step(arr, a-1);
    return;
}

void psort(int *arr, int a){
    initiate_tree(arr, a);
    step(arr, a);
    return;
}


int main(){
    int a;
    cin>>a;
    int *arr = new int[a];

    for (int i=0; i<a; i++){
        cin>>arr[i];
    }
    psort(arr, a);
    for (int i=0; i<a; i++){
        cout<<arr[i]<<' ';
    }
    delete[] arr;
    return 0;
}
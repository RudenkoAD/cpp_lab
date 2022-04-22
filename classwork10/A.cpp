#include <iostream>

using namespace std;

int evolve(int *arr, int n) {//arr длины 3
    if (n < 3) return arr[n];
    int temp = arr[0] + arr[1] + arr[2];
    arr[0] = arr[1];
    arr[1] = arr[2];
    arr[2] = temp;
    return evolve(arr, n - 1);
}

int main() {
    int N;
    cin >> N;
    int arr[3] = {1, 1, 2};
    cout << evolve(arr, N);
}
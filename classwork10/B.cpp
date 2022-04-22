#include <iostream>

using namespace std;

int greedvolve(int *price, int *arr, int step, int n) {//arr длины 3
    if (n - step < 0) return arr[n - step + 3];
    int temp = min(min(arr[0], arr[1]), arr[2]) + price[step - 1];
    arr[0] = arr[1];
    arr[1] = arr[2];
    arr[2] = temp;
    return greedvolve(price, arr, step + 1, n);
}

int main() {
    int N, step = 3;
    cin >> N;
    int *price = new int[N];
    for (int i = 0; i < N; i++)
        cin >> price[i];
    int arr[3] = {0, price[0], price[1]};
    cout << greedvolve(price, arr, step, N);
}
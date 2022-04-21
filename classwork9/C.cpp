#include <iostream>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    int *arr = new int[K];
    for (int i = 0; i < K; i++) {
        cin >> arr[i];
    }
    if (N - arr[K - 1] > M) {
        cout << -1;
        return 0;
    }
    int pos = 0, last = 0, count = 0;
    for (int i = 0; i < K; i++) {
        if (arr[i] - pos > M) {
            if (last == pos) {
                cout << -1;
                return 0;
            }
            pos = last;
            count++;
        }
    }
    if (N - pos > M) count++;
    cout << count;
    return 0;
}
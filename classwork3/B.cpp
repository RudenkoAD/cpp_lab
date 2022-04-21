#include <iostream>

using namespace std;

const int N = 4;

int find(int a[N], int target) {
    int i = 0;
    int j = N - 1;
    int k = 0;
    while (i != j) {
        k = (i + j) / 2;
        if (a[k] < target) {
            i = k;
        } else if (a[k] == target) {
            return k;
        } else {
            j = k;
        }
        if (j - i <= 1) {
            if (a[i] == target) return i;
            if (a[j] == target) return j;
            return -1;
        }
    }
    return -1;
}

int main() {
    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int target;
    cin >> target;
    int b = find(a, target);
    if (b == -1) {
        cout << '\n';
        return 0;
    } else {
        cout << b << '\n';
        return 0;
    }
}

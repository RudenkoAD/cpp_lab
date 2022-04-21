#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    char *A = new char[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int left = 0;
    int right = N;
    int temp;
    while (right - left > 1) {
        temp = (right + left) / 2;
        if (A[temp] == '0') left = temp;
        if (A[temp] == '1') right = temp;
    }
    if (A[left] == '1') cout << left + 1;
    if (A[right] == '1') cout << right + 1;
}


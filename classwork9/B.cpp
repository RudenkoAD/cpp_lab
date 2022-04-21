#include <iostream>

using namespace std;

const int a[4] = {98, 49, 7, 1};

int main() {
    int N;
    cin >> N;
    int count = 0;
    for (int i = 0; i < 4; i++) {
        count += (N - N % a[i]) / a[i];
        N %= a[i];
    }
    cout << count;
    return 0;
}
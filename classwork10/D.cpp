#include <iostream>

using namespace std;


int bins(int *a, int N, float target) {
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
            if (abs(a[i] - target) <= abs(a[j] - target)) return i;
            else return j;
        }
    }
    return -1;
}


void split(int start, int end, int *tags, int N, int &price) {
    if (start == end) return;
    int id = bins(tags, N, (static_cast<float>(start) + static_cast<float>(end)) / 2);
    //breakpoint:
    if (tags[id] == end or tags[id] == start) return;
    price += end - start;
    split(start, tags[id], tags, N, price);
    split(tags[id], end, tags, N, price);
    return;
}

int main() {
    int L, N, price = 0;
    cin >> L >> N;
    int *tags = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> tags[i];
    }
    split(0, L, tags, N, price);
    cout << price;
}
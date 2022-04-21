#include <iostream>

using namespace std;

struct lec {
    int start, finish;

    lec(int st, int fn) {
        start = st;
        finish = fn;
    }

    bool operator>(lec right) {
        if (start < right.start) return false;
        return (start > right.start or (start == right.start and finish > right.finish));
    }
};

template<typename T>
void structsort(T **arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*arr[j] > *arr[j + 1]) {
                T tmp = *arr[j];
                *arr[j] = *arr[j + 1];
                *arr[j + 1] = tmp;
            }
        }
    }
}

int main() {
    int N, st, fn;
    cin >> N;
    lec **crutch = new lec *[N];
    for (int i = 0; i < N; i++) {
        cin >> st >> fn;
        crutch[i] = new lec(st, fn);
    }
    structsort(crutch, N);
    int time = 0, count = 0;
    for (int i = 0; i < N; i++) {
        if (time <= crutch[i]->start) {
            count++;
            time = crutch[i]->finish;
        }
    }
    cout << count;
    return 0;
}
#include <iostream>

using namespace std;

void qsort(int *arr, int lo, int hi) {
    if (lo >= hi) return;

    int anchor = arr[(lo + hi) / 2];
    int anchorid = (lo + hi) / 2;
    int i = lo;
    int j = hi;
    while (i < j) {
        while ((arr[i] <= anchor) && i < anchorid) i++;
        while ((arr[j] >= anchor) && j > anchorid) j--;
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            if (i == anchorid) anchorid = j;
            else if (j == anchorid) anchorid = i;
        }
    }

    qsort(arr, lo = lo, anchorid - 1);
    qsort(arr, anchorid + 1, hi = hi);
}


int main() {
    int a;
    cin >> a;
    int *arr = new int[a];

    for (int i = 0; i < a; i++) {
        cin >> arr[i];
    }
    qsort(arr, 0, a - 1);
    for (int i = 0; i < a; i++) {
        cout << arr[i] << ' ';
    }
    delete[] arr;
    return 0;
}
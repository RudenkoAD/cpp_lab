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
    int N;
    cin >> N;
    int **matrix = new int *[N + 1];
    for (int i = 0; i < N + 1; i++) {
        matrix[i] = new int[N + 1];
        for (int j = 0; j < N + 1; j++) {
            matrix[i][j] = 0;
        }
    }
    int *str = new int[N];
    int *sostr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> str[i];
        sostr[i] = str[i];
    }
    qsort(sostr, 0, N);

    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            if (str[j - 1] < sostr[i - 1]) matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
            else if (str[j - 1] > sostr[i - 1]) matrix[i][j] = matrix[i][j - 1];
            else if (str[j - 1] == sostr[i - 1]) matrix[i][j] = 1 + matrix[i][j - 1];
        }
    }
    cout << matrix[N][N];
}

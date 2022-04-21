#include <iostream>

using namespace std;

void to_incident(int **matrix, int N, int M) {

    int **incident = new int *[N];
    for (int i = 0; i < N; i++) {
        incident[i] = new int[M];
        for (int j = 0; j < M; j++) {
            incident[i][j] = 0;
        }
    }

    int index = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (matrix[i][j] != 0) {
                incident[i][index] = matrix[i][j];
                incident[j][index] = matrix[i][j];
                index++;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << incident[i][j];
        }
        cout << '\n';
    }
}


int main() {
    int N, M;
    cin >> N >> M;
    int **matrix = new int *[N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
    to_incident(matrix, N, M);
}


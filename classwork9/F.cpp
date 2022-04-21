#include <iostream>

using namespace std;


int main() {
    int N, M;
    cin >> N >> M;

    int **matrix = new int *[N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[M];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }


}
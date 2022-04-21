#include <cstring>
#include <iostream>

struct student {
    char name[20];
    int grade;

    bool operator<(const student other) {
        return grade < other.grade;
    }

    bool operator>(const student other) {
        return grade > other.grade;
    }

    bool operator>(const int other) {
        return grade > other;
    }
};

void qsort(student *arr, int lo, int hi) {
    if (lo >= hi) return;

    student anchor = arr[(lo + hi) / 2];
    int i = lo;
    int j = hi;
    while (i < j) {
        while (arr[i] < anchor) i++;
        while (arr[j] > anchor) j--;
        if (i < j) {
            student temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    qsort(arr, lo = lo, j - 1);
    qsort(arr, i + 1, hi = hi);
}

int main() {
    int N;
    std::cin >> N;
    student *students = new student[N];

    for (int i = 0; i < N; i++) {
        std::cin >> students[i].name >> students[i].grade;
    }
    qsort(students, 0, N - 1);
    int M;
    std::cin >> M;
    for (int i = 0; i < N; i++) {
        if (students[i].grade >= M) {
            std::cout << students[i].name << ' ';
        }
    }
}



#include <iostream>

using namespace std;

int pow10(int a) {
    if (a == 0) {
        return 1;
    }
    return (10 * pow10(a - 1));
}

int fetch(int a, int length, int id) {
    return (a % (pow10(length - id)) - a % (pow10(length - id - 1))) / pow10(length - id - 1);
}

int find_lenght(int a) {
    for (int i = 1; true; i++) {
        if (pow10(i) > a) {
            return i;
        }
    }
}

int reverseint(int a, int length) {
    int result = 0;
    for (int i = 0; i < length; i++) {
        result += pow10(i) * fetch(a, length, i);
    }
    return result;
}


int main() {
    int a;
    cin >> a;
    int b;
    cin >> b;
    int c = reverseint(b, find_lenght(b));
    if (b == c) {
        cout << 1;
        return 0;
    } else {
        cout << c;
        return 0;
    }
}

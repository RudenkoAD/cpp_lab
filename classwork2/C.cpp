#include <iostream>
#include <vector>

using namespace std;

bool stepen2(int a) {
    if (a % 2) {
        if (a == 1) {
            return true;
        }
        return false;
    }
    return stepen2(a / 2);
}


int main() {
    int a;
    cin >> a;
    if (stepen2(a)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}

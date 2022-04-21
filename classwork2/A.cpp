#include <iostream>

using namespace std;

bool vis(int n) {
    return !(n % 400) || (!(n % 4) && n % 100);
}


int main() {
    int n;
    cin >> n;
    if (vis(n)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}

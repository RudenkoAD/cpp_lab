#include <iostream>
#include <vector>

using namespace std;


int main() {
    int counter = 0;
    int i;
    while (cin >> i) {
        if (i == 0) {
            break;
        }
        counter += 1 - (i % 2);
    }
    cout << counter;
}

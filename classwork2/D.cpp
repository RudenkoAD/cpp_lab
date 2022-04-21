#include <iostream>
#include <vector>

using namespace std;


int main() {
    int maxi = -1000000001;
    int i;
    while (cin >> i) {
        if (i == 0) {
            break;
        }
        if (!(i % 2)) {
            if (i > maxi) {
                maxi = i;
            }
        }
    }
    if (maxi == -1000000001) {
        return 0;
    }
    cout << maxi;
    return 0;
}

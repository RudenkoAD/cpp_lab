#include <iostream>

using namespace std;

struct otr {
    int p1;
    int p2;

    otr(int ip1, int ip2) {
        p1 = ip1;
        p2 = ip2;
    }
};

otr intersect(otr o1, otr o2) {
    int p1 = max(o1.p1, o2.p1);
    int p2 = min(o1.p2, o2.p2);
    return otr(p1, p2);
}

int main() {
    int N, a, b;
    cin >> N;
    otr cur = otr(-2147483648, +2147483647);
    otr temp = otr(0, 0);
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        temp.p1 = min(a, b);
        temp.p2 = max(a, b);
        cur = intersect(cur, temp);
    }
    if (cur.p1 <= cur.p2) {
        cout << "YES";
        return 0;
    } else {
        cout << "NO";
        return 0;
    }
}
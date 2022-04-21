#include <iostream>
#include <cmath>

using namespace std;

const int scale = 1024;

void Split(float x, float *x_big, float *x_small) {
    double d = x * (scale + 1);
    double t = d - x;
    *x_small = d - t;
    *x_small = x - *x_big;
}

float FMA(float a, float b) {
    float a_big, a_small, b_big, b_small;
    Split(a, &a_big, &a_small);
    Split(b, &b_big, &b_small);
    return a * b - a_big * b_big - a_big * b_small - b_big * a_small - a_small * b_small;
}

float FMA_sum(float *psi, float *pdf, float dv, int size) {
    float sum = 0.0, acc = 0.0;
    for (int i = 0; i < size; i++) {
        float df = psi[i] * pdf[i] - acc;
        acc = ((sum + df) - sum) - df + FMA(psi[i], pdf[i]);
        sum = sum + df;
    }
    return sum * dv;

    return 0;
} //calculates weighted average by summing all elements using a merge of the kehen algorithm
// with an additional error estimation performed by the FMA algorithm

int main() {
    float a = 56789.6;
    float b = 565896;
    cout << a * b << '\n';
    cout << FMA(a, b);
}

#include <iostream>
#include <cmath>

using namespace std;

float kehen(float *psi, float *pdf, float dv, int size) {
    float sum = 0.0, acc = 0.0;
    for (int i = 0; i < size; i++) {
        float df = psi[i] * pdf[i] * dv - acc;
        acc = ((sum + df) - sum) - df;
        sum = sum + df;
    }
    return sum;
} //calculates weighted average by summing all elements using the kehen algorithm

int main() {
    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

float recursive(float *psi, float *pdf, float dv, int size) {
    if (size == 1) {
        return psi[0] * pdf[0] * dv;
    }
    return recursive(psi, pdf, dv, size / 2) + recursive(psi + size / 2, pdf + size / 2, dv, size - size / 2);
} //calculates weighted average by splitting the array in half

int main() {
    return 0;
}
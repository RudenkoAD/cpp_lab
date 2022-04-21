#include <iostream>
#include <cmath>

using namespace std;

float adjacent(float *psi, float *pdf, float dv, int size) {
    for (int i = 0; i < size; i += 1) {
        psi[i] = psi[i] * pdf[i];
    }
    for (int step = 2; step < size; step *= 2) {
        int i = 0;
        for (; i + step / 2 < size; i += step) {
            psi[i] = psi[i] + psi[i + step / 2];
        }
        if (i < size) psi[i - step] += psi[i]; //fixes odd amounts of elements, may be very bad.
    }
    return psi[0] * dv;
} //calculates weighted average by summing adjacent elements repeatedly

int main() {
    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

float adjacent(float *psi, float *pdf, float dv, int size){
    float sum = 0.0;
    for (int step=2; step<size; step*=2) {
        for (int i = 0; i < size; i += step) {
            psi[i] * pdf[i] + psi[i + step / 2] * pdf[i + step / 2];
        }
    }
    return sum;
} //calculates weighted average by summing adjacent elements repeatedly

int main(){
    return 0;
}
#include <iostream>
#include <math.h>

using namespace std;

struct denom_array_t {
    unsigned int *arr;
    unsigned int sz;
};

unsigned int simplify(unsigned int *num, unsigned int *den) {
    unsigned int coeff = 1;
    for (int i = 2; i <= *num; i++) {
        if (*num % i == 0 and *den % i == 0) {
            *num = *num / i;
            *den = *den / i;
            coeff *= i;
            i--;
        }
    }
    return coeff;
}

denom_array_t egyptian_fractions(unsigned int num, unsigned int den) {
    denom_array_t *ans = new denom_array_t;
    unsigned int *arr = new unsigned int[num];
    ans->sz = 0;
    ans->arr = arr;
    unsigned int i = 0, dd = 0;
    while (num > 1) {
        dd = den / num + 1;
        num = num * dd - den;
        den = den * dd;
        simplify(&num, &den);
        ans->arr[i] = dd;
        ans->sz += 1;
        i++;
        cout << dd << " ";
    }
    ans->arr[i] = den;
    ans->sz += 1;
    cout << den;
    return *ans;
}

int main() {
    unsigned int a, b;
    cin >> a >> b;
    egyptian_fractions(a, b);
}

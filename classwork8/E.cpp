#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack *A = new Stack;
    char ch;
    while (cin >> ch) {
        switch (ch) {
            case '(':
                A->push(ch);
                break;
            case ')':
                if (A->is_empty()) {
                    cout << 1;
                    return 0;
                }
                A->pop();
                break;
            default:
                cout << "Unexpected character";
                return -1;
        }
    }
    cout << 0;
    return 0;
}


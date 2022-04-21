#include <iostream>

int counter() {
    static int a = 0;
    a++;
    return a;
}

int main() {
    std::cout << counter();
    std::cout << counter();
    std::cout << counter();
    std::cout << counter();
    std::cout << counter();
    std::cout << counter();
}
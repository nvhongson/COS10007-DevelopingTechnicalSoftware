#include <iostream>

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T>
T min(T a, T b) {
    return (a < b) ? a : b;
}

int main() {
    int a = 5, b = 3;
    std::cout << "max(" << a << ", " << b << ") = " << max(a, b) << std::endl;
    std::cout << "min(" << a << ", " << b << ") = " << min(a, b) << std::endl;

    char c1 = 'a', c2 = 'z';
    std::cout << "max(" << c1 << ", " << c2 << ") = " << max(c1, c2) << std::endl;
    std::cout << "min(" << c1 << ", " << c2 << ") = " << min(c1, c2) << std::endl;

    float f1 = 3.14, f2 = 2.71;
    std::cout << "max(" << f1 << ", " << f2 << ") = " << max(f1, f2) << std::endl;
    std::cout << "min(" << f1 << ", " << f2 << ") = " << min(f1, f2) << std::endl;

    return 0;
}

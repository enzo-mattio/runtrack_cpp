#include <iostream>

int main() {
    
    int n, m;
    std::cout << "Enter the first number: ";
    std::cin >> n;
    std::cout << "Enter the second number: ";
    std::cin >> m;
    std::cout << "Before swapping: n = " << n << ", m = " << m << std::endl;
    int temp = n;
    n = m;
    m = temp;
    std::cout << "After swapping: n = " << n << ", m = " << m << std::endl;
    return 0;
}
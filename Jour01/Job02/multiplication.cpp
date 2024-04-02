#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <number1> <number2>" << std::endl;
        return 1;
    }
    int a = std::stoi(argv[1]);
    int b = std::stoi(argv[2]);
    

    int product = a * b;
    std::cout << "The product of " << a << " and " << b << " is " << product << std::endl;
    return product;
}
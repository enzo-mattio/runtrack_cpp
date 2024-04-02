#include <iostream>

int main() {
    float ht;
    int kg;
    float tva;
    float ttc;

    std::cout << "Enter the price/kg without tax: ";
    std::cin >> ht;
    std::cout << "Enter the weight in kg: ";
    std::cin >> kg;
    std::cout << "Enter the tax rate: ";
    std::cin >> tva;

    ttc = (ht * kg) * (1 + tva / 100);
    std::cout << "The price with tax is: " << ttc << std::endl;

    return 0;
}
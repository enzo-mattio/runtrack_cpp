#include <iostream>



void swapValues(int& a, int& b) {
    int temp = a;  // Stocker la valeur de 'a' temporairement
    a = b;         // Affecter la valeur de 'b' à 'a'
    b = temp;      // Affecter la valeur temporaire (ancienne valeur de 'a') à 'b'
}

int main() {
    int x = 5, y = 10;
    
    std::cout << "Avant l'échange : x = " << x << ", y = " << y << std::endl;
    swapValues(x, y);
    std::cout << "Après l'échange : x = " << x << ", y = " << y << std::endl;

    return 0;
}


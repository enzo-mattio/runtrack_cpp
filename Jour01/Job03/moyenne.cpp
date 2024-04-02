#include <iostream>

int main() {
    // scanner les nombres que l'utilisateur va entrer (5 nombres) et les stocker dans un tableau pour la moyenne et le stockage on est limités a deux variables
    int numbers[5];
    for (int i = 0; i < 5; i++) {
        std::cout << "Enter a number: ";
        std::cin >> numbers[i];
    }
    // calculer la moyenne
    

    float average = 0;
    for (int i = 0; i < 5; i++) {
        average += numbers[i];
    }
    average /= 5;
    

    std::cout << "The average of the numbers is " << average << std::endl;
    


}
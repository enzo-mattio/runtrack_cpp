#include <iostream>

/*Créer une fonction fibonacci qui calcule le Nième terme de la suite de
Fibonacci. Le résultat doit être calculé par le compilateur lors du traitement
du code, et non lors de son exécution.*/

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    
    /*Après avoir écrit votre fonction, utilisez-la dans le programme principal pour
afficher les dix premiers termes de la suite de Fibonacci. Assurez-vous que les
valeurs sont correctes et que le programme fonctionne comme prévu.*/

    for (int i = 0; i < 10; i++) {
        std::cout << fibonacci(i) << " ";
    }
    std::cout << std::endl;
    return 0;
    
}

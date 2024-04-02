#include <iostream>
/*
Créer une fonction `addElement` qui prend en paramètre un tableau d'entiers,
la taille actuelle du tableau et l'entier à ajouter. Cette fonction doit allouer
dynamiquement un nouveau tableau avec une taille augmentée de 1 par
rapport à la taille actuelle, copier les éléments de l'ancien tableau dans le
nouveau, ajouter le nouvel entier à la fin du nouveau tableau et libérer la
mémoire de l'ancien tableau.

Créer une fonction `showTable` qui prend en paramètre un tableau d'entiers
et sa taille, et qui affiche tous les éléments du tableau.

Créer un tableau d'entiers vide avec une capacité initiale de 5 éléments.
Ajoutez plusieurs entiers au tableau à l'aide de la fonction `addElement`, puis
affichez le tableau à l'aide de la fonction `showTable`.
*/

void addElement(int *&array, int &size, int element) {
    int *newArray = new int[size + 1];
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    newArray[size] = element;
    delete[] array;
    array = newArray;
    size++;
}

void showTable(int *array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int size = 0;
    int *array = new int[size];
    addElement(array, size, 1);
    addElement(array, size, 2);
    addElement(array, size, 3);
    addElement(array, size, 4);
    addElement(array, size, 5);
    addElement(array, size, 6);
    addElement(array, size, 7);
    addElement(array, size, 8);
    addElement(array, size, 9);
    addElement(array, size, 10);
    showTable(array, size);
    delete[] array;
}

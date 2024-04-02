#include <iostream>

void doubleArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] *= 2;
    }
}
void printArray(int array[], int size) {
    doubleArray(array, size);
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

}

int main() {
    
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);
    printArray(array, size);
    return 0;
    
}

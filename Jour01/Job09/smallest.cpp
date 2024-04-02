#include <iostream>

int main(int argc, char **argv) {
    
// Launch : a.exe <int[]> <int> (second parameter is the size of the array)

    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <int[]> <int>" << std::endl;
        // first parameter : the array of integers have to be write like this : 1 2 3 4 5
        return 1;
    }
    
    int size = std::stoi(argv[argc - 1]);
    int *array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = std::stoi(argv[i + 1]);
    }

    int *smallest = &array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < *smallest) {
            smallest = &array[i];
        }
    }

    std::cout << "The smallest element in the array is " << *smallest << std::endl;
    delete[] array;

   
    return 0;
}
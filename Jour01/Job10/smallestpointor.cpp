#include <iostream>

int main(int argc, char **argv) {
    
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <int[]> <int>" << std::endl;
        return 1;
    }
    
    int size = std::stoi(argv[argc - 1]);
    int **array = new int*[size];
    for (int i = 0; i < size; i++) {
        array[i] = new int(std::stoi(argv[i + 1]));
    }

    int **smallest = &array[0];
    for (int i = 1; i < size; i++) {
        if (*array[i] < **smallest) {
            smallest = &array[i];
        }
    }

    std::cout << "The smallest element in the array is " << **smallest << std::endl;
    
    // Free memory
    for (int i = 0; i < size; ++i) {
        delete array[i];
    }
    delete[] array;

    return 0;
}

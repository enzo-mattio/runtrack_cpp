#include <iostream>
#include <cstring>



void MySortString(const char* strings[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(strings[i], strings[j]) > 0) {
                const char* temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }
}

int main() {
    
    const char* strings[] = {"banana", "apple", "orange", "grape", "kiwi"};
    int size = sizeof(strings) / sizeof(strings[0]);
    MySortString(strings, size);
    for (int i = 0; i < size; i++) {
        std::cout << strings[i] << " ";
    }
    std::cout << std::endl;
    return 0;
    
}

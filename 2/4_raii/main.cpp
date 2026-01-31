// RAII - Resoursce Acqusition Is Initalization
// All kinds of allocation of dynamic resources should be done in contrustor, and they should all be freed in destructor 

#include <cstdio>
#include <iostream>
#include <exception>

struct RAII
{
    FILE* _file;

    RAII() {
        // Resource initialization
        _file = fopen("data.txt", "r");
    }

    ~RAII() {
        fclose(_file);
    }
};


int foo_c() {
    int return_value = 0;

    FILE* file = fopen("data.txt", "r");
    if (file != NULL) {
        int number;
        while(fscanf(file, "%d", &number) != EOF) {
            if (number < 0) {
                return_value = 1;
                break;
            }
            printf("%d ", number);
        }
        printf("\n");
    } else {
        return_value = 1;
    }

    fclose(file);
    return return_value;
}

int foo_c2() {
    int return_value = 0;

    RAII directory;

    if (directory._file == NULL)
        throw std::runtime_error("Failed to open directory!\n");

    // ...
}


int main() {
    int return_value = foo_c();
    
    if (!return_value) {
        std::cout << "Success!" << std::endl;
    } else {
        std::cout << "Failure!" << std::endl;
        return return_value;
    }       

    return 0;
}
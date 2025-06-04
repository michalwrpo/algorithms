#include <stdlib.h>
#include <iostream>
#include <random>

int main(int argc, char* argv[]) {
    if (argc != 2 && argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <len> [max]" << std::endl;
        return -1;
    }
    
    long n = atol(argv[1]);
    std::cout << n << " ";
    
    long max = 0;
    std::mt19937 mt{ std::random_device{}() };
    
    if (argc == 3) {
        max = atol(argv[2]);
        std::uniform_int_distribution<int> dist(0, max);
        
        for (long i = 0; i < n; i++) {
            std::cout << dist(mt) << " ";
        }
    } else {
        std::uniform_int_distribution<int> dist(0, 2 * n - 1);
        
        for (long i = 0; i < n; i++) {
            std::cout << dist(mt) << " ";
        }        
    }

    std::cout << std::endl;

    return 0;
}
#include <iostream>

int main() {
    std::cout << "=== DYNAMIC ARRAY ALLOCATION ===\n"
              << "Your stack size is fixed. The HEAP is infinite (until RAM runs out).\n\n";
    
    int num_jobs {0};
    std::cout << "How many job offers do you wanna store? ";
    std::cin >> num_jobs;

    int* offers = new int[num_jobs];

    for (int i {0}; i < num_jobs; i++) {
        offers[i] = 20000 + (i * 1000);
    }

    std::cout << "\nSalaries stored on the heap:\n";
    for (int i {0}; i < num_jobs; i++) {
        std::cout << "Offer " << i << ": ¥" << offers[i]
                  << " (at address " << &offers[i] << ")\n";
    }

    delete[] offers;
    offers = nullptr;

    std::cout << "\nMemory freed. No leaks. Chinese production servers would approve.\n";

    std::cout << "\n=== SWAP FUNCTION USING POINTERS ===\n";
    int a {10}, b {99};
    std::cout << "Before swap: a = " << a << ", b = " << b << '\n';

    auto swap = [](int* x, int* y) {
        int temp {*x};
        *x = *y;
        *y = temp;
    };

    swap(&a, &b);
    std::cout << "After swap: a = " << a << ", b = " << b << '\n';

    return 0;
}

#include <iostream>

int main() {
    int salary_rmb {25000};
    int* ptr_salary {&salary_rmb};
    std::cout << "=== MEMORY ADDRESS THEATER ===\n"
              << "Value of salary_rmb:  " << salary_rmb << "RMB\n"
              << "Address of salary_rmb:    " << &salary_rmb << '\n'
              << "Value stored in ptr_salary:   " << ptr_salary << "(THIS IS AN ADDRESS)\n"
              << "ptr_salary points to value:   " << *ptr_salary << " RMB (dereferencing)\n\n"
              
              << "=== USING POINTER TO CHANGE SALARY ===\n";
    *ptr_salary = 30000;
    std::cout << "New salary_rmb (direct): " << salary_rmb << "RMB\n"
              << "New *ptr_salary: " << *ptr_salary << " RMB\n";

    struct JobOffer {
        std::string company;
        int monthly_pay;
    };

    JobOffer offer1 {"ByteDance", 28000};
    JobOffer* ptr_offer {&offer1};

    std::cout << "=== ARROW OPERATOR (->) ===\n"
              << "Company via (*ptr_offer).company: " << (*ptr_offer).company << '\n'
              << "Company via ptr_offer->company:   " << ptr_offer->company << " (arrow is shortcut)\n"
              << "Salary via ptr_offer->monthly_pay: " << ptr_offer->monthly_pay << "\n\n";
    
    std::cout << "=== DANGER: WILD POINTER ===\n";
    int* wild_ptr;
    // *wild_ptr = 42;      // UNCOMMENT = CRASH!!!
    std::cout << "Wild pointer value: " << wild_ptr << " (garbage address)\n"
              << "NEVER dereference an unitialized pointer!\n";
    int* safe_ptr {nullptr};
    std::cout << "=== NULL POINTER ===\n";
    if (safe_ptr == nullptr) {
        std::cout << "safe_ptr is nullptr. Safe to check, NOT to dereference.\n";
    }

    // *safe_ptr = 10;      // ALSO CRASH!

    return 0;
}
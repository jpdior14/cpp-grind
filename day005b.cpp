#include <iostream>
#include <string>

void intern_upgrade(int copied_balance) {
    copied_balance += 500;
    std::cout << "[Intern Func]: Look! Inside the function it's " << copied_balance << '\n';
}

void architect_upgrade(int& real_balance) {
    real_balance += 1000;
    std::cout << "[Architect Func]: Modified the core memory directly to " << real_balance << '\n';
}

int main() {
    std::cout << "=== TENCENT BILLING SYSTEM RUNNING ===\n\n";

    int user_balance {100};

    std::cout << "Original Database Balance: $" << user_balance << "\n\n"
              << ">> Running Intern Upgrade...\n";
    intern_upgrade(user_balance);
    std::cout << " <-- FAILURE. The original didn't change!\n\n"

              << ">> Running Architect Upgrade (with '&')...\n";
    architect_upgrade(user_balance);
    std::cout << "Main System Database: $" << user_balance
              << " <-- SUCCESS. Core RAM updated\n";
    
    return 0;
}

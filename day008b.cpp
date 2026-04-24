#include <iostream>
#include <string>

class Alipay_Account {
private:
    std::string user_name;
    double encrypted_balance;

public:
    Alipay_Account(std::string name, double start_amount) {
        user_name = name;
        encrypted_balance = start_amount;
        std::cout << "[ALIPAY SYSTEM BOOT]: New encrypted account verified for " << user_name << '\n';
    }

    void show_balance() {
        std::cout << "[Alipay User: " << user_name << "] Current Balance: ¥" << encrypted_balance << " RMB\n";
    }

    void secure_deposit(double money_in) {
        if (money_in > 0) {
            encrypted_balance += money_in;
            std::cout << "--> Deposit Success: ¥" << money_in << " RMB\n";
        }
    }

    void secure_withdraw(double money_out) {
        if (money_out > encrypted_balance) {
            std::cout << "!! [SECURITY RED ALERT] Insufficient funds! Attack blocked! !!\n";
        } else {
            encrypted_balance -= money_out;
            std::cout << "--> Withdrawal Success: ¥" << money_out << " RMB.\n";
        }
    }
};

int main() {
    std::cout << "=== ANT FINANCIAL (ALIBABA BASE) DEPLOYMENT ===\n\n";

    Alipay_Account godzilla_wallet {"Godzilla", 5000.00};

    godzilla_wallet.show_balance();

    std::cout << "\n>>> Ordering Xiaomi 14 Pro Phone...\n";

    godzilla_wallet.secure_withdraw(3999.00);
    godzilla_wallet.show_balance();

    std::cout << "\n>>> Malicious entity attempting to steal ¥20000...\n";
    godzilla_wallet.secure_withdraw(20000.00);

    // Try to UNCOMMENT below and the compiler will...
    // godzilla_wallet.encrypted_balance = 999999;

    return 0;
}

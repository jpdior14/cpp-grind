#include <iostream>
#include <thread>
#include <mutex> // NEW CORE BARRICADE WEAPON! 
#include <string>
#include <vector>

// 1. GLOBAL SHARED MEMORY (The Battlefield)
int warehouse_stock = 10;
std::mutex transaction_barricade; // This is the physical lock!

// 2. THE HIGH-SPEED PURCHASING ALGORITHM
void flash_sale_buyer(std::string buyer_id) {
    
    // We try to enter the transaction room...
    {
        // ================= SECURITY CHECKPOINT ================= //
        // 10 bots will hit this line. Only ONE is allowed to pass at a time!
        // std::lock_guard GRABS the mutex and locks the door behind it.
        std::lock_guard<std::mutex> digital_lock(transaction_barricade); 

        // INSIDE THE VAULT (Only 1 thread exists in here at any microsecond)
        if (warehouse_stock > 0) {
            std::cout << "[TAOBAO SERVER]: " << buyer_id << " secured the bag! ";
            warehouse_stock -= 1; // Take one from inventory
            std::cout << "Remaining Stock: " << warehouse_stock << '\n';
        } else {
            std::cout << "[TAOBAO SERVER]: " << buyer_id << " failed. SOLD OUT.\n";
        }
        // ================= DOOR OPENS ================= //
    } // As soon as this bracket hits, digital_lock auto-destroys and hands the key to the next thread waiting!
}

int main() {
    std::cout << "=== TAOBAO FLASH SALE DEPLOYMENT ===\n";
    std::cout << "Initial Stock: " << warehouse_stock << " iPhones\n\n";

    // Create an army of threads
    std::vector<std::thread> buyer_bots;

    std::cout << "!!! MASSIVE WEB TRAFFIC SPIKE DETECTED !!!\n";
    
    // Spawning 15 individual concurrent threads using our Day 4 vectors!
    // They are ALL firing into the 'flash_sale_buyer' function at nearly the SAME nanosecond!
    for (int i = 1; i <= 15; i++) {
        std::string name = "User_Bot_#" + std::to_string(i);
        buyer_bots.push_back(std::thread(flash_sale_buyer, name));
    }

    // Command the Main thread to wait for all 15 bots to finish their chaos.
    for (auto& bot : buyer_bots) {
        bot.join();
    }

    std::cout << "\nStatus: EVENT CONCLUDED. WAREHOUSE HOLDING EXACTLY " << warehouse_stock << " ITEMS.\n";
    std::cout << "DATA RACE PREVENTED BY MULTITHREAD MUTEX!\n";

    return 0;
}

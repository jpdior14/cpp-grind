#include <iostream>
#include <unordered_map> // NEW WEAPON! The O(1) Lookup Table.
#include <string>

int main() {
    std::cout << "=== TENCENT GLOBAL DATACENTER (Instant Indexing) ===\n\n";

    // 1. THE HASH MAP BLUEPRINT
    // Look at our templates in action! 
    // We are making a map where the "Key" is a string (username) 
    // and the "Value" is an int (account points)
    std::unordered_map<std::string, int> wechat_db;

    // 2. FILLING THE DB WITH THE INDEX PROTOCOL
    // Boom! Direct assignment without arrays, pushing back, or sizing!
    wechat_db["Tencent_CEO"] = 9999999;
    wechat_db["Intern_Bao"] = -5;
    wechat_db["Yaounde_Godzilla"] = 250000;
    
    // We can even check the size instantly!
    std::cout << "Server Live: Database holds " << wechat_db.size() << " user profiles.\n\n";

    // 3. THE $O(1)$ BYTEDANCE SEARCH REQUEST!
    std::string search_target = "Yaounde_Godzilla";

    std::cout << "--> Client requesting data for User: [" << search_target << "]\n";
    std::cout << "--> Bypassing vectors... ignoring other 1 billion entries...\n";

    // Check if the user exists using `.find()`. It operates at blazing speed!
    // 'wechat_db.end()' means "We reached the end of the void and didn't find them."
    if (wechat_db.find(search_target) != wechat_db.end()) {
        std::cout << "\n[QUERY MATCHED IN O(1) NANOSECONDS!]\n";
        
        // Retrieve the data DIRECTLY using the key name! 
        std::cout << search_target << " Balance: ¥" << wechat_db[search_target] << " RMB\n";
    } else {
        std::cout << "\n[ERROR]: User does not exist in the database!\n";
    }

    std::cout << "\nStatus: NO FOR-LOOPS USED. 100% MAXIMUM SERVER OPTIMIZATION!\n";

    return 0;
}

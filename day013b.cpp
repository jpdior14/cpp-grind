#include <iostream>
#include <vector>
#include <memory>  // Our Bodyguards!
#include <string>

// 1. THE PARENT BLUEPRINT
class WeChat_Item {
public:
    // This MUST exist in parent classes so that Children memory gets deleted properly later!
    virtual ~WeChat_Item() = default; 

    // THE MAGIC WORD: "virtual". It allows Children to shatter this logic and rewrite it dynamically!
    virtual void trigger_notification() {
        std::cout << "[WeChat Default] You have a blank notification.\n";
    }
};

// 2. THE TEXT MESSAGE (Child)
class TextMessage : public WeChat_Item {
private: 
    std::string sender;
public:
    TextMessage(std::string name) : sender(name) {}

    // OVERRIDE: We destroy the parent's generic message and deploy our own!
    void trigger_notification() override {
        std::cout << "[Message Bubble]💬 From " << sender << ": Are you studying in the taxi today?\n";
    }
};

// 3. THE RED PACKET FINANCE APP (Child 2)
class RedPacket : public WeChat_Item {
private:
    int money_rmb;
public:
    RedPacket(int amount) : money_rmb(amount) {}

    // OVERRIDE: Entirely different behavior, triggered from the exact same command!
    void trigger_notification() override {
        std::cout << "[WeChat Pay]🧧 FINANCIAL INCOMING: ¥" << money_rmb << " RMB added to your vault!!\n";
    }
};


int main() {
    std::cout << "=== TENCENT SHENZHEN CLUSTER: LOADING WECHAT UI ===\n\n";

    // THIS IS THE PEAK OF MODERN C++ 
    // We make a single dynamic vector holding Smart Pointers of the BASE class.
    std::vector<std::unique_ptr<WeChat_Item>> daily_notifications;

    // And yet... we shove CHILD objects inside it! Because a Text Message "IS A" WeChat Item.
    daily_notifications.push_back(std::make_unique<TextMessage>("Mom"));
    daily_notifications.push_back(std::make_unique<RedPacket>(500));
    daily_notifications.push_back(std::make_unique<TextMessage>("Huawei Recruiter"));

    std::cout << ">>> Running automated Notification Scanner:\n\n";

    // ONE single loop to process everything, regardless of what it is! This scales to millions.
    for (const auto& item_guard : daily_notifications) {
        
        // Polymorphism engaged! 
        // We run ONE function. The compiler mathematically figures out EXACTLY 
        // which child version of the function needs to fire at runtime! 
        item_guard->trigger_notification(); 
        
    } // BOOM: As soon as we leave the vector, every Smart Pointer deletes the data! ZERO Leaks!

    std::cout << "\nStatus: WECHAT TIMELINE RENDERED PURELY ON POLYMORPHIC ALGORITHMS!\n";

    return 0;
}

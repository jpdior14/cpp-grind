#include <iostream>
#include <vector>
#include <memory>
#include <string>

class WeChat_Item {
public:
	virtual ~WeChat_Item() = default;

	virtual void trigger_notification() {
		std::cout << "[WeChat Default] You have a blank notification.\n";
	}
};

class TextMessage : public WeChat_Item {
private:
	std::string sender;
public:
	TextMessage(std::string name) : sender(name) {}

	void trigger_notification() override {
		std::cout << "[Message Bubble] From " << sender << ": Are you studying in the taxi today?\n";
	}
};

class RedPacket : public WeChat_Item {
private:
	int money;
public:
	RedPacket(int amount) : money(amount) {}

	void trigger_notification() override {
		std::cout << "[WeChat Pay] FINANCIAL INCOMING: ¥" << money << " RMB added to your vault!!\n";
	}
};

int main() {
	std::cout << "=== TENCENT SHENZHEN CLUSTER: LOADING WECHAT UI ===\n\n";

	std::vector<std::unique_ptr<WeChat_Item>> daily_notifications;

	daily_notifications.push_back(std::make_unique<TextMessage>("Mom"));

	daily_notifications.push_back(std::make_unique<RedPacket>(500));

	daily_notifications.push_back(std::make_unique<TextMessage>("Huawei Recruiter"));

	std::cout << "Running automated Notification Scanner:\n\n";

	for (const auto& item_guard : daily_notifications) {
		item_guard->trigger_notification();
	}

	std::cout << "\nStatus: WECHAT TIMELINE RENDERED PURELY ON POLYMORPHIC ALGORITHMS!\n";

	return 0;
}

#include <iostream>
#include <string>

class Base_User {
protected:
	std::string username;
	int base_trust_score;

public:
	Base_User(std::string name) {
		username = name;
		base_trust_score = 100;
	}

	void core_login() {
		std::cout << "[BYTEDANCE SECURE DB] User " << username << " authenticated globally.\n";
	}
};

class TikTok_User : public Base_User {
private:
	int video_views;

public:
	TikTok_User(std::string name) : Base_User(name) {
		video_views = 0;
		std::cout << "[TIKTOK OVERRIDE] Profile established for international region.\n";
	}

	void watch_brainrot() {
		video_views += 1;
		base_trust_score -= 5;
		std::cout << ">>> " << username << " watched a video. Total Views: " << video_views << '\n'
			  << "	Base Trust Score dropping to: " << base_trust_score << " (Stop scrolling bruh!)\n";
	}
};

int main() {
	std::cout << "=== BYTEDANCE SERVER BOOT SEQUENCE ===\n\n";

	TikTok_User godzilla {"Godzilla"};

	std::cout << "\nAttempting Login:\n";
	godzilla.core_login();

	std::cout << "\nAlgorithm feeding videos:\n";
	godzilla.watch_brainrot();
	godzilla.watch_brainrot();

	return 0;
}

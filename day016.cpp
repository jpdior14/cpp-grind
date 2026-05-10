#include <iostream>
#include <thread>
#include <chrono>
#include <string>

void download_vid_data(std::string vid_name) {
	std::cout << "[Core 1]: Background Engine Started! Downloading " << vid_name << "...\n";

	std::this_thread::sleep_for(std::chrono::seconds(3));

	std::cout << "[Core 1]: VIDEO DOWNLOAD COMPLETE (" << vid_name << ")!\n";
}

void load_ui_comments() {
	std::cout << "[Core 2]: UI Render Started! Loading comment section...\n";

	for (int i {1}; i <= 3; i++) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "[Core 2 - UI]: User Comment " << i << " rendered on screen instantly!\n";
	}
}

int main() {
	std::cout << "=== BYTEDANCE (DOUYIN) ASYNC ENGINE STARTUP ===\n\n"
		  << "-> Waking up Multi-Core processor on ThinkPad...\n\n";

	std::thread background_task(download_vid_data, "Yaounde_Vlog.mp4");
	std::thread ui_task(load_ui_comments);

	std::cout << "\n[Main Thread]: Both secondary cores are now running independently!\n"
		  << "[Main Thread]: Waiting for them to finish...\n\n";

	background_task.join();
	ui_task.join();

	std::cout << "\nStatus: ASYNC EXECUTION COMPLETE. MULTI-CORE HARDWARE UNLOCKED!\n";

	return 0;
}

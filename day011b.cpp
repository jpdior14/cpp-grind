#include <iostream>

struct HonorOfKings_Map {
	int total_tress {5000};
	int total_npcs {1000};

	HonorOfKings_Map() {
		std::cout << "[RAM BUILDER] => 4K Map generated on the Hardware Heap!\n";
	}

	~HonorOfKings_Map() {
		std::cout << "[RAM PURGE] => 4K Map completely erased. Memory handed back to the system safely!\n";
	}
};

int main() {
	std::cout << "=== TENCENT TIANMEI STUDIOS (GAME INSTANCE START) ===\n\n"
			  << "Player requested matching phase. Building level...\n";

	HonorOfKings_Map* game_level_ptr = new HonorOfKings_Map;

	std::cout << "\nGame in Progress... 20 minutes pass... Defeat! (We'll get them next time)\n"
			  << "Closing game lobby...\n\n";

	delete game_level_ptr;

	game_level_ptr = nullptr;

	std::cout << "\nStatus: ZERO MEMORY LEAK. HARDWARE IN PERFECT CONDITION.\n"
			  << "Shutting Down safely.\n";

	return 0;
}

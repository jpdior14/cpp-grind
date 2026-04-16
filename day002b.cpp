#include <iostream>

int calculate_power_level(int base_level, int days_studied) {
	int current_level {base_level};

	for (int i {1}; i <= days_studied; i++) {
		current_level += 2;
	}

	return current_level;
}

int main() {
	int start_power {10};
	int streak_days {120};

	std::cout << "[System Boot]: Booting AI-Yaounde Tracker...\n";

	int end_power = calculate_power_level(start_power, streak_days);

	std::cout << "--- 1 Month Simulation ---\n"
		  << "If you study C++ on the bus for " << streak_days << " days:\n"
		  << "Your Base Skill Level: " << start_power << '\n'
		  << "Your Projected Level: " << end_power << '\n';

	if (end_power > 50) {
		std::cout << "\nStatus: UNTOUCHABLE. The gap is widening.\n";
	} else {
		std::cout << "\nStatus: Grind harder.\n";
	}

	return 0;
}

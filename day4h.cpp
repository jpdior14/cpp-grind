#include <iostream>
#include <string>

int main() {
	const int APPLICATIONS_NEEDED = 100;
	const int INTERVIEW_RATE_PERCENT = 3;

	std::cout << "=== MAIMAI JOB APPLICATION SIMULATOR ===\n"
		  << "Market: Java Backend, Fresh Grad, Chengdu\n\n";

	int interview_count = 0;
	for (int i = 1; i <= APPLICATIONS_NEEDED; i++) {
		std::cout << "Sending application #" << i << "...";

		if (i % 33 == 0) {
			std::cout << "INTERVIEW REQUEST (Company #" << (i % 10 + 1) << ")\n";
			interview_count++;
		} else {
			std::cout << "GHOSTED...\n";
		}
	}

	std::cout << "\n--- RESULTS AFTER " << APPLICATIONS_NEEDED << " APPLICATIONS ---\n"
		  << "Interviews received: " << interview_count << "\n"
		  << "Ghost rate: " << (APPLICATIONS_NEEDED - interview_count) * 100 / APPLICATIONS_NEEDED << "%\n";

	std::cout << "\n=== PREPARING FOR INTERVIEWS ===\n";
	int leetcode_problems_solved = 0;
	char ready = 'n';

	while (ready != 'y' && ready != 'Y') {
		leetcode_problems_solved += 5;
		std::cout << "Solved" << leetcode_problems_solved << " LeetCode problems...\n";

		if (leetcode_problems_solved >= 150) {
			std::cout << "You've solved 150+ problems. Are you ready for the interview? (y/n): ";
			std::cin >> ready;
		}

		if (leetcode_problems_solved >= 500) {
			std::cout << "You've solved 500 problems. You're either or dead. Automatically ready.\n";
			ready = 'y';
		}
	}

	std::cout << "\n--- FINAL STATUS ---\n"
		  << "Applications sent: " << APPLICATIONS_NEEDED << '\n'
		  << "Interviews: " << interview_count << '\n'
		  << "LeetCode count: " << leetcode_problems_solved << '\n';

	if (interview_count > 0 && leetcode_problems_solved >= 150) {
		std::cout << "Verdict: YOU MIGHT SURVIVE THE CHINESE TECH WINTER.\n";
	} else {
		std::cout << "Verdict: GRIND HARDER.\n";
	}

	std::cout << "\n=== BONUS: The 'Age 35' Countdown ===\n";
	int age = 22;
	do {
		std::cout << "Age " << age << ": Still employable?\n";
		age++;
	} while (age <= 35);
	std::cout << "Age 35 reached. Welcome to the 'expiration date'. Update your side hustle.\n";

	return 0;
}

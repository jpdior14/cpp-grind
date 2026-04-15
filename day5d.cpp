#include <iostream>
#include <string>

int send_applications(int num_apps, int response_rate_percent);

int grind_leetcode();

void age_countdown(int start_age);

void print_verdict(int apps, int interviews, int leetcode);

void send_applications(std::string company_name, int num_apps) {
	std::cout << "Targeting " << company_name << " with " << num_apps << " applications.\n";
	int result = send_applications(num_apps, 5);
	std::cout << "Got " << result << " interviews from " << company_name << ".\n";
}

int main() {
	std::cout << "=== MAIMAI JOB APPLICATION SIMULATOR ===\n"
		  << "Market: Java Backend, Fresh Grad, Chengdu\n\n";

	const int APPLICATIONS_NEEDED {100};
	const int INTERVIEW_RATE {3};

	send_applications("ByteDance", 20);
	int interviews_gotten = send_applications(APPLICATIONS_NEEDED, INTERVIEW_RATE);
	int leetcode_solved = grind_leetcode();

	std::cout << "\n=== FINAL REPORT ===\n";
	print_verdict(APPLICATIONS_NEEDED, interviews_gotten, leetcode_solved);

	age_countdown(22);

	return 0;
}

int send_applications(int num_apps, int response_rate_percent) {
	int interviews {0};

	for (int i = 1; i <= num_apps; i++) {
		std::cout << "Sending application #" << i << "...";

		int threshold {100 / response_rate_percent};

		if (i % threshold == 0) {
			std::cout << "INTERVIEW REQUEST!\n";
			interviews++;
		} else {
			std::cout << "GHOSTED.\n";
		}
	}

	std::cout << "\n--- APPLICATIONS COMPLETE! ---\n"
		  << "Sent: " << num_apps << '\n'
		  << "Interviews: " << interviews << '\n'
		  << "Ghost rate: " << (num_apps - interviews) * 100 / num_apps << "%\n";
	return interviews;
}

int grind_leetcode() {
	std::cout << "\n=== PREPARING FOR INTERVIEWS ===\n";

	int problems {0};
	char ready {'n'};

	while (ready != 'y' && ready != 'Y') {
		problems += 5;
		std::cout << "Solved " << problems << " Leetcode problems...\n";

		if (problems >= 150) {
			std::cout << "You've solved 150+ problems. Read y? (y/n): ";
			std::cin >> ready;
		}

		if (problems >= 500) {
			std::cout << "500 problems! Auto-ready.\n";
			ready = 'y';
		}
	}

	return problems;
}

void age_countdown(int start_age) {
	std::cout << "\n=== THE 'AGE 35' COUNTDOWN ===\n";

	int age = start_age;
	do {
		std::cout << "Age " << age << ": ";
		if (age < 30) {
			std::cout << "Safe. Keep grinding.\n";
		} else if (age < 35) {
			std::cout << "WARNING: Update your resume.\n";
		} else {
			std::cout << "EXPIRED. Hope you saved money.\n";
		}
		age++;
	} while (age <= 35);
}

void print_verdict(int apps, int interviews, int leetcode) {
	std::cout << "Applications: " << apps << '\n'
		  << "Interviews: " << interviews << '\n'
		  << "LeetCode solved: " << leetcode << '\n';

	if (interviews > 0 && leetcode >= 150) {
		std::cout << "Verdict: YOU MIGHT SURVIVE THE CHINESE TECH WINTER.\n";
	} else if (interviews == 0) {
		std::cout << "Verdict: Your resume needs work. Or the market is frozen. (Both true.)\n";
	} else {
		std::cout << "Verdict: GRIND HARDER!\n";
	}
}

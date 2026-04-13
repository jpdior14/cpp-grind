#include <iostream>
#include <string>

int main() {
	const int LEGAL_DAILY_HOURS = 8;
	const int LEGAL_WEEKLY_HOURS = 40;

	int hours_worked_today, hours_worked_this_week;

	std::cout << "=== CHINA OVERTIME CHECKER ===\n"
		  << "Enter hours worked TODAY: ";
	std::cin >> hours_worked_today;

	std::cout << "Enter hours worked THIS WEEK (including today): ";
	std::cin >> hours_worked_this_week;

	if (hours_worked_today > LEGAL_DAILY_HOURS) {
		std::cout << "\n[DAILY] ILLEGAL OVERTIME. You are owed extra pay.\n";
		int overtime_today = hours_worked_today - LEGAL_DAILY_HOURS;
		std::cout << "You worked " << overtime_today << " extra hour(s) today.\n";
	} else {
		std::cout << "\n[DAILY] Legal workday. Clock out and go home.\n";
	}

	if (hours_worked_this_week > LEGAL_WEEKLY_HOURS) {
                std::cout << "\n[WEEKLY] ILLEGAL OVERTIME. 996 detected. Seek compensation or RUN!\n";
                int overtime_week = hours_worked_this_week - LEGAL_WEEKLY_HOURS;
                std::cout << "You worked " << overtime_week << " extra hour(s) this week.\n";
        } else {
                std::cout << "\n[WEEKLY] Legal workweek. Your employer is (probably) not evil.\n";
        }

	if (hours_worked_today >= 12) {
		std::cout << "\nWARNING: You worked 12+ hours today!\n"
			  << "	At Chinese tech firms, this is '007' (0:00-0:00, 7 days).\n"
			  << "	Go to sleep. The code will be there tomorrow.\n";
	}

	std::cout << "\n--- VERDICT ---\n";
	if (hours_worked_today <= 8 && hours_worked_this_week <= 40) {
		std::cout << "You are a model employee. But are you learning enough?\n";
	} else if (hours_worked_today <= 10 && hours_worked_this_week <= 50) {
		std::cout << "You are in the 'grind zone.' Typical Chinese startup life.\n";
	} else {
		std::cout << "You are being exploited. Update your LeetCode profile.\n";
	}

	return 0;
}

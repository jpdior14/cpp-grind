#include <iostream>
#include <string>
#include <vector>

class SoftwareEngineer {
private:
	std::string name;
	int age;
	int leetcode_solved;
	std::vector<std::string> skills;
	bool is_employed;

public:
	SoftwareEngineer(std::string n, int a) : name(n), age(a), leetcode_solved(0), is_employed(false) {
		std::cout << "Engineer " << name << " created\n";
	}

	void grindLeetCode(int problems) {
		leetcode_solved += problems;
		std::cout << name << " solved " << problems
			  << " problems. Total: " << leetcode_solved << '\n';
	}

	void learnSkill(const std::string& skill) {
		skills.push_back(skill);
	}

	int getLeetCodeCount() const {
		return leetcode_solved;
	}

	void setEmployed(bool status) {
		is_employed = status;
	}

	void displayStatus() const {
		std::cout << "\n=== ENGINEER REPORT ===\n"
			  << "Name: " << name << '\n'
			  << "Age: " << age << '\n'
			  << "LeetCode: " << leetcode_solved << '\n'
			  << "Skills: ";
			for (const auto& skill: skills) {
				std::cout << skill << " ";
			}
			std::cout << "\nEmployed: " << (is_employed ? "YES" : "NO") << '\n';
	}
};

int main() {
	SoftwareEngineer christian("Christian", 17);

	christian.grindLeetCode(5);
	christian.grindLeetCode(3);
	christian.learnSkill("C++");
	christian.learnSkill("Chinese");
	christian.learnSkill("Algorithms");

	std::cout << "Problems solved: " << christian.getLeetCodeCount() << '\n';

	christian.setEmployed(false);
	christian.displayStatus();

	return 0;
}

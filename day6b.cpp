#include <iostream>
#include <string>
#include <vector>

struct TechCompany {
	std::string name;
	std::string headquarters;
	int founded_year;
	bool has_996_culture;
	int estimated_headcount;

};

void print_company (const TechCompany& company);
void print_all_companies(const std::vector<TechCompany>& companies);
int count_996_companies(const std::vector<TechCompany>& companies);
TechCompany find_oldest_company(const std::vector<TechCompany>& companies);

int main() {
	std::cout << "=== CHINESE TECH COMPANY DATABASE ===\n\n";

	std::vector<TechCompany> china_tech = {
		{"ByteDance", "Beijing", 2012, true, 150000},
		{"Tencent", "Shenzhen", 1998, true, 105000},
		{"Alibaba", "Hangzhou", 1999, true, 220000},
		{"Baidu", "Beijing", 2000, true, 40000},
		{"Huawei", "Shenzhen", 1987, true, 207000},
		{"DJI", "Shenzhen", 2006, true, 14000},
		{"Xiaomi", "Beijing", 2010, false, 33000},
		{"Pinduoduo", "Shanghai", 2015, true, 13000}
	};

	std::cout << "First company in database: " << china_tech[0].name << '\n'
		  << "Last company in database: " << china_tech[china_tech.size() - 1].name << '\n';

	print_all_companies(china_tech);

	int total_companies = china_tech.size();
	int nine_nine_six_count = count_996_companies(china_tech);
	TechCompany oldest = find_oldest_company(china_tech);

	std::cout << "\n=== ANALYTICS ===\n"
		  << "Total companies: " << total_companies << '\n'
		  << "Companies with 996 culture: " << nine_nine_six_count << " (" << (nine_nine_six_count * 100 / total_companies) << "%)\n"
		  << "Oldest company: " << oldest.name << " (founded " << oldest.founded_year << ")\n";

	std::string search_name;
	std::cout << "\nEnter a company name to search: ";
	std::getline(std::cin, search_name);
	std::cout << "\n[EXPERIMENT] Accessing index 100: " << china_tech.at(100).name << '\n';
	bool found = false;
	for (const auto& company : china_tech) {
		if (company.name == search_name) {
			std::cout << "\n FOUND:\n";
			print_company(company);
			found = true;
			break;
		}
	}
	if (!found) {
		std::cout << "\n Company not in database. Maybe a start-up?\n";
	}

	std::cout << "\n=== DANGER ZONE (Uncomment to crash ===\n"
		  << "// china_tech[100] would crash. Arrays don't check bounds in C++.\n"
		  << "// This is why we use .at() for safe access: china_tech.at(100) throws exception.\n";

	return 0;
}

void print_company(const TechCompany& company) {
	std::cout << " " << company.name << '\n'
		  << "	HQ: " << company.headquarters << '\n'
		  << "	Founded: " << company.founded_year << '\n'
		  << "	Headcount: ~" << company.estimated_headcount << '\n'
		  << "	996 Culture: " << (company.has_996_culture ? "Yes" : "ALLEGEDLY No") << '\n';
}

void print_all_companies(const std::vector<TechCompany>& companies) {
	std::cout << "=== ALL COMPANIES ===\n";
	for (size_t i = 0; i < companies.size(); i++) {
		std::cout << "[" << i << "] " << companies[i].name << '\n';
	}
	std::cout << "----------------------\n";
}

int count_996_companies(const std::vector<TechCompany>& companies) {
	int count = 0;
	for (const auto& c : companies) {
		if (c.has_996_culture) {
			count++;
		}
	}
	return count;
}

TechCompany find_oldest_company(const std::vector<TechCompany>& companies) {
	TechCompany oldest = companies[0];
	for (const auto c : companies) {
		if (c.founded_year < oldest.founded_year) {
			oldest = c;
		}
	}
	return oldest;
}

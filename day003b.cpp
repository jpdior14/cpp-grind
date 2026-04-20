#include <iostream>

int main() {
	int ictu_scores[6] {85, 92, 88, 100, 95, 89};

	int total_score {0};
	double final_average {0.0};

	std::cout << "[TENCENT HR PORTAL] - Connecting to ICTU Database...\n"
		  << "Loading first semester grades:\n";

	for (int i {0}; i < 6; i++) {
		std::cout << "Subject offset [" << i << "] Score: " <<ictu_scores[i] << '\n';

		total_score += ictu_scores[i];
	}

	final_average = static_cast<double> (total_score) / 6;

	std::cout << "============================\n"
		  << "AGGREGATE PIPELINE COMPLETE.\n"
		  << "Total Marks: " << total_score << " / 600\n"
		  << "Average Target Score: " << final_average << "%\n";

	if (final_average >= 90.0) {
		std::cout << "Hardware Grade: Huawei-tier Execution.\n";
	}

	return 0;
}

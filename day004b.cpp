#include <iostream>
#include <vector>
#include <string>

int main() {
	std::cout << "[ALIBABA SERVER START] System traffic Monitoring...\n\n";

	std::vector<int> traffic_spikes {};

	std::cout << "Server Capacity starting out: " << traffic_spikes.size() << " records.\n";

	traffic_spikes.push_back(15000);
	traffic_spikes.push_back(23000);
	traffic_spikes.push_back(40000);

	std::cout << "Live Update: Vector dynamically expanded to hold "
		  << traffic_spikes.size() << " traffic reports.\n"
		  << "\n--- Fetching Logs ---\n";
	int total_traffic {0};

	for (int spike : traffic_spikes) {
		std::cout << "Recorded Request: " << spike << " packets\n";
		total_traffic += spike;
	}

	std::cout << "\n[EMERGENCY 11:59 PM] Late user surge incoming...\n";
	traffic_spikes.push_back(80000);

	std::cout << "The Vector accepted it! Size is now: " << traffic_spikes.size() << '\n'
		  << "\nAll logs secure. Status: TAOBAO SERVER HOLDING. ZERO DOWNTIME.\n";

	return 0;
}

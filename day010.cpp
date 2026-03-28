#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> prices = {7, 1, 5, 3, 6, 4};

	int lowest = prices[0];
	int maxProfit = 0;

	for (int i = 0; i < prices.size(); i++) {
		if (prices[i] < lowest) {
			lowest = prices[i];
		}
		int profit = prices[i] - lowest;
		if (profit > maxProfit) {
			maxProfit = profit;
		}
	}

	cout << "Max profit: " << maxProfit << endl;
	return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	vector<int> nums = {1, 2, 3, 1};
	unordered_map<int, int> seen;

	for (int i = 0; i < nums.size(); i++) {
		if (seen.find(nums[i]) != seen.end()) {
			cout << "DUPLICATE FOUND!\n";
			return 0;
		} else {
			seen[nums[i]] = i;
		}
	}

	cout << "No duplicates\n";
	return 0;
}

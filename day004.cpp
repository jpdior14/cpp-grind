#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	vector<int> nums = {2, 7, 11, 15};
	int target = 9;
	unordered_map<int, int> seen;

	for (int i = 0; i < nums.size(); i++) {
		int need = target - nums[i];

		cout << "At index " << i << ", number is " << nums[i] << ", I need " << need << endl;

		if (seen.find(need) != seen.end()) {
			cout << "FOUND IT! Indices: " << seen[need] << " and " << i << endl;
		}
		seen[nums[i]] = i;
	}


	return 0;
}

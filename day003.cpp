#include <iostream>
#include <vector>

int main() {
	std::vector<int> nums = {2, 7, 11};
	int target = 9;

	for (int i = 0; i < nums.size(); i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			if (nums[i] + nums[j] == target) {
				std::cout << "FOUND IT!\nIndices: " << i << " and " << j << '\n';
            }
        }
    }
    return 0;
}

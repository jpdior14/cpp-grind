#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> nums = {-1, 0, 3, 5, 9, 12};
	int target = 2;

	int L = 0;
	int R = nums.size() - 1;

	int ans = -1;

	while (L <= R) {
		int mid = (L + R) / 2;

		if (nums[mid] == target) {
			ans = mid;
			break;
		} else if (nums[mid] < target) {
			L = mid+1;
		} else {
			R = mid-1;
		}
	}

	cout << "Found at index: " << ans << endl;
	return 0;
}

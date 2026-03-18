#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> nums = {5, 10, 15, 20};

	cout << "Before push_back, size: " << nums.size() << endl;

	nums.push_back(40);

	cout << "After push_back, size: " << nums.size() << endl;
	cout << "Last element: " << nums[4] << endl;

	return 0;
}

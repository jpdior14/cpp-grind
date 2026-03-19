#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {2, 7, 11};
    int target = 9;
    
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                cout << "FOUND IT!" << endl << "Indices: " << i << " and " << j << endl;
            }
        }
    }
    return 0;
}

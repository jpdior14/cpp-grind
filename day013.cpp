#include <iostream>
using namespace std;

int main() {
	int ans = 0;

	ans = ans ^ 4;
	cout << "After 4: " << ans << endl;

	ans = ans ^ 4;
	cout << "After twin 4: " << ans << endl;

	ans = ans ^ 7;
	cout << "After 7: " << ans << endl;

	return 0;
}

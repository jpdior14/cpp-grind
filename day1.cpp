#include <iostream>
using namespace std;

int main() {
	double x;
	double y;

	cout << "Enter X coordinate: ";
	cin >> x;

	cout << "Enter Y coordinate: ";
	cin >> y;

	double magnitude_squared = (x * x) + (y * y);

	cout << "Vector X: " << x << "\n";
	cout << "Vector Y: " << y << "\n";
	cout << "Their magnitude squared: " << magnitude_squared << "\n";

	return 0;
}

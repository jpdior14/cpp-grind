#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
        double x;

        int count = 0;
        double sum = 0;

	vector<double> history;

        while (true) {

                cout << "\n=== New Calculation ===\n";
                cout << "Enter a number (Type 999 to quit): ";
                cin >> x;

                if (x == 999) {
                        cout << "----------------------------\n";
                        cout << "Shutting down ... Bye!\n";

	                if (count > 0) {
        	                double sum = 0;
				double sum_squares = 0;

				for (double val : history) {
					sum += val;
					sum_squares += (val * val);
				}

				double average = sum / count;

				double magnitude = sqrt(sum_squares);

				cout << "Average Value: " << average << endl;
				cout << "Vector Magnitude (Norm): " << magnitude << endl;

			} else {
				cout << "No numbers entered.\n";
			}

			cout << "History of Inputs: ";
			for (double val : history) {
				cout << val << " ";
			}
			cout << "\n";
			break;
		}

		count += 1;
		sum += x;

		history.push_back(x);

		if (x > 0) {
			cout << "Result: Positive\n";
		} else if (x < 0) {

			cout << "Result: Negative\n";
		} else {
			cout << "Result: Zero\n";
		}
	}

	return 0;
}

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

double getAverage(const vector<double>& data) {
	if (data.empty()) return 0.0;

	double sum = 0;
	for (double val : data) {
		sum += val;
	}
	return sum / data.size();
}

double getNorm(const vector<double>& data) {
	double sum_sq = 0;
	for (double val : data) {
		sum_sq += val * val;
	}
	return sqrt(sum_sq);
}

void printReport(const vector<double>& data) {
	cout << "---------------------\n";
	cout << "REPORT GENERATED\n";

	if (data.empty()) {
		cout << "No data entered.\n";
		return;
	}

	double avg = getAverage(data);
	double norm = getNorm(data);

	cout << "Total Inputs: " << data.size() << endl;
	cout << "Average: " << avg << endl;
	cout << "Magnitude (Norm): " << norm << endl;

	cout << "History: ";
	for (double val : data) {
		cout << val << " ";
	}
	cout << "\n";
	cout << "Shutting down ...  Bye!\n";
	cout << "---------------------\n";
}

void saveToDisk(vector<double>& data) {
	ofstream file("history.txt");

	for (double val : data) {
		file << val << endl;
	}
	file.close();
}

void loadFromDisk(vector<double>& data) {
	ifstream file("history.txt");

	if (!file.is_open()) {
		return;
	}

	double val;
	while (file >> val) {
		data.push_back(val);
	}
	file.close();
}

int main() {
	vector<double> history;

	loadFromDisk(history);
	if (!history.empty()) {
		cout << "[SYSTEM] Previous session loaded. " << history.size() << " entries found.\n";
	}

	double x;

	while (true) {
		cout << "\nEnter a number (999 to exit; -999 to clear history): ";
		cin >> x;

		if (x == 999) {
			printReport(history);
			saveToDisk(history);
			break;
		}

		if (x == -999) {
			cout << "!!! WARNING: WIPING ALL HISTORY !!!\n";
			history.clear();
			cout << "History cleared. Ready for fresh data\n";
			continue;
		}

		history.push_back(x);
	}

	return 0;
}

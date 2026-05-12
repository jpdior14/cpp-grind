#include <iostream>

int calculateSum(int scores[], int size) {
	int sum {0};
	for (int i {0}; i < size; i++) {
		sum += scores[i];
	}
	return sum;
}

int calculateAverage(int scores[], int size) {
	int sum = calculateSum(scores, size);
	return sum / size;
}

int findHighest(int scores[], int size) {
	int highest = scores[0];
	for (int i {1}; i < size; i++) {
		if (scores[i] > highest) {
			highest = scores[i];
		}
	}
	return highest;
}

int findLowest(int scores[], int size) {
	int lowest = scores[0];
	for (int i {1}; i < size; i++) {
		if (scores[i] < lowest) {
			lowest = scores[i];
		}
	}
	return lowest;
}

int main() {
	int scores[5] {85, 92, 78, 90, 88};

	std::cout << "Sum: " << calculateSum(scores, 5) << '\n'
		  << "Average: " << calculateAverage(scores, 5) << '\n'
		  << "Highest: " << findHighest(scores, 5) << '\n'
		  << "Lowest: " << findLowest(scores, 5) << '\n';

	return 0;
}

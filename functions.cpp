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

int countAbove80(int scores[], int size) {
	int count {0};
	for (int i {0}; i < size; i++) {
		if (scores[i] >= 80) {
			count++;
		}
	}
	return count;
}

int main() {
	int scores[7] {85, 92, 78, 90, 88, 86, 87};

	std::cout << "Sum: " << calculateSum(scores, 7) << '\n'
		  << "Average: " << calculateAverage(scores, 7) << '\n'
		  << "Highest: " << findHighest(scores, 7) << '\n'
		  << "Lowest: " << findLowest(scores, 7) << '\n'
		  << "Number of scores with 80 and above: " << countAbove80(scores, 7) << '\n';

	return 0;
}

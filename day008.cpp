#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<char> s = {'h', 'e', 'l', 'l', 'o'};

	int L = 0;
	int R = s.size() - 1;

	while (L < R) {
		char temp = s[L];
		s[L] = s[R];
		s[R] = temp;
		L++;
		R--;
	}

	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << " ";
	}
	cout << endl;

	return 0;
}

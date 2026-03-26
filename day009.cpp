#include <iostream>
#include <string>
using namespace std;

int main() {
	string s = "A man, a plan, a canal: Panama";

	int L = 0;
	int R = s.size() - 1;

	while(L < R) {
		while (L < R && !isalnum(s[L])) {
			L++;
		}

		while (L < R && !isalnum(s[R])) {
			R--;
		}

		if (tolower(s[L]) != tolower(s[R])) {
			cout << "NOT a palindrome\n";
			return 0;
		}

		L++;
		R--;
	}

	cout << "YES, it's a palindrome!\n";

	return 0;
}

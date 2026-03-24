#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	string s = "anagram";
	string t = "nagaram";
	unordered_map<char, int> count;

	for (int i = 0; i < s.size(); i++) {
		count[s[i]]++;
	}

	for (int i = 0; i < t.size(); i++) {
		count[t[i]]--;
	}

	for (auto pair : count) {
		cout << pair.first << " appears " << pair.second << " times\n";
		if (pair.second != 0) {
        		cout << "NOT an anagram!\n";
       			return 0;
		}
	}

	cout << "YES, it's an anagram!\n";
	return 0;
}

#include <iostream>
using namespace std;

class Database {
public:
	Database() {
		cout << "Database connection opened." << endl;
	}
	~Database() {
		cout << "Database connection closed." << endl;
	}
};

int main() {
	Database db;
	return 0;
}

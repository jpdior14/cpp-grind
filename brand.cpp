#include <iostream>
using namespace std;

class Car {
private:
	string brand;
	int year;

public:
	void setBrand(string b) {
		brand = b;
	}

	void setYear(int y) {
		year = y;
	}

	void display() {
		cout << "Brand: " << brand << ", Year: " << year << endl;
	}
};

int main() {
	Car myCar;
	myCar.setBrand("Toyota");
	myCar.setYear(2020);
	myCar.display();
	return 0;
}

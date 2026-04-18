#include <iostream>
using namespace std;

class Rectangle {
private:
	int length, width;

public:
	void setDimensions(int l, int w) {
		length = l;
		width = w;
	}

	int area() {
		return length * width;
	}

	void print(int l, int w) {
		cout << "Hey JP, wassup?\nWelcome to the program for calulating the area of a rectangle!\nEnter the length of your rectangle: ";
        	cin >> l;
        	cout << "And the width? (in cm) ";
        	cin >> w;
	}
};

int main() {
	Rectangle rect;
	rect.setDimensions(int len, int wid);
	cout << "Great! The area of your rectangle is: " << rect.area() << " square cm\n";	
	return 0;
}

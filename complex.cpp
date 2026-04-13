#include <iostream>

class Complex {
private:
	float real, imag;
public:
	Complex(float r = 0, float i = 0) : real(r), imag(i) {}

	Complex operator+(const Complex &obj) {
		return Complex(real + obj.real, imag + obj.imag);
	}

	void display() {
		std::cout << real << " + " << imag << "i" << '\n';
	}
};

int main() {
	Complex c1(3,4), c2(1,2);
	Complex c3 = c1 + c2;
	c3.display();
	return 0;
}

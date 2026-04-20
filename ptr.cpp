#include <iostream>
using namespace std;

int main() {
	int *ptr = new int(5);	// allocate memory for an int
	cout << *ptr << endl;	//print 5
	delete ptr;	//clean the memory
	return 0;
}

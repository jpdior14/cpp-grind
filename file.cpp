#include <iostream>

struct Person {
	char name[50];
	int age;
}

Person p = {"John", 17};
ofstream outFile("person.dat", ios::binary);
outFile.write((char*)&p, sizeof(Person));
outFile.close();

ifstream inFile("person.data", ios::binary);
Person p2;
inFile.read((char*)&p2, sizeof(Person));
std::cout << "Name: " << p2.name << "Age: " << p2.age << '\n';

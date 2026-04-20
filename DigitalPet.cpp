#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

class DigitalPet {
private:
    std::string name;
    int hunger;      // from 0-100, higher = more hungry
    int happiness;   // from 0-100, higher = happier
    int energy;      // from 0-100
    int age;         // days lived
    bool isAlive;

    void checkHealth() {
        if (hunger >= 100 || happiness <= 0 || energy <= 0) {
            isAlive = false;
            std::cout << name << " has died... Game Over.\n";
        }
    }

    void updateState() {
        // This one is lready handled in passTime
    }

public:
    DigitalPet(const std::string& petName)
        : name(petName), hunger(50), happiness(70), energy(80), age(0), isAlive(true) {
        std::cout << "Welcome to the world, " << name << "!\n";
    }

    ~DigitalPet() {
        if (isAlive)
            std::cout << name << " says goodbye!\n";
        else
            std::cout << "R.I.P. " << name << '\n';
    }

    void feed() {
        if (!isAlive) return;
        hunger = std::max(0, hunger - 30);
        happiness += 5;
        energy = std::min(100, energy + 5);
        std::cout << name << " ate happily!\n";
        checkHealth();
    }

    void play() {
        if (!isAlive) return;
        if (energy < 10) {
            std::cout << name << " is too tired to play.\n";
            return;
        }
        hunger = std::min(100, hunger + 10);
        happiness = std::min(100, happiness + 20);
        energy = std::max(0, energy - 15);
        std::cout << name << " played and had fun!\n";
        checkHealth();
    }

    void sleep() {
        if (!isAlive) return;
        energy = std::min(100, energy + 30);
        hunger = std::min(100, hunger + 5);
        std::cout << name << " slept soundly.\n";
        checkHealth();
    }

    void talk() const {
        if (!isAlive) {
            std::cout << name << " is no more...\n";
            return;
        }
        std::cout << name << " says: ";
        if (happiness > 70)
            std::cout << "I'm so happy!\n";
        else if (happiness > 30)
            std::cout << "I'm doing okay.\n";
        else
            std::cout << "I'm sad...\n";
    }

	void bathe() {
		if (!isAlive) return;
		happiness = std::min(100, happiness + 15);
		energy = std::max(0, energy - 5);
		std::cout << name << " is now clean & fresh!\n";
		checkHealth();
	}

    std::string getName() const { return name; }
    int getHappiness() const { return happiness; }
    int getHunger() const { return hunger; }
    int getEnergy() const { return energy; }

    void passTime(int hours) {
        if (!isAlive) return;
        hunger = std::min(100, hunger + hours * 2);
        happiness = std::max(0, happiness - hours);
        energy = std::max(0, energy - hours);
        age += hours / 24;
        checkHealth();
    }

    void displayStatus() const {
        if (!isAlive) {
            std::cout << name << " is dead.\n";
            return;
        }
        std::cout << "\n--- " << name << "'s Status ---\n";
        std::cout << "Hunger: " << hunger << "/100\n";
        std::cout << "Happiness: " << happiness << "/100\n";
        std::cout << "Energy: " << energy << "/100\n";
        std::cout << "Age: " << age << " days\n";
        std::cout << "----------------------\n";
    }

    bool isDead() const { return !isAlive; }
};

int main() {
    std::cout << "Welcome to Digital Pet Simulator!\n";
    std::cout << "Name your pet: ";
    std::string name;
    std::getline(std::cin, name);

    DigitalPet pet(name);
    bool playing = true;
    int choice;

    while (!pet.isDead() && playing) {
        pet.displayStatus();
        std::cout << "\nWhat would you like to do?\n";
        std::cout << "1. Feed\n2. Play\n3. Sleep\n4. Talk\n5. Pass time\n6. Bathe\n7. Quit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: pet.feed(); break;
            case 2: pet.play(); break;
            case 3: pet.sleep(); break;
            case 4: pet.talk(); break;
            case 5:
                std::cout << "How many hours pass? ";
                int hrs;
                std::cin >> hrs;
                pet.passTime(hrs);
                break;
		case 6: pet.bathe(); break;
            case 7:
                playing = false;
                std::cout << "Thanks for playing!\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    }

    if (pet.isDead()) {
        pet.displayStatus();
        std::cout << "Game over.\n";
    }

    return 0;
}

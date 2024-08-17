#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base class representing a Hamburger
class Hamburger {
protected:
    string breadRollType;
    string meat;
    double basePrice;
    vector<pair<string, double>> additions;

public:
    // Constructor to initialize a Hamburger
    Hamburger(string breadRollType, string meat, double basePrice)
        : breadRollType(breadRollType), meat(meat), basePrice(basePrice) {}

    // Function to add an addition to the hamburger
    void addAddition(string name, double price) {
        additions.push_back(make_pair(name, price));
    }

    // Function to display the details of the hamburger
    void display() {
        cout << "Bread roll type: " << breadRollType << endl;
        cout << "Meat: " << meat << endl;
        cout << "Base price: $" << basePrice << endl;
        cout << "Additions:" << endl;
        double total = basePrice;
        for (const auto& addition : additions) {
            cout << "- " << addition.first << ": $" << addition.second << endl;
            total += addition.second;
        }
        cout << "Total price: $" << total << endl;
    }
};

// Derived class representing a HealthyBurger
class HealthyBurger : public Hamburger {
public:
    // Constructor to initialize a HealthyBurger
    HealthyBurger(string breadRollType, string meat, double basePrice)
        : Hamburger(breadRollType, meat, basePrice) {}

    // Override function to limit the number of additions to 6
    void addAddition(string name, double price) override {
        if (additions.size() < 6) {
            Hamburger::addAddition(name, price);
        } else {
            cout << "Cannot add more than 6 additions to a HealthyBurger." << endl;
        }
    }
};

// Derived class representing a DeluxeBurger
class DeluxeBurger : public Hamburger {
public:
    // Constructor to initialize a DeluxeBurger with predefined additions
    DeluxeBurger(string breadRollType, string meat, double basePrice)
        : Hamburger(breadRollType, meat, basePrice) {
        addAddition("Chips", 2.0);
        addAddition("Drink", 1.5);
    }

    // Override function to prevent adding more items to a DeluxeBurger
    void addAddition(string name, double price) override {
        cout << "Cannot add more items to a DeluxeBurger." << endl;
    }
};

int main() {
    // Create and display a regular Hamburger
    Hamburger hamburger("White", "Beef", 3.5);
    hamburger.addAddition("Lettuce", 0.5);
    hamburger.addAddition("Tomato", 0.5);
    hamburger.display();

    // Create and display a HealthyBurger
    HealthyBurger healthyBurger("Brown Rye", "Chicken", 4.0);
    healthyBurger.addAddition("Lettuce", 0.5);
    healthyBurger.addAddition("Tomato", 0.5);
    healthyBurger.addAddition("Carrot", 0.5);
    healthyBurger.addAddition("Cucumber", 0.5);
    healthyBurger.addAddition("Avocado", 1.0);
    healthyBurger.addAddition("Beetroot", 1.0);
    healthyBurger.display();

    // Create and display a DeluxeBurger
    DeluxeBurger deluxeBurger("White", "Beef", 5.0);
    deluxeBurger.addAddition("Cheese", 1.0);  // Attempt to add an extra item
    deluxeBurger.display();

    return 0;
}

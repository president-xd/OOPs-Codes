#include <iostream>
using namespace std;

// Define the Bird class
class Bird {
public:
    // Method to simulate walking
    void walk() {
        cout << "I am walking" << endl;
    }

    // Method to simulate flying
    void fly() {
        cout << "I am flying" << endl;
    }

    // Method to simulate singing
    void sing() {
        cout << "I am singing" << endl;
    }
};

// Main function to demonstrate Bird class functionality
int main() {
    Bird myBird; // Create an instance of Bird

    myBird.walk(); // Call the walk method
    myBird.fly();  // Call the fly method
    myBird.sing(); // Call the sing method

    return 0;
}

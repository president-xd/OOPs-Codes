#include <iostream>
using namespace std;

// Define the Arithmetic class
class Arithmetic {
protected:
    // Method to add two integers
    int add(int a, int b) {
        return a + b;
    }
};

// Define the Adder class that inherits from Arithmetic
class Adder : public Arithmetic {
public:
    // Overriding the add method in Adder class
    int add(int a, int b) {
        return Arithmetic::add(a, b);
    }
};

// Main function to demonstrate the use of the classes
int main() {
    Adder myAdder; // Create an instance of Adder

    // Print superclass information
    cout << "My superclass is: Arithmetic" << endl;

    // Call the add method and print the result
    cout << myAdder.add(42, 13) << " " << myAdder.add(20, 0) << endl;

    return 0;
}

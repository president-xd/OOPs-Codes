#include <iostream>
using namespace std;

class Printer {
private:
    int tonerLevel;
    int pagesPrinted;
    bool isDuplex;

public:
    // Constructor to initialize the printer
    Printer(bool duplex = false) : tonerLevel(100), pagesPrinted(0), isDuplex(duplex) {}

    // Method to refill the toner
    void refillToner() {
        tonerLevel = 100;
        cout << "Toner refilled to 100%." << endl;
    }

    // Method to print a page
    void printPage() {
        if (tonerLevel > 0) {
            pagesPrinted++;
            tonerLevel--;
            cout << "Page printed. Total pages printed: " << pagesPrinted << endl;
        } else {
            cout << "Toner is empty. Cannot print." << endl;
        }
    }

    // Method to check if the printer is duplex
    bool isDuplexPrinter() const {
        return isDuplex;
    }
};

int main() {
    Printer myPrinter(true);  // Create a duplex printer
    myPrinter.refillToner();  // Refill toner
    myPrinter.printPage();    // Print a page
    myPrinter.printPage();    // Print another page

    cout << "Is this printer duplex? " << (myPrinter.isDuplexPrinter() ? "Yes" : "No") << endl;

    return 0;
}

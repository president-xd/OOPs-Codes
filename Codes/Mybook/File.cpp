#include <iostream>
#include <string>
using namespace std;

// Define the abstract Book class
class Book {
protected:
    string title; // Protected member to store the book title

public:
    // Pure virtual function to set the title
    virtual void setTitle(const string &s) = 0;

    // Method to get the title
    string getTitle() const {
        return title;
    }
};

// Define the MyBook class that inherits from Book
class MyBook : public Book {
public:
    // Implement the setTitle method
    void setTitle(const string &s) override {
        title = s;
    }
};

// Main function to demonstrate the use of Book and MyBook classes
int main() {
    MyBook myBook; // Create an instance of MyBook
    string inputTitle;

    // Read the title from standard input
    getline(cin, inputTitle);

    // Set and print the book title
    myBook.setTitle(inputTitle);
    cout << "The title is: " << myBook.getTitle() << endl;

    return 0;
}

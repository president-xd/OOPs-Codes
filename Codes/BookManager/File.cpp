#include <iostream>
#include <string>
using namespace std;

// Abstract base class for a book
class Book {
public:
    string title;

    // Pure virtual function to set the title
    virtual void setTitle(string s) = 0;

    // Function to get the title
    string getTitle() {
        return title;
    }
};

// Derived class implementing the setTitle function
class MyBook : public Book {
public:
    void setTitle(string s) override {
        title = s;
    }
};

int main() {
    MyBook book;
    string input;

    cout << "Enter the title: ";
    getline(cin, input);

    book.setTitle(input);
    cout << "The title is: " << book.getTitle() << endl;

    return 0;
}

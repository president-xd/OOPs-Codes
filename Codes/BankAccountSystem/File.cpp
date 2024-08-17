#include <iostream>
#include <string>
using namespace std;

// Define the Account class
class Account {
protected:
    string accountNumber;
    string customerName;
    double balance;
    double interestRate; // Annual interest rate in percentage

public:
    // Constructor
    Account(const string &accNum, const string &custName, double initialBalance, double rate)
        : accountNumber(accNum), customerName(custName), balance(initialBalance), interestRate(rate) {}

    // Method to deposit funds
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    // Method to withdraw funds
    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: $" << amount << endl;
        } else {
            cout << "Insufficient funds or invalid amount." << endl;
        }
    }

    // Method to calculate interest earned
    double calculateInterest() const {
        return (balance * interestRate / 100);
    }

    // Method to display account information
    void displayAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Balance: $" << balance << endl;
    }
};

// Define the SavingsAccount class that inherits from Account
class SavingsAccount : public Account {
private:
    double minimumBalance;

public:
    // Constructor
    SavingsAccount(const string &accNum, const string &custName, double initialBalance, double rate, double minBalance)
        : Account(accNum, custName, initialBalance, rate), minimumBalance(minBalance) {}

    // Override the withdraw method to ensure minimum balance
    void withdraw(double amount) override {
        if (amount > 0 && (balance - amount) >= minimumBalance) {
            balance -= amount;
            cout << "Withdrew: $" << amount << endl;
        } else {
            cout << "Insufficient funds or minimum balance requirement not met." << endl;
        }
    }

    // Method to display account information
    void displayAccountInfo() const {
        Account::displayAccountInfo();
        cout << "Minimum Balance: $" << minimumBalance << endl;
    }
};

// Main function to demonstrate the use of Account and SavingsAccount classes
int main() {
    // Create an instance of SavingsAccount
    SavingsAccount mySavings("123456789", "John Doe", 1000.00, 3.5, 100.00);

    // Display account information
    mySavings.displayAccountInfo();
    
    // Deposit funds
    mySavings.deposit(500.00);
    
    // Withdraw funds
    mySavings.withdraw(200.00);

    // Calculate and display interest earned
    cout << "Interest Earned: $" << mySavings.calculateInterest() << endl;
    
    // Attempt to withdraw more than the balance allows
    mySavings.withdraw(1500.00);

    // Display account information again
    mySavings.displayAccountInfo();

    return 0;
}

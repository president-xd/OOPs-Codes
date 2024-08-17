#include <iostream>
#include <string>
using namespace std;

// Define the Sports class
class Sports {
public:
    // Method to return the name of the sport
    string getName() {
        return "Generic Sports";
    }

    // Method to print the number of team members
    virtual void getNumberOfTeamMembers() {
        cout << "Each team has n players in " << getName() << endl;
    }
};

// Define the Soccer class that inherits from Sports
class Soccer : public Sports {
public:
    // Override the getName method to return a specific name for Soccer
    string getName() override {
        return "Soccer Class";
    }

    // Override the getNumberOfTeamMembers method to specify the number of players for Soccer
    void getNumberOfTeamMembers() override {
        cout << "Each team has 11 players in " << getName() << endl;
    }
};

// Main function to demonstrate the use of Sports and Soccer classes
int main() {
    Sports sport;
    cout << sport.getName() << endl;
    sport.getNumberOfTeamMembers();
    
    Soccer soccer;
    cout << soccer.getName() << endl;
    soccer.getNumberOfTeamMembers();

    return 0;
}

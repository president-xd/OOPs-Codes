#include <iostream>
using namespace std;

int main() {
    int totalPassengers = 14;
    int totalDrivers = 6;
    int cars = 0;

    // Distribute passengers and drivers into cars
    while (totalPassengers >= 4 && totalDrivers >= 1) {
        cout << "Car " << ++cars << " has 4 passengers and 1 driver." << endl;
        totalPassengers -= 4;
        totalDrivers--;
    }

    // If exactly 4 passengers are left, place them in a car with a driver
    if (totalPassengers == 4) {
        cout << "Car " << ++cars << " has 4 passengers and 1 driver." << endl;
        totalPassengers -= 4;
        totalDrivers--;
    }

    // Handle remaining passengers and drivers
    if (totalPassengers > 0 || totalDrivers > 0) {
        if (totalPassengers <= 2 && totalDrivers == 1) {
            cout << "Car " << ++cars << " has " << totalPassengers << " passengers and 1 driver." << endl;
            totalPassengers = 0;
            totalDrivers--;
        } else if (totalPassengers > 2 || totalDrivers > 1) {
            int passengersPerCar = 2;
            while (totalPassengers > 0 && totalDrivers > 0) {
                if (totalPassengers < passengersPerCar) {
                    passengersPerCar = totalPassengers;
                }
                cout << "Car " << ++cars << " has " << passengersPerCar << " passengers and 1 driver." << endl;
                totalPassengers -= passengersPerCar;
                totalDrivers--;
            }
        } else {
            cout << "Car " << ++cars << " has 1 passenger and 1 driver." << endl;
            totalPassengers -= 1;
            totalDrivers--;
        }
    }

    return 0;
}

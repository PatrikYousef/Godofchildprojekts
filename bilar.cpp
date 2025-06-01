#include <iostream>
#include <vector>
#include <string>
#include <iomanip>  // For setting output format

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void addCar(vector<pair<string, int>>& cars) {
    clearScreen();
    string inputCar;
    cout << "\n--- Add a Car ---\n";
    cout << "Enter the car name: ";
    cin >> inputCar;

    int price;
    cout << "Enter the price of the car: ";
    cin >> price;

    // Add the car and its price as a pair
    cars.push_back(make_pair(inputCar, price));

    cout << "\nCar and price have been added:\n";
    cout << "Car: " << inputCar << ", Price: " << price << " USD\n";
    cout << "--------------------------------------\n";
}

void showCars(const vector<pair<string, int>>& cars) {
    clearScreen();
    
    if (cars.empty()) {
        cout << "\nThe car list is empty.\n";
        return;
    }

    cout << "\n--- All Cars and Their Prices ---\n\n";

    // Table headers
    cout << left << setw(25) << "Car" << setw(15) << "Price (USD)" << endl;
    cout << setfill('-') << setw(40) << "" << setfill(' ') << endl;

    // Data rows
    for (const auto& car : cars) {
        cout << left << setw(25) << car.first 
             << setw(15) << car.second << endl;
    }

    cout << setfill('-') << setw(40) << "" << setfill(' ') << endl;
}

// Function to delete a car and its corresponding price
void deleteCar(vector<pair<string, int>>& cars) {
    clearScreen();
    if (cars.empty()) {
        cout << "\nThere are no cars to delete.\n";
        return;
    }

    showCars(cars);

    cout << "\n--- Delete a Car ---\n";
    cout << "Which car do you want to delete? (Type the name): ";
    string name;
    cin.ignore();  // Ignore leftover newline from previous input
    getline(cin, name);

    for (size_t i = 0; i < cars.size(); ++i) {
        if (cars[i].first == name) {
            cars.erase(cars.begin() + i);
            cout << "Car '" << name << "' has been deleted.\n";
            cout << "--------------------------------------\n";
            return;
        }
    }
    cout << "Car '" << name << "' was not found.\n";
    cout << "-----------------------------------------------";
}

int main() {
    vector<pair<string, int>> cars;
    int choice;

    while (true) {
        cout << "\n--- Choose an option ---\n";
        cout << "1. Show all cars\n";
        cout << "2. Add a car\n";
        cout << "3. Delete a car\n";
        cout << "4. Exit program\n";
        cout << "Your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                showCars(cars);
                break;
            case 2:
                addCar(cars);
                break;
            case 3:
                deleteCar(cars);
                break;
            case 4:
                cout << "\nExiting program...\n";
                return 0;
            default:
                cout << "\nInvalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}

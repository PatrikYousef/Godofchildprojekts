#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <ctime>
#include <iomanip>
#include <algorithm>

using namespace std;

// Struct to store user information and passwords
struct UserPassword {
    string firstName;
    string lastName;
    string username;
    string password;
    float salary;
    float taxRate;
};

// Struct to store items in inventory
struct Item {
    string name;
    int price;
    int quantity;
};

// Function to convert string to lowercase for case-insensitive comparison
string toLower(const string& s) {
    string result = s;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Function to add a new item to inventory
void addItem(vector<Item>& inventory) {
    system("clear"); // Clear the screen (platform-specific)
    Item item;

    cout << "\n========== Add Item ==========\n\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    cout << "Item name: ";
    getline(cin, item.name);

    cout << "Price (in currency): ";
    while (!(cin >> item.price) || item.price < 0) {
        cout << "Invalid price. Please enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Quantity in stock: ";
    while (!(cin >> item.quantity) || item.quantity < 0) {
        cout << "Invalid quantity. Please enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    inventory.push_back(item);

    system("clear");
    cout << "\n========== Item Added ==========\n\n";

    cout << "------------------------------------------------------\n";
    cout << left << setw(25) << "Name" << setw(15) << "Price" << setw(15) << "Quantity" << "\n";
    cout << "------------------------------------------------------\n";
    cout << left << setw(25) << item.name << setw(15) << item.price << setw(15) << item.quantity << "\n";
    cout << "------------------------------------------------------\n";
}

// Function to list all items in inventory
void listItems(const vector<Item>& inventory) {
    system("clear");
    cout << "\n========== All Items ==========\n\n";

    if (inventory.empty()) {
        cout << "No items available.\n";
        return;
    }

    cout << "=====================================================\n";
    cout << left << setw(30) << "Item" << setw(15) << "Price" << setw(15) << "Quantity" << "\n";
    cout << "=====================================================\n";

    for (const auto& item : inventory) {
        cout << left << setw(30) << item.name << setw(15) << item.price << setw(15) << item.quantity << "\n";
    }

    cout << "=====================================================\n";
}

// Function to add a new user with details
void addUser(vector<UserPassword>& users) {
    system("clear");
    UserPassword user;

    cout << "\n========== Add User ==========\n\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    cout << "First name: ";
    getline(cin, user.firstName);

    cout << "Last name: ";
    getline(cin, user.lastName);

    cout << "Username: ";
    getline(cin, user.username);

    cout << "Password: ";
    getline(cin, user.password);

    cout << "Salary (currency): ";
    while (!(cin >> user.salary) || user.salary < 0) {
        cout << "Invalid salary. Please enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Tax rate (0.1 to 1.0): ";
    cin >> user.taxRate;

    users.push_back(user);
    system("clear");
    cout << "\n========== User Saved ==========\n\n";

    cout << "----------------------------------------------------------\n";
    cout << left << setw(15) << "First Name" << setw(15) << "Last Name" << setw(20) << "Username" << "\n";
    cout << "----------------------------------------------------------\n";
    cout << left << setw(15) << user.firstName << setw(15) << user.lastName << setw(20) << user.username << "\n";
    cout << "----------------------------------------------------------\n";
}

// Function to find users by first or last name
void findUser(const vector<UserPassword>& users) {
    system("clear");
    cout << "\n========== Find User ==========\n\n";

    if (users.empty()) {
        cout << "No users to search.\n";
        return;
    }

    cout << "Enter first or last name to search: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string searchName;
    getline(cin, searchName);
    string searchLower = toLower(searchName);

    bool found = false;

    system("clear");
    cout << "==========================================================================\n";
    cout << left << setw(15) << "First Name" << setw(15) << "Last Name" << setw(20) << "Username"
         << setw(15) << "Salary" << setw(15) << "Tax Paid" << setw(15) << "Net Salary" << "\n";
    cout << "==========================================================================\n";

    for (const auto& u : users) {
        if (toLower(u.firstName) == searchLower || toLower(u.lastName) == searchLower) {
            float taxPaid = u.salary * u.taxRate;
            float netSalary = u.salary - taxPaid;
            cout << left << setw(15) << u.firstName << setw(15) << u.lastName << setw(20) << u.username
                 << setw(15) << fixed << setprecision(2) << u.salary
                 << setw(15) << taxPaid << setw(15) << netSalary << "\n";
            found = true;
        }
    }

    if (!found)
        cout << "No user found with that name.\n";

    cout << "==========================================================================\n";
}

// Function for user login by matching username and password
bool login(const vector<UserPassword>& users, string& loggedInUser) {
    system("clear");

    if (users.empty()) {
        cout << "No registered users yet. Please create a user first.\n";
        return false;
    }

    cout << "\n========== Login ==========\n\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string username, password;

    cout << "Username: ";
    getline(cin, username);
    cout << "Password: ";
    getline(cin, password);

    for (const auto& u : users) {
        if (u.username == username && u.password == password) {
            system("clear");
            cout << "Login successful! Welcome, " << u.username << "!\n";
            loggedInUser = u.username;
            return true;
        }
    }

    cout << "Incorrect username or password.\n";
    return false;
}

// Function to buy items: reduces stock if enough quantity is available
void buyItems(vector<Item>& inventory) {
    system("clear");
    if (inventory.empty()) {
        cout << "\nNo items available for purchase.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true) {
        cout << "\nEnter item name to buy (or 'exit' to quit): ";
        string itemName;
        getline(cin, itemName);

        if (toLower(itemName) == "exit") break;

        cout << "How many would you like to buy? ";
        int quantityToBuy;
        if (!(cin >> quantityToBuy) || quantityToBuy <= 0) {
            cout << "Invalid quantity. Please try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        bool found = false;

        for (auto& item : inventory) {
            if (toLower(item.name) == toLower(itemName)) {
                found = true;
                if (item.quantity >= quantityToBuy) {
                    item.quantity -= quantityToBuy;
                    int totalPrice = item.price * quantityToBuy;
                    time_t now = time(0);
                    system("clear");
                    cout << "\n========== Purchase Completed ==========\n\n";
                    cout << "You bought " << quantityToBuy << " x " << item.name << " for " << totalPrice << " currency units.\n";
                    cout << "Purchase time: " << ctime(&now);
                    cout << "Remaining stock: " << item.quantity << "\n";
                    cout << "========================================\n";
                } else {
                    cout << "Only " << item.quantity << " items left in stock.\n";
                }
                break;
            }
        }

        if (!found) {
            cout << "Item not found.\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Function to show all users with salary and tax info
void showAllUsers(const vector<UserPassword>& users) {
    system("clear");
    if (users.empty()) {
        cout << "No users available.\n";
        return;
    }

    cout << "==========================================================================\n";
    cout << left << setw(15) << "First Name" << setw(15) << "Last Name" << setw(20) << "Username"
         << setw(15) << "Salary" << setw(15) << "Tax Paid" << setw(15) << "Net Salary" << "\n";
    cout << "==========================================================================\n";

    for (const auto& u : users) {
        float taxPaid = u.salary * u.taxRate;
        float netSalary = u.salary - taxPaid;
        cout << left << setw(15) << u.firstName << setw(15) << u.lastName << setw(20) << u.username
             << setw(15) << fixed << setprecision(2) << u.salary << setw(15) << taxPaid << setw(15) << netSalary << "\n";
    }

    cout << "==========================================================================\n";
}

int main() {
    vector<UserPassword> users; // List of users
    vector<Item> inventory;     // List of items
    string loggedInUser;

    // Login menu
    while (true) {
        system("clear");
        time_t timestamp = time(nullptr);
        cout << "===============================================\n";
        cout << "             Inventory System - Start\n";
        cout << "Date: " << ctime(&timestamp);
        cout << "===============================================\n\n";

        cout << "1. Login\n";
        cout << "2. Create User\n";
        cout << "3. Exit\n";
        cout << "-----------------------------------------------\n";
        cout << "Choice: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            if (login(users, loggedInUser)) break; // Successful login breaks loop
        }
        else if (choice == 2) {
            addUser(users);
        }
        else if (choice == 3) {
            cout << "\nExiting program.\n";
            return 0;
        }
        else {
            cout << "\nInvalid choice.\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
    }

    // Main menu after login
    while (true) {
        system("clear");
        cout << "===============================================\n";
        cout << "               Inventory System - Main Menu    \n";
        cout << "===============================================\n";
        cout << "Logged in as: " << loggedInUser << "\n\n";
        cout << "1. Add Item\n";
        cout << "2. List All Items\n";
        cout << "3. Buy Items\n";
        cout << "4. Find User\n";
        cout << "5. Show All Users\n";
        cout << "6. Logout\n";
        cout << "-----------------------------------------------\n";
        cout << "Choice: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addItem(inventory);
                break;
            case 2:
                listItems(inventory);
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.get();
                break;
            case 3:
                buyItems(inventory);
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.get();
                break;
            case 4:
                findUser(users);
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.get();
                break;
            case 5:
                showAllUsers(users);
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.get();
                break;
            case 6:
                cout << "Logging out...\n";
                loggedInUser.clear();
                return 0;
            default:
                cout << "Invalid choice.\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;
        }
    }
    return 0;
}

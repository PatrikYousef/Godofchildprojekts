#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Define the clear screen command depending on the operating system
#ifdef _WIN32
    #define CLEAR_COMMAND "cls"
#else
    #define CLEAR_COMMAND "clear"
#endif

// Class representing a user's financial data
class Payment {
public:
    string firstName;         // First name
    string lastName;          // Last name
    long long int income;     // Income
    long long int bills;      // Bills
    long long int food;       // Food expenses
    long long int clothes;    // Clothing expenses
};

// Function to clear the console screen
void clearScreen() {
    system(CLEAR_COMMAND);
}

// Function to add a new user
void addUser(vector<Payment>& users) {
    Payment user;
    string input;

    cout << "\n--- Add a New User ---\n";

    // Get first name
    cout << "First name: ";
    getline(cin, user.firstName);

    // Get last name
    cout << "Last name: ";
    getline(cin, user.lastName);

    // Get income and convert to number
    cout << "Income (numbers only): ";
    getline(cin, input);
    user.income = stoll(input);

    // Get monthly bills
    cout << "Monthly bills: ";
    getline(cin, input);
    user.bills = stoll(input);

    // Get monthly food expenses
    cout << "Monthly food expenses: ";
    getline(cin, input);
    user.food = stoll(input);

    // Get monthly clothing expenses
    cout << "Monthly clothing expenses: ";
    getline(cin, input);
    user.clothes = stoll(input);

    // Add user to the vector
    users.push_back(user);
    cout << "✅ User has been added successfully!\n";
}

// Function to display all users
void showUsers(const vector<Payment>& users) {
    if (users.empty()) {
        cout << "\n📭 No users to display.\n";
        return;
    }

    cout << "\n📋 --- User List --- 📋\n\n";

    // Print table headers with formatting
    cout << left << setw(3) << "#"
         << setw(15) << "First Name"
         << setw(15) << "Last Name"
         << setw(12) << "Income"
         << setw(12) << "Bills"
         << setw(12) << "Food"
         << setw(12) << "Clothes" << "\n";

    cout << string(81, '-') << "\n";

    int index = 1;
    // Loop through users and print their info
    for (const auto& user : users) {
        cout << left << setw(3) << index++
             << setw(15) << user.firstName
             << setw(15) << user.lastName
             << setw(12) << user.income
             << setw(12) << user.bills
             << setw(12) << user.food
             << setw(12) << user.clothes << "\n";
    }

    cout << string(81, '=') << "\n";
    cout << "📦 Total users: " << users.size() << "\n";
}

// Function to calculate savings for a user by first name
void calculateSavings(const vector<Payment>& users) {
    string nameToFind;
    cout << "\n--- Calculate Savings ---\n";
    cout << "Enter the first name of the user: ";
    getline(cin, nameToFind);

    bool found = false;

    // Search for user
    for (const auto& user : users) {
        if (user.firstName == nameToFind) {
            // Calculate savings: income minus all expenses
            long long int savings = user.income - user.bills - user.food - user.clothes;
            cout << "💰 Estimated savings for " << user.firstName << " " << user.lastName << ": " << savings << " money units\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "❌ User not found. Please check the name.\n";
    }
}

// Function to remove a user by first name
void removeUser(vector<Payment>& users) {
    string nameToRemove;
    cout << "\n--- Remove a User ---\n";
    cout << "Enter the first name of the user you want to remove: ";
    getline(cin, nameToRemove);

    // Use remove_if to "remove" user(s) with matching first name
    auto it = remove_if(users.begin(), users.end(), [&](const Payment& user) {
        return user.firstName == nameToRemove;
    });

    // If any user was found, erase from the vector
    if (it != users.end()) {
        users.erase(it, users.end());
        cout << "🗑️ User \"" << nameToRemove << "\" has been removed.\n";
    } else {
        cout << "❌ No user found with that name.\n";
    }
}

// Function to display the main menu
void showMenu() {
    cout << "\n============================\n";
    cout << "     💸 Personal Finance\n";
    cout << "============================\n";
    cout << "1. Add a new user\n";
    cout << "2. Show all users\n";
    cout << "3. Calculate savings\n";
    cout << "4. Remove a user\n";
    cout << "5. Exit\n";
    cout << "Enter your choice (1-5): ";
}

int main() {
    vector<Payment> users;   // Vector to store users
    string input;
    int choice;

    do {
        clearScreen();  // Clear screen before showing menu
        showMenu();     // Show menu
        getline(cin, input);

        try {
            choice = stoi(input);  // Convert input to integer
        } catch (...) {
            choice = -1;           // Handle invalid input
        }

        clearScreen();  // Clear screen after input

        switch (choice) {
            case 1:
                addUser(users);       // Add user
                break;
            case 2:
                showUsers(users);     // Show all users
                break;
            case 3:
                calculateSavings(users);  // Calculate savings
                break;
            case 4:
                removeUser(users);    // Remove user
                break;
            case 5:
                cout << "👋 Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "❗ Invalid input. Please enter a number between 1 and 5.\n";
                break;
        }

        // Wait for Enter key press to continue if not exiting
        if (choice != 5) {
            cout << "\nPress Enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (choice != 5);  // Loop until exit option selected

    return 0;
}

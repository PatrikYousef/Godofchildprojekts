#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <exception>
#include <cstdlib>
#include <limits>
#include <iostream>
#include <fstream>

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

struct BankAccount {
    string bankName;
    string firstName;
    string lastName;
    string accountNumber;
    string CVV;
    string expiryDate;
    int balance = 0;
};

struct User {
    string firstName;
    string lastName;
    string username;
    string password;
};

void safeInputInt(int& value, const string& prompt, int min = numeric_limits<int>::min(), int max = numeric_limits<int>::max()) {
    while (true) {
        cout << prompt;
        if (cin >> value) {
            if (value >= min && value <= max) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            } else {
                cout << "Value must be between " << min << " and " << max << ". Please try again.\n";
            }
        } else {
            cout << "Invalid input. Please enter an integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void saveUsersToFile(const vector<User>& users, const string& filename = "sparaddata") {
    ofstream MyFile(filename, ios::trunc); // overwrite entire file
    if (!MyFile) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    for (const auto& user : users) {
        MyFile << "First Name: " << user.firstName << endl;
        MyFile << "Last Name: " << user.lastName << endl; 
        MyFile << "Username: " << user.username << endl;
        MyFile << "Password: " << user.password << endl;
        MyFile << "------------------------" << endl;
    }
    MyFile.close();
}

void manageUsers(vector<User>& users) {
    User u;
    while (true) {
        clearScreen();
        int choice;
        safeInputInt(choice, "\n1. Create Account\n2. Login\n3. Delete Account\n4. Back\nWhat would you like to do? (1-4): ", 1, 4);

        

        try {
            switch (choice) {
                case 1: {
                    clearScreen();
                    cout << "Enter first name: ";
                    getline(cin, u.firstName);
                    cout << "Enter last name: ";
                    getline(cin, u.lastName);
                    cout << "Enter username: ";
                    getline(cin, u.username);
                    cout << "Enter password: ";
                    getline(cin, u.password);

                    bool alreadyTaken = false;
                    for (const auto& user : users) {
                        if (user.username == u.username) {
                            cout << "Username is already taken!" << endl;
                            alreadyTaken = true;
                            break;
                        }
                    }
                    if (!alreadyTaken) {
                        users.push_back(u);
                        saveUsersToFile(users);
                        cout << "Account created successfully!" << endl;
                    }
                    break;
                }
                case 2:
                    return; // Login - return to main program
                case 3: {
                    clearScreen();
                    string usernameInput;
                    cout << "Enter username to delete: ";
                    getline(cin, usernameInput);

                    auto it = remove_if(users.begin(), users.end(),
                                        [&usernameInput](const User& user) { return user.username == usernameInput; });

                    if (it != users.end()) {
                        users.erase(it, users.end());
                        saveUsersToFile(users);
                        cout << "Account deleted." << endl;
                    } else {
                        cout << "Account not found." << endl;
                    }
                    break;
                }
                case 4:
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }
        } catch (const exception& e) {
            clearScreen();
            cout << "An error occurred: " << e.what() << endl;
        }

        cout << "\nPress Enter to continue...";
        cin.get();
    }
}

bool login(const vector<User>& users, string& loggedInUser) {
    clearScreen();
    string usernameInput, passwordInput;
    cout << "Enter username: ";
    getline(cin, usernameInput);
    cout << "Enter password: ";
    getline(cin, passwordInput);

    for (const auto& user : users) {
        if (user.username == usernameInput && user.password == passwordInput) {
            loggedInUser = user.username;
            clearScreen();
            cout << "Welcome, " << user.firstName << "!" << endl;
            return true;
        }
    }

    clearScreen();
    cout << "Incorrect username or password. Please try again." << endl;
    return false;
}

void ageCheck() {
    while (true) {
        int age;
        safeInputInt(age, "How old are you? ");

        try {
            if (age < 18) {
                clearScreen();
                cout << "You must be 18 years or older to create an account." << endl;
            } else {
                clearScreen();
                cout << "You are eligible to create a bank account." << endl;
                break;
            }
        } catch (const exception& e) {
            clearScreen();
            cout << "An error occurred: " << e.what() << endl;
        }
    }
}

void addAccount(vector<BankAccount>& accounts) {
    try {
        ageCheck();

        BankAccount account;
        cout << "Bank name: ";
        getline(cin, account.bankName);

        cout << "First name: ";
        getline(cin, account.firstName);

        cout << "Last name: ";
        getline(cin, account.lastName);

        cout << "Account number: ";
        getline(cin, account.accountNumber);

        cout << "CVV: ";
        getline(cin, account.CVV);

        cout << "Expiry date (MMYY): ";
        getline(cin, account.expiryDate);

        accounts.push_back(account);

    } catch (const exception& e) {
        clearScreen();
        cout << "An error occurred: " << e.what() << endl;
    }
}

void showAccounts(const vector<BankAccount>& accounts) {
    if (accounts.empty()) {
        cout << "No accounts to display." << endl;
        return;
    }

    cout << "\n==========================================================================================" << endl;
    cout << "| No | Bank Name          | Full Name                | Account Number   | Balance  | CVV  | Expiry |" << endl;
    cout << "==========================================================================================" << endl;
    for (size_t i = 0; i < accounts.size(); ++i) {
        cout << "| " << setw(2) << right << i + 1 << " "
             << "| " << setw(18) << left << accounts[i].bankName
             << "| " << setw(24) << left << (accounts[i].firstName + " " + accounts[i].lastName)
             << "| " << setw(17) << left << accounts[i].accountNumber
             << "| $" << setw(8) << right << accounts[i].balance
             << " | " << setw(4) << left << accounts[i].CVV
             << "| " << setw(6) << left << accounts[i].expiryDate
             << "|" << endl;
    }
    cout << "==========================================================================================" << endl;
}

void deleteAccount(vector<BankAccount>& accounts) {
    clearScreen();
    string toDelete;
    cout << "Enter the first name of the account to delete: ";
    getline(cin, toDelete);

    auto it = remove_if(accounts.begin(), accounts.end(),
                        [&toDelete](const BankAccount& account) { return account.firstName == toDelete; });
    if (it != accounts.end()) {
        accounts.erase(it, accounts.end());
        clearScreen();
        cout << "Account for '" << toDelete << "' deleted.\n";
    } else {
        clearScreen();
        cout << "No account found with the first name '" << toDelete << "'.\n";
    }
}

void manageFunds(vector<BankAccount>& accounts) {
    clearScreen();
    cout << "===============================" << endl;
    cout << "       Welcome to the Bank     " << endl;
    cout << "===============================" << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Deposit money" << endl;
    cout << "2. Withdraw money" << endl;

    int choice;
    safeInputInt(choice, "Enter your choice (1 or 2): ", 1, 2);

    switch (choice) {
        case 1: {
            string name;
            cout << "Which person do you want to deposit money for? ";
            getline(cin, name);

            for (auto& account : accounts) {
                if (account.firstName == name) {
                    int amount;
                    safeInputInt(amount, "How much money would you like to deposit? ");
                    if (amount > 0) {
                        account.balance += amount;
                        cout << account.firstName << "'s balance: $" << account.balance << " | Deposited: $" << amount << endl;
                    } else {
                        cout << "Error: Amount must be positive." << endl;
                    }
                    return;
                }
            }
            cout << "No account found with that name." << endl;
            break;
        }
        case 2: {
            string name;
            cout << "Which person do you want to withdraw money from? ";
            getline(cin, name);

            for (auto& account : accounts) {
                if (account.firstName == name) {
                    int amount;
                    safeInputInt(amount, "How much money would you like to withdraw? ");
                    if (amount <= account.balance && amount > 0) {
                        account.balance -= amount;
                        cout << account.firstName << "'s balance: $" << account.balance << " | Withdrawn: $" << amount << endl;
                    } else {
                        cout << "Error: Insufficient funds or invalid amount." << endl;
                    }
                    return;
                }
            }
            cout << "No account found with that name." << endl;
            break;
        }
        default:
            cout << "Invalid choice." << endl;
            break;
    }
}

int main() {
    vector<BankAccount> accounts;
    vector<User> users;
    string loggedInUser;

    while (true) {
        clearScreen();
        int choice;
        safeInputInt(choice, "=== User Menu ===\n1. Manage accounts (Create/Delete User)\n2. Login\n3. Exit\nYour choice: ", 1, 3);

        if (choice == 1) {
            manageUsers(users);
        } else if (choice == 2) {
            if (login(users, loggedInUser))
                break;
            else {
                cout << "\nPress Enter to continue...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
            }
        } else if (choice == 3) {
            cout << "Exiting program..." << endl;
            return 0;
        } else {
            cout << "Invalid choice." << endl;
        }

        cout << "\nPress Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    // Main menu after login
    while (true) {
        clearScreen();
        cout << "\nSelect an option:" << endl;
        cout << "1. Add bank account" << endl;
        cout << "2. Show all accounts" << endl;
        cout << "3. Delete a bank account" << endl;
        cout << "4. Manage funds" << endl;
        cout << "5. Exit" << endl;
        cout << "6. Logout" << endl;

        int choice;
        safeInputInt(choice, "Your choice: ", 1, 6);

        switch (choice) {
            case 1:
                addAccount(accounts);
                break;
            case 2:
                showAccounts(accounts);
                break;
            case 3:
                deleteAccount(accounts);
                break;
            case 4:
                manageFunds(accounts);
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            case 6:
                main();  // Recursive call to restart login flow; not ideal for bigger projects but okay here
                return 0;
            default:
                cout << "Invalid choice." << endl;
                break;
        }

        cout << "\nPress Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }
}

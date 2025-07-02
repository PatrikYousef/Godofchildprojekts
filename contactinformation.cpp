#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

struct Contact {
    string firstName;
    string lastName;
    string email;
    long long phoneNumber;
};

struct Login {
    string username;
    string password;
};


void printLine(int length = 60, char ch = '=') {
    cout << string(length, ch) << endl;
}

void contactMenu(vector<Contact>& contacts) {
    int choice;
    printLine();
    cout << setw(25) << "--- Contact Menu ---" << endl;
    printLine();

    cout << "1. Add a New Contact\n";
    cout << "2. Show All Contacts\n";
    cout << "Choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        Contact c;
        cout << "\n";
        printLine(30, '-');
        cout << "Enter Contact Details\n";
        printLine(30, '-');

        cout << "First Name    : ";
        getline(cin, c.firstName);
        cout << "Last Name     : ";
        getline(cin, c.lastName);
        cout << "Email         : ";
        getline(cin, c.email);
        cout << "Phone Number  : ";
        while (!(cin >> c.phoneNumber)) {
            cout << "Invalid input. Enter digits only: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore();

        contacts.push_back(c);
        cout << "\n✔ Contact added successfully!\n";

    } else if (choice == 2) {
        if (contacts.empty()) {
            cout << "\n⚠ No contacts found.\n";
        } else {
            cout << "\n📇 Contact List:\n";
            printLine();
            cout << left
                 << setw(15) << "First Name"
                 << setw(15) << "Last Name"
                 << setw(30) << "Email"
                 << setw(15) << "Phone Number" << "\n";
            printLine();

            for (const auto& c : contacts) {
                cout << left
                     << setw(15) << c.firstName
                     << setw(15) << c.lastName
                     << setw(30) << c.email
                     << setw(15) << c.phoneNumber << "\n";
            }

            printLine();
        }
    } else {
        cout << "❌ Invalid choice.\n";
    }
}


void createLogin(vector<Login>& logins) {
    Login l;
    printLine();
    cout << setw(26) << "🔐 Create Login" << endl;
    printLine();

    cout << "Enter Username: ";
    cin >> l.username;
    cout << "Enter Password: ";
    cin >> l.password;

    logins.push_back(l);
    cout << "\n✔ User registered successfully!\n";
}

bool loginUser(const vector<Login>& logins) {
    string username, password;
    printLine();
    cout << setw(24) << "🔑 Login Portal" << endl;
    printLine();

    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    for (const auto& l : logins) {
        if (l.username == username && l.password == password) {
            cout << "\n✅ Login successful! Welcome, " << username << "!\n";
            return true;
        }
    }

    cout << "\n❌ Incorrect username or password.\n";
    return false;
}

int main() {
    vector<Login> logins;
    vector<Contact> contacts;
    int choice;

    while (true) {
        printLine();
        cout << setw(28) << "📱 Contact Manager Menu" << endl;
        printLine();

        cout << "1. 📇 Access Contacts\n";
        cout << "2. 🆕 Create Login\n";
        cout << "3. ❎ Exit\n";
        cout << "Choice: ";

        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        try {
            switch (choice) {
                case 1:
                    if (loginUser(logins)) {
                        contactMenu(contacts);
                    } else {
                        cout << "Access denied. Please try again.\n";
                    }
                    break;

                case 2:
                    createLogin(logins);
                    break;

                case 3:
                    cout << "\n👋 Exiting the program. Have a great day!\n";
                    return 0;

                default:
                    cout << "❌ Invalid choice. Please try again.\n";
            }
        } catch (const exception& e) {
            cerr << "⚠ Error: " << e.what() << '\n';
        }
    }
}
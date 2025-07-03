#include <iostream>
#include <vector>
#include <cctype>   // For isalpha() and tolower()
#include <limits>   // For clearing invalid input

using namespace std;

// 🌐 Global constants
const vector<char> encryptionMap = {
    '9', ':', ';', '<', '=', '>', '?', '0', '1', '2', '3', '4', '5',
    '6', '7', '(', ')', '*', '+', ',', '-', '.', '/', ' ', '!', '"'
};

const vector<char> alphabet = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g',
    'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u',
    'v', 'w', 'x', 'y', 'z'
};

void waitForEnter() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear leftover newline
    cout << "Press Enter to continue...\n";
    cin.get(); 
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


// 🔠 Converts plain name to encrypted symbols
void encryptName() {
    string input;
    cout << "\n✍️  Enter the name to encrypt (letters only): ";
    cin >> input;

    cout << "\n🔐 Encrypted Output: ";
    for (char character : input) {
        if (isalpha(character)) {
            character = tolower(character);
            int index = character - 'a';
            cout << encryptionMap[index];
        } else {
            cout << character;
        }
    }
    cout << "\n✅ Your name has been encrypted!\n";
}

// 🔓 Converts symbols back to plain letters
void decryptSymbols() {
    string input;
    cout << "\n🗝️  Enter the encrypted symbols (no spaces): ";
    cin >> input;

    cout << "\n🔍 Decrypted Output: ";
    for (char symbol : input) {
        bool found = false;
        for (int i = 0; i < encryptionMap.size(); ++i) {
            if (symbol == encryptionMap[i]) {
                cout << alphabet[i];
                found = true;
                break;
            }
        }
        if (!found) {
            cout << symbol;
        }
    }
    cout << "\n✅ Decryption complete!\n";
}

// 📋 Displays the menu and returns the user's choice
int displayMenu() {
    int choice;
    cout << "\n📋 MAIN MENU:\n";
    cout << "  [1] 🔏 Encrypt a name\n";
    cout << "  [2] 🔓 Decrypt symbols\n";
    cout << "  [3] ❌ Exit\n";
    cout << "👉 Enter your choice (1–3):";
    cin >> choice;

    // Handle invalid input (non-numeric)
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;  // Invalid
    }

    return choice;
}

// 🎀 Displays a fancy program header
void displayHeader() {
    cout << "\n";
    cout << "╔════════════════════════════════════════════════╗\n";
    cout << "║     🔐 WELCOME TO THE NAME ENCRYPTION TOOL.    ║\n";
    cout << "╚════════════════════════════════════════════════╝\n";
}

// 🚪 Handles exit
void exitProgram() {
    cout << "\n👋 Thank you for using the Name Encryption Tool!\n";
    cout << "🔒 Stay safe, and keep your names secret! 🕵️‍♂️\n";
    cout << "════════════════════════════════════════════════\n";
}

int main() {
    displayHeader();

    while (true) {
        int choice = displayMenu();

        switch (choice) {
            case 1:
            clearScreen();
                encryptName();
                waitForEnter();
                break;

            case 2:
                clearScreen();
                decryptSymbols();
                waitForEnter();
                break;
            case 3:
                exitProgram();
                return 0;
            default:
                cout << "\n⚠️  Invalid choice. Please enter 1, 2, or 3.\n";
                break;
        }
    }
}
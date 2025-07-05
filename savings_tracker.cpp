#include <iostream>
#include <vector>
#include <cctype>
#include <limits>
#include <iomanip>

using namespace std;

#ifdef _WIN32
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#else
#include <unistd.h>
#endif
// Class representing a single savings goal
class SavingGoal {
public:
    float totalAmount = 0;
    int months = 0;
    string goalName;
};

// Clear screen based on OS
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Clears input buffer on invalid input
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Display a list of example savings goals
void showGoalIdeas() {
    vector<string> ideas = {
        "Emergency Fund", "New Laptop or PC",
        "Vacation to Italy", "Birthday Gift for Parents",
        "Car Down Payment", "Wedding Fund",
        "Gaming Console", "University Tuition",
        "Gym Membership", "Start a Small Business",
        "Trip to Japan or Korea", "Home Renovation",
        "New Smartphone", "Streaming Subscriptions",
        "Concert Tickets", "Build a Gaming Setup",
        "Retirement Fund", "Pay Off Debt",
        "Holiday Shopping", "Apartment Deposit",
        "Pet Care Budget", "Hobby Equipment",
        "Baby Fund", "Language Course"
    };

    cout << "\n💡 Sample Savings Goals:\n";
    cout << string(55, '-') << '\n';
    cout << left << setw(30) << "📌 Goal Idea 1" << "📌 Goal Idea 2\n";
    cout << string(55, '-') << '\n';

    for (size_t i = 0; i < ideas.size(); i += 2) {
        cout << left << setw(30) << ideas[i];
        if (i + 1 < ideas.size())
            cout << ideas[i + 1];
        cout << '\n';
    }

    cout << string(55, '-') << "\n\n";
}

// Prints program title
void printHeader() {
    cout << "\n=========================================\n";
    cout << "         💰 Personal Savings Tracker      \n";
    cout << "=========================================\n";
}

// Add a new savings goal
void addSavingGoal(vector<SavingGoal>& goalsList) {
    SavingGoal goal;
    showGoalIdeas();
    cin.ignore();

    cout << "\n[+] Let's create a new savings goal!\n";
    cout << "🔹 What are you saving for? ";
    getline(cin, goal.goalName);

    cout << "🔹 Total amount to save for \"" << goal.goalName << "\": ";
    while (!(cin >> goal.totalAmount) || goal.totalAmount <= 0) {
        cout << "❌ Enter a positive amount: ";
        clearInput();
    }

    cout << "🔹 Over how many months do you want to save? ";
    while (!(cin >> goal.months) || goal.months <= 0) {
        cout << "❌ Enter a valid number of months: ";
        clearInput();
    }

    float monthlySaving = goal.totalAmount / goal.months;
    goalsList.push_back(goal);

    cout << "\n✅ Savings goal \"" << goal.goalName << "\" added successfully!\n";
    cout << "   ➤ Total: $" << fixed << setprecision(2) << goal.totalAmount;
    cout << " | Duration: " << goal.months << " months";
    cout << " | Monthly Target: $" << monthlySaving << "\n";
}

// View all added goals
void displayAllGoals(const vector<SavingGoal>& goalsList) {
    if (goalsList.empty()) {
        cout << "\n⚠️  You haven't added any savings goals yet.\n";
        return;
    }

    cout << "\n📋 Current Savings Goals:\n";
    cout << left << setw(22) << "📝 Goal Name"
         << setw(18) << "💵 Target Amount"
         << setw(10) << "📆 Months"
         << setw(18) << "📊 Monthly Needed\n";
    cout << string(70, '-') << '\n';

    for (const auto& goal : goalsList) {
        float monthly = goal.totalAmount / goal.months;
        cout << left << setw(22) << goal.goalName
             << setw(18) << fixed << setprecision(2) << goal.totalAmount
             << setw(10) << goal.months
             << setw(18) << monthly << '\n';
    }

    cout << string(70, '-') << "\n";
}

// Check savings progress for a specific goal
void checkRemainingBalance(const vector<SavingGoal>& goalsList) {
    if (goalsList.empty()) {
        cout << "\n⚠️ No goals available. Add one first.\n";
        return;
    }

    string searchGoal;
    float savedSoFar;

    cout << "\n💬 Enter the exact name of the goal to check: ";
    cin.ignore();
    getline(cin, searchGoal);

    bool found = false;

    for (const auto& goal : goalsList) {
        if (goal.goalName == searchGoal) {
            found = true;
            cout << "\n💰 How much have you saved for \"" << goal.goalName << "\"? ";
            while (!(cin >> savedSoFar) || savedSoFar < 0) {
                cout << "❌ Enter a valid number: ";
                clearInput();
            }

            float difference = goal.totalAmount - savedSoFar;
            cout << "\n------------------------------\n";
            if (difference > 0) {
                cout << "⏳ You still need to save: " << fixed << setprecision(2) << difference << "\n";
            } else if (difference < 0) {
                cout << "🎉 You’ve saved $" << -difference << " extra!\n";
            } else {
                cout << "✅ Perfect! You’ve saved the full amount!\n";
            }
            cout << "------------------------------\n";
            break;
        }
    }

    if (!found) {
        cout << "\n❗ Goal \"" << searchGoal << "\" not found.\n";
    }
}

// Check savings for all goals and show summary
void enterMoneyToCheckBalance(const vector<SavingGoal>& goalsList) {
    if (goalsList.empty()) {
        cout << "\n⚠️ You haven’t added any goals yet.\n";
        return;
    }

    float totalRemaining = 0;
    float totalSaved = 0;
    float totalTarget = 0;

    cin.ignore();

    cout << "\n💰 Enter your saved amount for each goal:\n";

    for (const auto& goal : goalsList) {
        float saved;
        cout << "🔸 \"" << goal.goalName << "\" (Target: " << fixed << setprecision(2) << goal.totalAmount << ") - Saved: ";
        while (!(cin >> saved) || saved < 0) {
            cout << "❌ Please enter a valid amount: ";
            clearInput();
        }

        float remaining = goal.totalAmount - saved;
        totalSaved += saved;
        totalTarget += goal.totalAmount;
        totalRemaining += (remaining > 0) ? remaining : 0;

        if (remaining > 0) {
            cout << "⏳ Still need to save: $" << remaining << "\n\n";
        } else if (remaining < 0) {
            cout << "🎉 You've saved $" << -remaining << " extra!\n\n";
        } else {
            cout << "✅ Goal fully saved!\n\n";
        }
    }

    cout << "\n📊 Summary:\n";
    cout << "-----------------------------\n";
    cout << "🎯 Total Goal: $" << totalTarget << "\n";
    cout << "💰 Saved So Far: $" << totalSaved << "\n";
    cout << "⏳ Remaining: $" << totalRemaining << "\n";
    cout << "-----------------------------\n";
}

// Optional: Play a sound (macOS only by default)
void playSound() {
#ifdef _WIN32
    PlaySound(TEXT("sound.wav"), NULL, SND_FILENAME | SND_ASYNC);
#else
    system("afplay avicii.MP4 &");
#endif
}

int main() {
    vector<SavingGoal> goals;
    int choice;

    playSound();

    while (true) {
        clearScreen();
        printHeader();

        cout << "\n📋 MAIN MENU\n";
        cout << "===========================================\n";
        cout << "\n[1] ➕  Add a New Savings Goal\n";
        cout << "\n[2] 📊  View All Savings Goals\n";
        cout << "\n[3] 🔍  Check Progress on a Goal\n";
        cout << "\n[4] 🧾  Enter Savings and View Summary\n";
        cout << "\n[5] ❌  Exit\n";
        cout << "\n===========================================\n";
        cout << "\n👉 Choose an option (1 - 5):";

        if (!(cin >> choice)) {
            cout << "\n❌ Invalid input. Please enter a number between 1 and 5.\n";
            clearInput();
            cout << "🔁 Press Enter to continue...";
            cin.ignore();
            cin.get();
            continue;
        }

        clearScreen();
        printHeader();

        switch (choice) {
            case 1:
                cout << "\n🟢 Option: Add New Savings Goal\n";
                addSavingGoal(goals);
                break;
            case 2:
                cout << "\n📂 Option: View All Goals\n";
                displayAllGoals(goals);
                break;
            case 3:
                cout << "\n🔎 Option: Check Progress\n";
                checkRemainingBalance(goals);
                break;
            case 4:
                cout << "\n🧾 Option: Enter Savings & Summary\n";
                enterMoneyToCheckBalance(goals);
                break;
            case 5:
                cout << "\n👋 Thanks for using the Personal Savings Tracker!\n";
                cout << "💪 Keep saving and make your dreams happen!\n\n";
                return 0;
            default:
                cout << "\n❗ Invalid choice. Please enter a number between 1 and 5.\n";
        }

        cout << "\n🔁 Press Enter to return to the main menu...";
        cin.ignore();
        cin.get();
    }

    return 0;
}

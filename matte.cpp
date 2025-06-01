#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <limits>  // för numeric_limits

// OS-anpassad rensning av skärm
#ifdef _WIN32
    #define CLEAR_COMMAND "cls"
#else
    #define CLEAR_COMMAND "clear"
#endif

void rensaSkärm() {
    system(CLEAR_COMMAND);
}


using namespace std;

// Funktion för att säkert läsa in ett heltal med felhantering
bool safeReadInt(int& num) {
    cin >> num;
    if (cin.fail()) {
        cin.clear(); // Rensa felflaggan
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Rensa inputbufferten
        return false;
    }
    return true;
}

void addNumber(vector<int>& numbers) {
    rensaSkärm();
    int num;
    cout << "Enter a number to add: ";
    if (!safeReadInt(num)) {
        cout << "Invalid input, please enter a valid integer.\n";
        return;
    }
    numbers.push_back(num);
    cout << num << " has been added.\n";
}

void removeNumber(vector<int>& numbers) {
    rensaSkärm();
    int num;
    cout << "Enter a number to remove: ";
    if (!safeReadInt(num)) {
        cout << "Invalid input, please enter a valid integer.\n";
        return;
    }
    auto it = find(numbers.begin(), numbers.end(), num);
    if (it != numbers.end()) {
        numbers.erase(it);
        cout << num << " has been removed.\n";
    } else {
        cout << num << " is not in the list.\n";
    }
}

void showNumbers(const vector<int>& numbers) {
    rensaSkärm();
    if (numbers.empty()) {
        cout << "The list is empty.\n";
        return;
    }
    vector<int> sorted_numbers = numbers;
    sort(sorted_numbers.begin(), sorted_numbers.end());
    cout << "List: ";
    for (int n : sorted_numbers) {
        cout << n << " ";
    }
    cout << "\n";
}

void showAverage(const vector<int>& numbers) {
    rensaSkärm();
    if (numbers.empty()) {
        cout << "The list is empty, no average to calculate.\n";
        return;
    }
    double average = accumulate(numbers.begin(), numbers.end(), 0.0) / numbers.size();
    cout << "Average value: " << average << "\n";
}

void showCount(const vector<int>& numbers) {
    rensaSkärm();
    cout << "Number of elements in the list: " << numbers.size() << "\n";
}

void showRandomNumber(const vector<int>& numbers) {
    rensaSkärm();
    if (numbers.empty()) {
        cout << "The list is empty, no random number can be chosen.\n";
        return;
    }
    int index = rand() % numbers.size();
    cout << "Random number: " << numbers[index] << "\n";
}

void showSum(const vector<int>& numbers) {
    rensaSkärm();
    int total = accumulate(numbers.begin(), numbers.end(), 0);
    cout << "Sum of all elements: " << total << "\n";
}

void showNegativeCount(const vector<int>& numbers) {
    rensaSkärm();
    int count = count_if(numbers.begin(), numbers.end(), [](int n){ return n < 0; });
    cout << "Number of negative elements: " << count << "\n";
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    vector<int> numbers;

    while (true) {
        cout << "\nChoose an option:\n"
             << "1. Add number\n"
             << "2. Remove number\n"
             << "3. Show numbers\n"
             << "4. Show average\n"
             << "5. Show count\n"
             << "6. Show random number\n"
             << "7. Show sum\n"
             << "8. Show count of negative numbers\n"
             << "9. Exit\n"
             << "Your choice: ";

        int choice;
        if (!safeReadInt(choice)) {
            cout << "Invalid choice, please enter a valid integer.\n";
            continue; // fråga igen
        }

        switch (choice) {
            case 1:
                addNumber(numbers);
                break;
            case 2:
                removeNumber(numbers);
                break;
            case 3:
                showNumbers(numbers);
                break;
            case 4:
                showAverage(numbers);
                break;
            case 5:
                showCount(numbers);
                break;
            case 6:
                showRandomNumber(numbers);
                break;
            case 7:
                showSum(numbers);
                break;
            case 8:
                showNegativeCount(numbers);
                break;
            case 9:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    }
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdlib> // För system()

using namespace std;

// Anpassa kommandot för att rensa skärmen beroende på OS
#ifdef _WIN32
    #define CLEAR_COMMAND "cls"
#else
    #define CLEAR_COMMAND "clear"
#endif

void rensaSkärm() {
    system(CLEAR_COMMAND);
}

void paus() {
    cout << "\nTryck på Enter för att fortsätta...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Datatyp för att spara betygsinformation
struct Betyg {
    string namn;
    string efternamn;
    char betyg;

    // Jämförelseoperator för att kunna använda std::remove
    bool operator==(const Betyg& other) const {
        return namn == other.namn && efternamn == other.efternamn && betyg == other.betyg;
    }
};

// Lägg till betyg
void läggTill(vector<Betyg>& system) {
    Betyg b;
    cout << "\n--- Lägg till betyg ---\n";
    cout << "Förnamn: ";
    cin >> b.namn;
    cout << "Efternamn: ";
    cin >> b.efternamn;
    cout << "Betyg (A-F): ";
    cin >> b.betyg;
    b.betyg = toupper(b.betyg);

    if (string("ABCDEF").find(b.betyg) != string::npos) {
        system.push_back(b);
        cout << "\n✅ Tillagt: " << b.namn << " " << b.efternamn << " (" << b.betyg << ")\n";
    } else {
        cout << "\n❌ Ogiltigt betyg. Endast A-F tillåtet.\n";
    }
}

// Ta bort ett specifikt betyg
void taBort(vector<Betyg>& system) {
    Betyg b;
    cout << "\n--- Ta bort betyg ---\n";
    cout << "Förnamn: ";
    cin >> b.namn;
    cout << "Efternamn: ";
    cin >> b.efternamn;
    cout << "Betyg: ";
    cin >> b.betyg;
    b.betyg = toupper(b.betyg);

    auto it = remove(system.begin(), system.end(), b);
    if (it != system.end()) {
        system.erase(it, system.end());
        cout << "\n🗑️  Post raderad.\n";
    } else {
        cout << "\n⚠️  Ingen matchande post hittades.\n";
    }
}

// Visa alla betyg
void visa(const vector<Betyg>& system) {
    cout << "\n--- Betygslista ---\n";
    if (system.empty()) {
        cout << "📭 Inga betyg tillagda ännu.\n";
        return;
    }

    cout << left << setw(20) << "Förnamn" 
         << setw(20) << "Efternamn" 
         << "Betyg\n";
    cout << string(50, '-') << '\n';

    for (const auto& b : system) {
        cout << left << setw(20) << b.namn
             << setw(20) << b.efternamn
             << b.betyg << '\n';
    }
}

// Visa huvudmenyn och returnera användarens val
int meny() {
    cout << "======= BETYGSSYSTEM =======\n";
    cout << "1. Lägg till betyg\n"
         << "2. Ta bort betyg\n"
         << "3. Visa betyg\n"
         << "4. Avsluta\n"
         << "============================\n"
         << "Val: ";

    int val;
    if (!(cin >> val)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1; // Felaktig inmatning
    }

    cin.ignore(); // För att rensa efter siffran
    return val;
}

int main() {
    vector<Betyg> system;
    while (true) {
        rensaSkärm();
        int val = meny();

        switch (val) {
            case 1: läggTill(system); break;
            case 2: taBort(system); break;
            case 3: visa(system); break;
            case 4:
                cout << "\n👋 Tack för att du använde systemet. Hejdå!\n";
                return 0;
            default:
                cout << "\n⚠️  Ogiltigt val. Ange en siffra mellan 1 och 4.\n";
        }

        paus();
    }
}

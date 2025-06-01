#include <iostream>
#include <vector>
#include <string>
#include <iomanip>  // For setting output format

using namespace std;

void rensaSkärm() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


void bilarna(vector<pair<string, int>>& bilar) {
    rensaSkärm();
    string dinval;
    cout << "\n--- Lägg till en bil ---\n";
    cout << "Vad vill du lägga till: ";
    cin >> dinval;

    int prisen;
    cout << "Vad är priset på varan: ";
    cin >> prisen;

    
    // Add the car and its price as a pair
    bilar.push_back(make_pair(dinval, prisen));

    cout << "\nBilen och priset har lagts till:\n";
    cout << "Bil: " << dinval << ", Pris: " << prisen << " SEK\n";
    cout << "--------------------------------------\n";
}

void visa(const vector<pair<string, int>>& bilar) {
    rensaSkärm();
    
    if (bilar.empty()) {
        cout << "\nBil-listan är tom.\n";
        return;
    }

    cout << "\n--- Alla bilar och deras priser ---\n\n";

    // Tabellrubriker
    cout << left << setw(25) << "Bil" << setw(15) << "Pris (SEK)" << endl;
    cout << setfill('-') << setw(40) << "" << setfill(' ') << endl;

    // Rader med data
    for (const auto& bil : bilar) {
        cout << left << setw(25) << bil.first 
             << setw(15) << bil.second << endl;
    }

    cout << setfill('-') << setw(40) << "" << setfill(' ') << endl;
}

// Funktion för att radera en bil och dess motsvarande pris
void radera(vector<pair<string, int>>& bilar) {
    rensaSkärm();
    if (bilar.empty()) {
        cout << "\nDet finns inga bilar att radera.\n";
        return;
    }

    visa(bilar);

    cout << "\n--- Radera en bil ---\n";
    cout << "Vilken bil vill du radera? (Skriv namnet): ";
    string namn;
    cin.ignore();  // Ignorera eventuell newline från tidigare input
    getline(cin, namn);

    for (size_t i = 0; i < bilar.size(); ++i) {
        if (bilar[i].first == namn) {
            bilar.erase(bilar.begin() + i);
            cout << "Bilen '" << namn << "' har raderats.\n";
            cout << "--------------------------------------\n";
            return;
        }
    }
    cout << "Bilen '" << namn << "' hittades inte.\n";
    cout << "-----------------------------------------------";
}

int main() {
    vector<pair<string, int>> bilar;
    int val;

    while (true) {
        cout << "\n--- Välj ett alternativ ---\n";
        cout << "1. Visa alla bilar\n";
        cout << "2. Lägg till bil\n";
        cout << "3. Radera bil\n";
        cout << "4. Avsluta programmet\n";
        cout << "Ditt val (1-4): ";
        cin >> val;

        switch (val) {
            case 1:
                visa(bilar);
                break;
            case 2:
                bilarna(bilar);
                break;
            case 3:
                radera(bilar);
                break;
            case 4:
                cout << "\nProgrammet avslutas...\n";
                return 0;
            default:
                cout << "\nOgiltigt val. Försök igen.\n";
                break;
        }
    }

    return 0;
}

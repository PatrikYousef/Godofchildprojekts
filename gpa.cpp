#include <iostream>
#include <iomanip>  // For std::fixed and std::setprecision
#include <cctype>   // For std::toupper
using namespace std;

// Converts a letter grade to a numerical grade point
float gradeToPoint(char grade) {
    switch (toupper(grade)) {
        case 'A': return 4.0;
        case 'B': return 3.3;
        case 'C': return 3.0;
        case 'D': return 2.0;
        case 'E': return 1.0;
        default:  return 0.0; // Invalid grade or F
    }
}

int main() {
    int numberOfCourses;
    float totalGradePoints = 0.0;
    float totalCredits = 0.0;

    cout << "=====================================\n";
    cout << "         GPA CALCULATOR\n";
    cout << "=====================================\n\n";

    cout << "Enter the number of courses: ";
    cin >> numberOfCourses;

    cout << "\n-------------------------------------\n";

    for (int i = 0; i < numberOfCourses; ++i) {
        char grade;
        float credit;

        cout << "\nCourse " << i + 1 << " Details:\n";
        cout << "  - Grade (A–E): ";
        cin >> grade;
        cout << "  - Credits: ";
        cin >> credit;

        float gradePoint = gradeToPoint(grade);
        totalGradePoints += gradePoint * credit;
        totalCredits += credit;
    }

    cout << "\n=====================================\n";
    if (totalCredits > 0) {
        float gpa = totalGradePoints / totalCredits;
        cout << fixed << setprecision(2); // Set GPA to 2 decimal places
        cout << "Your GPA is: " << gpa << "\n";
    } else {
        cout << "No valid course data entered.\n";
    }
    cout << "=====================================\n";

    return 0;
}

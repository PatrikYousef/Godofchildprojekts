GPA Calculator – Program Description
This C++ program is a console-based GPA (Grade Point Average) Calculator. It allows a user to input grades and corresponding credit hours for a number of courses, then calculates and displays the overall GPA.

Key Features:
Grade Input:
Accepts letter grades from A to E.
Case-insensitive (handles both uppercase and lowercase).
Converts letter grades into numerical grade points:
A → 4.0
B → 3.3
C → 3.0
D → 2.0
E → 1.0
Any other input is considered invalid and treated as an F with 0.0 points.
Credit Input:
For each course, the user also inputs the credit hours.
Supports decimal values for credit hours (e.g., 3.5).
GPA Calculation:
GPA is computed using the formula:
GPA
=
∑
(
Grade Points
×
Credits
)
∑
Credits
GPA= 
∑Credits
∑(Grade Points×Credits)
​	
 
GPA is displayed with 2 decimal places using std::fixed and std::setprecision.
User-Friendly Interface:
Clearly formatted and labeled prompts.
Clean visual layout with separators for readability.
Sample Use Case:
=====================================
         GPA CALCULATOR
=====================================

Enter the number of courses: 3

-------------------------------------

Course 1 Details:
  - Grade (A–E): A
  - Credits: 3

Course 2 Details:
  - Grade (B–E): b
  - Credits: 4

Course 3 Details:
  - Grade (A–E): c
  - Credits: 2

=====================================
Your GPA is: 3.48
=====================================

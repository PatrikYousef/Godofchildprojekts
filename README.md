The file named StockMate.cpp
# Inventory System

A simple console-based Inventory and User Management system written in C++.  
It supports user registration and login, item inventory management, purchasing items, and salary/tax tracking for users.

---

## Features

### User Management
- Create new users with first name, last name, username, password, salary, and tax rate.
- Login with username and password.
- Search users by first or last name.
- Display all users with salary, tax paid, and net salary information.

### Inventory Management
- Add new items to inventory (name, price, quantity).
- List all available items.
- Purchase items by reducing stock quantity and displaying purchase details including timestamp.

### User Interface
- Console menu-driven interface with clear prompts and input validation.
- User session management with login and logout.

---

## How to Use

### Compilation

Use a C++ compiler that supports C++11 or higher. For example, with `g++`:

```bash
g++ -o inventory_system inventory_system.cpp
Running the Program
./inventory_system
Workflow
Start the program
You will be presented with the login menu where you can:
Login with an existing user.
Create a new user.
Exit the program.
After login
Access the main menu to:
Add items to inventory.
List all items.
Purchase items.
Find users by name.
Show all users with financial details.
Logout.
Exit or logout
You can logout from the main menu or exit from the login menu.



The file name SavingMoney.cpp

### 💸 Personal Finance Manager (C++)
A console-based application for managing users' financial data. Add users, view their income and expenses, calculate their savings, and remove them — all from a simple, text-driven menu interface.

📋 Features
➕ Add a new user with income and expense details

📄 View all users in a formatted table

💰 Calculate savings for a specific user

🗑️ Remove users by their first name

🚪 Exit the application safely

🖼️ Menu Preview
markdown
Kopiera
Redigera
============================
     💸 Personal Finance
============================
1. Add a new user
2. Show all users
3. Calculate savings
4. Remove a user
5. Exit
Enter your choice (1-5):
🧠 How It Works
Data Structure
Each user is represented by the Payment class:

cpp
Kopiera
Redigera
class Payment {
public:
    string firstName;
    string lastName;
    long long int income;
    long long int bills;
    long long int food;
    long long int clothes;
};
Core Functions
Function	Description
addUser()	Adds a user and prompts for income/expenses
showUsers()	Displays a table of all user data
calculateSavings()	Calculates net savings by subtracting expenses from income
removeUser()	Deletes user(s) by their first name
showMenu()	Displays the main interactive menu
clearScreen()	Clears the console screen (cross-platform support)

🛠️ Requirements
C++11 or later

Compatible with Windows, macOS, or Linux (clears screen automatically)

Compiler: g++ recommended

🚀 How to Run
Save the file as main.cpp

Compile:

bash
Kopiera
Redigera
g++ -o finance_manager main.cpp
Run:

bash
Kopiera
Redigera
./finance_manager
🧪 Sample Output
plaintext
Kopiera
Redigera
--- Add a New User ---
First name: Alice
Last name: Johnson
Income (numbers only): 45000
Monthly bills: 12000
Monthly food expenses: 6000
Monthly clothing expenses: 3000
✅ User has been added successfully!
🔒 Notes
Users are identified only by their first name when removing or searching.

All amounts are treated as long long int, so they support large values.

Basic input validation is included for numeric conversion.

📃 License
MIT License – use it, learn from it, and modify as needed!


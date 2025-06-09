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

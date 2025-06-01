import os
def products():
    checkout = []
    
    while True:
        print("What do you want to do?")
        print("1. Add product")
        print("2. Show products")
        print("3. Delete product")
        print("4. Exit")
        choice = input("Enter number (1-4): ").strip()
        
        if choice == "1":
            os.system('clear')
            name = input("Product name: ").strip()
            try:
                price = float(input("Product price (kr): ").strip())
                code = int(input("Product code: ").strip())
                checkout.append((name, price, code))
                print(f"\n'{name}' has been added to the checkout.\n")
            except ValueError:
                print("\nInvalid input! Please enter correct values.\n")
        
        elif choice == "2":
            os.system('clear')
            if checkout:
                print("-" * 50)
                print(f"{'Name':<20}{'Price':<15}{'Code':<15}")
                print("-" * 50)
                for name, price, code in checkout:
                    print(f"{name:<20}{price:<15.2f}{code:<15}")
                print("-" * 50 + "\n")
            else:
                print("\nCheckout is empty.\n")
        
        elif choice == "3":
            os.system('clear')
            name = input("Which product do you want to delete: ").strip()
            try:
                price = float(input("Product price (kr): ").strip())
                code = int(input("Product code: ").strip())
                checkout.remove((name, price, code))
                print("\nUpdated checkout:")
                print("-" * 50)
                for name, price, code in checkout:
                    print(f"{name:<20}{price:<15.2f}{code:<15}")
                print("-" * 50)
            except ValueError:
                print("\nInvalid input! Please enter correct values.\n")
            except Exception:
                print("\nProduct not found in checkout.\n")
        
        elif choice == "4":
            os.system('clear')
            print("\nExiting program. Thank you for using the checkout!\n")
            break
        
        else:
            print("\nInvalid choice, please try again.\n")

products()

class FinanceTracker:

    def __init__(self):
        self.income = 0
        self.expenses = 0
        self.savings = 0

    def add_income(self):
        amount = int(input("Enter your income: "))
        self.income += amount
        print(f"Added income: ${amount}")

    def add_expense(self):
        amount = int(input("Enter your expenses: "))
        self.expenses += amount
        print(f"Added expense: ${amount}")

    def calculate_savings(self):
        self.savings = self.income - self.expenses
        print(f"Total savings: ${self.savings}")

    def get_summary(self):
        print("\n--- Finance Summary ---")
        print(f"Total Income: ${self.income}")
        print(f"Total Expenses: ${self.expenses}")
        print(f"Total Savings: ${self.savings}")
        print("\n")


tracker = FinanceTracker()
tracker.add_income()
tracker.add_expense()
tracker.calculate_savings()
tracker.get_summary()

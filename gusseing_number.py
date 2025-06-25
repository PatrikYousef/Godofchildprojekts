import random

def guessing_game():
    print("🎉 Welcome to the Number Guessing Game! 🎉")
    print("I'm thinking of a number between 1 and 10. Can you guess what it is?\n")

    # Generate a random number between 1 and 10
    number = random.randint(1, 10)
    attempts = 0

    # Fun messages to encourage the player
    fun_responses = [
        "Nice try!",
        "Almost had it!",
        "Keep going!",
        "You're getting warmer...",
        "Not quite, but don't give up!"
    ]

    while True:
        try:
            # Ask the user for a guess
            guess = int(input("👉 Enter your guess (1–10): "))
        except ValueError:
            print("⚠️ Please enter a valid number.")
            continue

        # Check if the guess is within range
        if guess < 1 or guess > 10:
            print("🚫 Your guess must be between 1 and 10.")
            continue

        # Count the number of attempts
        attempts += 1

        # Check the guess
        if guess == number:
            print(f"\n🎉 Congratulations! You guessed the number {number} in {attempts} {'try' if attempts == 1 else 'tries'}!")
            break
        elif guess < number:
            print("Too low! 📉 " + random.choice(fun_responses))
        else:
            print("Too high! 📈 " + random.choice(fun_responses))

# Run the game
guessing_game()

def name(letter):
    count = 0
    for char in letter:
        if char in "aeiouAEIOU":
            count += 1
    return count
letter = input("Write the name you wanna count the vowels: ")
num_vowels = name(letter)
print(f"The letter {letter} has {num_vowels} vowels")

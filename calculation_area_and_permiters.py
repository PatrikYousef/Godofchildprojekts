import math

print("Choose a calculation:")
print("1. Area of a rectangle")
print("2. Perimeter of a rectangle")
print("3. Area of a triangle")
print("4. Perimeter of a triangle")
print("5. Area of a circle")
print("6. Circumference of a circle")
print("7. Area of a square")
print("8. Perimeter of a square")

choice = int(input("Enter a number between 1 and 8: "))

if choice == 1:
    b = float(input("Enter the base: "))
    h = float(input("Enter the height: "))
    area = b * h
    print("The area of the rectangle is:", area)

elif choice == 2:
    b = float(input("Enter the base: "))
    h = float(input("Enter the height: "))
    perimeter = 2 * (b + h)
    print("The perimeter of the rectangle is:", perimeter)

elif choice == 3:
    b = float(input("Enter the base: "))
    h = float(input("Enter the height: "))
    area = (b * h) / 2
    print("The area of the triangle is:", area)

elif choice == 4:
    a = float(input("Enter side A: "))
    b = float(input("Enter side B: "))
    c = float(input("Enter side C: "))
    perimeter = a + b + c
    print("The perimeter of the triangle is:", perimeter)

elif choice == 5:
    r = float(input("Enter the radius: "))
    area = math.pi * r ** 2
    print("The area of the circle is:", area)

elif choice == 6:
    r = float(input("Enter the radius: "))
    circumference = 2 * math.pi * r
    print("The circumference of the circle is:", circumference)

elif choice == 7:
    side = float(input("Enter the side length: "))
    area = side ** 2
    print("The area of the square is:", area)

elif choice == 8:
    side = float(input("Enter the side length: "))
    perimeter = 4 * side
    print("The perimeter of the square is:", perimeter)

else:
    print("Invalid choice. Please enter a number between 1 and 8.")

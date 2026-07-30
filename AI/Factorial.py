# Factorial using recursion
def factorial(n):
    if n == 0 or n == 1:   # base case
        return 1
    else:
        return n * factorial(n - 1)

# Main program
print("Factorial Program")
num = int(input("Enter a number: "))
result = factorial(num)
print(f"Factorial of {num} is {result}")

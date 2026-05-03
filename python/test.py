def is_armstrong(number):
    # Convert number to string to easily iterate and find the number of digits
    num_str = str(number)
    num_digits = len(num_str)
    
    # Calculate the sum of digits raised to the power of num_digits
    sum_of_powers = sum(int(digit) ** num_digits for digit in num_str)
    
    # Return True if the sum equals the original number
    return sum_of_powers == number

# --- Usage Examples ---

# 1. Check a specific number
test_num = int(input("Enter a number: "))
if is_armstrong(test_num):
    print(f"{test_num} is an Armstrong number.")
else:
    print(f"{test_num} is not an Armstrong number.")

# 2. Find all Armstrong numbers in a range (e.g., 1 to 2000)
# print("\nArmstrong numbers between 1 and 2000:")
# armstrong_list = [num for num in range(1, 2001) if is_armstrong(num)]
# print(armstrong_list)
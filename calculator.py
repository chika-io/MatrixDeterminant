#!/usr/bin/env python3
"""
Calculator CLI App
Author: Ukpai Chika Nwakaibeya
GitHub: https://github.com/chika-io
Description: A command-line calculator supporting basic and advanced operations.
"""

import math
import os

# ─────────────────────────────────────────────
#  OPERATIONS
# ─────────────────────────────────────────────

def add(a, b): return a + b
def subtract(a, b): return a - b
def multiply(a, b): return a * b

def divide(a, b):
    if b == 0:
        raise ValueError("Cannot divide by zero.")
    return a / b

def modulus(a, b):
    if b == 0:
        raise ValueError("Cannot divide by zero.")
    return a % b

def power(a, b): return a ** b

def square_root(a):
    if a < 0:
        raise ValueError("Cannot take square root of a negative number.")
    return math.sqrt(a)

def log(a):
    if a <= 0:
        raise ValueError("Logarithm undefined for zero or negative numbers.")
    return math.log10(a)

def ln(a):
    if a <= 0:
        raise ValueError("Natural log undefined for zero or negative numbers.")
    return math.log(a)


# ─────────────────────────────────────────────
#  HELPERS
# ─────────────────────────────────────────────

def clear_screen():
    os.system('cls' if os.name == 'nt' else 'clear')

def get_number(prompt):
    while True:
        try:
            return float(input(prompt))
        except ValueError:
            print("  ⚠  Invalid input. Please enter a number.\n")

def format_result(value):
    """Display as int if result is a whole number, else float."""
    if isinstance(value, float) and value.is_integer():
        return int(value)
    return round(value, 10)

def print_banner():
    print("=" * 45)
    print("       CALCULATOR CLI  —  chika-io")
    print("=" * 45)

def print_menu():
    print("""
  BASIC OPERATIONS
  ─────────────────
  1. Addition           ( a + b )
  2. Subtraction        ( a - b )
  3. Multiplication     ( a × b )
  4. Division           ( a ÷ b )
  5. Modulus            ( a % b )
  6. Power              ( a ^ b )

  ADVANCED OPERATIONS
  ─────────────────────
  7. Square Root        ( √a )
  8. Logarithm base 10  ( log a )
  9. Natural Logarithm  ( ln a )

  ─────────────────────
  H. History
  C. Clear Screen
  Q. Quit
""")


# ─────────────────────────────────────────────
#  MAIN LOOP
# ─────────────────────────────────────────────

def main():
    history = []

    clear_screen()
    print_banner()

    while True:
        print_menu()
        choice = input("  Enter option: ").strip().upper()

        try:
            if choice == 'Q':
                print("\n  Thanks for using Calculator CLI. Goodbye!\n")
                break

            elif choice == 'C':
                clear_screen()
                print_banner()

            elif choice == 'H':
                print("\n  ── Calculation History ──")
                if not history:
                    print("  No calculations yet.")
                else:
                    for i, entry in enumerate(history, 1):
                        print(f"  {i}. {entry}")
                print()
                input("  Press Enter to continue...")

            elif choice == '1':
                a = get_number("  Enter first number: ")
                b = get_number("  Enter second number: ")
                result = add(a, b)
                entry = f"{format_result(a)} + {format_result(b)} = {format_result(result)}"
                print(f"\n  ✔  Result: {format_result(result)}\n")
                history.append(entry)

            elif choice == '2':
                a = get_number("  Enter first number: ")
                b = get_number("  Enter second number: ")
                result = subtract(a, b)
                entry = f"{format_result(a)} - {format_result(b)} = {format_result(result)}"
                print(f"\n  ✔  Result: {format_result(result)}\n")
                history.append(entry)

            elif choice == '3':
                a = get_number("  Enter first number: ")
                b = get_number("  Enter second number: ")
                result = multiply(a, b)
                entry = f"{format_result(a)} × {format_result(b)} = {format_result(result)}"
                print(f"\n  ✔  Result: {format_result(result)}\n")
                history.append(entry)

            elif choice == '4':
                a = get_number("  Enter first number: ")
                b = get_number("  Enter second number: ")
                result = divide(a, b)
                entry = f"{format_result(a)} ÷ {format_result(b)} = {format_result(result)}"
                print(f"\n  ✔  Result: {format_result(result)}\n")
                history.append(entry)

            elif choice == '5':
                a = get_number("  Enter first number: ")
                b = get_number("  Enter second number: ")
                result = modulus(a, b)
                entry = f"{format_result(a)} % {format_result(b)} = {format_result(result)}"
                print(f"\n  ✔  Result: {format_result(result)}\n")
                history.append(entry)

            elif choice == '6':
                a = get_number("  Enter base: ")
                b = get_number("  Enter exponent: ")
                result = power(a, b)
                entry = f"{format_result(a)} ^ {format_result(b)} = {format_result(result)}"
                print(f"\n  ✔  Result: {format_result(result)}\n")
                history.append(entry)

            elif choice == '7':
                a = get_number("  Enter number: ")
                result = square_root(a)
                entry = f"√{format_result(a)} = {format_result(result)}"
                print(f"\n  ✔  Result: {format_result(result)}\n")
                history.append(entry)

            elif choice == '8':
                a = get_number("  Enter number: ")
                result = log(a)
                entry = f"log({format_result(a)}) = {format_result(result)}"
                print(f"\n  ✔  Result: {format_result(result)}\n")
                history.append(entry)

            elif choice == '9':
                a = get_number("  Enter number: ")
                result = ln(a)
                entry = f"ln({format_result(a)}) = {format_result(result)}"
                print(f"\n  ✔  Result: {format_result(result)}\n")
                history.append(entry)

            else:
                print("\n  ⚠  Invalid option. Please choose from the menu.\n")

        except ValueError as e:
            print(f"\n  ✖  Error: {e}\n")

        input("  Press Enter to continue...")
        clear_screen()
        print_banner()


if __name__ == "__main__":
    main()

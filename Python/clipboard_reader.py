import pyperclip
import time

def read_clipboard():
    """Reads and prints text currently stored in clipboard."""
    text = pyperclip.paste()
    if text:
        print(" Clipboard content:")
        print("-------------------------")
        print(text)
        print("-------------------------")
    else:
        print(" Clipboard is empty.")

def write_clipboard():
    """Copies user input text to clipboard."""
    text = input("Enter text to copy to clipboard: ")
    pyperclip.copy(text)
    print(" Text copied to clipboard!")

def clear_clipboard():
    """Clears clipboard content."""
    pyperclip.copy("")
    print("🧹 Clipboard cleared!")

if __name__ == "__main__":
    print("=== Clipboard Utility ===")
    print("1️⃣ Read clipboard")
    print("2️⃣ Write to clipboard")
    print("3️⃣ Clear clipboard")
    choice = input("Choose an option (1/2/3): ").strip()

    if choice == "1":
        read_clipboard()
    elif choice == "2":
        write_clipboard()
    elif choice == "3":
        clear_clipboard()
    else:
        print(" Invalid choice. Please select 1, 2, or 3.")

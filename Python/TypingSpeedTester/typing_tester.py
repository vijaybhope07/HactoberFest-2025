import time
import random

def get_sentence():
    """
    Returns a random sentence from a predefined list.
    """
    sentences = [
        "The quick brown fox jumps over the lazy dog.",
        "Never underestimate the power of a good book.",
        "Hacktoberfest is a great way to start open source.",
        "Python is a versatile and popular programming language.",
        "The early bird catches the worm.",
        "Programming is the art of algorithm design.",
        "Always code as if the guy who ends up maintaining your code will be a violent psychopath who knows where you live."
    ]
    return random.choice(sentences)

def typing_test():
    """
    Main function to run the typing speed test.
    """
    sentence = get_sentence()
    print("\n--- Python Typing Speed Tester ---")
    print("\nType this sentence as fast as you can:")
    print(f"\n'{sentence}'\n")

    input("Press Enter when you are ready to start...")

    # Record the start time
    start_time = time.time()

    # Get user input
    typed_text = input("Start typing: ")

    # Record the end time
    end_time = time.time()

    # --- Calculations ---

    # Calculate elapsed time
    elapsed_time = end_time - start_time

    # Calculate number of words in the original sentence
    word_count = len(sentence.split())

    # Calculate WPM (Words Per Minute)
    # (Total Words / Total Seconds) * 60
    wpm = (word_count / elapsed_time) * 60

    # Calculate Accuracy (Simple character comparison)
    correct_chars = 0
    for i in range(min(len(sentence), len(typed_text))):
        if sentence[i] == typed_text[i]:
            correct_chars += 1

    accuracy = (correct_chars / len(sentence)) * 100

    # --- Display Results ---
    print("\n--- Your Results ---")
    print(f"Time taken: {elapsed_time:.2f} seconds")
    print(f"Your typing speed: {wpm:.2f} WPM")
    print(f"Accuracy: {accuracy:.2f}%")
    print("\n--------------------")

if __name__ == "__main__":
    while True:
        typing_test()
        if input("\nDo you want to try again? (y/n): ").lower() != 'y':
            break
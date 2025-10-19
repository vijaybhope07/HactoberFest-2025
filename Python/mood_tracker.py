"""
Mood Tracker - A beginner-friendly Python project
Track your daily mood and view statistics!
"""

import datetime

# Store moods in a list (in a real app, you'd use a file or database)
mood_log = []

def display_menu():
    """Display the main menu options"""
    print("\n🌟 MOOD TRACKER 🌟")
    print("=" * 30)
    print("1. Log today's mood")
    print("2. View mood history")
    print("3. View mood statistics")
    print("4. Exit")
    print("=" * 30)

def log_mood():
    """Let user log their current mood"""
    print("\nHow are you feeling today?")
    print("1. 😄 Happy")
    print("2. 😊 Good")
    print("3. 😐 Okay")
    print("4. 😔 Sad")
    print("5. 😠 Angry")
    
    choice = input("\nEnter your choice (1-5): ")
    
    moods = {
        "1": "Happy",
        "2": "Good",
        "3": "Okay",
        "4": "Sad",
        "5": "Angry"
    }
    
    if choice in moods:
        note = input("Add a note (optional): ")
        today = datetime.date.today().strftime("%Y-%m-%d")
        
        mood_entry = {
            "date": today,
            "mood": moods[choice],
            "note": note
        }
        
        mood_log.append(mood_entry)
        print(f"\n✅ Mood logged successfully for {today}!")
    else:
        print("\n❌ Invalid choice. Please try again.")

def view_history():
    """Display all mood entries"""
    if not mood_log:
        print("\n📭 No mood entries yet. Start logging your mood!")
        return
    
    print("\n📖 YOUR MOOD HISTORY")
    print("=" * 50)
    
    for entry in mood_log:
        print(f"\nDate: {entry['date']}")
        print(f"Mood: {entry['mood']}")
        if entry['note']:
            print(f"Note: {entry['note']}")
        print("-" * 50)

def view_statistics():
    """Show mood statistics"""
    if not mood_log:
        print("\n📭 No mood entries yet. Start logging your mood!")
        return
    
    print("\n📊 MOOD STATISTICS")
    print("=" * 50)
    
    # Count each mood
    mood_counts = {}
    for entry in mood_log:
        mood = entry['mood']
        mood_counts[mood] = mood_counts.get(mood, 0) + 1
    
    # Display counts
    print(f"\nTotal entries: {len(mood_log)}")
    print("\nMood breakdown:")
    
    for mood, count in mood_counts.items():
        percentage = (count / len(mood_log)) * 100
        print(f"  {mood}: {count} times ({percentage:.1f}%)")
    
    # Find most common mood
    most_common = max(mood_counts, key=mood_counts.get)
    print(f"\n🏆 Most common mood: {most_common}")

def main():
    """Main program loop"""
    print("Welcome to your Personal Mood Tracker! 🌈")
    
    while True:
        display_menu()
        choice = input("\nEnter your choice: ")
        
        if choice == "1":
            log_mood()
        elif choice == "2":
            view_history()
        elif choice == "3":
            view_statistics()
        elif choice == "4":
            print("\n👋 Thanks for using Mood Tracker! Take care!")
            break
        else:
            print("\n❌ Invalid choice. Please enter 1-4.")

# Run the program
if __name__ == "__main__":
    main()
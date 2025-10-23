def generate_anagrams(input_str):
    """
    Generate all unique anagrams of a given input string using recursion.
    Args:
        input_str (str): The input string.
    Returns:
        list[str]: Sorted list of unique anagrams.
    """

    # Base case: a single character has only one anagram — itself
    if len(input_str) == 1:
        return [input_str]

    all_anagrams = []
    first_char = input_str[0]
    rem_chars = input_str[1:]

    # Recursive step: generate anagrams for remaining characters
    rem_anagrams = generate_anagrams(rem_chars)

    # Insert the first character at all positions in each sub-anagram
    for partial_anagrams in rem_anagrams:
        for position in range(len(partial_anagrams) + 1):
            new_anagram = partial_anagrams[:position] + first_char + partial_anagrams[position:]
            all_anagrams.append(new_anagram)

    # Remove duplicates and return sorted list
    return sorted(list(set(all_anagrams)))


# User input and pretty print output
input_str = input("Enter a string to generate its unique anagrams: ")
anagrams = generate_anagrams(input_str)

print(f"\nWe have {len(anagrams)} unique anagrams:")
for i, word in enumerate(anagrams, 1):
    end_char = ", " if i != len(anagrams) else ".\n"
    print(f"{i}. {word}", end=end_char)

anagrams = generate_anagrams(input_str)
print(f"\nWe have {len(anagrams)} unique anagrams. They are:")
print(", ".join(anagrams) + ".")
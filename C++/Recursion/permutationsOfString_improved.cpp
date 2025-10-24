// C++ program to generate all permutations of a string using recursion
// Uses backtracking approach: Choose, Explore, Backtrack
// Time Complexity: O(n! * n), Space Complexity: O(n) for recursion stack

#include <iostream>
#include <string>
using namespace std;

// Function to generate all permutations using recursion
// Parameters:
//   str - the string being permuted (passed by reference)
//   index - current position being fixed in this recursive call
void generatePermutations(string &str, int index) {
    // Base case: when we've fixed all positions, print the permutation
    if (index == str.length() - 1) {
        cout << str << endl;
        return;
    }
    
    // Try each character from current index to end
    for (int i = index; i < str.length(); i++) {
        swap(str[index], str[i]);            // Choose: fix str[i] at position index
        generatePermutations(str, index + 1); // Explore: recurse for remaining positions
        swap(str[index], str[i]);            // Backtrack: restore original state
    }
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    
    if (input.empty()) {
        cout << "Empty string has no permutations." << endl;
        return 1;
    }
    
    cout << "All permutations of \"" << input << "\" are:" << endl;
    generatePermutations(input, 0);
    
    return 0;
}

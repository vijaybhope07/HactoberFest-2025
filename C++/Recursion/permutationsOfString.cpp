#include <bits/stdc++.h>
using namespace std;

// Function to generate all permutations using recursion
void generatePermutations(string &str, int index) {
    if (index == str.length() - 1) {
        cout << str << endl;
        return;
    }
    
    for (int i = index; i < str.length(); i++) {
        swap(str[index], str[i]); // Choose
        generatePermutations(str, index + 1); // Explore
        swap(str[index], str[i]); // Backtrack
    }
}

int main() {
    string input = "ABC";
    cout << "All permutations of " << input << " are:" << endl;
    generatePermutations(input, 0);
    return 0;
}

// C++ program to check fixed point in an array using linear search
// A fixed point in an array is an index i such that arr[i] = i
// Time Complexity: O(n), Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

// Function to find fixed point in array
// Returns the index where arr[i] == i, or -1 if no such point exists
int fixedPoint(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == i) return i;
    }
    // If no fixed point is found
    return -1;
}

int main() {
    // Example with fixed point at index 3 (arr[3] = 3)
    vector<int> arr = {-10, -5, 0, 3, 7};

    int result = fixedPoint(arr);

    if (result != -1) {
        cout << "Fixed point found at index: " << result << endl;
    } else {
        cout << "No fixed point found in the array." << endl;
    }

    return 0;
}

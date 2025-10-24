// C++ program to find the element which is greater than or equal to
// all left elements and smaller than or equal to all right elements
// Time Complexity: O(n^2) - can be optimized to O(n)
// Space Complexity: O(1)

#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// Function to find partition point element
// Returns the element that satisfies the partition property, or -1 if not found
int findElement(vector<int> &arr) {
    // Iterate through each element
    for (int i = 1; i < arr.size() - 1; i++) {
        // Store maximum in left portion
        int left = INT_MIN;
        for (int j = 0; j < i; j++) {
            left = max(left, arr[j]);
        }

        // Store minimum in right portion
        int right = INT_MAX;
        for (int j = i + 1; j < arr.size(); j++) {
            right = min(right, arr[j]);
        }

        // Check if current element is greater than or equal to left max
        // and smaller than or equal to right min
        if (arr[i] >= left && arr[i] <= right) {
            return arr[i];
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {5, 1, 4, 3, 6, 8, 10, 7, 9};

    int result = findElement(arr);

    if (result != -1) {
        cout << "Partition point element: " << result << endl;
    } else {
        cout << "No partition point found in the array." << endl;
    }

    return 0;
}

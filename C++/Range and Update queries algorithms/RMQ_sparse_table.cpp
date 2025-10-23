#include <bits/stdc++.h>
using namespace std;

// Sparse Table for Range Minimum Query (RMQ)
// Time Complexity: O(n log n) for preprocessing, O(1) for query
// Space Complexity: O(n log n)

class SparseTable {
private:
    vector<vector<int>> st;  // Sparse table
    vector<int> log_table;    // Precomputed logarithm values
    int n;                    // Size of input array
    
public:
    // Constructor: Builds the sparse table
    SparseTable(vector<int>& arr) {
        n = arr.size();
        int max_log = log2(n) + 1;
        
        // Initialize sparse table
        st.assign(n, vector<int>(max_log));
        log_table.assign(n + 1, 0);
        
        // Precompute logarithm values for faster query
        for (int i = 2; i <= n; i++) {
            log_table[i] = log_table[i / 2] + 1;
        }
        
        // Initialize first column with original array values
        for (int i = 0; i < n; i++) {
            st[i][0] = arr[i];
        }
        
        // Build sparse table using dynamic programming
        // st[i][j] represents minimum value in range [i, i + 2^j - 1]
        for (int j = 1; j < max_log; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    
    // Query function: Returns minimum value in range [L, R] (0-indexed)
    int query(int L, int R) {
        // Calculate the length and its logarithm
        int len = R - L + 1;
        int k = log_table[len];
        
        // Compare overlapping ranges to get minimum
        // This works because min is an idempotent function: min(a, a) = a
        return min(st[L][k], st[R - (1 << k) + 1][k]);
    }
    
    // Alternative query using log2 (slightly slower but more intuitive)
    int query_alternative(int L, int R) {
        int len = R - L + 1;
        int k = log2(len);
        return min(st[L][k], st[R - (1 << k) + 1][k]);
    }
};

// Driver code with examples
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // Example 1: Basic RMQ
    cout << "Example 1: Basic Range Minimum Query" << endl;
    vector<int> arr1 = {7, 2, 3, 0, 5, 10, 3, 12, 18};
    int n1 = arr1.size();
    
    cout << "Array: ";
    for (int x : arr1) cout << x << " ";
    cout << endl;
    
    SparseTable st1(arr1);
    
    // Test various range queries
    vector<pair<int, int>> queries1 = {{0, 4}, {4, 7}, {7, 8}, {0, 8}, {1, 3}};
    
    cout << "Range Minimum Queries:" << endl;
    for (auto& q : queries1) {
        int L = q.first, R = q.second;
        cout << "Min in range [" << L << ", " << R << "] = " 
             << st1.query(L, R) << endl;
    }
    cout << endl;
    
    // Example 2: Array with duplicates
    cout << "Example 2: Array with duplicate minimum values" << endl;
    vector<int> arr2 = {5, 3, 8, 3, 9, 1, 4, 1, 6};
    int n2 = arr2.size();
    
    cout << "Array: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;
    
    SparseTable st2(arr2);
    
    vector<pair<int, int>> queries2 = {{0, 3}, {2, 5}, {5, 8}, {0, 8}};
    
    cout << "Range Minimum Queries:" << endl;
    for (auto& q : queries2) {
        int L = q.first, R = q.second;
        cout << "Min in range [" << L << ", " << R << "] = " 
             << st2.query(L, R) << endl;
    }
    cout << endl;
    
    // Example 3: Interactive test
    cout << "Example 3: Interactive test with custom array" << endl;
    vector<int> arr3 = {4, 2, 9, 7, 3, 6, 8, 1, 5};
    
    cout << "Array: ";
    for (int x : arr3) cout << x << " ";
    cout << endl;
    
    SparseTable st3(arr3);
    
    cout << "Testing all possible ranges:" << endl;
    for (int i = 0; i < arr3.size(); i++) {
        for (int j = i; j < arr3.size(); j++) {
            cout << "Range [" << i << ", " << j << "]: min = " 
                 << st3.query(i, j) << endl;
        }
    }
    
    return 0;
}

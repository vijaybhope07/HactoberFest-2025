// Maximum Number of Distinct Elements After Operations

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0, prev = INT_MIN;
        for (int num : nums) {
            int curr = min(max(num - k, prev + 1), num + k);
            if (curr > prev) {
                cnt++;
                prev = curr;
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 5, 6, 2, 8};
    int k = 2;
    cout << sol.maxDistinctElements(nums, k) << endl;
    return 0;
}

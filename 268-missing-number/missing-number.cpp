class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Step 1

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i) {
                return i; // Step 2
            }
        }

        return nums.size(); // Step 3
    }
};

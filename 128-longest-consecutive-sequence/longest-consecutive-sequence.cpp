class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        sort(nums.begin(), nums.end());

        int longest = 1;
        int currLen = 1;

        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1]) continue; // skip duplicates
            if (nums[i] == nums[i - 1] + 1) {
                currLen++;
            } else {
                longest = max(longest, currLen);
                currLen = 1;
            }
        }

        longest = max(longest, currLen);
        return longest;
    }
};

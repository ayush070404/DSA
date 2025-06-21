class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(101, 0);  // Because 0 <= nums[i] <= 100

        // Count frequency of each number
        for (int num : nums) {
            count[num]++;
        }

        // Convert to prefix sum to get "how many numbers are smaller"
        for (int i = 1; i < 101; ++i) {
            count[i] += count[i - 1];
        }

        vector<int> result;
        for (int num : nums) {
            if (num == 0)
                result.push_back(0);
            else
                result.push_back(count[num - 1]);
        }

        return result;
    }
};

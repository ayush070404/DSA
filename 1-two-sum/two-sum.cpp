class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        vector<int> ans;

        // Ayush
    
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i}; // Found a valid pair
            }

            numMap[nums[i]] = i; // Store index of current number
        }

        return {}; // Return empty vector if no pair is found
    }
};

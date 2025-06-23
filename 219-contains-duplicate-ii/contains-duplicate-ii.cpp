

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;

        for (int i = 0; i < nums.size(); i++) {
            if (window.count(nums[i])) return true;

            window.insert(nums[i]);

            // Keep only the last k elements in the set
            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
        }

        return false;
    }
};


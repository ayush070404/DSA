class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int hash[1001] = {0};  // assuming values in nums1 and nums2 are in range [0, 1000]
        vector<int> ans;

        for (int num : nums1) {
            hash[num] = 1;  // mark presence in nums1
        }

        for (int num : nums2) {
            if (hash[num] == 1) {
                ans.push_back(num);  // it's common
                hash[num] = -1;      // mark as used to avoid duplicates
            }
        }

        return ans;
    }
};

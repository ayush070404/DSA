class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // in case k > n

        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[(i + k) % n] = nums[i];
        }

        nums = arr;
    }
};

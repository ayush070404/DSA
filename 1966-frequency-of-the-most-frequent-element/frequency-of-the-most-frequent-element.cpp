class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long l = 0, r = 0;
        long long sum = 0;
        long long maxfreq = 0;

        while (r < n) {
            sum += nums[r];

            while ((long long)nums[r] * (r - l + 1) - sum > k) {
                sum -= nums[l];
                l++;
            }

            maxfreq = max(maxfreq, (long long)(r - l + 1)); // ✅ type match
            r++;
        }

        return (int)maxfreq;  // cast back to int if required by the problem
    }
};


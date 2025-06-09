typedef __int128 ll;

class Solution {
public:
    bool solve(int i, ll prod, ll target, vector<int> &nums) {
        int n = nums.size();
        if (prod > target) return false;
        if (prod == target) return true;
        if(i == n ) return false;
        

        // take
        if (solve(i + 1, prod * nums[i], target, nums)) return true;
        // not take
        if (solve(i + 1, prod, target, nums)) return true;

        return false;
    }

    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();
        ll product = 1;
        for (int i = 0; i < n; i++) {
            product *= nums[i];
        }

        if ((ll)target * target != product) return false;

        return solve(0, 1, target, nums);
    }
};

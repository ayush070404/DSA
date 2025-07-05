class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < nums[high]) {
                // Minimum is in left part (including mid)
                high = mid;
            }
            else if (nums[mid] > nums[high]) {
                // Minimum is in right part (excluding mid)
                low = mid + 1;
            }
            else {
                // nums[mid] == nums[high], can't decide, safely shrink
                high--;
            }
        }

        return nums[low];
    }
};

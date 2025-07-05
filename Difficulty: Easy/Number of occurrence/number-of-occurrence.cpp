class Solution {
  public:
    int countFreq(vector<int>& nums, int x) {
        // code here
        int n = nums.size();
        int start = -1, end = -1;

        // if (n == 0) return {start, end};

        // Find first occurrence
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == x) {
                start = mid;
                high = mid - 1; // search further left
            } else if (nums[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // Find last occurrence
        low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == x) {
                end = mid;
                low = mid + 1; // search further right
            } else if (nums[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if(start == -1 || end == -1) return 0;
        return end- start+1;
        
    }
};

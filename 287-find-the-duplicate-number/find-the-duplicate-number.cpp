class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i= 0 ; i<n ; i++){
            int index = nums[i]%n;
            nums[index]+= n;
        }

        for(int i=0 ; i<n ; i++){
            if(nums[i]/n>= 2) ans = i;
        }
        return ans;
    }
};
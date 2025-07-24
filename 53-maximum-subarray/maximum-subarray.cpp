class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int ans = INT_MIN;
        int l = 0 , r = 0;
        while(l<= r && r<n){
            sum+= nums[r];
            ans = max(ans , sum);
            if(sum<0) {
                l++;
                sum = 0;
            }
            r++;
        }
    return ans;
    }
};
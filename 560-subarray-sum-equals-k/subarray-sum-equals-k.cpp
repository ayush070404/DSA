class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        unordered_map <int, int>preSum;
        int sum = 0;

        for(int i=0 ; i<n ;i++){
            sum+= nums[i];
            if(sum == k) count++;

            if(preSum.find(sum-k)!=preSum.end()){
                count+=preSum[sum-k];
            }
            
            preSum[sum]++;
            
        }
    return count;
    }
};

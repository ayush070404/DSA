class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n ==1) return true;
        if(nums[0]==0) return false;
        vector<int> zeroes;
        for(int i=0 ; i<n ; i++){
            if(nums[i] == 0 ) zeroes.push_back(i);
        }
        if(zeroes.size() == 0) return true;
        while(!zeroes.empty()){
            int ind = zeroes.back();
            zeroes.pop_back();
            if(ind == n-1) continue;
            bool canReach = false;
            for (int i = ind - 1; i >= 0; i--) {
                if (nums[i] > ind - i) {
                    canReach = true;
                    break;
                }
            }
            if (!canReach) return false; 

        }
    return true;
    }
};
class Solution {
public:

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totSum = accumulate(arr.begin(), arr.end(), 0);
    
    if(totSum-d<0) return 0;
    if((totSum-d)%2!=0) return 0;
    
    int target = (totSum-d)/2; // tryingh to devide in two equAL subsets so need even target
    vector<vector<int>> dp(n, vector<int>(target +1, 0));

    // Base case for the 0th index
    if (arr[0] == 0) {
        dp[0][0] = 2; // pick and not pick
    } else {
        dp[0][0] = 1; // not pick
        if (arr[0] <= target)
            dp[0][arr[0]] = 1; // pick
    }

    for(int i = 1 ; i <n ; i++) {
        for( int tar = 0 ; tar <=target ; tar++){

            int not_pick = dp[i-1][tar];

            int pick = 0;
            if(arr[i]<= tar) pick = dp[i-1][tar- arr[i]];

            dp[i][tar] = (pick+ not_pick);
        }
    }
    return dp[n-1][target];

}


    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n , target , nums);
    }
};
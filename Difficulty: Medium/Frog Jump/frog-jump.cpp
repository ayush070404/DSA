
class Solution {
  public:
    int minloss(int n ,vector<int>& height, vector<int>& dp){
        if(n == 0) return 0;
        // if( n ==1) return abs(height[1]- height[0]);
        if(dp[n] != -1) return dp[n];
        int step1 = minloss(n-1 , height, dp) + abs(height[n]- height[n-1]);
        int step2 = INT_MAX;
        if(n>1){
            step2  = minloss(n-2 , height, dp) + abs(height[n]- height[n-2]);
        }
        
        return dp[n] =min(step1, step2);
    }
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n+1 , -1);
        return minloss(n-1 , height , dp);
    }
};


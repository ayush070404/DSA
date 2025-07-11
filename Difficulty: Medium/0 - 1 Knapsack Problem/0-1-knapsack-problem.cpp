class Solution {
  public:
  
    int solve(int ind , int weight , vector<int> &val , vector<int> &wt, vector<vector<int>> &dp){
        if(ind == 0 ){
            if(weight >= wt[0]) return val[0];
            else return 0;
        }
        if(dp[ind][weight] != -1) return dp[ind][weight];
        int not_pick = solve(ind-1 , weight , val , wt, dp);
        int pick = 0;
        if(wt[ind] <= weight) pick = val[ind] + solve(ind-1 , weight -wt[ind], val , wt, dp);
        
        return dp[ind][weight]= max(not_pick, pick);
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp( n , vector<int>(W+1 , -1));
        return solve(n-1 , W , val , wt, dp);
    }
};
class Solution {
  public:
  
    int solve(int ind , int target , vector<int> &arr, vector<vector<int>> &dp){
        if(ind == 0){
            if(target == 0 && arr[0] == 0) return 2;
            else if(target == arr[0] || target == 0) return 1;
            else return 0;
        }
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int not_pick = solve(ind-1 , target , arr, dp);
        int pick = 0;
        if(arr[ind] <= target) pick = solve(ind-1 , target-arr[ind] , arr, dp);
        
        return dp[ind][target] = pick+not_pick;
    }
  
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int n = arr.size();
        int totSum = accumulate(arr.begin() , arr.end(), 0);
        
        if(totSum -d < 0) return 0;
        if((totSum - d)%2 != 0) return 0;
        int target = (totSum -d)/2;
        
        vector<vector<int>> dp( n , vector<int>(target+1 , -1));
        
        return solve(n-1 , target , arr, dp);
    }
};
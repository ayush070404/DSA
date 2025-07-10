class Solution {
  public:
  
    int solve(int ind , vector<int> &arr , int target , vector<vector<int>> &dp){
        if(ind == 0){
            
            if(target == 0 && arr[ind] == 0) return 2;
            
            else if(target == arr[ind] || target == 0) return 1;
            
            else return 0;
        }
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int not_pick = solve(ind -1 , arr , target , dp);
        int pick = 0;
        if(arr[ind]<= target){
            pick = solve(ind -1 , arr , target - arr[ind] , dp);
        }
         return dp[ind][target] = (pick +not_pick);
    }
  
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n , vector<int> (target+1 , -1));
        
        return solve(n-1 , arr , target , dp);
        
    }
};
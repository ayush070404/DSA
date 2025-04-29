class Solution {
public:
    bool solve(int ind, vector <int> & arr, int target , vector <vector<int>> & dp){
        if(target == 0) return true;
        if(ind == 0) return arr[0] == target;

        if(dp[ind][target] !=-1 ) return dp[ind][target];

        bool not_take = solve(ind-1 , arr ,target , dp);

        bool take = false;
        if(arr[ind]<= target ){
            take = solve(ind -1 , arr , target - arr[ind], dp);
        }

        dp[ind][target] = take | not_take;

        return dp[ind][target];
    }

    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i =0 ; i<n ; i++){
            sum += arr[i];
        }
        if(sum % 2 != 0) return false;
        int k = sum/2;
        vector<vector<bool>> dp(n, vector<bool>(sum/2 + 1, 0));
        for(int i = 0 ; i<n ; i++) dp[i][0] = true;
        if(arr[0] <=k) dp[0][arr[0]] = true;

        for(int i = 1; i<n ; i++){
            for(int target = 1; target<= k ; target++){

                bool not_take = dp[i-1][target];

                bool take = false;
                if(arr[i] <= target) take = dp[i-1][target - arr[i]];

                dp[i][target] = take| not_take;
            }
        }
    return dp[n-1][k];
    }
};
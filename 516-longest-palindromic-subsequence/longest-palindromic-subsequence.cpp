class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string str1 = s;
        string str2 = s;  // copy original
        reverse(str2.begin(), str2.end()); 


        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        for(int i =0 ; i< n ; i++) dp[i][0] = 0;
        for(int j =0 ; j< n ; j++) dp[0][j] = 0;
            

        for(int i = 1 ; i<=n; i++){
            for(int j= 1 ; j<=n; j++){

                if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];

                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

            }
        } 
        return dp[n][n];
    }
};
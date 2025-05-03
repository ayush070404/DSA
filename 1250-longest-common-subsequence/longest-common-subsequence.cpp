class Solution {
public:

    
int solve (int ind1, int ind2 , string &s , string &t, vector<vector<int>> &dp){
	if(ind1< 0 || ind2< 0 ) return 0;

	if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

	if(s[ind1] == t[ind2]) dp[ind1][ind2]= 1+ solve(ind1-1, ind2-1, s, t, dp);

	else dp[ind1][ind2]= max(solve(ind1-1, ind2, s, t, dp) , solve(ind1, ind2-1, s, t, dp));\

	return dp[ind1][ind2];
}

    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

        return solve (n-1 , m-1 , s , t , dp);
    }
};





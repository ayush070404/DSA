class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector < vector < int >> dp(n + 1, vector < int > (m + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }

        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }

        int len = n+ m -dp[n][m];
        int i = n;
        int j = m;

        int index = len - 1;
        string str = "";
        for (int k = 1; k <= len; k++) {
            str += "$"; // dummy string
        }

        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
            str[index] = s1[i - 1];
            index--;
            i--;
            j--;
            } 
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                str[index] = s1[i-1];
                index--;
                i--;
            } 
            else {
                str[index] = s2[j-1];
                index --;
                j--;
            }
        }
        while(i>0){
            str[index] = s1[i-1];
            index --;
            i--;
        }
        while(j>0){
            str[index] = s2[j-1];
            index --;
            j--;
        }
        // reverse(str.begin(), str.end());
        return str;

    }
};


 
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());  // Sort greed factors
        sort(s.begin(), s.end());  // Sort cookies

        int cnt = 0;
        int i = 0, j = 0;

        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) { // ✅ Corrected condition
                cnt++;  
                i++;  // Move to next child
            }
            j++;  // Move to next cookie
        }

        return cnt;
    }
};

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0; // child index
        int j = 0; // cookie index
        int n = g.size(), m = s.size();

        while(i < n && j < m) {
            if(g[i] <= s[j]) {
                i++; // child is content
            }
            j++; // move to next cookie either way
        }
        
        return i; // number of content children
    }
};

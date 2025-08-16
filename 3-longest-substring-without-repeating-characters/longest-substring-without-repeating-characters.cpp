class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> result;
        int maxLen = 0;
        int l = 0, r = 0;

        while (r < n) {
            if (result.find(s[r]) == result.end()) {
                // expand window
                result.insert(s[r]);
                maxLen = max(maxLen, r - l + 1);
                r++;
            } else {
                // shrink window
                result.erase(s[l]);
                l++;
            }
        }
        return maxLen;
    }
};

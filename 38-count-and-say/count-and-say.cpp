class Solution {
public:

        string getNextTerm(const string &s) {
            string result = "";
            int count = 1;
            
            for (int i = 1; i <= s.size(); i++) {
                if (i < s.size() && s[i] == s[i - 1]) {
                    count++;
                } else {
                    result += to_string(count) + s[i - 1];
                    count = 1;
                }
            }
            return result;
        }

        // Recursive function
        string countAndSay(int n) {
            // Base case
            if (n == 1) return "1";
            
            // Recursive step: get (n-1)th term, then build nth
            string prev = countAndSay(n - 1);
            return getNextTerm(prev);
        }
};
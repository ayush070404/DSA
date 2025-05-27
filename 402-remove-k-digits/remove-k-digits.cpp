class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        // Remove remaining digits from the end if needed
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Build the result from stack (in reverse order)
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        while(res.size() != 0 && res.back() == '0') res.pop_back();
        
        reverse(res.begin(), res.end());

        return res.empty() ? "0" : res;
    }
};

class Solution {
public:
    int minAddToMakeValid(string s) {
        int n= s.size();
        stack<char> st;
        int cnt = 0;
        for(int i=0 ; i <n ; i++){
            if(s[i]=='(') st.push(s[i]);
            else if(s[i]==')' && !st.empty()){
                st.pop();
            }
            else{
                cnt++;
            }
        }
    if(!st.empty()) return st.size() + cnt;
    return cnt;
    }
};
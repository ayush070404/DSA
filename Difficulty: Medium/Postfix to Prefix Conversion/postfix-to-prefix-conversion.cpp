// User function Template for C++

class Solution {
  public:
    string postToPre(string exp) {
        // Write your code here
        stack <string> st;
        int n =exp.size();
        for(int i = 0 ; i  < n ; i++){
            
            if(isalnum(exp[i])) st.push(string(1, exp[i]));
            
            else{
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                
                string convt = exp[i] + s2 + s1;
                st.push(convt);
            }
        }
        
     return st.top(); 
        
    }
};
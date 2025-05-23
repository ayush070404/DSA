// User function Template for C++

class Solution {
  public:
    string preToInfix(string exp) {
        // Write your code here
        stack <string> st;
        int n =exp.size();
        for(int i =n-1 ; i>= 0 ; i--){
            
            if(isalnum(exp[i])) st.push(string(1, exp[i]));
            
            else{
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                
                string convt = '(' + s1 + exp[i] + s2 +')';
                st.push(convt);
            }
        }
        
     return st.top(); 
    }
};
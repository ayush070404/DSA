// User function Template for C++

class Solution {
  public:
    string preToPost(string exp) {
         stack <string> st;
        int n =exp.size();
        for(int i =n-1 ; i>= 0 ; i--){
            
            if(isalnum(exp[i])) st.push(string(1, exp[i]));
            
            else{
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                
                string convt =  s1 + s2+ exp[i] ;
                st.push(convt);
            }
        }
        
     return st.top(); 
    }
};
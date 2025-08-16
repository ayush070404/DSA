class Solution {
public:

    string getNextTerm(string &s){
        string result = "";
        int count =1;
        for(int i=1 ; i<=s.size() ; i++){
            if(i< s.size() && s[i]==s[i-1]){
                count++;
            }
            else{
                result+= to_string(count)+s[i-1];
                count =1;
            }
        }
        return result;
    }

    string countAndSay(int n) {
        string term = "1";
        for(int i=2 ; i<=n ; i++){
            term = getNextTerm(term);
        }
        return term;
    }
};
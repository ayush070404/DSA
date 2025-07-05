class Solution {
public:
    bool checkPalin(string &substr){
        int n = substr.size();
        int low = 0 , high=n-1;
        while(low<= high){
            if(substr[low]!=substr[high]){
                return false;
            }
            else{
                low++;
                high--;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string ans="";
        for(int i = 0 ; i< n ;i++){
            string substr = "";
            for(int j =i ; j<n ; j++){
                substr+=s[j];
                if(checkPalin(substr)== true && substr.size()>ans.size()){
                    ans = substr;
                }
            }
        }
        return ans;
    }
};
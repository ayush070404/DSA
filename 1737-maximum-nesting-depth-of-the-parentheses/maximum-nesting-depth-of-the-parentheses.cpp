class Solution {
public:
    int maxDepth(string s) {
        int n =s.size();
        int count = 0;
        int ans = 0;
        for(char ch: s){
            if(ch == '('){
                count++;
                ans = max(ans, count);
            }
            else if(ch== ')'){
                count --;
            }
            else{
                continue;
            }
        }
    return ans;
    }
};
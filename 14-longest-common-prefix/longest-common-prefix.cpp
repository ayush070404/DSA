class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n =strs.size();
        string pre = strs[0];

        for(int i = 1 ; i< n ; i++){
            string s1= strs[i];
            int m = s1.length();
            int p = pre.size();
            int cnt = 0;
            for(int j = 0 ; j< min(m, p) ; j++){
                if(pre[j] == s1[j]) {
                    pre[j] = s1[j];
                    cnt++;
                }
                else break;
            }
            pre.erase(cnt, p-cnt);
            cnt = 0;
        }
        return pre;
    }
};
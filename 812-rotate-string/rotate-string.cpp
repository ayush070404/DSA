class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        if(n != m) return false;

        for(int i = 0 ; i < n ; i++){
            string ans = "";
            for(int j = 0 ; j < m ; j++){
                ans += s[(i + j) % n];
            }

            if(ans == goal) return true;
        }
        return false;
    }
};

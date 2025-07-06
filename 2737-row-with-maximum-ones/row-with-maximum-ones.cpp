class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int cnt_max = 0;
        int index = -1;
        vector<int> ans;

        //traverse the matrix:
        for (int i = 0; i < n; i++) {
            int cnt_ones = 0;
            for (int j = 0; j < m; j++) {
                if(matrix[i][j] == 1) cnt_ones++;
            }
            if (cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                index = i;
                ans = {index, cnt_max};
            }
        }
        if(ans.empty()) return{0,0};
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;

        for(int i =1 ; i<=n ; i++){
            vector<int> row(i , 1);
            vector<int> prevRow;
            if(!ans.empty()) prevRow = ans.back();
            if(i == 1|| i == 2) {
                ans.push_back(row);
            }
            else{
                for(int j = 1 ; j<i-1 ; j++){
                    row[j] = prevRow[j-1]+ prevRow[j];
                }
                ans.push_back(row);
            }
        }
    return ans;
    }
};
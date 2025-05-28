class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<pair<int , int>> zeroes;

        for (int row = 0 ; row< n ; row++){
            for(int col  = 0 ; col < m ; col++){

                if(matrix[row][col] == 0){
                    zeroes.push_back({row, col});
                }
            }
        }

        while(!zeroes.empty()){
            int row = zeroes.back().first;
            int col = zeroes.back().second;
            zeroes.pop_back();
            for(int j = 0 ; j< m ; j++ ){
                matrix[row][j] = 0;
            }
            for(int i = 0 ; i< n ; i++ ){
                matrix[i][col] = 0;
            }
        }


    }
};
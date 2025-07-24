class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int row = 0 ; row<n ;row++){
            for(int col = row ; col<n ; col++){
                if(row == col) continue;
                swap(matrix[row][col], matrix[col][row]);
            }
        }

        for(int col = 0; col<n /2; col++){
            for(int row = 0 ; row<n ; row++){
                swap(matrix[row][col], matrix[row][n-1-col]);
            }
        }
        
    }
};
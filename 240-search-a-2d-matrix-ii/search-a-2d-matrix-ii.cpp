class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        return search(matrix, 0, 0, matrix.size() - 1, matrix[0].size() - 1, target);
    }

private:
    bool search(vector<vector<int>>& matrix, int r1, int c1, int r2, int c2, int target) {
        // Base case: if submatrix is invalid
        if (r1 > r2 || c1 > c2) return false;

        // If submatrix is small, search it manually (brute-force for 2x2 or 3x3 etc.)
        if ((r2 - r1 <= 1) && (c2 - c1 <= 1)) {
            for (int i = r1; i <= r2; i++) {
                for (int j = c1; j <= c2; j++) {
                    if (matrix[i][j] == target) return true;
                }
            }
            return false;
        }

        // Find the middle element
        int mid_row = (r1 + r2) / 2;
        int mid_col = (c1 + c2) / 2;
        int mid_val = matrix[mid_row][mid_col];

        if (mid_val == target) return true;
        else if (mid_val > target) {
            // Eliminate bottom-right part
            return search(matrix, r1, c1, mid_row, mid_col, target) ||       // top-left
                   search(matrix, r1, mid_col + 1, mid_row, c2, target) ||  // top-right
                   search(matrix, mid_row + 1, c1, r2, mid_col, target);    // bottom-left
        } else {
            // Eliminate top-left part
            return search(matrix, mid_row + 1, mid_col + 1, r2, c2, target) ||   // bottom-right
                   search(matrix, r1, mid_col + 1, mid_row, c2, target) ||       // top-right
                   search(matrix, mid_row + 1, c1, r2, mid_col, target);         // bottom-left
        }
    }
};

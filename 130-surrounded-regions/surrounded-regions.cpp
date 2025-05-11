class Solution {
public:


    void dfs(int row, int col, int n, int m, vector<vector<int>> &vis, vector<vector<char>> &mat) {
        vis[row][col] = 1;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                vis[nrow][ncol] == 0 && mat[nrow][ncol] == 'O') {
                dfs(nrow, ncol, n, m, vis, mat);
            }
        }
    }

    void solve(vector<vector<char>>& mat) {
     
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // First and last row
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && mat[0][j] == 'O') {
                dfs(0, j, n, m, vis, mat);
            }
            if (!vis[n - 1][j] && mat[n - 1][j] == 'O') {
                dfs(n - 1, j, n, m, vis, mat);
            }
        }

        // First and last column
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && mat[i][0] == 'O') {
                dfs(i, 0, n, m, vis, mat);
            }
            if (!vis[i][m - 1] && mat[i][m - 1] == 'O') {
                dfs(i, m - 1, n, m, vis, mat);
            }
        }

        // Flip unvisited 'O' to 'X'
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && mat[row][col] == 'O') {
                    mat[row][col] = 'X';
                }
            }
        }

        // return mat;
    }   
    
};
class Solution {
public:

    void dfs(int n , int m, int row, int col , vector<vector<int>> &vis, vector<vector<char>> &grid){
        vis[row][col] = 1;
        int delrow[] = {-1, 0 , 1 , 0};
        int delcol[] = {0, 1 , 0 , -1};

        for(int i =0 ; i<4; i++){
            int r = row + delrow[i];
            int c = col + delcol[i];

            if(r>= 0 && r< n && c>= 0 && c< m && vis[r][c] == 0 && grid[r][c] == '1'){
                dfs(n , m , r ,c ,vis, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int num = 0;
        vector<vector<int>> vis(n, vector<int> (m ,0));

        for(int row =0 ; row<n ; row++){
            for(int col =0 ; col <m ; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    dfs(n , m , row , col , vis , grid);
                    num++;
                }
            }
        }
    return num;
    }
};
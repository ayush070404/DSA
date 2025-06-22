class Solution {
public:

    void dfs(int m , int n, int row, int col , vector<vector<int>> &vis, vector<vector<char>> &grid){
        vis[row][col] = 1;
        int delrow[] = {-1, 0 , 1 , 0};
        int delcol[] = {0, 1 , 0 , -1};

        for(int i =0 ; i<4; i++){
            int r = row + delrow[i];
            int c = col + delcol[i];

            if(r>= 0 && r< m && c>= 0 && c< n && vis[r][c] == 0 && grid[r][c] == '1'){
                dfs(m , n , r ,c ,vis, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int num = 0;
        vector<vector<int>> vis(m, vector<int> (n ,0));

        for(int row =0 ; row<m ; row++){
            for(int col =0 ; col <n ; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    dfs(m , n , row , col , vis , grid);
                    num++;
                }
            }
        }
    return num;
    }
};
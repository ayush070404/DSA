class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int> , int>> q; // queue declaration
        vector<vector<int>> vis(n, vector<int>(m , 0));
        int cntFresh = 0;

        for(int row=0 ; row< n ; row++){
            for(int col=0 ; col< m ; col++){
                if(grid[row][col] == 2){
                    q.push({{row,col}, 0});
                    vis[row][col] = 2;
                }
                // else{
                //     vis[row][col] = 0;
                // }

                if(grid[row][col] ==1) cntFresh++;
            }
        }
        int tm =0;
        int cnt = 0;
        int delrow [] = {-1 , 0 , 1, 0};
        int delcol [] = { 0 , 1 , 0 ,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
         tm = max(tm, t);

            for(int i=0 ; i< 4; i++){
                
                int row = r + delrow[i];
                int col = c + delcol[i];
                if(row >= 0 && row < n && col>=0 && col < m && vis[row][col] == 0 && grid[row][col] == 1){
                    q.push({{row, col }, t+1});
                    vis[row][col] = 2;
                    cnt++;
                }
                
            }
        }
    if(cnt != cntFresh) return -1;

    else return tm;
       
    }
};
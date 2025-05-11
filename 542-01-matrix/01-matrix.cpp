class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m , 0));
        vector<vector<int>> ans(n, vector<int>(m , 0));

        queue<pair<pair<int, int> , int>> q;

        for(int row = 0 ; row < n ; row++){
            for(int col =0 ; col < m ; col++){
                if( mat[row][col] == 0){
                    q.push({{row, col}, 0});
                    vis[row][col] = 1;
                    // ans[row][col] =0;
                }
            }
        }

        int delrow[] = {-1 , 0 , 1 , 0};
        int delcol[] = {0 , 1, 0 , -1};
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            ans[r][c] = dis;

            for(int i =0 ; i<4 ; i++){
                int row = r + delrow[i];
                int col = c + delcol[i];
                if(row>= 0 && row <n && col>= 0 && col < m && vis[row][col]== 0){
                    q.push({{row,col}, dis+1});
                    vis[row][col] = 1;
                }
            }
        }
        return ans;
    }
};
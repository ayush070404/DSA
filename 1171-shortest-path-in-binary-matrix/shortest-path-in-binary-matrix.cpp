// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int n = grid.size();
//         if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
//         if(n ==1) return 1;
//         vector<vector<int>> dist(n , vector<int> (n , 1e9));
//         queue<pair<int , pair<int, int>>> q;
//         q.push({ 1 , { 0 , 0}});
//         dist[0][0] = 1;

//         int delrow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
//         int delcol[] = {-1, 0, 1, 1, 1, 0, -1, -1};


//         while(!q.empty()){
//             int row = q.front().second.first;
//             int col = q.front().second.second;
//             int dis = q.front().first;
//             q.pop();

//             for(int i =0 ; i< 8 ; i++){
//                 int nrow = row + delrow[i];
//                 int ncol = col + delcol[i];

//                 if(nrow >=0 && nrow < n && ncol >= 0 && ncol <n && grid[nrow][ncol] == 0){
//                     if(dis + 1 < dist[nrow][ncol]){
//                         dist[nrow][ncol] = dis +1;
//                         if(nrow == n-1 && ncol == n-1) return dist[nrow][ncol];
//                         q.push({dist[nrow][ncol], {nrow, ncol}});
//                     }
//                 }
//             }
//         }
//     return -1;   
//     }
// };
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<int, pair<int, int>>> q; // {steps, {row, col}}
        q.push({1, {0, 0}});
        vis[0][0] = 1;

        int delrow[] = {-1,-1, 0,1,1,1, 0,-1};
        int delcol[] = {0 ,1, 1,1,0 ,-1,-1,-1};

        while(!q.empty()){
            int r = q.front().second.first;
            int c = q.front().second.second;
            int steps = q.front().first;
            q.pop();

            if(r == n-1 & c == n-1) return steps;

            for(int i = 0; i < 8 ; i++){
                int row = r + delrow[i];
                int col = c + delcol[i];

                if(row >= 0 && row < n && col >= 0 && col < n && !vis[row][col] && grid[row][col] == 0){
                    vis[row][col] = 1;
                    q.push({steps+ 1 , {row ,col}});
                }
            } 
        }
    return -1;  
    }
};

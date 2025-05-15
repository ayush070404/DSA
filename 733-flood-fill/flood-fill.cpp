class Solution {
public:

    void dfs(int n, int m , int row , int col , vector<vector<int>>& image ,vector<vector<int>> &res, vector<vector<int>> &vis ,int  inCol, int color){
        vis[row][col] = 1;
res[row][col] = color; // \U0001f525 Add this line


        int delrow[] = {-1 , 0 , 1 , 0};
        int delcol[] = {0 , 1 , 0 , -1};

        for(int i = 0 ; i<4 ; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow< n && ncol>=0 && ncol < m && image[nrow][ncol]== inCol && vis[nrow][ncol] == -1){
                dfs(n , m , nrow , ncol , image, res, vis, inCol, color);
                // vis[nrow][ncol] = 1;
                res[nrow][ncol] = color;

            }
        }


    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int n = image.size();
       int m = image[0].size();

       vector<vector<int>> res = image;
       vector<vector<int>> vis(n , vector<int> (m, -1));
       int inCol = image[sr][sc];

       dfs(n , m , sr ,sc , image , res , vis , inCol , color);

       return res;
    }
};
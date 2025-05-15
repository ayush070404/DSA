class Solution {
public:

void dfs(int row, int col , vector<vector<int>> &vis,vector<vector<char>>& board,      vector<vector<char>> &ans){
    int n = board.size();
    int m = board[0].size();

    vis[row][col] = 1;
    ans[row][col] = 'O';
    int delrow[] = {-1, 0 , 1, 0};
    int delcol[] = {0 , 1 , 0, -1};

    for(int i =0 ; i< 4 ; i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            vis[nrow][ncol] == 0 && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol , vis , board, ans);
            }
    }

}

void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();

    vector<vector<char>> ans(n , vector<char>(m, 'X'));
    vector<vector<int>> vis(n, vector<int>(m, 0));

    // Left and Right border
    for(int i = 0; i < n ; i++){
        if(board[i][0] == 'O'){
            dfs(i , 0 , vis, board, ans );
        }
        if(board[i][m-1] == 'O'){
            dfs(i , m-1 , vis, board, ans );
        }
    }

    // Top and Bottom border (Fix here)
    for(int j = 0; j < m ; j++){
        if(board[0][j] == 'O'){
            dfs(0 , j , vis, board, ans );
        }
        if(board[n-1][j] == 'O'){
            dfs(n-1 , j , vis, board, ans );
        }
    }

    board = ans;
}

};

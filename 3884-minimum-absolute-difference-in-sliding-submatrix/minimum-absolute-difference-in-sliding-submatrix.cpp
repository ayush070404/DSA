class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1, 0));

        for (int i = 0; i <= n - k; i++) {
            for (int j = 0; j <= m - k; j++) {
                vector<int> temp;

                // Extract the k x k submatrix elements
                for (int x = 0; x < k; x++) {
                    for (int y = 0; y < k; y++) {
                        temp.push_back(grid[i + x][j + y]);
                    }
                }

                // Sort to easily find minimum difference between distinct elements
                sort(temp.begin(), temp.end());

                int diff = INT_MAX;
                for (int t = 0; t < temp.size() - 1; t++) {
                    if (temp[t] != temp[t + 1]) {
                        diff = min(diff, abs(temp[t] - temp[t + 1]));
                    }
                }

                // If all values are equal, no distinct pair exists; return 0
                ans[i][j] = (diff == INT_MAX ? 0 : diff);
            }
        }

        return ans;
    }
};

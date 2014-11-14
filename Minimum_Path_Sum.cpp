class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        vector<vector<int>> f;

        if (grid.size() == 0)
            return 0;
        if (grid[0].size() == 0)
            return 0;

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            vector<int> t;
            for (int j = 0; j < n; j++)
                t.push_back(0);
            f.push_back(t);
        }

        f[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
            f[i][0] = f[i-1][0] + grid[i][0];
        for (int j = 1; j < n; j++)
            f[0][j] = f[0][j-1] + grid[0][j];

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
            {
                f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j];
            }

        //Note about the return, it's mot f[m][n]!
        return f[m-1][n-1];
    }
};

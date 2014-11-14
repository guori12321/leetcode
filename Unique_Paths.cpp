class Solution {
public:
    int uniquePaths(int m, int n) {
        int f[100][100];

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                f[i][j] = 0;

        for (int i = 0; i < m; i++)
            f[i][0] = 1;
        for (int j = 0; j < n; j++)
            f[0][j] = 1;

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
            {
                f[i][j] = f[i-1][j] + f[i][j-1];
            }

        //Attention that the grid in the example is numbered 1..m, 1..n, but in the array we number 0..m-1, 0..n-1
        return f[m-1][n-1];
    }
};

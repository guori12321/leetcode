//We can simply rotate by claiming a new matrix.
//Now let's do it in-place.

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if (n <= 1)
            return;

        int m = n/2;

        if (n%2 == 1)
            for (int i = 1; i <= m; i++)
            {
                vector<int> t;
                int l = m - i;
                int r = m + i;

                for (int j = l; j <= r; j++)
                    //left
                    t.push_back(matrix[m-i][j]);

                for (int j = l; j <= r; j++)
                    //left = down
                    matrix[j][m-i] = matrix[m+i][j];

                for (int j = l; j <= r; j++)
                    //down = right
                    matrix[m+i][j] = matrix[r-(j-l)][m+i];

                for (int j = l; j <= r; j++)
                    //right = up
                    matrix[j][m+i] = matrix[m-i][j];

                for (int j = l; j <= r; j++)
                    //up = original left
                    matrix[m-i][j] = t[r-j];
            }
        else
        {
            for (int i = 0; i < m; i++)
            {
                vector<int> t;
                int l = m-1 - i;
                int r = m + i;
                for (int j = l; j <= r; j++)
                    //left
                    t.push_back(matrix[j][m-1-i]);

                //left = down
                for (int j = l; j <=r; j++)
                    matrix[j][m-1-i] = matrix[m+i][j];

                //down = right
                for (int j = l; j <=r; j++)
                    matrix[m+i][j] = matrix[r-(j-l)][m+i];

                //right = up
                for (int j = l; j <=r; j++)
                    matrix[j][m+i] = matrix[m-1-i][j];

                //up = original left
                for (int j = l; j <= r; j++)
                    matrix[m-1-i][j] = t[r-j];
            }
        }

        return;
    }
};


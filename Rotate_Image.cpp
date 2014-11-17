//We can simply rotate by claiming a new matrix.
//Or we can just rotate round by round, from the most inner round to the outside
//We know that one center symmetry can be the add of two line symmetry. Now let's do it via fold twice: one is by the diagonal, one is by the middle vertical line.
//
//Original:
//1 2
//3 4
//
//After fold by the diagonal line:
//1 3
//2 4
//
//After fold by the middle vertical line:
//3 1
//4 2

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
            {
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }

        //The codes are the same when n is odd and even
        if (n % 2 == 0)
            //n = 4, 0 1 2 3
            //n/2 = 2
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n/2; j++)
                {
                    int t = matrix[i][j];
                    matrix[i][j] = matrix[i][n-1 - j];
                    matrix[i][n-1 - j] = t;
                }
        else
            //n = 5, 0 1 2 3 4
            //n/2=2
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n/2; j++)
                {
                    int t = matrix[i][j];
                    matrix[i][j] = matrix[i][n-1 - j];
                    matrix[i][n-1 - j] = t;
                }
    }
};

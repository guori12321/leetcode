class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        if (matrix.size() == 0)
            return ans;

        int m = matrix.size();
        int n = matrix[0].size();

        //Note that 1+min(m,n)
        int levelMax = (1+min(m,n))/2;

        for (int i = 0; i < levelMax; i++)
        {
            int a = 0 + i;
            int b = 0 + i;
            int c = m-1 - i;
            int d = n-1 - i;

            //up
            for (int j = b; j <= d; j++)
                ans.push_back(matrix[a][j]);

            //right
            for (int j = a + 1; j <= c; j++)
                ans.push_back(matrix[j][d]);

            //Attention that c == a
            //down
            if (c > a)
                for (int j = d-1; j >= b; j--)
                    ans.push_back(matrix[c][j]);

            //Attention that b ==d
            //And remember that we can not add [a][b], it's already added
            //left
            if (b < d)
            for (int j = c-1; j > a; j--)
                ans.push_back(matrix[j][b]);
        }
        return ans;
    }
};

class Solution {
public:
    int t = 0;

    bool DFS(int rowl, int rowr, int l, int r, vector<vector<int>> &matrix)
    {
        if (rowl > rowr || l > r || rowl > matrix.size()-1 || rowr < 0 || l > matrix[0].size() -1|| r < 0)
            return false;

        if (rowl == rowr && l == r)
            if (matrix[rowl][l] == t)
                return true;
            else
                return false;

        if (rowl == rowr)
        {
            int m = (l+r) / 2;
            if (matrix[rowl][m] == t)
                return true;
            if (matrix[rowl][m] > t)
                return DFS(rowl, rowl, l, m-1, matrix);
            else
                return DFS(rowl, rowl, m+1, r, matrix);
        }

        int rowm = (rowl + rowr) / 2;
        if (matrix[rowm][0] > t)
            return DFS(rowl, rowm-1, l, r, matrix);
        else
            if (matrix[rowm][matrix[0].size()-1] < t)
                return DFS(rowm+1, rowr, l, r, matrix);
            else{
                return DFS(rowm, rowm, l, r, matrix);
            }
    }
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        t = target;

        if (matrix.size() == 0)
            return false;

        if (matrix[0].size() == 0)
            return false;

        return DFS(0, matrix.size()-1, 0, matrix[0].size() -1, matrix);

    }
};


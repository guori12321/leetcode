class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {

        if (triangle.size() < 1)
            return 0;
        if (triangle.size() == 1)
            return triangle[0][0];

        vector<int> level0;
        vector<int> level1;

        int m = triangle.size();
        int n = triangle[0].size();

        level0 = triangle[0];
        for (int i = 1; i < m; i++)
        {
            level1 = triangle[i];
            for (int j = 0; j < triangle[i].size(); j++)
                //Pay attention to the left and right boundaries.
                //we need to transfer level0.size() to int, otherwise
                //no matching function for call to ‘min(int&, std::vector<int>::size_type)’
                level1[j] = min(level0[max(0, j-1)], level0[ min(j, int(level0.size()-1) ) ] ) + triangle[i][j];
            level0 = level1;
        }

        int ans = INT_MAX;
        for (int i = 0; i < level0.size(); i++)
            ans = min(ans, level0[i]);
        return ans;
    }
};


// [ 1, 2, 3 ],
// [ 8, 9, 4 ],
// [ 7, 6, 5 ]

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> ans;

        if (n == 0)
            return ans;

        for (int i = 0; i < n; i++)
        {
            vector<int> t;
            for (int j = 0; j < n; j++)
                t.push_back(0);
            ans.push_back(t);
        }

        int levelMax = (n+1) / 2;
        int num = 1;

        for (int i = 0; i < levelMax; i++)
        {
            int a = 0 + i;
            int b = n-1 - i;

            for (int j = a; j <= b; j++)
            {
                ans[a][j] = num;
                num++;
            }
            for (int j = a+1; j <= b; j++)
            {
                ans[j][b] = num;
                num++;
            }
            for (int j = b-1; j >= a; j--)
            {
                ans[b][j] = num;
                num++;
            }
            for (int j = b-1; j >= a+1; j--)
            {
                ans[j][a] = num;
                num++;
            }
        }
        return ans;
    }
};

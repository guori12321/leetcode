class Solution {
public:
    vector<bool> flag;
    vector<vector<int>> ansList;
    vector<int> ans;
    int n = 0;

    void DFS(int k, vector<int> &num)
    {
        if (k == 0)
        {
            ansList.push_back(ans);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (flag[i] == false)
            {
                flag[i] = true;
                ans.push_back(num[i]);
                DFS(k-1);

                flag[i] = false;
                ans.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int> &num) {
        n = num.size();
        if (n == 0)
            return ansList;

        for (int i = 0; i < n; i++)
            flag.push_back(false);

        DFS(n, num);

        return ansList;
    }
};

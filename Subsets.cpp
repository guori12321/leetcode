class Solution {
public:

    vector<vector<int>> ansList;
    vector<int> ans;

    void DFS(int k, vector<int> &S)
    {
        int n = S.size();
        if (k == n)
        {
            ansList.push_back(ans);
            return;
        }

        DFS(k+1, S);

        ans.push_back(S[k]);
        DFS(k+1, S);
        ans.pop_back();

        return;
    }

    vector<vector<int> > subsets(vector<int> &S) {

        int n = S.size();
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                if (S[i] > S[j])
                {
                    int t = S[i];
                    S[i] = S[j];
                    S[j] = t;
                }

        DFS(0, S);
        return ansList;
    }
};


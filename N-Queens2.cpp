class Solution {
public:
    vector<int> ans;
    vector<vector<string>> ansList;
    int queueNum = 0;
    int totAns = 0;

    bool check(int level, int loc)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            if ((abs(i-level) == abs(loc - ans[i])) || (loc == ans[i]))
                return false;
        }
        return true;
    }

    void DFS(int level)
    {
        if (level >= queueNum)
            return;
        for (int i = 0; i < queueNum; i++)
        {
            if (check(level, i))
            {
                ans.push_back(i);
                if (level == queueNum - 1)
                {
                    vector<string> oneAns;
                    for (int t = 0; t < ans.size(); t++)
                    {
                        string ansColumn = "";
                        for (int tt = 0; tt < ans.size(); tt++)
                            ansColumn += tt == ans[t] ? "Q" : ".";
                        oneAns.push_back(ansColumn);
                    }
                    ansList.push_back(oneAns);
                    totAns++;
                }
                else
                    DFS(level+1);

                ans.pop_back();
            }
        }
    }

    int totalNQueens(int n) {
        queueNum = n;

        DFS(0);
        return totAns;
    }
};


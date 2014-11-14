class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        vector<int> ans(m+n);

        int p = 0;
        int i = 0;
        int j = 0;

        //Note that if we put (i==m) or (j ==n) inside while, there should be or, otherwise &&
        while (i < m || j < n)
        {
            if (i == m)
            {
                while (j < n)
                {
                    ans[p] = B[j];
                    p++;
                    j++;
                }
                break;
            }
            if (j == n)
            {
                while (i < m)
                {
                    ans[p] = A[i];
                    p++;
                    i++;
                }
                break;
            }

            if (A[i] <= B[j])
            {
                ans[p] = A[i];
                p++;
                i++;
            }
            else
            {
                ans[p] = B[j];
                p++;
                j++;
            }
        }

        for (int i = 0; i < ans.size(); i++)
            A[i] = ans[i];
        return;
    }
};

class Solution {

public:
    int DFS(int l, int r, int A[], int n, int target)
    {
        if (l > r || l > n-1 || r < 0)
            return -1;
        //Note that l may equal to r, in this situation, we treat it as not rotated.
        if (A[l] <= A[r])
        {
            int m = (l+r)/2;
            if (A[m] == target)
                return m;
            if (A[m] > target)
                return DFS(l, m-1, A, n, target);
            else
                return DFS(m+1, r, A, n, target);
        }
        else
        {
            int m = (l+r)/2;
            int a = DFS(l, m, A, n, target);
            int b = DFS(m+1, r, A, n, target);
            if (a == -1 && b == -1)
                return -1;
            return (a+ b +1);
        }
    }

    int search(int A[], int n, int target) {
        return DFS(0, n-1, A, n ,target);
    }
};


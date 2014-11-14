class Solution {
public:
    int DFS(int l, int r, vector<int> &num)
    {
        if (l > r)
            return INT_MAX;
        if (l == r)
            return num[l];

        if (num[l] < num[r])
            return num[l];

        int t = (l+r) / 2;
        //Note that in the binary search, the left and right parts cannot be overlapped, otherwise we will meet TLE: we recursive on the same number again and again.
        return min(DFS(l, t, num), DFS(t+1, r, num));
    }

    int findMin(vector<int> &num) {
        return DFS(0, num.size() - 1, num);
    }
};


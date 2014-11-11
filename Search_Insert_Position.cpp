class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int l = 0, r = n-1;

        while (l <= r)
        {
            if (A[(l+r)/2] == target)
                return (l+r) / 2;

            if (A[(l+r)/2] < target)
                l = (l+r)/2 + 1;
            else
                if (A[(l+r)/2] > target)
                    r = (l+r)/2 - 1;
        }

        //Pay attention to boundaries.
        //If not sure, give as more examples as possible.
        if (l >= n)
            return n;

        if (A[l] < target)
            return l+1;
        return l;
    }
};

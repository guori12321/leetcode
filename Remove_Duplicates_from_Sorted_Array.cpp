class Solution {
public:
    int removeDuplicates(int A[], int n) {

        if (n <= 1)
            return n;

        int i = 0, j = 1;

        while (i < n)
        {
            i++;
            if (A[i-1] >= A[i])
            {
                //Attention about boundary. while (j < n), then j can be n outside while loop.
                while (A[i-1] >= A[j] && j < n-1)
                    j++;
                if (j == n-1)
                {
                    if (A[i-1] >= A[j])
                        return i;
                    else
                    {
                        A[i] = A[j];
                        return i+1;
                    }
                }
                A[i] = A[j];
                j++;
            }
        }

        //while (i < n), and outside while, i can be n
        return i;
    }
};


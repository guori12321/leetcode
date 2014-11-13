class Solution {
public:
    void sortColors(int A[], int n) {
        int count[3];

        for (int i = 0; i < 3; i++)
            count[i] = 0;

        for (int i = 0; i < n; i++)
            count[ A[i] ]++;

        int pos = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < count[i]; j++)
            {
                A[pos] = i;
                pos++;
            }

        return;
    }
};

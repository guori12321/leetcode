//Very tricky problem
//Just like the poison and mouse question: you have 1024 boxes of medicines and 10 mouse to test which one of the 1024 medicine is poison. You just number the 1024 boxes from 0 to 1023, and they will have a corresponding binary number. And the 10 mouse stand for the 10 bits in th binary number. For one medicine, for the 1 bits in its binary number, let those mouse eat it who stand for the corresponding bits value of 1.
//And according to the result of the dead mouses, we can find the corresponding binary number of the poison.

class Solution {
public:
    int singleNumber(int A[], int n) {
        const int INT_BIT = sizeof(int) * 8;
        int count[INT_BIT];
        int ans = 0;

        for (int i = 0; i < INT_BIT; i++)
            count[i] = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < INT_BIT; j++)
            {
                //This is wrong:
                //count[j] += ( A[i] & (1 << j) );
                count[j] += (A[i] >> j) & 1;
                //Prevent overflow
                count[j] %= 3;
            }
        }

        for (int i = 0; i < INT_BIT; i++)
            if (count[i] % 3 != 0)
            {
                ans = ans | (1 << i);
            }

        return ans;

    }
};

//XOR. For the numbers who shows twice, we xor them twice so the result will be 0. For the number who shows just once, we xor it with 0, so the result is itself.
//A tricky problem...
class Solution {
public:
    int singleNumber(int A[], int n) {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans ^= A[i];
        }

        return ans;
    }
};

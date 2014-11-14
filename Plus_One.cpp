class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size();

        digits[n-1]++;

        for (int i = n-1; i >= 0; i--)
        {
            if (digits[i] > 9 && i > 0)
            {
                digits[i-1] += digits[i] / 10;
                digits[i] %= 10;
            }
        }

        if (digits[0] > 9)
        {
            int carry = digits[0] / 10;
            digits[0] %= 10;
            //No push_head, but insert(iter, [int times], elem)
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};

